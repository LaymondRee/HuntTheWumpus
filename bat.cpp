/**************************************************
 * Filename: bat.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Initializes values for bat class
 * Input: None
 * Output: Initialized bat values
 **************************************************/

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include "bat.h"

Bat::Bat(){

}

/**************************************************
 * Function: Bat
 * Description: Initializes values for bat class
 * Pre-conditions: None
 * Post-conditions: Initialized bat class
 **************************************************/
Bat::Bat(vector<vector<char> >& rooms){
	srand(time(NULL));
	int loop = 1;

	do{
		event_x = rand() % rooms.size();
		event_y = rand() % rooms.size();
	
		if(rooms[event_x][event_y] == ' '){
			loop = 0;
			rooms[event_x][event_y] = 'B';
		}

	}while(loop == 1);

}

/**************************************************
 * Function: percept
 * Description: Prints statement if player in adjacent room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Bat::percept(){
	cout << "You hear wings flapping." << endl;
}

/**************************************************
 * Function: encounter
 * Description: Prints statement if player in same room
 * Pre-conditions: None
 * Post-conditions: Statement printed
 **************************************************/
void Bat::encounter(){
	cout << "You ran into super bats!" << endl;
}
