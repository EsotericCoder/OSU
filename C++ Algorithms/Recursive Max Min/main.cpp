/*********************************************
** Desc: Compares a recursive vs iterative
**		 implementation of max/ min function
*********************************************/
#include <chrono>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
typedef chrono::high_resolution_clock::time_point timeHR;

/*********************************************
** Function: iterMax(array, size)
** Desc: Iteratively finds the max
*********************************************/
int itrMax(int *list, int size) {
	int max = list[0];
	for (int c = 1; c < size; c++) {
		if (max < list[c])
			max = list[c];
	}
	return max;
}


/*********************************************
** Function: recMax(array, size)
** Desc: Recursively finds the max
*********************************************/
int recMax(int *list, int size) {
	if (size == 1)
		return list[0];
	int midPoint = size / 2;
	int max1 = recMax(list, midPoint);
	int max2 = recMax(&list[midPoint], size - midPoint);
	if (max1 < max2)
		return max2;
	else
		return max1;
}


/*********************************************
** Function: timing
** Desc: Returns the run time of the function
*********************************************/
double timing(int (*func)(int*, int), int *list, int size) {
	timeHR start = chrono::high_resolution_clock::now();
	func(list, size);
	timeHR end = chrono::high_resolution_clock::now();
	auto diff = end - start;
	return (diff.count());
}


/*********************************************
** Function: createList
** Desc: Randomly generates a list of n elements
*********************************************/
int* createList(int n) {
	int list[100000];
	if (n > 100000)
		throw;
	for (int c = 0; c < n; c++)
		list[c] = rand() % 100;
	return &list[0];
}


/*********************************************
** Function: Main
** Desc: Main testing function
*********************************************/
int main() {
	ofstream file;
	file.open("question7.csv");
	srand(time(0));
	int* list;
	int listN[20];
	int listItr[20];
	int listRec[20];
	int n = 0;
	for (int c = 0; c < 20; c++) {
		n += 5000;
		cout << "Printing n = " << n << endl;
		listN[c] = n;
		list = createList(n);
		listItr[c] = timing(itrMax, list, n);
		listRec[c] = timing(recMax, list, n);
		file << listN[c] << "," << listItr[c] << "," << listRec[c] << endl;
	}
	file.close();
	cout << "ENDED CALC" << endl;
	return 0;
}