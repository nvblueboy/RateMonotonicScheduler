#include <iostream>

#include "Scheduler.h"

using namespace std;

#ifndef TIMER_H
#define TIMER_H

class Timer {
	public:
		Timer();
		~Timer();
		void run();
		Semaphore* s;
	private:
};

#endif