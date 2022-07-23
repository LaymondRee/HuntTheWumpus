/**************************************************
 * Filename: room.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all member functions/variables for room class
 **************************************************/

#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "event.h"
#include "wumpus.h"
#include "bat.h"
#include "pit.h"
#include "gold.h"

using namespace std;

class Room{
	private:
		int size;
		bool mode;
		bool has_gold;
		bool is_alive;
		bool wumpus_alive;
		bool wumpus_awake;
		int n_arrows;
		int start_x;
		int start_y;
		int player_x;
		int player_y;
		int wstart_x;
		int wstart_y;
		int wumpus_x;
		int wumpus_y;
		vector<vector<char> > rooms;

	public:
		Room(char**, int);
		void move(string);
		void arrow(string);
		void win(int&);
		void turn(int&);
		void print_map();
		void room_percept();
		void room_encounter();
		void wumpus_move();
		void same_map();
};

#endif
