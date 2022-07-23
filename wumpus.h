/**************************************************
 * Filename: wumpus.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all member functions for wumpus class
 **************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include <vector>
#include "event.h"

using namespace std;

class Wumpus : public Event{
	public:
		Wumpus();
		Wumpus(vector<vector<char> >&, int&, int&);
		void percept();
		void encounter();
};

#endif
