#include "Bookkeeper.h"

Bookkeeper::Bookkeeper() { 
	done = true; 
	overruns = 0;
	runCount = 0;
}

Bookkeeper::~Bookkeeper() {}