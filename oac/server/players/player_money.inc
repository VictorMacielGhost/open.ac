/**
 * This script provides robust money management functionality for the game server, aimed at
 * preventing cheating and ensuring fair gameplay.
 * 
 * The script includes functions to retrieve, give, and reset player money, as well as a
 * comprehensive system to handle player finances securely. 
 * By managing player money securely, it helps protect the server from cheating attempts and
 * ensures a balanced gaming experience for all players.
 *
 * @author DeviceBlack
 * @date 11/May/2024
 * @time 05:30
 */

static oac_money[MAX_PLAYERS]; // Array to store player money

/**
 * @brief Prints information about which module is loaded and how it will work.
 */
OAC_StartingModulePlayerMoney()
{
	print("\n[OAC] > Starting Module: ./server/players/player_money");
	print("[OAC] > Players' money will be stored by the server and not by the client.");
}

/**
 * @brief Resets player money to zero when they connect to the server.
 * 
 * @param playerid The ID of the player connecting to the server.
 */
OAC_ResetPlayerMoneyOnConnect(playerid)
{
	oac_money[playerid] = 0;
}

/**
 * @brief Retrieves the current amount of money for a player.
 * 
 * @param playerid The ID of the player.
 * @return The amount of money the player currently has.
 */
stock OAC_GetPlayerMoney(playerid)
{
	return IsPlayerConnected(playerid) ? oac_money[playerid] : 0;
}

/**
 * @brief Gives money to a player.
 * 
 * @param playerid The ID of the player to give money to.
 * @param money The amount of money to give.
 * @return True if the player's money is successfully updated, false otherwise.
 */
stock bool:OAC_GivePlayerMoney(playerid, money)
{
	if(ResetPlayerMoney(playerid))
	{
		oac_money[playerid] += money;
		GivePlayerMoney(playerid, oac_money[playerid]);
	}
	else return false;
	return true;
}

/**
 * @brief Resets a player's money to zero.
 * 
 * @param playerid The ID of the player whose money will be reset.
 * @return True if the player's money is successfully reset, false otherwise.
 */
stock bool:OAC_ResetPlayerMoney(playerid)
{
	if(ResetPlayerMoney(playerid))
	{
		oac_money[playerid] = 0;
	}
	else return false;
	return true;
}

// Macro definitions to replace existing functions with the ones provided in this script

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney OAC_GetPlayerMoney

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney OAC_GivePlayerMoney

#if defined _ALS_ResetPlayerMoney
	#undef ResetPlayerMoney
#else
	#define _ALS_ResetPlayerMoney
#endif
#define ResetPlayerMoney OAC_ResetPlayerMoney