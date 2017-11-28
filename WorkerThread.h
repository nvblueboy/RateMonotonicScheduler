#include<iostream>
#include<thread>

#include "Semaphore.h"
#include "Bookkeeper.h"

using namespace std;

#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

class WorkerThread{
	public:
		WorkerThread(int _runCount);
		~WorkerThread();
		void run();
		void setProcessor(int processor);
		void setPriority(int priority);
		void join();
		Semaphore* s;
		Bookkeeper* bk;
	private:
		int runCount;
		thread threadObj;
};

void doWork(int runCount, Semaphore* s, Bookkeeper* bk);

#endif