/***********************************************
** Title: Project 2, Coin Change
** Desc: Finds the minimum amount of change
***********************************************/

#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

/***********************************************
** Name: DynMinCoin
** Desc: Object for helping the dynamic function
***********************************************/
class DynMinCoin {
public:
	int min;
	int* coinMat;
	int amount;
	DynMinCoin* basedOn;
	int indexBasedOn;
};


/***********************************************
** Name: ouput
** Desc: Output object of the algorithm functions
***********************************************/
class output {
public:
	int *coins;
	int numCoin = 0;
};


#endif // !ALGORITHM_HPP