/**************************************************
 * Filename: room.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all components of Hunt the Wumpus
 * Input: Direction of movement/arrow
 * Output: Hunt the Wumpus game
 **************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "room.h"

using namespace std;

/**************************************************
 * Function: Room
 * Description: Initializes values for room class
 * Pre-conditions: None
 * Post-conditions: Initialized room class
 **************************************************/
Room::Room(char** argv, int g_mode){
	//Initializes values for room class
	size = atoi(argv[1]);
	mode = g_mode;
	srand(time(NULL));
	has_gold = false;
	is_alive = true;
	wumpus_alive = true;
	wumpus_awake = false;
	n_arrows = 4;

	//Creates cave of specified size
	rooms.resize(size);
	for(int i = 0; i < size; i++){
		rooms[i].resize(size);
	}

	//Initializes all rooms to ' '
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			rooms[i][j] = ' ';
		}
	}

	//Determines player starting location
	start_x = rand() % size;
	start_y = rand() % size;
	player_x = start_x;
	player_y = start_y;
	rooms[player_x][player_y] = 'x';

	//Determines location of all special rooms
	Wumpus wumpus(rooms, wumpus_x, wumpus_y);
	wstart_x = wumpus_x;
	wstart_y = wumpus_y;
	Gold gold(rooms);
	Pit pit1(rooms);
	Pit pit2(rooms);
	Bat bat1(rooms);
	Bat bat2(rooms);
}

/**************************************************
 * Function: move
 * Parameters: string direction
 * Description: Move player in chosen direction
 * Pre-conditions: Inputted direction
 * Post-conditions: Player moved
 **************************************************/
void Room::move(string direction){
	//Move player in chosen direction
	if(direction == "w"){
		player_y -= 1;
	}else if(direction == "a"){
		player_x -= 1;
	}else if(direction == "s"){
		player_y += 1;
	}else if(direction == "d"){	
		player_x += 1;
	}
}

/**************************************************
 * Function: arrow
 * Parameters: string direction
 * Description: Fires arrow chosen direction
 * Pre-conditions: Inputted direction
 * Post-conditions: Arrow fired
 **************************************************/
void Room::arrow(string direction){
	//Function over 20 lines because it doesn't make sense to split it

	int distance = 3;
	n_arrows -= 1;

	//Checks if player has arrows
	if(n_arrows < 1){
		cout << "You have no more arrows" << endl;
		return;
	}

	//Fire arrow in chosen direction
	if(direction == " w"){
		if(player_y - 3 < 0){
			distance = player_y;
		}
		for(int i = 1; i < distance + 1; i++){
			if(rooms[player_x][player_y - i] == 'W'){
				cout << "Your arrow hit the Wumpus!" << endl;
				wumpus_alive = false;
				return;
			}
		}
	}else if(direction == " a"){
		if(player_x - 3 < 0){
			distance = player_x;
		}
		for(int i = 1; i < distance + 1; i++){
			if(rooms[player_x - i][player_y] == 'W'){
				cout << "Your arrow hit the Wumpus!" << endl;
				wumpus_alive = false;
				return;
			}
		}
	}else if(direction == " s"){
		if(player_y + 3 > size - 1){
			distance = size - 1 - player_y;
		}
		for(int i = 1; i < distance + 1; i++){
			if(rooms[player_x][player_y + i] == 'W'){
				cout << "Your arrow hit the Wumpus!" << endl;
				wumpus_alive = false;
				return;
			}
		}
	}else if(direction == " d"){
		if(player_x + 3 > size - 1){
			distance = size - 1 - player_x;
		}
		for(int i = 1; i < distance + 1; i++){
			if(rooms[player_x + i][player_y] == 'W'){
				cout << "Your arrow hit the Wumpus!" << endl;
				wumpus_alive = false;
				return;
			}
		}
	}

	//Wakes Wumpus up if arrow misses
	if(wumpus_awake == false){
		cout << "The Wumpus has awoken!" << endl;
		wumpus_awake = true;
	}
}

/**************************************************
 * Function: win
 * Parameters: int& loop
 * Description: Checks to see if player has won
 * Pre-conditions: Player location and has_gold
 * Post-conditions: Determines if game should continue
 **************************************************/
void Room::win(int& loop){
	if(has_gold == true && rooms[player_x][player_y] == 'x'){
		cout << "You escaped the cave with the gold!" << endl;
		loop = 0;
	}
}

/**************************************************
 * Function: turn
 * Parameters: int& loop
 * Description: Goes through all processes that occur in one turn
 * Pre-conditions: Dirrection of movement/arrow
 * Post-conditions: Player moved/Arrow fired
 **************************************************/
void Room::turn(int& loop){
	string choose;
	loop = 1;

	//Prints information about adjacent and current room
	room_encounter();
	room_percept();

	//Handles all player actions
	if(is_alive == true){
		print_map();
		getline(cin, choose);

		if(choose == "w"){
			move(choose);
		}else if(choose == "a"){
			move(choose);
		}else if(choose == "s"){
			move(choose);
		}else if(choose == "d"){
			move(choose);
		}else if(choose == " w"){
			arrow(choose);
		}else if(choose == " a"){
			arrow(choose);
		}else if(choose == " s"){
			arrow(choose);
		}else if(choose == " d"){
			arrow(choose);
		}
	}

	//Checks if player has won/loss
	win(loop);
	if(is_alive == false){
		loop = 0;
		return;
	}

	//Moves Wumpus if it is awake and alive
	if(wumpus_awake == true && wumpus_alive == true){
		wumpus_move();
	}
}

/**************************************************
 * Function: print_map
 * Description: Prints the map
 * Pre-conditions: Mode and location of rooms/player
 * Post-conditions: Map is printed
 **************************************************/
void Room::print_map(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << "+-";
		}
		cout << "+" << endl;

		//Determines what to print based on game mode
		for(int k = 0; k < size; k++){
			cout << "|";
			if(k == player_x && i == player_y){
				cout << "*";
			}else if(rooms[k][i] == ' ' || mode == 0){
				cout << ' ';
			}else if(mode == 1){
				cout << rooms[k][i];
			}
		}
		cout << "|" << endl;
	}
	for(int i = 0; i < size; i++){
		cout << "+-";
	}
	cout << "+" << endl;
}

/**************************************************
 * Function: room_percept
 * Description: Checks for special adjacent rooms
 * Pre-conditions: Location of rooms and player
 * Post-conditions: Prints warning messages
 **************************************************/
void Room::room_percept(){
	//Function over 20 lines because it doesn't make sense to split it

	if(player_y > 0 && rooms[player_x][player_y - 1] == 'W'){
		Wumpus w;
		w.percept();
	}
	if(player_x > 0 && rooms[player_x - 1][player_y] == 'W'){
		Wumpus w;
		w.percept();
	}
	if(player_y < size - 1 && rooms[player_x][player_y + 1] == 'W'){
		Wumpus w;
		w.percept();
	}
	if(player_x < size - 1 && rooms[player_x + 1][player_y] == 'W'){
		Wumpus w;
		w.percept();
	}
	if(player_y > 0 && rooms[player_x][player_y - 1] == 'G'){
		Gold g;
		g.percept();
	}
	if(player_x > 0 && rooms[player_x - 1][player_y] == 'G'){
		Gold g;
		g.percept();
	}
	if(player_y < size - 1 && rooms[player_x][player_y + 1] == 'G'){
		Gold g;
		g.percept();
	}
	if(player_x < size - 1 && rooms[player_x + 1][player_y] == 'G'){
		Gold g;
		g.percept();
	}
	if(player_y > 0 && rooms[player_x][player_y - 1] == 'P'){
		Pit p;
		p.percept();
	}
	if(player_x > 0 && rooms[player_x - 1][player_y] == 'P'){
		Pit p;
		p.percept();
	}
	if(player_y < size - 1 && rooms[player_x][player_y + 1] == 'P'){
		Pit p;
		p.percept();
	}
	if(player_x < size - 1 && rooms[player_x + 1][player_y] == 'P'){
		Pit p;
		p.percept();
	}
	if(player_y > 0 && rooms[player_x][player_y - 1] == 'B'){
		Bat b;
		b.percept();
	}
	if(player_x > 0 && rooms[player_x - 1][player_y] == 'B'){
		Bat b;
		b.percept();
	}
	if(player_y < size - 1 && rooms[player_x][player_y + 1] == 'B'){
		Bat b;
		b.percept();
	}
	if(player_x < size - 1 && rooms[player_x + 1][player_y] == 'B'){
		Bat b;;
		b.percept();
	}
}

/**************************************************
 * Function: room_encounter
 * Description: Checks for event in current room
 * Pre-conditions: Location of rooms and player
 * Post-conditions: Carries out special event
 **************************************************/
void Room::room_encounter(){
	srand(time(NULL));

	if(rooms[player_x][player_y] == 'W'){
		if(wumpus_alive == true){
			Wumpus w;
			w.encounter();
			is_alive = false;
		}
	}else if(rooms[player_x][player_y] == 'G'){
		Gold g;
		g.encounter();
		has_gold = true;
	}else if(rooms[player_x][player_y] == 'P'){
		Pit p;
		p.encounter();
		is_alive = false;
	}else if(rooms[player_x][player_y] == 'B'){
		Bat b;
		b.encounter();
		player_x = rand() % size;
		player_y = rand() % size;
		room_encounter();
	}
}

/**************************************************
 * Function: wumpus_move
 * Description: Moves Wumpus if alive and awake
 * Pre-conditions: Condition of the wumpus
 * Post-conditions: Wumpus is moved
 **************************************************/
void Room::wumpus_move(){
	srand(time(NULL));
	int moving = rand() % 4;

	//Determines if the Wumpus is going to move
	if(moving != 0){
		moving = rand() % 4;

		//Move Wumpus if possible
		if(moving == 0 && wumpus_y > 0 && rooms[wumpus_x][wumpus_y - 1] == ' '){
			cout << "The Wumpus has moved rooms" << endl;
			rooms[wumpus_x][wumpus_y] = ' ';
			rooms[wumpus_x][wumpus_y - 1] = 'W';
			wumpus_y -= 1;
		}
		if(moving == 1 && wumpus_x > 0 && rooms[wumpus_x - 1][wumpus_y] == ' '){
			cout << "The Wumpus has moved rooms" << endl;
			rooms[wumpus_x][wumpus_y] = ' ';
			rooms[wumpus_x - 1][wumpus_y] = 'W';
			wumpus_x -= 1;
		}
		if(moving == 2 && wumpus_y < size - 1 && rooms[wumpus_x][wumpus_y + 1] == ' '){
			cout << "The Wumpus has moved rooms" << endl;
			rooms[wumpus_x][wumpus_y] = ' ';
			rooms[wumpus_x][wumpus_y + 1] = 'W';
			wumpus_y += 1;
		}
		if(moving == 4 && wumpus_x < size - 1 && rooms[wumpus_x + 1][wumpus_y] == ' '){
			cout << "The Wumpus has moved rooms" << endl;
			rooms[wumpus_x][wumpus_y] = ' ';
			rooms[wumpus_x + 1][wumpus_y] = 'W';
			wumpus_x += 1;
		}
	}
}

/**************************************************
 * Function: same_map
 * Description: Resets the current map
 * Pre-conditions: None
 * Post-conditions: Reinitializes starting values
 **************************************************/
void Room::same_map(){
	//Resets all starting values
	has_gold = false;
	is_alive = true;
	wumpus_alive = true;
	wumpus_awake = false;
	n_arrows = 4;
	player_x = start_x;
	player_y = start_y;
	rooms[wumpus_x][wumpus_y] = ' ';
	rooms[wstart_x][wstart_y] = 'W';
	wumpus_x = wstart_x;
	wumpus_y = wstart_y;
}
