/**
 * This file serves as the entry point for the project and contains the main function.
 *
 * @author DeviceBlack
 * @date 11/May/2024
 * @time 05:30
 */

// Including external libraries not related to the project.
#include <open.mp>

/**
 * @brief Entry function triggered when the server loads completely.
 */
main()
{
    print("[ OAC ] > Open Anti Cheat - 2024");
    OAC_main();
}

// Macro definitions to replace existing functions with the ones provided in this script.

#if defined _ALS_main
    #undef main
#else
    #define _ALS_main
#endif
#define main OAC_main
#if defined OAC_main
    forward OAC_main();
#endif

// Including other superior modules related to the project.
#include "oac/server/players/player_money.inc" // Include for player money management module.
#include "oac/server/players/player_health.inc" // Include for player health management module.
#include "oac/flow_manager.inc" // Include for control flow manager module.