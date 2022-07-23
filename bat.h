/**************************************************
 * Filename: bat.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all member functions for bat class
 **************************************************/

#ifndef BAT_H
#define BAT_H

#include <vector>
#include "event.h"

using namespace std;

class Bat : public Event{
	public:
		Bat();
		Bat(vector<vector<char> >&);
		void percept();
		void encounter();
};

#endif
