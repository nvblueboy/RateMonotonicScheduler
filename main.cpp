#include <iostream>
#include <thread>

#include "Semaphore.h"
#include "WorkerThread.h"
#include "Scheduler.h"
#include "Timer.h"

using namespace std;


int main() {

	cout << "Running..." << endl;
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

	cout << "Done." << endl;
	cout << "Statistics:" << endl;
	cout << "Thread 0 ran: " << sched.threads[0]->bk->runCount << " times." << endl;	
	cout << "Thread 0 overruns: " << sched.threads[0]->bk->overruns << endl;
	cout << "Thread 1 ran: " << sched.threads[1]->bk->runCount << " times." << endl;
	cout << "Thread 1 overruns: " << sched.threads[1]->bk->overruns << endl;
	cout << "Thread 2 ran: " << sched.threads[2]->bk->runCount << " times." << endl;
	cout << "Thread 2 overruns: " << sched.threads[2]->bk->overruns << endl;
	cout << "Thread 3 ran: " << sched.threads[3]->bk->runCount << " times." << endl;
	cout << "Thread 3 overruns: " << sched.threads[3]->bk->overruns << endl;  
	return 0;
}