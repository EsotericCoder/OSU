/*********************************************
** Name: Timing functions
** Desc: Class object for timing function
*********************************************/
#ifndef TIMING_HPP
#define TIMING_HPP
using namespace std;

#include <chrono>
class TimeFunction {
	// Timing function and overloads
	public:
		int time (void* (*func)(int a1, int a2), int b1, int b2);
		int time (void* (*func)(int* a1, int a2), int* b1, int b2);
		int time (output (*func)(int* a1, int a2, int a3), int* b1, int b2, int b3);
};
#endif // !TIMINGHPP