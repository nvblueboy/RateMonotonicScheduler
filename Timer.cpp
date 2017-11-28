#include "Timer.h"

Timer::Timer() {

}

Timer::~Timer() {}

void Timer::run() {
	for(int i = 0; i < 32; ++i) {
		this_thread::sleep_for(chrono::microseconds(10000));
		s->signal();
	}
}