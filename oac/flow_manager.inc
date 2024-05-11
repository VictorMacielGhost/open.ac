/**
 * @file control_flow_manager.inc
 * @brief This file is responsible for distributing the control flow among the different modules of the system,
 * using an approach based on hooks, callbacks, and timers.
 * 
 * It acts as an intelligent intermediary, coordinating the execution of operations in response to
 * specific events and ensuring smooth interaction among the various components of the system.
 *
 * @author DeviceBlack
 * @date 11/May/2024
 * @time 05:30
 */

/**
 * @brief Callback function triggered when a player connects to the server.
 */
public OnPlayerConnect(playerid)
{
    OAC_ResetPlayerMoneyOnConnect(playerid); // Call function to reset player money.

    #if defined OAC_OnPlayerConnect
        return OAC_OnPlayerConnect(playerid);
    #else
        return 1;
    #endif
}

// Macro definitions to replace existing functions with the ones provided in this script.

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect OAC_OnPlayerConnect
#if defined OAC_OnPlayerConnect
    forward OAC_OnPlayerConnect(playerid);
#endif