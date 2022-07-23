/**************************************************
 * Filename: driver.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Plays Hunt the Wumpus game
 * Input: Direction of movement/arrow
 * Output: Hunt the Wumpus game
 **************************************************/

#include <iostream>
#include <string>
#include "room.h"

using namespace std;

int main(int argc, char** argv){
	int loop = 1;
	bool g_mode;
	int choose;

	//Checks for correct number of commandline arguments
	if(argc != 3){
		cout << "Incorrect number of commandline arguments!" << endl;
		return 0;
	}

	string s(argv[2]);

	//Checks for valid commandline arguments
	if(s != "true" && s != "false"){
		cout << "Invalid commandline argument of " << argv[2] << endl;
		return 0;
	}

	//Determines game mode the game will be played
	if(s == "true"){
		g_mode = 1;
	}else if(s == "false"){
		g_mode = 0;
	}

	//Continues to loop until player wins or loses
	while(loop == 1){
	Room r(argv, g_mode);
		while(loop == 1){
			r.turn(loop);

			if(loop == 0){
				cout << endl << "Would you like to..." << endl;
				cout << "Play the same map (1)" << endl;
				cout << "Play a different map (2)" << endl;
				cout << "Quit the game (3)" << endl;
				cin >> choose;

				if(choose == 1){
					loop = 1;
					r.same_map();
				}
			}
		}
		if(choose == 2){
			loop = 1;
		}
	}
	return 0;
}
