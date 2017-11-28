#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

class Semaphore{
	public:
		Semaphore(int starting);
		~Semaphore();
		void wait();
		void signal();
	private:
		int count;
		condition_variable cv;
		mutex mtx;

};

#endif