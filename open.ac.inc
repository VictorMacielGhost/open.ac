/*
    @Version: 0.1
    @Date: 2022-17-09
    @Updated: 2022/25/09
    @Authors: Alan! / RhaegarX / Victor Ghost
    @github: https://github.com/lucasgama335/openac
*/

#if defined _openac_included
    #endinput
#else 
    #define _openac_included
    #define _openac_version "0.2"
#endif

#if !defined _samp_included
    #tryinclude <a_samp>
    #if !defined _samp_included
        #error Couldn't Locate a_samp Include! Please Insert a_samp before open.ac to load properly.
    #endif
#endif

