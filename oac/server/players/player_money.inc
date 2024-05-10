/**
 * This script provides robust money management functionality for the game server, aimed at preventing cheating and ensuring fair gameplay.
 * 
 * The script includes functions to retrieve, give, and reset player money, as well as a comprehensive system to handle player finances securely. 
 * By managing player money securely, it helps protect the server from cheating attempts and ensures a balanced gaming experience for all players.
 *
 * Author: DeviceBlack
 * Date: 08/May/2024
 * Time: 22:30
 */

/**
 * @brief Static variable to store each player's money.
 */
static _oac_money[MAX_PLAYERS];

/**
 * @brief Retrieves a player's money.
 *
 * @param playerid The player's ID.
 * @return The player's money if connected, otherwise returns 0.
 */
stock _oac_GetPlayerMoney(playerid)
{
	// Check if the player is connected, return their money if they are, otherwise return 0
	return IsPlayerConnected(playerid) ? _oac_money[playerid] : 0;
}

/**
 * @brief Gives money to a player.
 *
 * @param playerid The player's ID.
 * @param money The amount of money to give.
 * @return 1 if the operation is successful, otherwise returns 0.
 */
stock _oac_GivePlayerMoney(playerid, money)
{
	// Add the specified amount of money to the player's balance
	return SetPlayerMoney(playerid, (_oac_money[playerid] + money));
}

/**
 * @brief Resets a player's money.
 *
 * @param playerid The player's ID.
 * @return 1 if the operation is successful, otherwise returns 0.
 */
stock _oac_ResetPlayerMoney(playerid)
{
	// Set the player's money to 0 and return 1 if successful, otherwise return 0
	return SetPlayerMoney(playerid, 0) ? 1 : 0;
}

/**
 * @brief Sets a player's money.
 *
 * @param playerid The player's ID.
 * @param money The amount of money to set.
 * @return 1 if the operation is successful, otherwise returns 0.
 */
stock SetPlayerMoney(playerid, money) {
	// Check if it's possible to reset the player's money
	if(ResetPlayerMoney(playerid))
	{	
		// Set the player's money to the specified amount
		_oac_money[playerid] = money;
		
		// If the new balance is not 0, give the money to the player
		if(money != 0) GivePlayerMoney(playerid, _oac_money[playerid]);
		
		// Return 1 if the operation is successful
		return 1;
	}
	
	// Return 0 if unable to reset the player's money
	return 0;
}

/**
 * @brief Hooking functions
 */
#if defined _ALS_GetPlayerMoney
    #undef GetPlayerMoney
#else
    #define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney _oac_GetPlayerMoney

#if defined _ALS_GivePlayerMoney
    #undef GivePlayerMoney
#else
    #define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney _oac_GivePlayerMoney

#if defined _ALS_ResetPlayerMoney
    #undef ResetPlayerMoney
#else
    #define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney _oac_ResetPlayerMoney