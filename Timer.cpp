#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {}

void Timer::run() {
	for(int i = 0; i < 160; ++i) {
		//Sleep for some amount of time then signal to kick off the scheduler..
		this_thread::sleep_for(chrono::microseconds(10000));
		s->signal();
	}
}