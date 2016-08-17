/*********************************************
** Name: Timing functions
** Desc: Class object for timing function
*********************************************/
#include "Timing.hpp"
using namespace std;
typedef std::chrono::system_clock timeHR;

/*********************************************
** Name: time
** Desc: Times a function with a two int inputs
*********************************************/
int TimeFunction::time(void* (*func)(int a1, int a2), int b1, int b2) {
	timeHR::time_point start;
	timeHR::time_point end;
	start = timeHR::now();
	func(b1, b2);
	end = timeHR::now();
	auto diff = end - start;
	return (diff.count());
}

/*********************************************
** Name: time
** Desc: Times a function with an array int then int
*********************************************/
int TimeFunction::time(void* (*func)(int* a1, int a2), int* b1, int b2) {
	timeHR::time_point start;
	timeHR::time_point end;
	start = timeHR::now();
	func(b1, b2);
	end = timeHR::now();
	auto diff = end - start;
	return (diff.count());
}


