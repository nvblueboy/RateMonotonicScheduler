#include <iostream>
#include <vector>

#include "WorkerThread.h"

using namespace std;

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler{
	public:
		Scheduler();
		~Scheduler();
		void run();
		void setProcessor(int processor);
		void setPriority(int priority);
		void join();
		Semaphore* s;
		int* scheduleTime;
		vector<WorkerThread*> threads;
	private:
		thread threadObj;
};

void schedule(vector<WorkerThread*> threads, Semaphore* s);

#endif