/*
 * This file contains the default set of the mono internal calls.
 * Each type that has internal call methods must be declared here
 * with the ICALL_TYPE macro as follows:
 *
 * 	ICALL_TYPE(typeid, typename, first_icall_id)
 *
 * typeid must be a C symbol name unique to the type, don't worry about namespace
 * 	pollution, since it will be automatically prefixed to avoid it.
 * typename is a C string containing the full name of the type
 * first_icall_id s the symbol ID of the first internal call of the declared
 * 	type (see below)
 *
 * The list of internal calls of the methods of a type must follow the
 * type declaration. Each internal call is defined by the following macro:
 *
 * 	ICALL(icallid, methodname, cfuncptr)
 *
 * icallid must be a C symbol, unique for each icall defined in this file and
 * tipically equal to the typeid + '_' + a sequential number.
 * methodname is a C string defining the method name and the optional signature
 * (the signature is required only when several internal calls in the type
 * have the same name)
 * cfuncptr is the C function that implements the internal call. Note that this
 * file is included at the end of metadata/icall.c, so the C function must be
 * visible to the compiler there.
 *
 * *** Adding a new internal call ***
 * Remember that ICALL_TYPE declarations must be kept sorted wrt each other
 * ICALL_TYPE declaration. The same happens for ICALL declarations, but only
 * limited to the icall list of each type. The sorting is based on the type or
 * method name.
 * When adding a new icall, make sure it is inserted correctly in the list and
 * that it defines a unique ID. ID are currently numbered and ordered, but if
 * you need to insert a method in the middle, don't bother renaming all the symbols.
 * Remember to change also the first_icall_id argument in the ICALL_TYPE 
 * declaration if you add a new icall at the beginning of a type's icall list.
 */
ICALL_TYPE(UNORM, "Mono.Globalization.Unicode.Normalization", UNORM_1)
ICALL(UNORM_1, "load_normalization_resource", load_normalization_resource)

#ifndef DISABLE_COM
ICALL_TYPE(COMPROX, "Mono.Interop.ComInteropProxy", COMPROX_1)
ICALL(COMPROX_1, "AddProxy", ves_icall_Mono_Interop_ComInteropProxy_AddProxy)
ICALL(COMPROX_2, "FindProxy", ves_icall_Mono_Interop_ComInteropProxy_FindProxy)
#endif

ICALL_TYPE(RUNTIME, "Mono.Runtime", RUNTIME_1)
ICALL(RUNTIME_1, "GetDisplayName", ves_icall_Mono_Runtime_GetDisplayName)

#ifndef PLATFORM_RO_FS
ICALL_TYPE(KPAIR, "Mono.Security.Cryptography.KeyPairPersistence", KPAIR_1)
ICALL(KPAIR_1, "_CanSecure", ves_icall_Mono_Security_Cryptography_KeyPairPersistence_CanSecure)
ICALL(KPAIR_2, "_IsMachineProtected", ves_icall_Mono_Security_Cryptography_KeyPairPersistence_IsMachineProtected)
ICALL(KPAIR_3, "_IsUserProtected", ves_icall_Mono_Security_Cryptography_KeyPairPersistence_IsUserProtected)
ICALL(KPAIR_4, "_ProtectMachine", ves_icall_Mono_Security_Cryptography_KeyPairPersistence_ProtectMachine)
ICALL(KPAIR_5, "_ProtectUser", ves_icall_Mono_Security_Cryptography_KeyPairPersistence_ProtectUser)
#endif /* !PLATFORM_RO_FS */

ICALL_TYPE(ACTIV, "System.Activator", ACTIV_1)
ICALL(ACTIV_1, "CreateInstanceInternal", ves_icall_System_Activator_CreateInstanceInternal)

ICALL_TYPE(APPDOM, "System.AppDomain", APPDOM_1)
ICALL(APPDOM_1, "ExecuteAssembly", ves_icall_System_AppDomain_ExecuteAssembly)
ICALL(APPDOM_2, "GetAssemblies", ves_icall_System_AppDomain_GetAssemblies)
ICALL(APPDOM_3, "GetData", ves_icall_System_AppDomain_GetData)
ICALL(APPDOM_4, "InternalGetContext", ves_icall_System_AppDomain_InternalGetContext)
ICALL(APPDOM_5, "InternalGetDefaultContext", ves_icall_System_AppDomain_InternalGetDefaultContext)
ICALL(APPDOM_6, "InternalGetProcessGuid", ves_icall_System_AppDomain_InternalGetProcessGuid)
ICALL(APPDOM_7, "InternalIsFinalizingForUnload", ves_icall_System_AppDomain_InternalIsFinalizingForUnload)
ICALL(APPDOM_8, "InternalPopDomainRef", ves_icall_System_AppDomain_InternalPopDomainRef)
ICALL(APPDOM_9, "InternalPushDomainRef", ves_icall_System_AppDomain_InternalPushDomainRef)
ICALL(APPDOM_10, "InternalPushDomainRefByID", ves_icall_System_AppDomain_InternalPushDomainRefByID)
ICALL(APPDOM_11, "InternalSetContext", ves_icall_System_AppDomain_InternalSetContext)
ICALL(APPDOM_12, "InternalSetDomain", ves_icall_System_AppDomain_InternalSetDomain)
ICALL(APPDOM_13, "InternalSetDomainByID", ves_icall_System_AppDomain_InternalSetDomainByID)
ICALL(APPDOM_14, "InternalUnload", ves_icall_System_AppDomain_InternalUnload)
ICALL(APPDOM_15, "LoadAssembly", ves_icall_System_AppDomain_LoadAssembly)
ICALL(APPDOM_16, "LoadAssemblyRaw", ves_icall_System_AppDomain_LoadAssemblyRaw)
ICALL(APPDOM_17, "SetData", ves_icall_System_AppDomain_SetData)
ICALL(APPDOM_18, "createDomain", ves_icall_System_AppDomain_createDomain)
ICALL(APPDOM_19, "getCurDomain", ves_icall_System_AppDomain_getCurDomain)
ICALL(APPDOM_20, "getFriendlyName", ves_icall_System_AppDomain_getFriendlyName)
ICALL(APPDOM_21, "getRootDomain", ves_icall_System_AppDomain_getRootDomain)
ICALL(APPDOM_22, "getSetup", ves_icall_System_AppDomain_getSetup)

ICALL_TYPE(ARGI, "System.ArgIterator", ARGI_1)
ICALL(ARGI_1, "IntGetNextArg()",                  mono_ArgIterator_IntGetNextArg)
ICALL(ARGI_2, "IntGetNextArg(intptr)", mono_ArgIterator_IntGetNextArgT)
ICALL(ARGI_3, "IntGetNextArgType",                mono_ArgIterator_IntGetNextArgType)
ICALL(ARGI_4, "Setup",                            mono_ArgIterator_Setup)

ICALL_TYPE(ARRAY, "System.Array", ARRAY_1)
ICALL(ARRAY_1, "ClearInternal",    ves_icall_System_Array_ClearInternal)
ICALL(ARRAY_2, "Clone",            mono_array_clone)
ICALL(ARRAY_3, "CreateInstanceImpl",   ves_icall_System_Array_CreateInstanceImpl)
ICALL(ARRAY_14, "CreateInstanceImpl64",   ves_icall_System_Array_CreateInstanceImpl64)
ICALL(ARRAY_4, "FastCopy",         ves_icall_System_Array_FastCopy)
ICALL(ARRAY_5, "GetGenericValueImpl", ves_icall_System_Array_GetGenericValueImpl)
ICALL(ARRAY_6, "GetLength",        ves_icall_System_Array_GetLength)
ICALL(ARRAY_15, "GetLongLength",        ves_icall_System_Array_GetLongLength)
ICALL(ARRAY_7, "GetLowerBound",    ves_icall_System_Array_GetLowerBound)
ICALL(ARRAY_8, "GetRank",          ves_icall_System_Array_GetRank)
ICALL(ARRAY_9, "GetValue",         ves_icall_System_Array_GetValue)
ICALL(ARRAY_10, "GetValueImpl",     ves_icall_System_Array_GetValueImpl)
ICALL(ARRAY_11, "SetGenericValueImpl", ves_icall_System_Array_SetGenericValueImpl)
ICALL(ARRAY_12, "SetValue",         ves_icall_System_Array_SetValue)
ICALL(ARRAY_13, "SetValueImpl",     ves_icall_System_Array_SetValueImpl)

ICALL_TYPE(BUFFER, "System.Buffer", BUFFER_1)
ICALL(BUFFER_1, "BlockCopyInternal", ves_icall_System_Buffer_BlockCopyInternal)
ICALL(BUFFER_2, "ByteLengthInternal", ves_icall_System_Buffer_ByteLengthInternal)
ICALL(BUFFER_3, "GetByteInternal", ves_icall_System_Buffer_GetByteInternal)
ICALL(BUFFER_4, "SetByteInternal", ves_icall_System_Buffer_SetByteInternal)

ICALL_TYPE(CHAR, "System.Char", CHAR_1)
ICALL(CHAR_1, "GetDataTablePointers", ves_icall_System_Char_GetDataTablePointers)

ICALL_TYPE (COMPO_W, "System.ComponentModel.Win32Exception", COMPO_W_1)
ICALL (COMPO_W_1, "W32ErrorMessage", ves_icall_System_ComponentModel_Win32Exception_W32ErrorMessage)

ICALL_TYPE(DEFAULTC, "System.Configuration.DefaultConfig", DEFAULTC_1)
ICALL(DEFAULTC_1, "get_bundled_machine_config", get_bundled_machine_config)
ICALL(DEFAULTC_2, "get_machine_config_path", ves_icall_System_Configuration_DefaultConfig_get_machine_config_path)

/* Note that the below icall shares the same function as DefaultConfig uses */
ICALL_TYPE(INTCFGHOST, "System.Configuration.InternalConfigurationHost", INTCFGHOST_1)
ICALL(INTCFGHOST_1, "get_bundled_app_config", get_bundled_app_config)
ICALL(INTCFGHOST_2, "get_bundled_machine_config", get_bundled_machine_config)

ICALL_TYPE(CONSOLE, "System.ConsoleDriver", CONSOLE_1)
ICALL(CONSOLE_1, "InternalKeyAvailable", ves_icall_System_ConsoleDriver_InternalKeyAvailable )
ICALL(CONSOLE_2, "Isatty", ves_icall_System_ConsoleDriver_Isatty )
ICALL(CONSOLE_3, "SetBreak", ves_icall_System_ConsoleDriver_SetBreak )
ICALL(CONSOLE_4, "SetEcho", ves_icall_System_ConsoleDriver_SetEcho )
ICALL(CONSOLE_5, "TtySetup", ves_icall_System_ConsoleDriver_TtySetup )

ICALL_TYPE(CONVERT, "System.Convert", CONVERT_1)
ICALL(CONVERT_1, "InternalFromBase64CharArray", InternalFromBase64CharArray )
ICALL(CONVERT_2, "InternalFromBase64String", InternalFromBase64String )

ICALL_TYPE(TZONE, "System.CurrentSystemTimeZone", TZONE_1)
ICALL(TZONE_1, "GetTimeZoneData", ves_icall_System_CurrentSystemTimeZone_GetTimeZoneData)

ICALL_TYPE(DTIME, "System.DateTime", DTIME_1)
ICALL(DTIME_1, "GetNow", mono_100ns_datetime)
ICALL(DTIME_2, "GetTimeMonotonic", mono_100ns_ticks)

#ifndef DISABLE_DECIMAL
ICALL_TYPE(DECIMAL, "System.Decimal", DECIMAL_1)
ICALL(DECIMAL_1, "decimal2Int64", mono_decimal2Int64)
ICALL(DECIMAL_2, "decimal2UInt64", mono_decimal2UInt64)
ICALL(DECIMAL_3, "decimal2double", mono_decimal2double)
ICALL(DECIMAL_4, "decimal2string", mono_decimal2string)
ICALL(DECIMAL_5, "decimalCompare", mono_decimalCompare)
ICALL(DECIMAL_6, "decimalDiv", mono_decimalDiv)
ICALL(DECIMAL_7, "decimalFloorAndTrunc", mono_decimalFloorAndTrunc)
ICALL(DECIMAL_8, "decimalIncr", mono_decimalIncr)
ICALL(DECIMAL_9, "decimalIntDiv", mono_decimalIntDiv)
ICALL(DECIMAL_10, "decimalMult", mono_decimalMult)
ICALL(DECIMAL_11, "decimalRound", mono_decimalRound)
ICALL(DECIMAL_12, "decimalSetExponent", mono_decimalSetExponent)
ICALL(DECIMAL_13, "double2decimal", mono_double2decimal) /* FIXME: wrong signature. */
ICALL(DECIMAL_14, "string2decimal", mono_string2decimal)
#endif

ICALL_TYPE(DELEGATE, "System.Delegate", DELEGATE_1)
ICALL(DELEGATE_1, "CreateDelegate_internal", ves_icall_System_Delegate_CreateDelegate_internal)
ICALL(DELEGATE_2, "SetMulticastInvoke", ves_icall_System_Delegate_SetMulticastInvoke)

ICALL_TYPE(DEBUGR, "System.Diagnostics.Debugger", DEBUGR_1)
ICALL(DEBUGR_1, "IsAttached_internal", ves_icall_System_Diagnostics_Debugger_IsAttached_internal)

ICALL_TYPE(TRACEL, "System.Diagnostics.DefaultTraceListener", TRACEL_1)
ICALL(TRACEL_1, "WriteWindowsDebugString", ves_icall_System_Diagnostics_DefaultTraceListener_WriteWindowsDebugString)

#ifndef DISABLE_PROCESS_HANDLING
ICALL_TYPE(FILEV, "System.Diagnostics.FileVersionInfo", FILEV_1)
ICALL(FILEV_1, "GetVersionInfo_internal(string)", ves_icall_System_Diagnostics_FileVersionInfo_GetVersionInfo_internal)

ICALL_TYPE(PERFCTR, "System.Diagnostics.PerformanceCounter", PERFCTR_1)
ICALL(PERFCTR_1, "FreeData", mono_perfcounter_free_data)
ICALL(PERFCTR_2, "GetImpl", mono_perfcounter_get_impl)
ICALL(PERFCTR_3, "GetSample", mono_perfcounter_get_sample)
ICALL(PERFCTR_4, "UpdateValue", mono_perfcounter_update_value)

ICALL_TYPE(PERFCTRCAT, "System.Diagnostics.PerformanceCounterCategory", PERFCTRCAT_1)
ICALL(PERFCTRCAT_1, "CategoryDelete", mono_perfcounter_category_del)
ICALL(PERFCTRCAT_2, "CategoryHelpInternal",   mono_perfcounter_category_help)
ICALL(PERFCTRCAT_3, "CounterCategoryExists", mono_perfcounter_category_exists)
ICALL(PERFCTRCAT_4, "Create",         mono_perfcounter_create)
ICALL(PERFCTRCAT_5, "GetCategoryNames", mono_perfcounter_category_names)
ICALL(PERFCTRCAT_6, "GetCounterNames", mono_perfcounter_counter_names)
ICALL(PERFCTRCAT_7, "GetInstanceNames", mono_perfcounter_instance_names)
ICALL(PERFCTRCAT_8, "InstanceExistsInternal", mono_perfcounter_instance_exists)

ICALL_TYPE(PROCESS, "System.Diagnostics.Process", PROCESS_1)
ICALL(PROCESS_1, "CreateProcess_internal(System.Diagnostics.ProcessStartInfo,intptr,intptr,intptr,System.Diagnostics.Process/ProcInfo&)", ves_icall_System_Diagnostics_Process_CreateProcess_internal)
ICALL(PROCESS_2, "ExitCode_internal(intptr)", ves_icall_System_Diagnostics_Process_ExitCode_internal)
ICALL(PROCESS_3, "ExitTime_internal(intptr)", ves_icall_System_Diagnostics_Process_ExitTime_internal)
ICALL(PROCESS_4, "GetModules_internal(intptr)", ves_icall_System_Diagnostics_Process_GetModules_internal)
ICALL(PROCESS_5, "GetPid_internal()", ves_icall_System_Diagnostics_Process_GetPid_internal)
ICALL(PROCESS_5B, "GetPriorityClass(intptr,int&)", ves_icall_System_Diagnostics_Process_GetPriorityClass)
ICALL(PROCESS_5H, "GetProcessData", ves_icall_System_Diagnostics_Process_GetProcessData)
ICALL(PROCESS_6, "GetProcess_internal(int)", ves_icall_System_Diagnostics_Process_GetProcess_internal)
ICALL(PROCESS_7, "GetProcesses_internal()", ves_icall_System_Diagnostics_Process_GetProcesses_internal)
ICALL(PROCESS_8, "GetWorkingSet_internal(intptr,int&,int&)", ves_icall_System_Diagnostics_Process_GetWorkingSet_internal)
ICALL(PROCESS_9, "Kill_internal", ves_icall_System_Diagnostics_Process_Kill_internal)
ICALL(PROCESS_10, "ProcessName_internal(intptr)", ves_icall_System_Diagnostics_Process_ProcessName_internal)
ICALL(PROCESS_11, "Process_free_internal(intptr)", ves_icall_System_Diagnostics_Process_Process_free_internal)
ICALL(PROCESS_11B, "SetPriorityClass(intptr,int,int&)", ves_icall_System_Diagnostics_Process_SetPriorityClass)
ICALL(PROCESS_12, "SetWorkingSet_internal(intptr,int,int,bool)", ves_icall_System_Diagnostics_Process_SetWorkingSet_internal)
ICALL(PROCESS_13, "ShellExecuteEx_internal(System.Diagnostics.ProcessStartInfo,System.Diagnostics.Process/ProcInfo&)", ves_icall_System_Diagnostics_Process_ShellExecuteEx_internal)
ICALL(PROCESS_14, "StartTime_internal(intptr)", ves_icall_System_Diagnostics_Process_StartTime_internal)
ICALL(PROCESS_14M, "Times", ves_icall_System_Diagnostics_Process_Times)
ICALL(PROCESS_15, "WaitForExit_internal(intptr,int)", ves_icall_System_Diagnostics_Process_WaitForExit_internal)
ICALL(PROCESS_16, "WaitForInputIdle_internal(intptr,int)", ves_icall_System_Diagnostics_Process_WaitForInputIdle_internal)

ICALL_TYPE (PROCESSHANDLE, "System.Diagnostics.Process/ProcessWaitHandle", PROCESSHANDLE_1)
ICALL (PROCESSHANDLE_1, "ProcessHandle_close(intptr)", ves_icall_System_Diagnostics_Process_ProcessHandle_close)
ICALL (PROCESSHANDLE_2, "ProcessHandle_duplicate(intptr)", ves_icall_System_Diagnostics_Process_ProcessHandle_duplicate)
#endif /* !DISABLE_PROCESS_HANDLING */

ICALL_TYPE(STOPWATCH, "System.Diagnostics.Stopwatch", STOPWATCH_1)
ICALL(STOPWATCH_1, "GetTimestamp", mono_100ns_ticks)

ICALL_TYPE(DOUBLE, "System.Double", DOUBLE_1)
ICALL(DOUBLE_1, "ParseImpl",    mono_double_ParseImpl)

ICALL_TYPE(ENUM, "System.Enum", ENUM_1)
ICALL(ENUM_1, "ToObject", ves_icall_System_Enum_ToObject)
ICALL(ENUM_5, "compare_value_to", ves_icall_System_Enum_compare_value_to)
ICALL(ENUM_4, "get_hashcode", ves_icall_System_Enum_get_hashcode)
ICALL(ENUM_3, "get_underlying_type", ves_icall_System_Enum_get_underlying_type)
ICALL(ENUM_2, "get_value", ves_icall_System_Enum_get_value)

ICALL_TYPE(ENV, "System.Environment", ENV_1)
ICALL(ENV_1, "Exit", ves_icall_System_Environment_Exit)
ICALL(ENV_2, "GetCommandLineArgs", mono_runtime_get_main_args)
ICALL(ENV_3, "GetEnvironmentVariableNames", ves_icall_System_Environment_GetEnvironmentVariableNames)
ICALL(ENV_4, "GetLogicalDrivesInternal", ves_icall_System_Environment_GetLogicalDrives )
ICALL(ENV_5, "GetMachineConfigPath", ves_icall_System_Configuration_DefaultConfig_get_machine_config_path)
ICALL(ENV_6, "GetOSVersionString", ves_icall_System_Environment_GetOSVersionString)
ICALL(ENV_6a, "GetPageSize", mono_pagesize)
ICALL(ENV_7, "GetWindowsFolderPath", ves_icall_System_Environment_GetWindowsFolderPath)
ICALL(ENV_8, "InternalSetEnvironmentVariable", ves_icall_System_Environment_InternalSetEnvironmentVariable)
ICALL(ENV_9, "get_ExitCode", mono_environment_exitcode_get)
ICALL(ENV_10, "get_HasShutdownStarted", ves_icall_System_Environment_get_HasShutdownStarted)
ICALL(ENV_11, "get_MachineName", ves_icall_System_Environment_get_MachineName)
ICALL(ENV_12, "get_NewLine", ves_icall_System_Environment_get_NewLine)
ICALL(ENV_13, "get_Platform", ves_icall_System_Environment_get_Platform)
ICALL(ENV_14, "get_ProcessorCount", mono_cpu_count)
ICALL(ENV_15, "get_TickCount", mono_msec_ticks)
ICALL(ENV_16, "get_UserName", ves_icall_System_Environment_get_UserName)
ICALL(ENV_16m, "internalBroadcastSettingChange", ves_icall_System_Environment_BroadcastSettingChange)
ICALL(ENV_17, "internalGetEnvironmentVariable", ves_icall_System_Environment_GetEnvironmentVariable)
ICALL(ENV_18, "internalGetGacPath", ves_icall_System_Environment_GetGacPath)
ICALL(ENV_19, "internalGetHome", ves_icall_System_Environment_InternalGetHome)
ICALL(ENV_20, "set_ExitCode", mono_environment_exitcode_set)

ICALL_TYPE(GC, "System.GC", GC_0)
ICALL(GC_0, "CollectionCount", mono_gc_collection_count)
ICALL(GC_0a, "GetGeneration", mono_gc_get_generation)
ICALL(GC_1, "GetTotalMemory", ves_icall_System_GC_GetTotalMemory)
ICALL(GC_2, "InternalCollect", ves_icall_System_GC_InternalCollect)
ICALL(GC_3, "KeepAlive", ves_icall_System_GC_KeepAlive)
ICALL(GC_4, "ReRegisterForFinalize", ves_icall_System_GC_ReRegisterForFinalize)
ICALL(GC_4a, "RecordPressure", mono_gc_add_memory_pressure)
ICALL(GC_5, "SuppressFinalize", ves_icall_System_GC_SuppressFinalize)
ICALL(GC_6, "WaitForPendingFinalizers", ves_icall_System_GC_WaitForPendingFinalizers)
ICALL(GC_7, "get_MaxGeneration", mono_gc_max_generation)
ICALL(GC_9, "get_ephemeron_tombstone", ves_icall_System_GC_get_ephemeron_tombstone)
ICALL(GC_8, "register_ephemeron_array", ves_icall_System_GC_register_ephemeron_array)

ICALL_TYPE(COMPINF, "System.Globalization.CompareInfo", COMPINF_1)
ICALL(COMPINF_1, "assign_sortkey(object,string,System.Globalization.CompareOptions)", ves_icall_System_Globalization_CompareInfo_assign_sortkey)
ICALL(COMPINF_2, "construct_compareinfo(string)", ves_icall_System_Globalization_CompareInfo_construct_compareinfo)
ICALL(COMPINF_3, "free_internal_collator()", ves_icall_System_Globalization_CompareInfo_free_internal_collator)
ICALL(COMPINF_4, "internal_compare(string,int,int,string,int,int,System.Globalization.CompareOptions)", ves_icall_System_Globalization_CompareInfo_internal_compare)
ICALL(COMPINF_5, "internal_index(string,int,int,char,System.Globalization.CompareOptions,bool)", ves_icall_System_Globalization_CompareInfo_internal_index_char)
ICALL(COMPINF_6, "internal_index(string,int,int,string,System.Globalization.CompareOptions,bool)", ves_icall_System_Globalization_CompareInfo_internal_index)

ICALL_TYPE(CULINF, "System.Globalization.CultureInfo", CULINF_2)
ICALL(CULINF_2, "construct_datetime_format", ves_icall_System_Globalization_CultureInfo_construct_datetime_format)
ICALL(CULINF_4, "construct_internal_locale_from_current_locale", ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_current_locale)
ICALL(CULINF_5, "construct_internal_locale_from_lcid", ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_lcid)
ICALL(CULINF_6, "construct_internal_locale_from_name", ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_name)
ICALL(CULINF_7, "construct_internal_locale_from_specific_name", ves_icall_System_Globalization_CultureInfo_construct_internal_locale_from_specific_name)
ICALL(CULINF_8, "construct_number_format", ves_icall_System_Globalization_CultureInfo_construct_number_format)
ICALL(CULINF_9, "internal_get_cultures", ves_icall_System_Globalization_CultureInfo_internal_get_cultures)
ICALL(CULINF_10, "internal_is_lcid_neutral", ves_icall_System_Globalization_CultureInfo_internal_is_lcid_neutral)

ICALL_TYPE(REGINF, "System.Globalization.RegionInfo", REGINF_1)
ICALL(REGINF_1, "construct_internal_region_from_lcid", ves_icall_System_Globalization_RegionInfo_construct_internal_region_from_lcid)
ICALL(REGINF_2, "construct_internal_region_from_name", ves_icall_System_Globalization_RegionInfo_construct_internal_region_from_name)

#ifndef PLATFORM_NO_DRIVEINFO
ICALL_TYPE(IODRIVEINFO, "System.IO.DriveInfo", IODRIVEINFO_1)
ICALL(IODRIVEINFO_1, "GetDiskFreeSpaceInternal", ves_icall_System_IO_DriveInfo_GetDiskFreeSpace)
ICALL(IODRIVEINFO_2, "GetDriveTypeInternal", ves_icall_System_IO_DriveInfo_GetDriveType)
#endif

ICALL_TYPE(FAMW, "System.IO.FAMWatcher", FAMW_1)
ICALL(FAMW_1, "InternalFAMNextEvent", ves_icall_System_IO_FAMW_InternalFAMNextEvent)

ICALL_TYPE(FILEW, "System.IO.FileSystemWatcher", FILEW_4)
ICALL(FILEW_4, "InternalSupportsFSW", ves_icall_System_IO_FSW_SupportsFSW)

ICALL_TYPE(INOW, "System.IO.InotifyWatcher", INOW_1)
ICALL(INOW_1, "AddWatch", ves_icall_System_IO_InotifyWatcher_AddWatch)
ICALL(INOW_2, "GetInotifyInstance", ves_icall_System_IO_InotifyWatcher_GetInotifyInstance)
ICALL(INOW_3, "RemoveWatch", ves_icall_System_IO_InotifyWatcher_RemoveWatch)

ICALL_TYPE(MONOIO, "System.IO.MonoIO", MONOIO_1)
ICALL(MONOIO_1, "Close(intptr,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Close)
#ifndef PLATFORM_RO_FS
ICALL(MONOIO_2, "CopyFile(string,string,bool,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_CopyFile)
ICALL(MONOIO_3, "CreateDirectory(string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_CreateDirectory)
ICALL(MONOIO_4, "CreatePipe(intptr&,intptr&)", ves_icall_System_IO_MonoIO_CreatePipe)
ICALL(MONOIO_5, "DeleteFile(string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_DeleteFile)
#endif /* !PLATFORM_RO_FS */
ICALL(MONOIO_34, "DuplicateHandle", ves_icall_System_IO_MonoIO_DuplicateHandle)
ICALL(MONOIO_37, "FindClose", ves_icall_System_IO_MonoIO_FindClose)
ICALL(MONOIO_35, "FindFirst", ves_icall_System_IO_MonoIO_FindFirst)
ICALL(MONOIO_36, "FindNext", ves_icall_System_IO_MonoIO_FindNext)
ICALL(MONOIO_6, "Flush(intptr,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Flush)
ICALL(MONOIO_7, "GetCurrentDirectory(System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_GetCurrentDirectory)
ICALL(MONOIO_8, "GetFileAttributes(string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_GetFileAttributes)
ICALL(MONOIO_9, "GetFileStat(string,System.IO.MonoIOStat&,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_GetFileStat)
ICALL(MONOIO_10, "GetFileSystemEntries", ves_icall_System_IO_MonoIO_GetFileSystemEntries)
ICALL(MONOIO_11, "GetFileType(intptr,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_GetFileType)
ICALL(MONOIO_12, "GetLength(intptr,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_GetLength)
#ifndef PLATFORM_RO_FS
ICALL(MONOIO_13, "GetTempPath(string&)", ves_icall_System_IO_MonoIO_GetTempPath)
ICALL(MONOIO_14, "Lock(intptr,long,long,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Lock)
ICALL(MONOIO_15, "MoveFile(string,string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_MoveFile)
#endif /* !PLATFORM_RO_FS */
ICALL(MONOIO_16, "Open(string,System.IO.FileMode,System.IO.FileAccess,System.IO.FileShare,System.IO.FileOptions,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Open)
ICALL(MONOIO_17, "Read(intptr,byte[],int,int,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Read)
#ifndef PLATFORM_RO_FS
ICALL(MONOIO_18, "RemoveDirectory(string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_RemoveDirectory)
ICALL(MONOIO_18M, "ReplaceFile(string,string,string,bool,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_ReplaceFile)
#endif /* !PLATFORM_RO_FS */
ICALL(MONOIO_19, "Seek(intptr,long,System.IO.SeekOrigin,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Seek)
ICALL(MONOIO_20, "SetCurrentDirectory(string,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_SetCurrentDirectory)
ICALL(MONOIO_21, "SetFileAttributes(string,System.IO.FileAttributes,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_SetFileAttributes)
ICALL(MONOIO_22, "SetFileTime(intptr,long,long,long,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_SetFileTime)
ICALL(MONOIO_23, "SetLength(intptr,long,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_SetLength)
#ifndef PLATFORM_RO_FS
ICALL(MONOIO_24, "Unlock(intptr,long,long,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Unlock)
#endif
ICALL(MONOIO_25, "Write(intptr,byte[],int,int,System.IO.MonoIOError&)", ves_icall_System_IO_MonoIO_Write)
ICALL(MONOIO_26, "get_AltDirectorySeparatorChar", ves_icall_System_IO_MonoIO_get_AltDirectorySeparatorChar)
ICALL(MONOIO_27, "get_ConsoleError", ves_icall_System_IO_MonoIO_get_ConsoleError)
ICALL(MONOIO_28, "get_ConsoleInput", ves_icall_System_IO_MonoIO_get_ConsoleInput)
ICALL(MONOIO_29, "get_ConsoleOutput", ves_icall_System_IO_MonoIO_get_ConsoleOutput)
ICALL(MONOIO_30, "get_DirectorySeparatorChar", ves_icall_System_IO_MonoIO_get_DirectorySeparatorChar)
ICALL(MONOIO_31, "get_InvalidPathChars", ves_icall_System_IO_MonoIO_get_InvalidPathChars)
ICALL(MONOIO_32, "get_PathSeparator", ves_icall_System_IO_MonoIO_get_PathSeparator)
ICALL(MONOIO_33, "get_VolumeSeparatorChar", ves_icall_System_IO_MonoIO_get_VolumeSeparatorChar)

ICALL_TYPE(IOPATH, "System.IO.Path", IOPATH_1)
ICALL(IOPATH_1, "get_temp_path", ves_icall_System_IO_get_temp_path)

ICALL_TYPE(MATH, "System.Math", MATH_1)
ICALL(MATH_1, "Acos", ves_icall_System_Math_Acos)
ICALL(MATH_2, "Asin", ves_icall_System_Math_Asin)
ICALL(MATH_3, "Atan", ves_icall_System_Math_Atan)
ICALL(MATH_4, "Atan2", ves_icall_System_Math_Atan2)
ICALL(MATH_5, "Cos", ves_icall_System_Math_Cos)
ICALL(MATH_6, "Cosh", ves_icall_System_Math_Cosh)
ICALL(MATH_7, "Exp", ves_icall_System_Math_Exp)
ICALL(MATH_8, "Floor", ves_icall_System_Math_Floor)
ICALL(MATH_9, "Log", ves_icall_System_Math_Log)
ICALL(MATH_10, "Log10", ves_icall_System_Math_Log10)
ICALL(MATH_11, "Pow", ves_icall_System_Math_Pow)
ICALL(MATH_12, "Round", ves_icall_System_Math_Round)
ICALL(MATH_13, "Round2", ves_icall_System_Math_Round2)
ICALL(MATH_14, "Sin", ves_icall_System_Math_Sin)
ICALL(MATH_15, "Sinh", ves_icall_System_Math_Sinh)
ICALL(MATH_16, "Sqrt", ves_icall_System_Math_Sqrt)
ICALL(MATH_17, "Tan", ves_icall_System_Math_Tan)
ICALL(MATH_18, "Tanh", ves_icall_System_Math_Tanh)

ICALL_TYPE(MCATTR, "System.MonoCustomAttrs", MCATTR_1)
ICALL(MCATTR_1, "GetCustomAttributesDataInternal", mono_reflection_get_custom_attrs_data)
ICALL(MCATTR_2, "GetCustomAttributesInternal", custom_attrs_get_by_type)
ICALL(MCATTR_3, "IsDefinedInternal", custom_attrs_defined_internal)

ICALL_TYPE(MENUM, "System.MonoEnumInfo", MENUM_1)
ICALL(MENUM_1, "get_enum_info", ves_icall_get_enum_info)

ICALL_TYPE(MTYPE, "System.MonoType", MTYPE_1)
ICALL(MTYPE_1, "GetArrayRank", ves_icall_MonoType_GetArrayRank)
ICALL(MTYPE_2, "GetConstructors", ves_icall_Type_GetConstructors_internal)
ICALL(MTYPE_3, "GetConstructors_internal", ves_icall_Type_GetConstructors_internal)
ICALL(MTYPE_4, "GetCorrespondingInflatedConstructor", ves_icall_MonoType_GetCorrespondingInflatedMethod)
ICALL(MTYPE_5, "GetCorrespondingInflatedMethod", ves_icall_MonoType_GetCorrespondingInflatedMethod)
ICALL(MTYPE_6, "GetElementType", ves_icall_MonoType_GetElementType)
ICALL(MTYPE_7, "GetEvents_internal", ves_icall_Type_GetEvents_internal)
ICALL(MTYPE_8, "GetField", ves_icall_Type_GetField)
ICALL(MTYPE_9, "GetFields_internal", ves_icall_Type_GetFields_internal)
ICALL(MTYPE_10, "GetGenericArguments", ves_icall_MonoType_GetGenericArguments)
ICALL(MTYPE_11, "GetInterfaces", ves_icall_Type_GetInterfaces)
ICALL(MTYPE_12, "GetMethodsByName", ves_icall_Type_GetMethodsByName)
ICALL(MTYPE_13, "GetNestedType", ves_icall_Type_GetNestedType)
ICALL(MTYPE_14, "GetNestedTypes", ves_icall_Type_GetNestedTypes)
ICALL(MTYPE_15, "GetPropertiesByName", ves_icall_Type_GetPropertiesByName)
ICALL(MTYPE_16, "InternalGetEvent", ves_icall_MonoType_GetEvent)
ICALL(MTYPE_17, "IsByRefImpl", ves_icall_type_isbyref)
ICALL(MTYPE_18, "IsCOMObjectImpl", ves_icall_type_iscomobject)
ICALL(MTYPE_19, "IsPointerImpl", ves_icall_type_ispointer)
ICALL(MTYPE_20, "IsPrimitiveImpl", ves_icall_type_isprimitive)
ICALL(MTYPE_21, "getFullName", ves_icall_System_MonoType_getFullName)
ICALL(MTYPE_22, "get_Assembly", ves_icall_MonoType_get_Assembly)
ICALL(MTYPE_23, "get_BaseType", ves_icall_get_type_parent)
ICALL(MTYPE_24, "get_DeclaringMethod", ves_icall_MonoType_get_DeclaringMethod)
ICALL(MTYPE_25, "get_DeclaringType", ves_icall_MonoType_get_DeclaringType)
ICALL(MTYPE_26, "get_IsGenericParameter", ves_icall_MonoType_get_IsGenericParameter)
ICALL(MTYPE_27, "get_Module", ves_icall_MonoType_get_Module)
ICALL(MTYPE_28, "get_Name", ves_icall_MonoType_get_Name)
ICALL(MTYPE_29, "get_Namespace", ves_icall_MonoType_get_Namespace)
ICALL(MTYPE_31, "get_attributes", ves_icall_get_attributes)
ICALL(MTYPE_33, "get_core_clr_security_level", vell_icall_MonoType_get_core_clr_security_level)
ICALL(MTYPE_32, "type_from_obj", mono_type_type_from_obj)

#ifndef DISABLE_SOCKETS
ICALL_TYPE(NDNS, "System.Net.Dns", NDNS_1)
ICALL(NDNS_1, "GetHostByAddr_internal(string,string&,string[]&,string[]&)", ves_icall_System_Net_Dns_GetHostByAddr_internal)
ICALL(NDNS_2, "GetHostByName_internal(string,string&,string[]&,string[]&)", ves_icall_System_Net_Dns_GetHostByName_internal)
ICALL(NDNS_3, "GetHostName_internal(string&)", ves_icall_System_Net_Dns_GetHostName_internal)

ICALL_TYPE(SOCK, "System.Net.Sockets.Socket", SOCK_1)
ICALL(SOCK_1, "Accept_internal(intptr,int&,bool)", ves_icall_System_Net_Sockets_Socket_Accept_internal)
ICALL(SOCK_2, "Available_internal(intptr,int&)", ves_icall_System_Net_Sockets_Socket_Available_internal)
ICALL(SOCK_3, "Bind_internal(intptr,System.Net.SocketAddress,int&)", ves_icall_System_Net_Sockets_Socket_Bind_internal)
ICALL(SOCK_4, "Blocking_internal(intptr,bool,int&)", ves_icall_System_Net_Sockets_Socket_Blocking_internal)
ICALL(SOCK_5, "Close_internal(intptr,int&)", ves_icall_System_Net_Sockets_Socket_Close_internal)
ICALL(SOCK_6, "Connect_internal(intptr,System.Net.SocketAddress,int&)", ves_icall_System_Net_Sockets_Socket_Connect_internal)
ICALL (SOCK_6a, "Disconnect_internal(intptr,bool,int&)", ves_icall_System_Net_Sockets_Socket_Disconnect_internal)
ICALL(SOCK_7, "GetSocketOption_arr_internal(intptr,System.Net.Sockets.SocketOptionLevel,System.Net.Sockets.SocketOptionName,byte[]&,int&)", ves_icall_System_Net_Sockets_Socket_GetSocketOption_arr_internal)
ICALL(SOCK_8, "GetSocketOption_obj_internal(intptr,System.Net.Sockets.SocketOptionLevel,System.Net.Sockets.SocketOptionName,object&,int&)", ves_icall_System_Net_Sockets_Socket_GetSocketOption_obj_internal)
ICALL(SOCK_9, "Listen_internal(intptr,int,int&)", ves_icall_System_Net_Sockets_Socket_Listen_internal)
ICALL(SOCK_10, "LocalEndPoint_internal(intptr,int,int&)", ves_icall_System_Net_Sockets_Socket_LocalEndPoint_internal)
ICALL(SOCK_11, "Poll_internal", ves_icall_System_Net_Sockets_Socket_Poll_internal)
ICALL(SOCK_11a, "Receive_internal(intptr,System.Net.Sockets.Socket/WSABUF[],System.Net.Sockets.SocketFlags,int&)", ves_icall_System_Net_Sockets_Socket_Receive_array_internal)
ICALL(SOCK_12, "Receive_internal(intptr,byte[],int,int,System.Net.Sockets.SocketFlags,int&)", ves_icall_System_Net_Sockets_Socket_Receive_internal)
ICALL(SOCK_13, "RecvFrom_internal(intptr,byte[],int,int,System.Net.Sockets.SocketFlags,System.Net.SocketAddress&,int&)", ves_icall_System_Net_Sockets_Socket_RecvFrom_internal)
ICALL(SOCK_14, "RemoteEndPoint_internal(intptr,int,int&)", ves_icall_System_Net_Sockets_Socket_RemoteEndPoint_internal)
ICALL(SOCK_15, "Select_internal(System.Net.Sockets.Socket[]&,int,int&)", ves_icall_System_Net_Sockets_Socket_Select_internal)
ICALL(SOCK_15a, "SendFile(intptr,string,byte[],byte[],System.Net.Sockets.TransmitFileOptions)", ves_icall_System_Net_Sockets_Socket_SendFile)
ICALL(SOCK_16, "SendTo_internal(intptr,byte[],int,int,System.Net.Sockets.SocketFlags,System.Net.SocketAddress,int&)", ves_icall_System_Net_Sockets_Socket_SendTo_internal)
ICALL(SOCK_16a, "Send_internal(intptr,System.Net.Sockets.Socket/WSABUF[],System.Net.Sockets.SocketFlags,int&)", ves_icall_System_Net_Sockets_Socket_Send_array_internal)
ICALL(SOCK_17, "Send_internal(intptr,byte[],int,int,System.Net.Sockets.SocketFlags,int&)", ves_icall_System_Net_Sockets_Socket_Send_internal)
ICALL(SOCK_18, "SetSocketOption_internal(intptr,System.Net.Sockets.SocketOptionLevel,System.Net.Sockets.SocketOptionName,object,byte[],int,int&)", ves_icall_System_Net_Sockets_Socket_SetSocketOption_internal)
ICALL(SOCK_19, "Shutdown_internal(intptr,System.Net.Sockets.SocketShutdown,int&)", ves_icall_System_Net_Sockets_Socket_Shutdown_internal)
ICALL(SOCK_20, "Socket_internal(System.Net.Sockets.AddressFamily,System.Net.Sockets.SocketType,System.Net.Sockets.ProtocolType,int&)", ves_icall_System_Net_Sockets_Socket_Socket_internal)
ICALL(SOCK_21, "WSAIoctl(intptr,int,byte[],byte[],int&)", ves_icall_System_Net_Sockets_Socket_WSAIoctl)
ICALL(SOCK_22, "socket_pool_queue", icall_append_io_job)

ICALL_TYPE(SOCKEX, "System.Net.Sockets.SocketException", SOCKEX_1)
ICALL(SOCKEX_1, "WSAGetLastError_internal", ves_icall_System_Net_Sockets_SocketException_WSAGetLastError_internal)
#endif /* !DISABLE_SOCKETS */

ICALL_TYPE(NUMBER_FORMATTER, "System.NumberFormatter", NUMBER_FORMATTER_1)
ICALL(NUMBER_FORMATTER_1, "GetFormatterTables", ves_icall_System_NumberFormatter_GetFormatterTables)

ICALL_TYPE(OBJ, "System.Object", OBJ_1)
ICALL(OBJ_1, "GetType", ves_icall_System_Object_GetType)
ICALL(OBJ_2, "InternalGetHashCode", mono_object_hash)
ICALL(OBJ_3, "MemberwiseClone", ves_icall_System_Object_MemberwiseClone)
ICALL(OBJ_4, "obj_address", ves_icall_System_Object_obj_address)

ICALL_TYPE(ASSEM, "System.Reflection.Assembly", ASSEM_1)
ICALL(ASSEM_1, "FillName", ves_icall_System_Reflection_Assembly_FillName)
ICALL(ASSEM_2, "GetCallingAssembly", ves_icall_System_Reflection_Assembly_GetCallingAssembly)
ICALL(ASSEM_3, "GetEntryAssembly", ves_icall_System_Reflection_Assembly_GetEntryAssembly)
ICALL(ASSEM_4, "GetExecutingAssembly", ves_icall_System_Reflection_Assembly_GetExecutingAssembly)
ICALL(ASSEM_5, "GetFilesInternal", ves_icall_System_Reflection_Assembly_GetFilesInternal)
ICALL(ASSEM_6, "GetManifestModuleInternal", ves_icall_System_Reflection_Assembly_GetManifestModuleInternal)
ICALL(ASSEM_7, "GetManifestResourceInfoInternal", ves_icall_System_Reflection_Assembly_GetManifestResourceInfoInternal)
ICALL(ASSEM_8, "GetManifestResourceInternal", ves_icall_System_Reflection_Assembly_GetManifestResourceInternal)
ICALL(ASSEM_9, "GetManifestResourceNames", ves_icall_System_Reflection_Assembly_GetManifestResourceNames)
ICALL(ASSEM_10, "GetModulesInternal", ves_icall_System_Reflection_Assembly_GetModulesInternal)
ICALL(ASSEM_11, "GetNamespaces", ves_icall_System_Reflection_Assembly_GetNamespaces)
ICALL(ASSEM_12, "GetReferencedAssemblies", ves_icall_System_Reflection_Assembly_GetReferencedAssemblies)
ICALL(ASSEM_13, "GetTypes", ves_icall_System_Reflection_Assembly_GetTypes)
ICALL(ASSEM_14, "InternalGetAssemblyName", ves_icall_System_Reflection_Assembly_InternalGetAssemblyName)
ICALL(ASSEM_15, "InternalGetType", ves_icall_System_Reflection_Assembly_InternalGetType)
ICALL(ASSEM_16, "InternalImageRuntimeVersion", ves_icall_System_Reflection_Assembly_InternalImageRuntimeVersion)
ICALL(ASSEM_17, "LoadFrom", ves_icall_System_Reflection_Assembly_LoadFrom)
ICALL(ASSEM_18, "LoadPermissions", ves_icall_System_Reflection_Assembly_LoadPermissions)
	/*
	 * Private icalls for the Mono Debugger
	 */
ICALL(ASSEM_19, "MonoDebugger_GetMethodToken", ves_icall_MonoDebugger_GetMethodToken)

	/* normal icalls again */
ICALL(ASSEM_20, "get_EntryPoint", ves_icall_System_Reflection_Assembly_get_EntryPoint)
ICALL(ASSEM_21, "get_ReflectionOnly", ves_icall_System_Reflection_Assembly_get_ReflectionOnly)
ICALL(ASSEM_22, "get_code_base", ves_icall_System_Reflection_Assembly_get_code_base)
ICALL(ASSEM_23, "get_fullname", ves_icall_System_Reflection_Assembly_get_fullName)
ICALL(ASSEM_24, "get_global_assembly_cache", ves_icall_System_Reflection_Assembly_get_global_assembly_cache)
ICALL(ASSEM_25, "get_location", ves_icall_System_Reflection_Assembly_get_location)
ICALL(ASSEM_26, "load_with_partial_name", ves_icall_System_Reflection_Assembly_load_with_partial_name)

ICALL_TYPE(ASSEMN, "System.Reflection.AssemblyName", ASSEMN_1)
ICALL(ASSEMN_1, "ParseName", ves_icall_System_Reflection_AssemblyName_ParseName)

ICALL_TYPE(CATTR_DATA, "System.Reflection.CustomAttributeData", CATTR_DATA_1)
ICALL(CATTR_DATA_1, "ResolveArgumentsInternal", mono_reflection_resolve_custom_attribute_data)

ICALL_TYPE(ASSEMB, "System.Reflection.Emit.AssemblyBuilder", ASSEMB_1)
ICALL(ASSEMB_1, "InternalAddModule", mono_image_load_module_dynamic)
ICALL(ASSEMB_2, "basic_init", mono_image_basic_init)

ICALL_TYPE(CATTRB, "System.Reflection.Emit.CustomAttributeBuilder", CATTRB_1)
ICALL(CATTRB_1, "GetBlob", mono_reflection_get_custom_attrs_blob)

#ifndef DISABLE_REFLECTION_EMIT
ICALL_TYPE(DERIVEDTYPE, "System.Reflection.Emit.DerivedType", DERIVEDTYPE_1)
ICALL(DERIVEDTYPE_1, "create_unmanaged_type", mono_reflection_create_unmanaged_type)
#endif

ICALL_TYPE(DYNM, "System.Reflection.Emit.DynamicMethod", DYNM_1)
ICALL(DYNM_1, "create_dynamic_method", mono_reflection_create_dynamic_method)

ICALL_TYPE(ENUMB, "System.Reflection.Emit.EnumBuilder", ENUMB_1)
ICALL(ENUMB_1, "setup_enum_type", ves_icall_EnumBuilder_setup_enum_type)

ICALL_TYPE(GPARB, "System.Reflection.Emit.GenericTypeParameterBuilder", GPARB_1)
ICALL(GPARB_1, "initialize", mono_reflection_initialize_generic_parameter)

ICALL_TYPE(METHODB, "System.Reflection.Emit.MethodBuilder", METHODB_1)
ICALL(METHODB_1, "MakeGenericMethod", mono_reflection_bind_generic_method_parameters)

ICALL_TYPE(MODULEB, "System.Reflection.Emit.ModuleBuilder", MODULEB_8)
ICALL(MODULEB_8, "RegisterToken", ves_icall_ModuleBuilder_RegisterToken)
ICALL(MODULEB_1, "WriteToFile", ves_icall_ModuleBuilder_WriteToFile)
ICALL(MODULEB_2, "basic_init", mono_image_module_basic_init)
ICALL(MODULEB_3, "build_metadata", ves_icall_ModuleBuilder_build_metadata)
ICALL(MODULEB_4, "create_modified_type", ves_icall_ModuleBuilder_create_modified_type)
ICALL(MODULEB_5, "getMethodToken", ves_icall_ModuleBuilder_getMethodToken)
ICALL(MODULEB_6, "getToken", ves_icall_ModuleBuilder_getToken)
ICALL(MODULEB_7, "getUSIndex", mono_image_insert_string)
ICALL(MODULEB_9, "set_wrappers_type", mono_image_set_wrappers_type)

ICALL_TYPE(SIGH, "System.Reflection.Emit.SignatureHelper", SIGH_1)
ICALL(SIGH_1, "get_signature_field", mono_reflection_sighelper_get_signature_field)
ICALL(SIGH_2, "get_signature_local", mono_reflection_sighelper_get_signature_local)

ICALL_TYPE(TYPEB, "System.Reflection.Emit.TypeBuilder", TYPEB_1)
ICALL(TYPEB_1, "create_generic_class", mono_reflection_create_generic_class)
ICALL(TYPEB_2, "create_internal_class", mono_reflection_create_internal_class)
ICALL(TYPEB_3, "create_runtime_class", mono_reflection_create_runtime_class)
ICALL(TYPEB_4, "get_IsGenericParameter", ves_icall_TypeBuilder_get_IsGenericParameter)
ICALL(TYPEB_5, "get_event_info", mono_reflection_event_builder_get_event_info)
ICALL(TYPEB_6, "setup_generic_class", mono_reflection_setup_generic_class)
ICALL(TYPEB_7, "setup_internal_class", mono_reflection_setup_internal_class)

ICALL_TYPE(FIELDI, "System.Reflection.FieldInfo", FILEDI_1)
ICALL(FILEDI_1, "GetTypeModifiers", ves_icall_System_Reflection_FieldInfo_GetTypeModifiers)
ICALL(FILEDI_2, "GetUnmanagedMarshal", ves_icall_System_Reflection_FieldInfo_GetUnmanagedMarshal)
ICALL(FILEDI_3, "internal_from_handle_type", ves_icall_System_Reflection_FieldInfo_internal_from_handle_type)

ICALL_TYPE(MEMBERI, "System.Reflection.MemberInfo", MEMBERI_1)
ICALL(MEMBERI_1, "get_MetadataToken", mono_reflection_get_token)

ICALL_TYPE(MBASE, "System.Reflection.MethodBase", MBASE_1)
ICALL(MBASE_1, "GetCurrentMethod", ves_icall_GetCurrentMethod)
ICALL(MBASE_2, "GetMethodBodyInternal", ves_icall_System_Reflection_MethodBase_GetMethodBodyInternal)
ICALL(MBASE_3, "GetMethodFromHandleInternal", ves_icall_System_Reflection_MethodBase_GetMethodFromHandleInternal)
ICALL(MBASE_4, "GetMethodFromHandleInternalType", ves_icall_System_Reflection_MethodBase_GetMethodFromHandleInternalType)

ICALL_TYPE(MODULE, "System.Reflection.Module", MODULE_1)
ICALL(MODULE_1, "Close", ves_icall_System_Reflection_Module_Close)
ICALL(MODULE_2, "GetGlobalType", ves_icall_System_Reflection_Module_GetGlobalType)
ICALL(MODULE_3, "GetGuidInternal", ves_icall_System_Reflection_Module_GetGuidInternal)
ICALL(MODULE_14, "GetHINSTANCE", ves_icall_System_Reflection_Module_GetHINSTANCE)
ICALL(MODULE_4, "GetMDStreamVersion", ves_icall_System_Reflection_Module_GetMDStreamVersion)
ICALL(MODULE_5, "GetPEKind", ves_icall_System_Reflection_Module_GetPEKind)
ICALL(MODULE_6, "InternalGetTypes", ves_icall_System_Reflection_Module_InternalGetTypes)
ICALL(MODULE_7, "ResolveFieldToken", ves_icall_System_Reflection_Module_ResolveFieldToken)
ICALL(MODULE_8, "ResolveMemberToken", ves_icall_System_Reflection_Module_ResolveMemberToken)
ICALL(MODULE_9, "ResolveMethodToken", ves_icall_System_Reflection_Module_ResolveMethodToken)
ICALL(MODULE_10, "ResolveSignature", ves_icall_System_Reflection_Module_ResolveSignature)
ICALL(MODULE_11, "ResolveStringToken", ves_icall_System_Reflection_Module_ResolveStringToken)
ICALL(MODULE_12, "ResolveTypeToken", ves_icall_System_Reflection_Module_ResolveTypeToken)
ICALL(MODULE_13, "get_MetadataToken", mono_reflection_get_token)

ICALL_TYPE(MCMETH, "System.Reflection.MonoCMethod", MCMETH_1)
ICALL(MCMETH_1, "GetGenericMethodDefinition_impl", ves_icall_MonoMethod_GetGenericMethodDefinition)
ICALL(MCMETH_2, "InternalInvoke", ves_icall_InternalInvoke)

ICALL_TYPE(MEVIN, "System.Reflection.MonoEventInfo", MEVIN_1)
ICALL(MEVIN_1, "get_event_info", ves_icall_get_event_info)

ICALL_TYPE(MFIELD, "System.Reflection.MonoField", MFIELD_1)
ICALL(MFIELD_1, "GetFieldOffset", ves_icall_MonoField_GetFieldOffset)
ICALL(MFIELD_2, "GetParentType", ves_icall_MonoField_GetParentType)
ICALL(MFIELD_5, "GetRawConstantValue", ves_icall_MonoField_GetRawConstantValue)
ICALL(MFIELD_3, "GetValueInternal", ves_icall_MonoField_GetValueInternal)
ICALL(MFIELD_6, "ResolveType", ves_icall_MonoField_ResolveType)
ICALL(MFIELD_4, "SetValueInternal", ves_icall_MonoField_SetValueInternal)

ICALL_TYPE(MGENCM, "System.Reflection.MonoGenericCMethod", MGENCM_1)
ICALL(MGENCM_1, "get_ReflectedType", ves_icall_MonoGenericMethod_get_ReflectedType)

ICALL_TYPE(MGENCL, "System.Reflection.MonoGenericClass", MGENCL_5)
ICALL(MGENCL_5, "initialize", mono_reflection_generic_class_initialize)
ICALL(MGENCL_6, "register_with_runtime", mono_reflection_register_with_runtime)

/* note this is the same as above: unify */
ICALL_TYPE(MGENM, "System.Reflection.MonoGenericMethod", MGENM_1)
ICALL(MGENM_1, "get_ReflectedType", ves_icall_MonoGenericMethod_get_ReflectedType)

ICALL_TYPE(MMETH, "System.Reflection.MonoMethod", MMETH_1)
ICALL(MMETH_1, "GetDllImportAttribute", ves_icall_MonoMethod_GetDllImportAttribute)
ICALL(MMETH_2, "GetGenericArguments", ves_icall_MonoMethod_GetGenericArguments)
ICALL(MMETH_3, "GetGenericMethodDefinition_impl", ves_icall_MonoMethod_GetGenericMethodDefinition)
ICALL(MMETH_4, "InternalInvoke", ves_icall_InternalInvoke)
ICALL(MMETH_5, "MakeGenericMethod_impl", mono_reflection_bind_generic_method_parameters)
ICALL(MMETH_6, "get_IsGenericMethod", ves_icall_MonoMethod_get_IsGenericMethod)
ICALL(MMETH_7, "get_IsGenericMethodDefinition", ves_icall_MonoMethod_get_IsGenericMethodDefinition)
ICALL(MMETH_8, "get_base_method", ves_icall_MonoMethod_get_base_method)
ICALL(MMETH_9, "get_name", ves_icall_MonoMethod_get_name)

ICALL_TYPE(MMETHI, "System.Reflection.MonoMethodInfo", MMETHI_4)
ICALL(MMETHI_4, "get_method_attributes", vell_icall_get_method_attributes)
ICALL(MMETHI_1, "get_method_info", ves_icall_get_method_info)
ICALL(MMETHI_2, "get_parameter_info", ves_icall_get_parameter_info)
ICALL(MMETHI_3, "get_retval_marshal", ves_icall_System_MonoMethodInfo_get_retval_marshal)

ICALL_TYPE(MPROPI, "System.Reflection.MonoPropertyInfo", MPROPI_1)
ICALL(MPROPI_1, "GetTypeModifiers", property_info_get_type_modifiers)
ICALL(MPROPI_3, "get_default_value", property_info_get_default_value)
ICALL(MPROPI_2, "get_property_info", ves_icall_get_property_info)

ICALL_TYPE(PARAMI, "System.Reflection.ParameterInfo", PARAMI_1)
ICALL(PARAMI_1, "GetMetadataToken", mono_reflection_get_token)
ICALL(PARAMI_2, "GetTypeModifiers", param_info_get_type_modifiers)

ICALL_TYPE(RUNH, "System.Runtime.CompilerServices.RuntimeHelpers", RUNH_1)
ICALL(RUNH_1, "GetObjectValue", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue)
	 /* REMOVEME: no longer needed, just so we dont break things when not needed */
ICALL(RUNH_2, "GetOffsetToStringData", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetOffsetToStringData)
ICALL(RUNH_3, "InitializeArray", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray)
ICALL(RUNH_4, "RunClassConstructor", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunClassConstructor)
ICALL(RUNH_5, "RunModuleConstructor", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunModuleConstructor)
ICALL(RUNH_5h, "SufficientExecutionStack", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack)
ICALL(RUNH_6, "get_OffsetToStringData", ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetOffsetToStringData)

ICALL_TYPE(GCH, "System.Runtime.InteropServices.GCHandle", GCH_1)
ICALL(GCH_1, "CheckCurrentDomain", GCHandle_CheckCurrentDomain)
ICALL(GCH_2, "FreeHandle", ves_icall_System_GCHandle_FreeHandle)
ICALL(GCH_3, "GetAddrOfPinnedObject", ves_icall_System_GCHandle_GetAddrOfPinnedObject)
ICALL(GCH_4, "GetTarget", ves_icall_System_GCHandle_GetTarget)
ICALL(GCH_5, "GetTargetHandle", ves_icall_System_GCHandle_GetTargetHandle)

#ifndef DISABLE_COM
ICALL_TYPE(MARSHAL, "System.Runtime.InteropServices.Marshal", MARSHAL_1)
ICALL(MARSHAL_1, "AddRefInternal", ves_icall_System_Runtime_InteropServices_Marshal_AddRefInternal)
#else
ICALL_TYPE(MARSHAL, "System.Runtime.InteropServices.Marshal", MARSHAL_2)
#endif
ICALL(MARSHAL_2, "AllocCoTaskMem", ves_icall_System_Runtime_InteropServices_Marshal_AllocCoTaskMem)
ICALL(MARSHAL_3, "AllocHGlobal", ves_icall_System_Runtime_InteropServices_Marshal_AllocHGlobal)
ICALL(MARSHAL_4, "DestroyStructure", ves_icall_System_Runtime_InteropServices_Marshal_DestroyStructure)
#ifndef DISABLE_COM
ICALL(MARSHAL_5, "FreeBSTR", ves_icall_System_Runtime_InteropServices_Marshal_FreeBSTR)
#endif
ICALL(MARSHAL_6, "FreeCoTaskMem", ves_icall_System_Runtime_InteropServices_Marshal_FreeCoTaskMem)
ICALL(MARSHAL_7, "FreeHGlobal", ves_icall_System_Runtime_InteropServices_Marshal_FreeHGlobal)
#ifndef DISABLE_COM
ICALL(MARSHAL_44, "GetCCW", ves_icall_System_Runtime_InteropServices_Marshal_GetCCW)
ICALL(MARSHAL_8, "GetComSlotForMethodInfoInternal", ves_icall_System_Runtime_InteropServices_Marshal_GetComSlotForMethodInfoInternal)
#endif
ICALL(MARSHAL_9, "GetDelegateForFunctionPointerInternal", ves_icall_System_Runtime_InteropServices_Marshal_GetDelegateForFunctionPointerInternal)
ICALL(MARSHAL_10, "GetFunctionPointerForDelegateInternal", mono_delegate_to_ftnptr)
#ifndef DISABLE_COM
ICALL(MARSHAL_45, "GetIDispatchForObjectInternal", ves_icall_System_Runtime_InteropServices_Marshal_GetIDispatchForObjectInternal)
ICALL(MARSHAL_46, "GetIUnknownForObjectInternal", ves_icall_System_Runtime_InteropServices_Marshal_GetIUnknownForObjectInternal)
#endif
ICALL(MARSHAL_11, "GetLastWin32Error", ves_icall_System_Runtime_InteropServices_Marshal_GetLastWin32Error)
#ifndef DISABLE_COM
ICALL(MARSHAL_47, "GetObjectForCCW", ves_icall_System_Runtime_InteropServices_Marshal_GetObjectForCCW)
ICALL(MARSHAL_48, "IsComObject", ves_icall_System_Runtime_InteropServices_Marshal_IsComObject)
#endif
ICALL(MARSHAL_12, "OffsetOf", ves_icall_System_Runtime_InteropServices_Marshal_OffsetOf)
ICALL(MARSHAL_13, "Prelink", ves_icall_System_Runtime_InteropServices_Marshal_Prelink)
ICALL(MARSHAL_14, "PrelinkAll", ves_icall_System_Runtime_InteropServices_Marshal_PrelinkAll)
ICALL(MARSHAL_15, "PtrToStringAnsi(intptr)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringAnsi)
ICALL(MARSHAL_16, "PtrToStringAnsi(intptr,int)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringAnsi_len)
#ifndef DISABLE_COM
ICALL(MARSHAL_17, "PtrToStringBSTR", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringBSTR)
#endif
ICALL(MARSHAL_18, "PtrToStringUni(intptr)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringUni)
ICALL(MARSHAL_19, "PtrToStringUni(intptr,int)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStringUni_len)
ICALL(MARSHAL_20, "PtrToStructure(intptr,System.Type)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStructure_type)
ICALL(MARSHAL_21, "PtrToStructure(intptr,object)", ves_icall_System_Runtime_InteropServices_Marshal_PtrToStructure)
#ifndef DISABLE_COM
ICALL(MARSHAL_22, "QueryInterfaceInternal", ves_icall_System_Runtime_InteropServices_Marshal_QueryInterfaceInternal)
#endif
ICALL(MARSHAL_43, "ReAllocCoTaskMem", ves_icall_System_Runtime_InteropServices_Marshal_ReAllocCoTaskMem)
ICALL(MARSHAL_23, "ReAllocHGlobal", ves_icall_System_Runtime_InteropServices_Marshal_ReAllocHGlobal)
ICALL(MARSHAL_24, "ReadByte", ves_icall_System_Runtime_InteropServices_Marshal_ReadByte)
ICALL(MARSHAL_25, "ReadInt16", ves_icall_System_Runtime_InteropServices_Marshal_ReadInt16)
ICALL(MARSHAL_26, "ReadInt32", ves_icall_System_Runtime_InteropServices_Marshal_ReadInt32)
ICALL(MARSHAL_27, "ReadInt64", ves_icall_System_Runtime_InteropServices_Marshal_ReadInt64)
ICALL(MARSHAL_28, "ReadIntPtr", ves_icall_System_Runtime_InteropServices_Marshal_ReadIntPtr)
#ifndef DISABLE_COM
ICALL(MARSHAL_49, "ReleaseComObjectInternal", ves_icall_System_Runtime_InteropServices_Marshal_ReleaseComObjectInternal)
ICALL(MARSHAL_29, "ReleaseInternal", ves_icall_System_Runtime_InteropServices_Marshal_ReleaseInternal)
#endif
ICALL(MARSHAL_30, "SizeOf", ves_icall_System_Runtime_InteropServices_Marshal_SizeOf)
#ifndef DISABLE_COM
ICALL(MARSHAL_31, "StringToBSTR", ves_icall_System_Runtime_InteropServices_Marshal_StringToBSTR)
#endif
ICALL(MARSHAL_32, "StringToHGlobalAnsi", ves_icall_System_Runtime_InteropServices_Marshal_StringToHGlobalAnsi)
ICALL(MARSHAL_33, "StringToHGlobalUni", ves_icall_System_Runtime_InteropServices_Marshal_StringToHGlobalUni)
ICALL(MARSHAL_34, "StructureToPtr", ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr)
ICALL(MARSHAL_35, "UnsafeAddrOfPinnedArrayElement", ves_icall_System_Runtime_InteropServices_Marshal_UnsafeAddrOfPinnedArrayElement)
ICALL(MARSHAL_36, "WriteByte", ves_icall_System_Runtime_InteropServices_Marshal_WriteByte)
ICALL(MARSHAL_37, "WriteInt16", ves_icall_System_Runtime_InteropServices_Marshal_WriteInt16)
ICALL(MARSHAL_38, "WriteInt32", ves_icall_System_Runtime_InteropServices_Marshal_WriteInt32)
ICALL(MARSHAL_39, "WriteInt64", ves_icall_System_Runtime_InteropServices_Marshal_WriteInt64)
ICALL(MARSHAL_40, "WriteIntPtr", ves_icall_System_Runtime_InteropServices_Marshal_WriteIntPtr)
ICALL(MARSHAL_41, "copy_from_unmanaged", ves_icall_System_Runtime_InteropServices_Marshal_copy_from_unmanaged)
ICALL(MARSHAL_42, "copy_to_unmanaged", ves_icall_System_Runtime_InteropServices_Marshal_copy_to_unmanaged)

ICALL_TYPE(ACTS, "System.Runtime.Remoting.Activation.ActivationServices", ACTS_1)
ICALL(ACTS_1, "AllocateUninitializedClassInstance", ves_icall_System_Runtime_Activation_ActivationServices_AllocateUninitializedClassInstance)
ICALL(ACTS_2, "EnableProxyActivation", ves_icall_System_Runtime_Activation_ActivationServices_EnableProxyActivation)

ICALL_TYPE(MONOMM, "System.Runtime.Remoting.Messaging.MonoMethodMessage", MONOMM_1)
ICALL(MONOMM_1, "InitMessage", ves_icall_MonoMethodMessage_InitMessage)

ICALL_TYPE(REALP, "System.Runtime.Remoting.Proxies.RealProxy", REALP_1)
ICALL(REALP_1, "InternalGetProxyType", ves_icall_Remoting_RealProxy_InternalGetProxyType)
ICALL(REALP_2, "InternalGetTransparentProxy", ves_icall_Remoting_RealProxy_GetTransparentProxy)

ICALL_TYPE(REMSER, "System.Runtime.Remoting.RemotingServices", REMSER_0)
ICALL(REMSER_0, "GetVirtualMethod", ves_icall_Remoting_RemotingServices_GetVirtualMethod)
ICALL(REMSER_1, "InternalExecute", ves_icall_InternalExecute)
ICALL(REMSER_2, "IsTransparentProxy", ves_icall_IsTransparentProxy)

ICALL_TYPE(MHAN, "System.RuntimeMethodHandle", MHAN_1)
ICALL(MHAN_1, "GetFunctionPointer", ves_icall_RuntimeMethod_GetFunctionPointer)

ICALL_TYPE(RNG, "System.Security.Cryptography.RNGCryptoServiceProvider", RNG_1)
ICALL(RNG_1, "RngClose", ves_icall_System_Security_Cryptography_RNGCryptoServiceProvider_RngClose)
ICALL(RNG_2, "RngGetBytes", ves_icall_System_Security_Cryptography_RNGCryptoServiceProvider_RngGetBytes)
ICALL(RNG_3, "RngInitialize", ves_icall_System_Security_Cryptography_RNGCryptoServiceProvider_RngInitialize)
ICALL(RNG_4, "RngOpen", ves_icall_System_Security_Cryptography_RNGCryptoServiceProvider_RngOpen)

#ifndef DISABLE_POLICY_EVIDENCE
ICALL_TYPE(EVID, "System.Security.Policy.Evidence", EVID_1)
ICALL(EVID_1, "IsAuthenticodePresent", ves_icall_System_Security_Policy_Evidence_IsAuthenticodePresent)

ICALL_TYPE(WINID, "System.Security.Principal.WindowsIdentity", WINID_1)
ICALL(WINID_1, "GetCurrentToken", ves_icall_System_Security_Principal_WindowsIdentity_GetCurrentToken)
ICALL(WINID_2, "GetTokenName", ves_icall_System_Security_Principal_WindowsIdentity_GetTokenName)
ICALL(WINID_3, "GetUserToken", ves_icall_System_Security_Principal_WindowsIdentity_GetUserToken)
ICALL(WINID_4, "_GetRoles", ves_icall_System_Security_Principal_WindowsIdentity_GetRoles)

ICALL_TYPE(WINIMP, "System.Security.Principal.WindowsImpersonationContext", WINIMP_1)
ICALL(WINIMP_1, "CloseToken", ves_icall_System_Security_Principal_WindowsImpersonationContext_CloseToken)
ICALL(WINIMP_2, "DuplicateToken", ves_icall_System_Security_Principal_WindowsImpersonationContext_DuplicateToken)
ICALL(WINIMP_3, "RevertToSelf", ves_icall_System_Security_Principal_WindowsImpersonationContext_RevertToSelf)
ICALL(WINIMP_4, "SetCurrentToken", ves_icall_System_Security_Principal_WindowsImpersonationContext_SetCurrentToken)

ICALL_TYPE(WINPRIN, "System.Security.Principal.WindowsPrincipal", WINPRIN_1)
ICALL(WINPRIN_1, "IsMemberOfGroupId", ves_icall_System_Security_Principal_WindowsPrincipal_IsMemberOfGroupId)
ICALL(WINPRIN_2, "IsMemberOfGroupName", ves_icall_System_Security_Principal_WindowsPrincipal_IsMemberOfGroupName)

ICALL_TYPE(SECSTRING, "System.Security.SecureString", SECSTRING_1)
ICALL(SECSTRING_1, "DecryptInternal", ves_icall_System_Security_SecureString_DecryptInternal)
ICALL(SECSTRING_2, "EncryptInternal", ves_icall_System_Security_SecureString_EncryptInternal)
#endif /* !DISABLE_POLICY_EVIDENCE */

ICALL_TYPE(SECMAN, "System.Security.SecurityManager", SECMAN_1)
ICALL(SECMAN_1, "GetLinkDemandSecurity", ves_icall_System_Security_SecurityManager_GetLinkDemandSecurity)
ICALL(SECMAN_2, "get_CheckExecutionRights", ves_icall_System_Security_SecurityManager_get_CheckExecutionRights)
ICALL(SECMAN_3, "get_RequiresElevatedPermissions", mono_security_core_clr_require_elevated_permissions)
ICALL(SECMAN_4, "get_SecurityEnabled", ves_icall_System_Security_SecurityManager_get_SecurityEnabled)
ICALL(SECMAN_5, "set_CheckExecutionRights", ves_icall_System_Security_SecurityManager_set_CheckExecutionRights)
ICALL(SECMAN_6, "set_SecurityEnabled", ves_icall_System_Security_SecurityManager_set_SecurityEnabled)

ICALL_TYPE(STRING, "System.String", STRING_1)
ICALL(STRING_1, ".ctor(char*)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_2, ".ctor(char*,int,int)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_3, ".ctor(char,int)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_4, ".ctor(char[])", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_5, ".ctor(char[],int,int)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_6, ".ctor(sbyte*)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_7, ".ctor(sbyte*,int,int)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_8, ".ctor(sbyte*,int,int,System.Text.Encoding)", ves_icall_System_String_ctor_RedirectToCreateString)
ICALL(STRING_8a, "GetLOSLimit", ves_icall_System_String_GetLOSLimit)
ICALL(STRING_9, "InternalAllocateStr", ves_icall_System_String_InternalAllocateStr)
ICALL(STRING_10, "InternalIntern", ves_icall_System_String_InternalIntern)
ICALL(STRING_11, "InternalIsInterned", ves_icall_System_String_InternalIsInterned)
ICALL(STRING_12, "InternalSplit", ves_icall_System_String_InternalSplit)

ICALL_TYPE(TENC, "System.Text.Encoding", TENC_1)
ICALL(TENC_1, "InternalCodePage", ves_icall_System_Text_Encoding_InternalCodePage)

ICALL_TYPE(ILOCK, "System.Threading.Interlocked", ILOCK_1)
ICALL(ILOCK_1, "Add(int&,int)", ves_icall_System_Threading_Interlocked_Add_Int)
ICALL(ILOCK_2, "Add(long&,long)", ves_icall_System_Threading_Interlocked_Add_Long)
ICALL(ILOCK_3, "CompareExchange(T&,T,T)", ves_icall_System_Threading_Interlocked_CompareExchange_T)
ICALL(ILOCK_4, "CompareExchange(double&,double,double)", ves_icall_System_Threading_Interlocked_CompareExchange_Double)
ICALL(ILOCK_5, "CompareExchange(int&,int,int)", ves_icall_System_Threading_Interlocked_CompareExchange_Int)
ICALL(ILOCK_6, "CompareExchange(intptr&,intptr,intptr)", ves_icall_System_Threading_Interlocked_CompareExchange_IntPtr)
ICALL(ILOCK_7, "CompareExchange(long&,long,long)", ves_icall_System_Threading_Interlocked_CompareExchange_Long)
ICALL(ILOCK_8, "CompareExchange(object&,object,object)", ves_icall_System_Threading_Interlocked_CompareExchange_Object)
ICALL(ILOCK_9, "CompareExchange(single&,single,single)", ves_icall_System_Threading_Interlocked_CompareExchange_Single)
ICALL(ILOCK_10, "Decrement(int&)", ves_icall_System_Threading_Interlocked_Decrement_Int)
ICALL(ILOCK_11, "Decrement(long&)", ves_icall_System_Threading_Interlocked_Decrement_Long)
ICALL(ILOCK_12, "Exchange(T&,T)", ves_icall_System_Threading_Interlocked_Exchange_T)
ICALL(ILOCK_13, "Exchange(double&,double)", ves_icall_System_Threading_Interlocked_Exchange_Double)
ICALL(ILOCK_14, "Exchange(int&,int)", ves_icall_System_Threading_Interlocked_Exchange_Int)
ICALL(ILOCK_15, "Exchange(intptr&,intptr)", ves_icall_System_Threading_Interlocked_Exchange_IntPtr)
ICALL(ILOCK_16, "Exchange(long&,long)", ves_icall_System_Threading_Interlocked_Exchange_Long)
ICALL(ILOCK_17, "Exchange(object&,object)", ves_icall_System_Threading_Interlocked_Exchange_Object)
ICALL(ILOCK_18, "Exchange(single&,single)", ves_icall_System_Threading_Interlocked_Exchange_Single)
ICALL(ILOCK_19, "Increment(int&)", ves_icall_System_Threading_Interlocked_Increment_Int)
ICALL(ILOCK_20, "Increment(long&)", ves_icall_System_Threading_Interlocked_Increment_Long)
ICALL(ILOCK_21, "Read(long&)", ves_icall_System_Threading_Interlocked_Read_Long)

ICALL_TYPE(ITHREAD, "System.Threading.InternalThread", ITHREAD_1)
ICALL(ITHREAD_1, "Thread_free_internal", ves_icall_System_Threading_InternalThread_Thread_free_internal)

ICALL_TYPE(MONIT, "System.Threading.Monitor", MONIT_8)
ICALL(MONIT_8, "Enter", mono_monitor_enter)
ICALL(MONIT_1, "Exit", mono_monitor_exit)
ICALL(MONIT_2, "Monitor_pulse", ves_icall_System_Threading_Monitor_Monitor_pulse)
ICALL(MONIT_3, "Monitor_pulse_all", ves_icall_System_Threading_Monitor_Monitor_pulse_all)
ICALL(MONIT_4, "Monitor_test_owner", ves_icall_System_Threading_Monitor_Monitor_test_owner)
ICALL(MONIT_5, "Monitor_test_synchronised", ves_icall_System_Threading_Monitor_Monitor_test_synchronised)
ICALL(MONIT_6, "Monitor_try_enter", ves_icall_System_Threading_Monitor_Monitor_try_enter)
ICALL(MONIT_7, "Monitor_wait", ves_icall_System_Threading_Monitor_Monitor_wait)
ICALL(MONIT_9, "try_enter_with_atomic_var", ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var)

ICALL_TYPE(MUTEX, "System.Threading.Mutex", MUTEX_1)
ICALL(MUTEX_1, "CreateMutex_internal(bool,string,bool&)", ves_icall_System_Threading_Mutex_CreateMutex_internal)
ICALL(MUTEX_2, "OpenMutex_internal(string,System.Security.AccessControl.MutexRights,System.IO.MonoIOError&)", ves_icall_System_Threading_Mutex_OpenMutex_internal)
ICALL(MUTEX_3, "ReleaseMutex_internal(intptr)", ves_icall_System_Threading_Mutex_ReleaseMutex_internal)

ICALL_TYPE(NATIVEC, "System.Threading.NativeEventCalls", NATIVEC_1)
ICALL(NATIVEC_1, "CloseEvent_internal", ves_icall_System_Threading_Events_CloseEvent_internal)
ICALL(NATIVEC_2, "CreateEvent_internal(bool,bool,string,bool&)", ves_icall_System_Threading_Events_CreateEvent_internal)
ICALL(NATIVEC_3, "OpenEvent_internal(string,System.Security.AccessControl.EventWaitHandleRights,System.IO.MonoIOError&)", ves_icall_System_Threading_Events_OpenEvent_internal)
ICALL(NATIVEC_4, "ResetEvent_internal",  ves_icall_System_Threading_Events_ResetEvent_internal)
ICALL(NATIVEC_5, "SetEvent_internal",    ves_icall_System_Threading_Events_SetEvent_internal)

ICALL_TYPE(SEMA, "System.Threading.Semaphore", SEMA_1)
ICALL(SEMA_1, "CreateSemaphore_internal(int,int,string,bool&)", ves_icall_System_Threading_Semaphore_CreateSemaphore_internal)
ICALL(SEMA_2, "OpenSemaphore_internal(string,System.Security.AccessControl.SemaphoreRights,System.IO.MonoIOError&)", ves_icall_System_Threading_Semaphore_OpenSemaphore_internal)
ICALL(SEMA_3, "ReleaseSemaphore_internal(intptr,int,bool&)", ves_icall_System_Threading_Semaphore_ReleaseSemaphore_internal)

ICALL_TYPE(THREAD, "System.Threading.Thread", THREAD_1)
ICALL(THREAD_1, "Abort_internal(System.Threading.InternalThread,object)", ves_icall_System_Threading_Thread_Abort)
ICALL(THREAD_1aa, "AllocTlsData", mono_thread_alloc_tls)
ICALL(THREAD_1a, "ByteArrayToCurrentDomain(byte[])", ves_icall_System_Threading_Thread_ByteArrayToCurrentDomain)
ICALL(THREAD_1b, "ByteArrayToRootDomain(byte[])", ves_icall_System_Threading_Thread_ByteArrayToRootDomain)
ICALL(THREAD_2, "ClrState(System.Threading.InternalThread,System.Threading.ThreadState)", ves_icall_System_Threading_Thread_ClrState)
ICALL(THREAD_2a, "ConstructInternalThread", ves_icall_System_Threading_Thread_ConstructInternalThread)
ICALL(THREAD_3, "CurrentInternalThread_internal", mono_thread_internal_current)
ICALL(THREAD_3a, "DestroyTlsData", mono_thread_destroy_tls)
ICALL(THREAD_4, "FreeLocalSlotValues", mono_thread_free_local_slot_values)
ICALL(THREAD_55, "GetAbortExceptionState", ves_icall_System_Threading_Thread_GetAbortExceptionState)
ICALL(THREAD_7, "GetDomainID", ves_icall_System_Threading_Thread_GetDomainID)
ICALL(THREAD_8, "GetName_internal(System.Threading.InternalThread)", ves_icall_System_Threading_Thread_GetName_internal)
ICALL(THREAD_11, "GetState(System.Threading.InternalThread)", ves_icall_System_Threading_Thread_GetState)
ICALL(THREAD_53, "Interrupt_internal(System.Threading.InternalThread)", ves_icall_System_Threading_Thread_Interrupt_internal)
ICALL(THREAD_12, "Join_internal(System.Threading.InternalThread,int,intptr)", ves_icall_System_Threading_Thread_Join_internal)
ICALL(THREAD_13, "MemoryBarrier", ves_icall_System_Threading_Thread_MemoryBarrier)
ICALL(THREAD_14, "ResetAbort_internal()", ves_icall_System_Threading_Thread_ResetAbort)
ICALL(THREAD_15, "Resume_internal()", ves_icall_System_Threading_Thread_Resume)
ICALL(THREAD_18, "SetName_internal(System.Threading.InternalThread,string)", ves_icall_System_Threading_Thread_SetName_internal)
ICALL(THREAD_21, "SetState(System.Threading.InternalThread,System.Threading.ThreadState)", ves_icall_System_Threading_Thread_SetState)
ICALL(THREAD_22, "Sleep_internal", ves_icall_System_Threading_Thread_Sleep_internal)
ICALL(THREAD_54, "SpinWait_nop", ves_icall_System_Threading_Thread_SpinWait_nop)
ICALL(THREAD_23, "Suspend_internal(System.Threading.InternalThread)", ves_icall_System_Threading_Thread_Suspend)
ICALL(THREAD_25, "Thread_internal", ves_icall_System_Threading_Thread_Thread_internal)
ICALL(THREAD_26, "VolatileRead(byte&)", ves_icall_System_Threading_Thread_VolatileRead1)
ICALL(THREAD_27, "VolatileRead(double&)", ves_icall_System_Threading_Thread_VolatileRead8)
ICALL(THREAD_28, "VolatileRead(int&)", ves_icall_System_Threading_Thread_VolatileRead4)
ICALL(THREAD_29, "VolatileRead(int16&)", ves_icall_System_Threading_Thread_VolatileRead2)
ICALL(THREAD_30, "VolatileRead(intptr&)", ves_icall_System_Threading_Thread_VolatileReadIntPtr)
ICALL(THREAD_31, "VolatileRead(long&)", ves_icall_System_Threading_Thread_VolatileRead8)
ICALL(THREAD_32, "VolatileRead(object&)", ves_icall_System_Threading_Thread_VolatileReadIntPtr)
ICALL(THREAD_33, "VolatileRead(sbyte&)", ves_icall_System_Threading_Thread_VolatileRead1)
ICALL(THREAD_34, "VolatileRead(single&)", ves_icall_System_Threading_Thread_VolatileRead4)
ICALL(THREAD_35, "VolatileRead(uint&)", ves_icall_System_Threading_Thread_VolatileRead2)
ICALL(THREAD_36, "VolatileRead(uint16&)", ves_icall_System_Threading_Thread_VolatileRead2)
ICALL(THREAD_37, "VolatileRead(uintptr&)", ves_icall_System_Threading_Thread_VolatileReadIntPtr)
ICALL(THREAD_38, "VolatileRead(ulong&)", ves_icall_System_Threading_Thread_VolatileRead8)
ICALL(THREAD_39, "VolatileWrite(byte&,byte)", ves_icall_System_Threading_Thread_VolatileWrite1)
ICALL(THREAD_40, "VolatileWrite(double&,double)", ves_icall_System_Threading_Thread_VolatileWrite8)
ICALL(THREAD_41, "VolatileWrite(int&,int)", ves_icall_System_Threading_Thread_VolatileWrite4)
ICALL(THREAD_42, "VolatileWrite(int16&,int16)", ves_icall_System_Threading_Thread_VolatileWrite2)
ICALL(THREAD_43, "VolatileWrite(intptr&,intptr)", ves_icall_System_Threading_Thread_VolatileWriteIntPtr)
ICALL(THREAD_44, "VolatileWrite(long&,long)", ves_icall_System_Threading_Thread_VolatileWrite8)
ICALL(THREAD_45, "VolatileWrite(object&,object)", ves_icall_System_Threading_Thread_VolatileWriteObject)
ICALL(THREAD_46, "VolatileWrite(sbyte&,sbyte)", ves_icall_System_Threading_Thread_VolatileWrite1)
ICALL(THREAD_47, "VolatileWrite(single&,single)", ves_icall_System_Threading_Thread_VolatileWrite4)
ICALL(THREAD_48, "VolatileWrite(uint&,uint)", ves_icall_System_Threading_Thread_VolatileWrite2)
ICALL(THREAD_49, "VolatileWrite(uint16&,uint16)", ves_icall_System_Threading_Thread_VolatileWrite2)
ICALL(THREAD_50, "VolatileWrite(uintptr&,uintptr)", ves_icall_System_Threading_Thread_VolatileWriteIntPtr)
ICALL(THREAD_51, "VolatileWrite(ulong&,ulong)", ves_icall_System_Threading_Thread_VolatileWrite8)
ICALL(THREAD_9, "Yield", ves_icall_System_Threading_Thread_Yield)
ICALL(THREAD_52, "current_lcid()", ves_icall_System_Threading_Thread_current_lcid)

ICALL_TYPE(THREADP, "System.Threading.ThreadPool", THREADP_1)
ICALL(THREADP_1, "GetAvailableThreads", ves_icall_System_Threading_ThreadPool_GetAvailableThreads)
ICALL(THREADP_2, "GetMaxThreads", ves_icall_System_Threading_ThreadPool_GetMaxThreads)
ICALL(THREADP_3, "GetMinThreads", ves_icall_System_Threading_ThreadPool_GetMinThreads)
ICALL(THREADP_35, "SetMaxThreads", ves_icall_System_Threading_ThreadPool_SetMaxThreads)
ICALL(THREADP_4, "SetMinThreads", ves_icall_System_Threading_ThreadPool_SetMinThreads)
ICALL(THREADP_5, "pool_queue", icall_append_job)

ICALL_TYPE(WAITH, "System.Threading.WaitHandle", WAITH_1)
ICALL(WAITH_1, "SignalAndWait_Internal", ves_icall_System_Threading_WaitHandle_SignalAndWait_Internal)
ICALL(WAITH_2, "WaitAll_internal", ves_icall_System_Threading_WaitHandle_WaitAll_internal)
ICALL(WAITH_3, "WaitAny_internal", ves_icall_System_Threading_WaitHandle_WaitAny_internal)
ICALL(WAITH_4, "WaitOne_internal", ves_icall_System_Threading_WaitHandle_WaitOne_internal)

ICALL_TYPE(TYPE, "System.Type", TYPE_1)
ICALL(TYPE_1, "EqualsInternal", ves_icall_System_Type_EqualsInternal)
ICALL(TYPE_2, "GetGenericParameterAttributes", ves_icall_Type_GetGenericParameterAttributes)
ICALL(TYPE_3, "GetGenericParameterConstraints_impl", ves_icall_Type_GetGenericParameterConstraints)
ICALL(TYPE_4, "GetGenericParameterPosition", ves_icall_Type_GetGenericParameterPosition)
ICALL(TYPE_5, "GetGenericTypeDefinition_impl", ves_icall_Type_GetGenericTypeDefinition_impl)
ICALL(TYPE_6, "GetInterfaceMapData", ves_icall_Type_GetInterfaceMapData)
ICALL(TYPE_7, "GetPacking", ves_icall_Type_GetPacking)
ICALL(TYPE_8, "GetTypeCode", ves_icall_type_GetTypeCodeInternal)
ICALL(TYPE_9, "GetTypeCodeInternal", ves_icall_type_GetTypeCodeInternal)
ICALL(TYPE_10, "IsArrayImpl", ves_icall_Type_IsArrayImpl)
ICALL(TYPE_11, "IsInstanceOfType", ves_icall_type_IsInstanceOfType)
ICALL(TYPE_12, "MakeGenericType", ves_icall_Type_MakeGenericType)
ICALL(TYPE_13, "MakePointerType", ves_icall_Type_MakePointerType)
ICALL(TYPE_14, "get_IsGenericInstance", ves_icall_Type_get_IsGenericInstance)
ICALL(TYPE_15, "get_IsGenericType", ves_icall_Type_get_IsGenericType)
ICALL(TYPE_16, "get_IsGenericTypeDefinition", ves_icall_Type_get_IsGenericTypeDefinition)
ICALL(TYPE_17, "internal_from_handle", ves_icall_type_from_handle)
ICALL(TYPE_18, "internal_from_name", ves_icall_type_from_name)
ICALL(TYPE_19, "make_array_type", ves_icall_Type_make_array_type)
ICALL(TYPE_20, "make_byref_type", ves_icall_Type_make_byref_type)
ICALL(TYPE_21, "type_is_assignable_from", ves_icall_type_is_assignable_from)
ICALL(TYPE_22, "type_is_subtype_of", ves_icall_type_is_subtype_of)

ICALL_TYPE(TYPEDR, "System.TypedReference", TYPEDR_1)
ICALL(TYPEDR_1, "ToObject",	mono_TypedReference_ToObject)
ICALL(TYPEDR_2, "ToObjectInternal",	mono_TypedReference_ToObjectInternal)

ICALL_TYPE(VALUET, "System.ValueType", VALUET_1)
ICALL(VALUET_1, "InternalEquals", ves_icall_System_ValueType_Equals)
ICALL(VALUET_2, "InternalGetHashCode", ves_icall_System_ValueType_InternalGetHashCode)

ICALL_TYPE(WEBIC, "System.Web.Util.ICalls", WEBIC_1)
ICALL(WEBIC_1, "GetMachineConfigPath", ves_icall_System_Configuration_DefaultConfig_get_machine_config_path)
ICALL(WEBIC_2, "GetMachineInstallDirectory", ves_icall_System_Web_Util_ICalls_get_machine_install_dir)
ICALL(WEBIC_3, "GetUnmanagedResourcesPtr", ves_icall_get_resources_ptr)

#ifndef DISABLE_COM
ICALL_TYPE(COMOBJ, "System.__ComObject", COMOBJ_1)
ICALL(COMOBJ_1, "CreateRCW", ves_icall_System_ComObject_CreateRCW)
ICALL(COMOBJ_2, "GetInterfaceInternal", ves_icall_System_ComObject_GetInterfaceInternal)
ICALL(COMOBJ_3, "ReleaseInterfaces", ves_icall_System_ComObject_ReleaseInterfaces)
#endif
