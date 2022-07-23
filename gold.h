/**************************************************
 * Filename: gold.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Contains all member functions for gold class
 **************************************************/

#ifndef GOLD_H
#define GOLD_H

#include <vector>
#include "event.h"

using namespace std;

class Gold : public Event{
	public:
		Gold();
		Gold(vector<vector<char> >&);
		void percept();
		void encounter();
};

#endif
