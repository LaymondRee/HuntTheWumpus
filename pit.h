/**************************************************
 * Filename: pit.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all member functions for pit class
 **************************************************/

#ifndef PIT_H
#define PIT_H

#include <vector>
#include "event.h"

using namespace std;

class Pit : public Event{
	public:
		Pit();
		Pit(vector<vector<char> >&);
		void percept();
		void encounter();
};

#endif
