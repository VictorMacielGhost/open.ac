/*
    DEBUG FILE - This is not finished and not ready to use!
    Internal include file - Plugin Management
    @Date 09/05/2024
    @Author @VictorMacielGhost
*/

#define     AOC_PLUGIN_PAWNRAKNET    0x1
#define     AOC_PLUGIN_PAWNCMD       0x2
#define     AOC_PLUGIN_COLANDREAS    0x3
#define     AOC_PLUGIN_MAPANDREAS    0x4
#define     AOC_PLUGIN_SSCANF        0x5
#define     AOC_PLUGIN_STREAMER      0x6
#define     AOC_PLUGIN_CRASHDETECT   0x7

enum aoc_Allowed_Plugins
{
    bool:pawnraknet,
    bool:pawncmd,
    bool:colandreas,
    bool:mapandreas,
    bool:sscanf,
    bool:streamer,
    bool:crashdetect
};

static aoc_AllowedPluginsUsage[aoc_Allowed_Plugins];

stock AOC_AllowPluginUsage(const pluginname[])
{
    printf("[open.ac] Info: Setting up additional plugin %s...", pluginame);
    switch(pluginname)
    {
        case "Pawn.Raknet", "Raknet", "PawnRaknet", "Pawn Raknet", "PR":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawnraknet] = true;
        }

        case "Pawn.CMD", "PawnCMD", "Pawn CMD", "PC":
        {
            #if !defined PAWNCMD_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true;
        }

        case "colandreas":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true;
        }

        case "mapandreas":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true;
        }

        case "sscanf":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true;
        }

        case "streamer":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true;
        }

        case "crashdetect":
        {
            #if !defined PAWNRAKNET_INC_
                printf("[open.ac] Error: Plugin include was not loaded before open.ac. Please Recompile your script with the propper plugin include file.\nPlugin Name: %s\a", pluginame);
                return 0;
            #endif

            aoc_AllowedPluginsUsage[pawncmd] = true; 
        }

        default:
        {
            printf("[open.ac] Info: The plugin %s was not recognized by the anti cheat system. Please, Check in the manuals if we do support it.", pluginname);
            return 0;
        }
    }
    
    printf("[open.ac] Info: The plugin %s include file has been found. open.ac now has permission to manipulate plugin's functions.", pluginame);

    return 1;
}
