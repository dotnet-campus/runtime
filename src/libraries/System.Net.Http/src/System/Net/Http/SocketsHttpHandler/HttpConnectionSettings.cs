// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System.Collections.Generic;
using System.Net.Security;

namespace System.Net.Http
{
    /// <summary>Provides a state bag of settings for configuring HTTP connections.</summary>
    internal sealed class HttpConnectionSettings
    {
        private const string Http2SupportEnvironmentVariableSettingName = "DOTNET_SYSTEM_NET_HTTP_SOCKETSHTTPHANDLER_HTTP2SUPPORT";
        private const string Http2SupportAppCtxSettingName = "System.Net.Http.SocketsHttpHandler.Http2Support";
        
        internal DecompressionMethods _automaticDecompression = HttpHandlerDefaults.DefaultAutomaticDecompression;

        internal bool _useCookies = HttpHandlerDefaults.DefaultUseCookies;
        internal CookieContainer _cookieContainer;

        internal bool _useProxy = HttpHandlerDefaults.DefaultUseProxy;
        internal IWebProxy _proxy;
        internal ICredentials _defaultProxyCredentials;

        internal bool _preAuthenticate = HttpHandlerDefaults.DefaultPreAuthenticate;
        internal ICredentials _credentials;

        internal bool _allowAutoRedirect = HttpHandlerDefaults.DefaultAutomaticRedirection;
        internal int _maxAutomaticRedirections = HttpHandlerDefaults.DefaultMaxAutomaticRedirections;

        internal int _maxConnectionsPerServer = HttpHandlerDefaults.DefaultMaxConnectionsPerServer;
        internal int _maxResponseDrainSize = HttpHandlerDefaults.DefaultMaxResponseDrainSize;
        internal TimeSpan _maxResponseDrainTime = HttpHandlerDefaults.DefaultResponseDrainTimeout;
        internal int _maxResponseHeadersLength = HttpHandlerDefaults.DefaultMaxResponseHeadersLength;

        internal TimeSpan _pooledConnectionLifetime = HttpHandlerDefaults.DefaultPooledConnectionLifetime;
        internal TimeSpan _pooledConnectionIdleTimeout = HttpHandlerDefaults.DefaultPooledConnectionIdleTimeout;
        internal TimeSpan _expect100ContinueTimeout = HttpHandlerDefaults.DefaultExpect100ContinueTimeout;
        internal TimeSpan _connectTimeout = HttpHandlerDefaults.DefaultConnectTimeout;

        internal Version _maxHttpVersion;

        internal SslClientAuthenticationOptions _sslOptions;

        internal IDictionary<string, object> _properties;

        public HttpConnectionSettings()
        {
            _maxHttpVersion = AllowHttp2 ? HttpVersion.Version20 : HttpVersion.Version11;
        }

        /// <summary>Creates a copy of the settings but with some values normalized to suit the implementation.</summary>
        public HttpConnectionSettings CloneAndNormalize()
        {
            // Force creation of the cookie container if needed, so the original and clone share the same instance.
            if (_useCookies && _cookieContainer == null)
            {
                _cookieContainer = new CookieContainer();
            }

            // The implementation uses Environment.TickCount to track connection lifetimes, as Environment.TickCount
            // is measurable faster than DateTime.UtcNow / Stopwatch.GetTimestamp, and we do it at least once per request.
            // However, besides its lower resolution (which is fine for SocketHttpHandler's needs), due to being based on
            // an Int32 rather than Int64, the difference between two tick counts is at most ~49 days.  This means that
            // specifying a connection idle or lifetime of greater than 49 days would cause it to never be reached.  The
            // chances of a connection being open anywhere near that long is close to zero, as is the chance that someone
            // would choose to specify such a long timeout, but regardless, we avoid issues by capping the timeouts.
            TimeSpan timeLimit = TimeSpan.FromDays(40); // something super long but significantly less than the 49 day limit
            TimeSpan pooledConnectionLifetime = _pooledConnectionLifetime < timeLimit ? _pooledConnectionLifetime : timeLimit;
            TimeSpan pooledConnectionIdleTimeout = _pooledConnectionIdleTimeout < timeLimit ? _pooledConnectionIdleTimeout : timeLimit;

            return new HttpConnectionSettings()
            {
                _allowAutoRedirect = _allowAutoRedirect,
                _automaticDecompression = _automaticDecompression,
                _cookieContainer = _cookieContainer,
                _connectTimeout = _connectTimeout,
                _credentials = _credentials,
                _defaultProxyCredentials = _defaultProxyCredentials,
                _expect100ContinueTimeout = _expect100ContinueTimeout,
                _maxAutomaticRedirections = _maxAutomaticRedirections,
                _maxConnectionsPerServer = _maxConnectionsPerServer,
                _maxHttpVersion = _maxHttpVersion,
                _maxResponseDrainSize = _maxResponseDrainSize,
                _maxResponseDrainTime = _maxResponseDrainTime,
                _maxResponseHeadersLength = _maxResponseHeadersLength,
                _pooledConnectionLifetime = pooledConnectionLifetime,
                _pooledConnectionIdleTimeout = pooledConnectionIdleTimeout,
                _preAuthenticate = _preAuthenticate,
                _properties = _properties,
                _proxy = _proxy,
                _sslOptions = _sslOptions?.ShallowClone(), // shallow clone the options for basic prevention of mutation issues while processing
                _useCookies = _useCookies,
                _useProxy = _useProxy,
            };
        }

        private static bool AllowHttp2
        {
            get
            {
                // First check for the AppContext switch, giving it priority over the environment variable.
                if (AppContext.TryGetSwitch(Http2SupportAppCtxSettingName, out bool allowHttp2))
                {
                    return allowHttp2;
                }

                // AppContext switch wasn't used. Check the environment variable.
                string envVar = Environment.GetEnvironmentVariable(Http2SupportEnvironmentVariableSettingName);
                if (envVar != null && (envVar.Equals("true", StringComparison.OrdinalIgnoreCase) || envVar.Equals("1")))
                {
                    // Allow HTTP/2.0 protocol.
                    return true;
                }

                // Default to a maximum of HTTP/1.1.
                return false;
            }
        }
    }
}
