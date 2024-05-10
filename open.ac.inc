/*
    Include file that includes all the other includes, Global Constants and Config files.
    @Date 09/05/2024
    @Author @VictorMacielGhost
*/

#if defined __open_ac_included
    #endinput
#else 
    #define __open_ac_included
#endif

#define     OAC_MAJOR_VERSION   0x1
#define     OAC_MINOR_VERSION   __date
#define     OAC_PATCH_VERSION   __time

#define     OAC_COPYRIGHT       "© 2022 ~ 2024 open.ac?"

#define     OAC_DEBUG_MODE

// Includes OAC dependencies and parses ini files when server's starts

// Under development, ignore the following lines

#if defined ALS_OnScriptInit
    #define openac_OnScriptInit ALS_OnScriptInit
#elseif defined FILTERSCRIPT
    #define openac_OnScriptInit OnFilterScriptInit
#else 
    #define openac_OnScriptInit OnGamemodeInit
#endif

#if defined openac_OnScriptInit
    forward openac_OnScriptInit();
#endif