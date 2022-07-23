/**************************************************
 * Filename: event.h
 * Author: Raymond Lee
 * Date: 5-23-2021
 * Description: Abstract class for special rooms
 **************************************************/

#ifndef EVENT_H
#define EVENT_H

class Event{
	protected:
		int event_x;
		int event_y;
	public:
		Event();
		virtual void percept() = 0;
		virtual void encounter() = 0;
		int get_x();
		int get_y();
};

#endif
