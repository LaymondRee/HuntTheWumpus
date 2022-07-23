/**************************************************
 * Filename: pit.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Initializes values for pit class
 * Input: None
 * Output: Initialized pit values
 **************************************************/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "pit.h"

Pit::Pit(){

}

/**************************************************
 * Function: Pit
 * Description: Initializes values for pit class
 * Pre-conditions: None
 * Post-conditions: Initialized pit class
 **************************************************/
Pit::Pit(vector<vector<char> >& rooms){
	srand(time(NULL));
	int loop = 1;

	do{
		event_x = rand() % rooms.size();
		event_y = rand() % rooms.size();
	
		if(rooms[event_x][event_y] == ' '){
			loop = 0;
			rooms[event_x][event_y] = 'P';
		}

	}while(loop == 1);

}

/**************************************************
 * Function: percept
 * Description: Prints statement if player in adjacent room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Pit::percept(){
	cout << "You feel a breeze." << endl;
}

/**************************************************
 * Function: encounter
 * Description: Prints statement if player in same room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Pit::encounter(){
	cout << "You fell down a pit!" << endl;
}
