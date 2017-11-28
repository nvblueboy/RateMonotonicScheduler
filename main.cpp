#include <iostream>
#include <thread>

#include "Semaphore.h"
#include "WorkerThread.h"
#include "Scheduler.h"
#include "Timer.h"

using namespace std;


int main() {
	// WorkerThread w1(1);
	// WorkerThread w2(3);

	// Semaphore* s1 = new Semaphore(0);
	// Semaphore* s2 = new Semaphore(0);

	// w1.s = s1;
	// w2.s = s2;

	// w1.run();
	// w1.setProcessor(0);
	// w1.setPriority(1);
	// s1->signal();

	// // w2.run();
	// // w2.setProcessor(0);
	// // w2.setPriority(2);
	// // s2->signal();

	// w1.join();
	// // w2.join();
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