/**************************************************
 * Filename: gold.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Initializes values for gold class
 * Input: None
 * Output: Initialized values for gold
 **************************************************/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "gold.h"

Gold::Gold(){

}

/**************************************************
 * Function: Gold
 * Description: Initializes values for gold class
 * Pre-conditions: None
 * Post-conditions: Initialized gold class
 **************************************************/
Gold::Gold(vector<vector<char> >& rooms){
	srand(time(NULL));
	int loop = 1;

	do{
		event_x = rand() % rooms.size();
		event_y = rand() % rooms.size();
	
		if(rooms[event_x][event_y] == ' '){
			loop = 0;
			rooms[event_x][event_y] = 'G';
		}

	}while(loop == 1);

}

/**************************************************
 * Function: percept
 * Description: Prints statement if player in adjacent room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Gold::percept(){
	cout << "You see a glimmer nearby." << endl;
}

/**************************************************
 * Function: encounter
 * Description: Prints statement if player in same room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Gold::encounter(){
	cout << "You found the gold!" << endl;
}
