/**
 * This script implements an advanced system to check the player's health in numerous different scenarios, calculate 
 * damage possibilities, and detect potential cheating.
 * 
 * The script includes complex algorithms that analyze the player's state in various gameplay situations,
 * estimate potential damage based on multiple variables, and employ cheat detection mechanisms
 * to ensure a fair and 
 * balanced gaming experience.
 *
 * @author DeviceBlack
 * @date 11/May/2024
 * @time 14:10
 */

#define MAX_VENDING_MACHINE	(84)

static enum OAC_VENDING_MACHINE
{
	model,
	Float:posx,
	Float:posy,
	Float:posz
};

/**
 * @brief Prints information about which module is loaded and how it will work.
 */
OAC_StartingModulePlayerHealth()
{
	print("\n[OAC] > Starting Module: ./server/players/player_health");
	
	#if defined Maintain OAC_DO_NOT_REMOVE_VENDING_MACHINES
		print("[OAC] > Players near the vending machine will be constantly checked.");
	#else
		print("[OAC] > Vending machines will be removed for players upon logging in.");
	#endif
}

/**
 * @brief Removes vending machines for players upon connecting to the server.
 * 
 * This function removes vending machines for players upon connecting to the server, 
 * improving gameplay experience and preventing exploitation of vending machines for cheating.
 * 
 * @param playerid The ID of the player who is connecting to the server.
 */
OAC_RemoveVendingMachinesOnConnect(playerid)
{
	#if !defined Maintain OAC_DO_NOT_REMOVE_VENDING_MACHINES
		new const Float:oac_machines[MAX_VENDING_MACHINE][OAC_VENDING_MACHINE] =
		{
			{955, 1277.83, 372.51, 18.95},
			{955, -862.82, 1536.60, 21.98},
			{955, 201.01, -107.61, 0.89},
			{955, -253.74, 2597.95, 62.24},
			{955, -14.70, 1175.35, 18.95},
			{955, 2352.17, -1357.15, 23.77},
			{955, 2325.97, -1645.13, 14.21},
			{955, 1928.73, -1772.44, 12.94},
			{955, 2085.77, 2071.35, 10.45},
			{955, 1520.14, 1055.26, 10.00},
			{955, 2503.14, 1243.69, 10.21},
			{955, 2319.99, 2532.85, 10.21},
			{955, 1154.72, -1460.89, 15.15},
			{955, 2060.11, -1897.64, 12.92},
			{955, 1729.78, -1943.04, 12.94},
			{955, 1789.21, -1369.26, 15.16},
			{955, -1980.78, 142.66, 27.07},
			{955, -2118.96, -423.64, 34.72},
			{955, -2118.61, -422.41, 34.72},
			{955, -2097.27, -398.33, 34.72},
			{955, -2092.08, -490.05, 34.72},
			{955, -2063.27, -490.05, 34.72},
			{955, -2005.64, -490.05, 34.72},
			{955, -2034.46, -490.05, 34.72},
			{955, -2068.56, -398.33, 34.72},
			{955, -2039.85, -398.33, 34.72},
			{955, -2011.14, -398.33, 34.72},
			{955, -1350.11, 492.28, 10.58},
			{955, 2085.77, 2071.35, 10.45},
			{955, 1520.14, 1055.26, 10.00},
			{955, 2503.14, 1243.69, 10.21},
			{955, 2319.99, 2532.85, 10.21},
			{956, 2271.72, -76.46, 25.96},
			{956, 662.42, -552.16, 15.71},
			{956, -253.74, 2599.75, 62.24},
			{956, -76.03, 1227.99, 19.12},
			{956, -1455.11, 2591.66, 55.23},
			{956, 2139.51, -1161.48, 23.35},
			{956, 2153.23, -1016.14, 62.23},
			{956, 2480.85, -1959.27, 12.96},
			{956, 1634.10, -2237.53, 12.89},
			{956, -2229.18, 286.41, 34.70},
			{956, -1350.11, 493.85, 10.58},
			{956, 2845.72, 1295.04, 10.78},
			{956, 2647.69, 1129.66, 10.21},
			{956, 1398.84, 2222.60, 10.42},
			{956, 1659.46, 1722.85, 10.21},
			{1209, -2420.21, 984.57, 44.29},
			{1302, -2420.17, 985.94, 44.29},
			{1775, 501.82, -1.42, 1000.73},
			{1775, 373.82, -178.14, 1000.73},
			{1775, 495.96, -24.32, 1000.73},
			{1775, 2222.20, 1606.77, 1000.05},
			{1775, 2155.90, 1606.77, 1000.05},
			{1775, 2209.90, 1607.19, 1000.05},
			{1775, 2576.70, -1284.43, 1061.09},
			{1775, 2225.20, -1153.42, 1025.90},
			{1775, -19.03, -57.83, 1003.63},
			{1775, -16.11, -91.64, 1003.63},
			{1775, -15.10, -140.22, 1003.63},
			{1775, -32.44, -186.69, 1003.63},
			{1775, -35.72, -140.22, 1003.63},
			{1775, -32.44, -186.69, 1003.63},
			{1775, -35.72, -140.22, 1003.63},
			{1775, -19.03, -57.83, 1003.63},
			{1775, -16.11, -91.64, 1003.63},
			{1775, -15.10, -140.22, 1003.63},
			{1776, 379.03, -178.88, 1000.73},
			{1776, 500.56, -1.36, 1000.73},
			{1776, 2222.36, 1602.64, 1000.06},
			{1776, 2155.84, 1607.87, 1000.06},
			{1776, 2202.45, 1617.00, 1000.06},
			{1776, 2209.24, 1621.21, 1000.06},
			{1776, 330.67, 178.50, 1020.07},
			{1776, 331.92, 178.50, 1020.07},
			{1776, 350.90, 206.08, 1008.47},
			{1776, 361.56, 158.61, 1008.47},
			{1776, 371.59, 178.45, 1020.07},
			{1776, 374.89, 188.97, 1008.47},
			{1776, -36.14, -57.87, 1003.63},
			{1776, -17.54, -91.71, 1003.63},
			{1776, -16.53, -140.29, 1003.63},
			{1776, -33.87, -186.76, 1003.63},
			{1977, 316.87, -140.35, 998.58}
		};
		
		for(new i; i < MAX_VENDING_MACHINE; i++)
		{
			RemoveBuildingForPlayer(playerid, oac_machines[i][model], oac_machines[i][posx], oac_machines[i][posy], oac_machines[i][posz], 23.0);
		}
	#endif
