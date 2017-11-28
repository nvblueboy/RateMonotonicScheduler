#include "Scheduler.h"

Scheduler::Scheduler() {
	threads.push_back(new WorkerThread(1));
	threads.push_back(new WorkerThread(2));
	threads.push_back(new WorkerThread(4));
	threads.push_back(new WorkerThread(16));
}

Scheduler::~Scheduler() {}

void Scheduler::run() {
	threads[0]->run();
	threads[0]->setProcessor(0);
	threads[0]->setPriority(90);
	threads[1]->run();
	threads[1]->setProcessor(0);
	threads[1]->setPriority(80);
	threads[2]->run();
	threads[2]->setProcessor(0);
	threads[2]->setPriority(70);
	threads[3]->run();
	threads[3]->setProcessor(0);
	threads[3]->setPriority(60);

	threadObj = thread(schedule, threads, s);
}

void Scheduler::setProcessor(int processor) {
	cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(processor, &cpuset);
    int rc = pthread_setaffinity_np(threadObj.native_handle(), sizeof(cpu_set_t), &cpuset);
}

void Scheduler::setPriority(int priority) {
	sched_param sch_params;
    sch_params.sched_priority = priority;
    int rc = pthread_setschedparam(threadObj.native_handle(), SCHED_FIFO, &sch_params);
    if (rc) {
    	cout << "Priority switch failed with rc " << rc << endl;
    }
}

void Scheduler::join() {
	threadObj.join();
}

void schedule(vector<WorkerThread*> threads, Semaphore* s) {
	int scheduleTime = -1;
	for (int i = 0; i < 32; ++i) {
		scheduleTime++;
		s->wait();
		if (!threads[0]->bk->done) {
				cout << "Overrun 0" << endl;
			}
		threads[0]->s->signal();
		if (scheduleTime % 2 == 0) {
			if (!threads[1]->bk->done) {
				cout << "Overrun 1" << endl;
			}
			threads[1]->s->signal();
		}
		if (scheduleTime % 4 == 0) {
			if (!threads[2]->bk->done) {
				cout << "Overrun 2" << endl;
			}
			threads[2]->s->signal();
		}
		if (scheduleTime % 16 == 0) {
			if (!threads[3]->bk->done) {
				cout << "Overrun 3" << endl;
			}
			threads[3]->s->signal();
		}
	}
}