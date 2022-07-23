/**************************************************
 * Filename: event.cpp
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Abstract class
 * Input: None
 * Output: None
 **************************************************/

#include "event.h"

Event::Event(){

}

int Event::get_x(){
	return event_x;
}

int Event::get_y(){
	return event_y;
}
