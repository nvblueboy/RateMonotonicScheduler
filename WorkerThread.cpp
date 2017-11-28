#include "WorkerThread.h"


WorkerThread::WorkerThread(int _runCount) {
	runCount = _runCount;
	s = new Semaphore(0);
	bk = new Bookkeeper();
}

WorkerThread::~WorkerThread() {}

void WorkerThread::run() {
	threadObj = thread(doWork, runCount, s, bk);
}

void WorkerThread::setProcessor(int processor) {
	cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(processor, &cpuset);
    int rc = pthread_setaffinity_np(threadObj.native_handle(), sizeof(cpu_set_t), &cpuset);
}

void WorkerThread::setPriority(int priority) {
	sched_param sch_params;
    sch_params.sched_priority = priority;
    int rc = pthread_setschedparam(threadObj.native_handle(), SCHED_FIFO, &sch_params);
    if (rc) {
    	cout << "Priority switch failed with rc " << rc << endl;
    }
}

void WorkerThread::join() {
	threadObj.join();
}

void doWork(int runCount, Semaphore* s, Bookkeeper* bk) {
	for (int j = 0; j < 32; ++j){
		s->wait();
		bk->done = false;
		for (int run = 0; run < runCount; ++run) {
			int** arr = new int*[10];

			for (int row = 0; row < 10; ++row) {
				arr[row] = new int[10];
				for (int column = 0; column < 10; ++column) {
					arr[row][column] = 2;
				}
			}
			
			int cols[10] = {0,5,1,6,2,7,3,8,4,9};
			
			for (int i = 0; i < 10; ++i) {
				int col = cols[i];
				for (int j = 0; j < 10; ++j) {
					arr[1][i] = arr[1][i] * arr[j][i];
				}
			}
		} 
		bk->done = true;
	}
}
