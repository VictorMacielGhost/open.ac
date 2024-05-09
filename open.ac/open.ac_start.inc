/*
 * @Date: 2022/07/12
 * open.ac all rights reserved (2022 - 2024)
 */


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

public openac_OnScriptInit()
{
    // print include stuff
    new date[6];
    getdate(date[0], date[1], date[2]);
    gettime(date[3], date[4], date[5]);
    printf("[open.ac]: [Info]: Ant Cheat Started on %d/%02d/%2d at %02d/%02d/%02d", date[0], date[1], date[2], date[3], date[4], date[5]);
    printf("[open.ac]: [Info]: open.ac (2022 - 2024) All Rights Reserved.");

    #if defined Console_Warning_Filterscript
        print("[open.ac]: [Warning]: Ant Cheat System Started as FILTERSCRIPT.");
    #endif
    #if defined Console_Show_AC_Stats
        printf("[open.ac]: [Server Stats]: Server Started at address: %s", address);
        printf("[open.ac]: [Server Stats]: open.ac Started Successfully!");
    #endif
    return 1;
}
