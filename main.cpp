#include <iostream>
#include <thread>

#include "Semaphore.h"
#include "WorkerThread.h"
#include "Scheduler.h"
#include "Timer.h"

using namespace std;


int main() {
	Semaphore* timeS = new Semaphore(0);
	Scheduler sched;
	sched.s = timeS;
	sched.run();
	sched.setPriority(99);
	sched.setProcessor(0);
	Timer time;
	sched.s = timeS;
	time.s = timeS;
	time.run();

	sched.join();
	return 0;
}