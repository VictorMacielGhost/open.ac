/*
    @Version: 0.3
    @Date: 2022-17-09
    @Updated: 2022/14/12
    @Authors: Alan! / RhaegarX / Victor Ghost
    @github: https://github.com/VictorMacielGhost/open.ac
*/

#if defined _open_ac_included
    #warning open.ac Already included! (included twice)
    #endinput
#else 
    #define _open_ac_included
    #define _open_ac_version "0.3"
#endif

#if defined FILTERSCRIPT
    Console_Warning_Filterscript();
#endif

#if !defined _INC_open_mp
    #tryinclude <open.mp>
    #if !defined _INC_open_mp
        #error Couldn't Locate open.mp Include! Please Insert open.mp before open.ac to load properly.
    #endif
#endif

#include "open.ac\open.ac_start.inc"