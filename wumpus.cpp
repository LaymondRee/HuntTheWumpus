/**************************************************
 * Filename: wumpus.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Initializes values for wumpus class
 * Input: None
 * Output: Initialized wumpus values
 **************************************************/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "wumpus.h"

Wumpus::Wumpus(){

}

/**************************************************
 * Function: Wumpus
 * Description: Initializes values for wumpus class
 * Pre-conditions: None
 * Post-conditions: Initialized wumpus class
 **************************************************/
Wumpus::Wumpus(vector<vector<char> >& rooms, int& wumpus_x, int& wumpus_y){
	srand(time(NULL));
	int loop = 1;

	do{
		event_x = rand() % rooms.size();
		event_y = rand() % rooms.size();
	
		if(rooms[event_x][event_y] == ' '){
			loop = 0;
			rooms[event_x][event_y] = 'W';
		}

	}while(loop == 1);

	wumpus_x = event_x;
	wumpus_y = event_y;

}

/**************************************************
 * Function: percept
 * Description: Prints statement if player in adjacent room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Wumpus::percept(){
	cout << "You smell a terrible stench." << endl;
}

/**************************************************
 * Function: encounter
 * Description: Prints statement if player in same room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Wumpus::encounter(){
	cout << "You ran into the Wumpus and died!" << endl;
}
