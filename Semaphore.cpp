#include "Semaphore.h"

Semaphore::Semaphore(int starting) {
	count = starting;
}

Semaphore::~Semaphore() {
	
}

void Semaphore::wait() {
	unique_lock<std::mutex> lck(mtx);
	while(count <= 0) { cv.wait(lck); }
	count--;
}

void Semaphore::signal() {
	count++;
	cv.notify_all();
}
