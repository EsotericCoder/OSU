/***********************************************
** Title: Project 2, Coin Change
** Desc: Finds the minimum amount of change
***********************************************/
#include <iostream>
#include <fstream>
#include <math.h>

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


/*********************************************
** Name: time
** Desc: Times a function with an array int then two int
*********************************************/
#include <chrono>
using namespace std;
typedef std::chrono::system_clock timeHR;
int time(output(*func)(int* a1, int a2, int a3), int* b1, int b2, int b3) {
	timeHR::time_point start;
	timeHR::time_point end;
	start = timeHR::now();
	func(b1, b2, b3);
	end = timeHR::now();
	auto diff = end - start;
	return (diff.count());
}


/***********************************************
** Name: changegreedy
** Desc: Uses the greedy approach to find the
**		 minimum coins required for change
***********************************************/
output changegreedy(int *arr, int size, int amount) {
	output change;
	int numOfCoins;
	change.numCoin = 0;
	change.coins = (int*)malloc(size * sizeof(int));

	//loop through array
	for (int i = size - 1; i >= 0; i--) {
		if (amount > 0) {
			numOfCoins = amount / arr[i];
			amount = amount - (numOfCoins * arr[i]);
			change.coins[i] = numOfCoins;
			change.numCoin = change.numCoin + numOfCoins;
		}
		else
			change.coins[i] = 0;
	}
	return change;
}


/***********************************************
** Name: changeslow
** Desc: Finds the minimum change using a devide
**		 and conquer technique
***********************************************/
output changeslow(int *coins, int numCoins, int change)
{
	//Var declaration
	int i;
	int numCoin;
	output coins1, coins2;
	output totalCoins;
	output tempCoins;

	// Initialises the coin matrices in the output classes
	totalCoins.coins = (int*)malloc(numCoins*sizeof(int));
	tempCoins.coins = (int*)malloc(numCoins * sizeof(int));
	for (int c = 0; c < numCoins; c++) {
		totalCoins.coins[c] = 0;
		tempCoins.coins[c] = 0;
	}

	//Base case: if there is a K-cent coin
	for (i = 0; (i < numCoins) && (coins[i] != change); i++);
	if (coins[i] == change) {
		tempCoins.coins[i] = 1;
		tempCoins.numCoin = 1;
		delete totalCoins.coins;
		return tempCoins;
	}

	//Recursive case
	for (int c = 1; c < change; c++) {
		coins1 = changeslow(coins, numCoins, c);
		coins2 = changeslow(coins, numCoins, change - c);
		numCoin = coins1.numCoin + coins2.numCoin;
		if ((c == 1) || (totalCoins.numCoin > numCoin)) {
			totalCoins.numCoin = numCoin;
			for (int k = 0; k < numCoins; k++)
				totalCoins.coins[k] = coins1.coins[k] + coins2.coins[k];
		}
	}

	//delete coins1.coins;
	//delete coins2.coins;
	//delete tempCoins.coins;

	return totalCoins;
}


/***********************************************
** Name: changedp
** Desc: Finds the minimum change using a dynamic
**       programming
***********************************************/
output changedp(int* v, int vSize, int amount) {
	// Variable Decleration
	DynMinCoin *aMat = (DynMinCoin*)malloc(amount*sizeof(DynMinCoin));
	int diff;

	// Intialises the coin matrices in aMat, O(vSize*amount)
	for (int c = 0; c < amount; c++) {
		aMat[c].coinMat = (int*)malloc(vSize * sizeof(int));
		for (int k = 0; k < vSize; k++)
			aMat[c].coinMat[k] = 0;
	}

	// Solves the sub problem amount = 1
	aMat[0].coinMat[0] = 1;
	aMat[0].min = 1;
	aMat[0].amount = 1;

	// Solve all the sub problems up to the amount
	for (int a = 2; a <= amount; a++) {
		// Worset Case: Change is completely pennies
		aMat[a - 1].amount = a;
		aMat[a - 1].min = a;
		aMat[a - 1].basedOn = nullptr;

		// Looks for a better solution
		for (int c = 1; c < vSize; c++) {
			diff = a - v[c];
			if (diff == 0)
				aMat[a - 1].min = 1;
			else if ((diff > 0) && (aMat[diff - 1].min + 1 < aMat[a - 1].min)) {
				aMat[a - 1].min = aMat[diff - 1].min + 1;
				aMat[a - 1].basedOn = &aMat[diff - 1];
				aMat[a - 1].indexBasedOn = c;
			}
		}

		// Updates the coin matrix with the best solution
		if (aMat[a - 1].min == a)
			aMat[a - 1].coinMat[0] = a;
		else if (aMat[a - 1].min == 1) {
			for (int c = 0; c < vSize; c++) {
				if (v[c] == a)
					aMat[a - 1].coinMat[c] = 1;
			}
		}
		else {
			for (int c = 0; c < vSize; c++)
				aMat[a - 1].coinMat[c] = aMat[a - 1].basedOn->coinMat[c];
			aMat[a - 1].coinMat[aMat[a - 1].indexBasedOn]++;
		}
	}

	// Prevents memory leaks
	int tempMin = aMat[amount - 1].min;
	int* tempCoinMat = aMat[amount - 1].coinMat;
	for (int c = 0; c < amount - 1; c++)
		delete aMat[c].coinMat;
	delete aMat;

	// Returns the results
	output output;
	output.numCoin = tempMin;
	output.coins = tempCoinMat;
	return output;
}


/***********************************************
** Name: printOutput
** Desc: prints an output class data
***********************************************/
void printOutput(int amount, int *coins, int numCoins, output minCoins) {
	cout << "For amount = " << amount << endl;
	cout << "The minimum number of coins: " << minCoins.numCoin << endl;
	for (int c = 0; c < numCoins; c++)
		cout << coins[c] << ": " << minCoins.coins[c] << endl;
}


/***********************************************
** Name: printOutputFile
** Desc: prints an output class data
***********************************************/
void printOutputFile(ofstream &file, output minCoins, int size) {
	file << "Minimum Number: " << minCoins.numCoin << endl;
	file << "[" << minCoins.coins[0];
	for (int c = 1; c < size; c++) {
		file << ", " << minCoins.coins[c];
	}
	file << "]" << endl;
}



/***********************************************
** Name: main
** Desc: Main Running Code
***********************************************/
#if 1
int main() {
	// Asks if they would like to run all three algorithms
	bool validInput = false;
	bool skipChangeSlow = false;
	char in[256];
	while (validInput == false) {
		cout << "Would you like to run changeslow? y/n" << endl;
		cin >> in;
		if ((in[0] == 121) || (in[0] == 110))
			validInput = true;
	}
	if (in[0] == 110)
		skipChangeSlow = true;
	
	// Opens the files
	output cg, cs, cd;
	ifstream file;
	ofstream outFile;
	file.open("coin1.txt");
	outFile.open("coin_results.txt");
	if ((!file.is_open()) || (!outFile.is_open())) {
		cout << "File failed to open" << endl;
		return 0;
	}

	// Variable decleration
	char str[256];
	int nOpen;
	int nClose;
	int nComma;
	int *arr;
	int sum;
	int index;
	bool isNegative;
	int amount;

	// Reads the input, calculates and outputs
	while (!file.eof()) {
		// Gets the next line as a string
		for (int c = 0; c < 256; c++)
			str[c] = 0;
		file.getline(str, 256);

		// Counts the number of: "[" "]" "," in the string
		nComma = 0;
		nOpen = 0;
		nClose = 0;
		for (int c = 0; c < 256; c++) {
			if (str[c] == 44)		// 44 = ","
				nComma++;
			else if (str[c] == 91)	// 91 = "["
				nOpen++;
			else if (str[c] == 93)	// 93 = "]"
				nClose++;
		}

		// Skips strings without a valid array
		if ((nOpen != 1) || (nClose != 1)) continue;

		// Extracts the data from the string
		arr = new int[nComma + 1];
		sum = 0;
		index = 0;
		isNegative = false;
		for (int c = 0; c < 256; c++) {
			// Saves the extracted data to the array
			if ((str[c] == 44) || (str[c] == 93)) { // str[c] = "," OR "]"
				if (index == nComma + 1) {
					cout << "An error has occured in reading the array" << endl;
					throw;
				}
				arr[index] = sum;
				if (isNegative)
					arr[index] *= -1;
				index++;
				sum = 0;
				isNegative = false;
			}

			// Converts the string into a integer
			else if ((str[c] > 47) && (str[c] < 58)) // If str[c] is a number
				sum = 10 * sum + str[c] - 48;

			// Detects negative numbers
			else if (str[c] == 45) // 45 = "-"
				isNegative = true;
		}

		// Gets the amount
		for (int c = 0; c < 256; c++)
			str[c] = 0;
		file.getline(str, 256);
		amount = 0;
		for (int c = 0; c < 256; c++) {
			if ((str[c] > 47) && (str[c] < 58)) // If str[c] is a number
				amount = 10 * amount + str[c] - 48;
		}

		if (!skipChangeSlow) {
			cout << "Running all three algorithms" << endl;
			cout << "This may take a while due to changeslow" << endl;
			cout << "NOTE: If the problem is to large, the recursive" << endl;
			cout << "calls in changeslow will stack overflow and will kill the program" << endl;
			cs = changeslow(arr, index, amount);
		}
		cg = changegreedy(arr, index, amount);
		cd = changedp(arr, index, amount);

		if (!skipChangeSlow) {
			outFile << "changeslow" << endl;
			printOutputFile(outFile, cs, index);
		}
		outFile << endl << "changegreedy" << endl;
		printOutputFile(outFile, cg, index);
		outFile << endl << "changedp" << endl;
		printOutputFile(outFile, cd, index);
		outFile << endl;


		delete arr;
	}
	file.close();
	outFile.close();
}
#elif 1
// question 7 and 8
int main() {
	// Opens the file
	ofstream file;
	file.open("data7_8.csv");

	// Defines the coin sets;
	int V0[] = { 1, 5, 10, 25, 50 };
	int sizeV0 = 5;
	file << "V0 = [1, 5, 10, 25, 50]" << endl;
	int V1[] = { 1, 2, 6, 12, 24, 48, 60};
	int sizeV1 = 7;
	file << "V1 = [1, 2, 6, 12, 24, 48, 60]" << endl;
	int V2[] = { 1, 6, 13, 37, 150};
	int sizeV2 = 5;
	file << "V2 = [1, 6, 13, 37, 150]" << endl;
	int sizeV3 = 16;
	int *V3 = new(int[sizeV3]);
	V3[0] = 1;
	V3[1] = 2;
	file << "V3 = [1, 2";
	for (int c = 2; c < sizeV3; c++) {
		V3[c] = V3[c - 1] + 2;
		file << ", " << V3[c];
	}
	file << "]" << endl;

	// Gets timing data for change changeslow
	int Vtime[4];
	int lastTime = 0;
	int amount = 1;
	file << "\nCHANGESLOW" << endl;
	file << "Amount, time V0, time V1, time V2, time V3" << endl;
	while (lastTime < 10000000) {
		cout << "Amount = " << amount << ", Last Time = " << lastTime << endl;
		Vtime[0] = time(changeslow, V0, sizeV0, amount);
		Vtime[1] = time(changeslow, V1, sizeV1, amount);
		Vtime[2] = time(changeslow, V2, sizeV2, amount);
		Vtime[3] = time(changeslow, V3, sizeV3, amount);
		lastTime = Vtime[0];
		for (int c = 1; c < 4; c++) {
			if (lastTime < Vtime[c])
				lastTime = Vtime[c];
		}
		file << amount << "," << Vtime[0] << "," << Vtime[1] << ",";
		file << Vtime[2] << "," << Vtime[3] << endl;
		amount *= 2;
	}

	// Gets timing data for changegreedy
	lastTime = 0;
	amount = 1;
	file << "\nCHANGEGREEDY" << endl;
	file << "Amount, time V0, time V1, time V2, time V3" << endl;
	while (amount > 0) {
		cout << "Amount = " << amount << ", Last Time = " << lastTime << endl;
		Vtime[0] = time(changegreedy, V0, sizeV0, amount);
		Vtime[1] = time(changegreedy, V1, sizeV1, amount);
		Vtime[2] = time(changegreedy, V2, sizeV2, amount);
		Vtime[3] = time(changegreedy, V3, sizeV3, amount);
		lastTime = Vtime[0];
		for (int c = 1; c < 4; c++) {
			if (lastTime < Vtime[c])
				lastTime = Vtime[c];
		}
		file << amount << "," << Vtime[0] << "," << Vtime[1] << ",";
		file << Vtime[2] << "," << Vtime[3] << endl;
		amount *= 2;
	}

	// Gets timing data for changedp
	lastTime = 0;
	amount = 1;
	file << "\nCHANGEDP" << endl;
	file << "Amount, time V0, time V1, time V2, time V3" << endl;
	while (lastTime < 10000000) {
		cout << "Amount = " << amount << ", Last Time = " << lastTime << endl;
		Vtime[0] = time(changedp, V0, sizeV0, amount);
		Vtime[1] = time(changedp, V1, sizeV1, amount);
		Vtime[2] = time(changedp, V2, sizeV2, amount);
		Vtime[3] = time(changedp, V3, sizeV3, amount);
		lastTime = Vtime[0];
		for (int c = 1; c < 4; c++) {
			if (lastTime < Vtime[c])
				lastTime = Vtime[c];
		}
		file << amount << "," << Vtime[0] << "," << Vtime[1] << ",";
		file << Vtime[2] << "," << Vtime[3] << endl;
		amount *= 2;
	}

	// Additional data for question 8
	int V4[] = { 1, 2, 5, 10, 25, 50, 100, 200, 500, 1000 };
	int sizeV4 = 10;
	int A1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int sizeA1 = 15;
	int sizeA2 = 20;
	int *A2 = new(int[sizeA2]);
	for (int c = 0; c < sizeA2; c++)
		A2[c] = pow(2, c);

	// Generates data for different input sizes
	int inputSize;
	ofstream data8;
	data8.open("data8.csv");
	data8 << "CHANGES MAX SIZE OF V3 FROM DATA7" << endl;
	data8 << "CHANGESLOW" << endl;
	data8 << "Amount";
	for (int c = 1; c <= sizeV4; c++)
		data8 << "," << c;
	data8 << endl;
	for (int c = 0; c < sizeA1; c++) {
		cout << "Amount = " << c << endl;
		data8 << c;
		for (inputSize = 1; inputSize <= sizeV4; inputSize++) {
			cout << "     InputSize = " << inputSize << endl;
			data8 << "," << time(changeslow, V4, inputSize, c);
		}
		data8 << endl;
	}

	data8 << "CHANGEGREEDY" << endl;
	data8 << "Amount";
	for (int c = 1; c <= sizeV4; c++)
		data8 << "," << c;
	data8 << endl;
	for (int c = 0; c < sizeA2; c++) {
		cout << "Amount = " << c << endl;
		data8 << A2[c];
		for (inputSize = 1; inputSize <= sizeV4; inputSize++) {
			cout << "     InputSize = " << inputSize << endl;
			data8 << "," << time(changegreedy, V4, inputSize, A2[c]);
		}
		data8 << endl;
	}

	data8 << "CHANGEDP" << endl;
	data8 << "Amount";
	for (int c = 1; c <= sizeV4; c++)
		data8 << "," << c;
	data8 << endl;
	for (int c = 0; c < sizeA2; c++) {
		cout << "Amount = " << c << endl;
		data8 << A2[c];
		for (inputSize = 1; inputSize <= sizeV4; inputSize++) {
			cout << "     InputSize = " << inputSize << endl;
			data8 << "," << time(changedp, V4, inputSize, A2[c]);
		}
		data8 << endl;
	}

	return 0;
}

#elif 1
// question 6
int main() {
	int sizeV = 16;
	int *V = new(int[sizeV]);
	V[0] = 1;
	V[1] = 2;
	for (int c = 2; c < sizeV; c++)
		V[c] = V[c - 1] + 2;
	int sizeA = 202;
	int *A = new(int[sizeA]);
	A[0] = 1999;
	ofstream file;
	file.open("data6.csv");
	file << "Amount, changegreedy, changedp" << endl;
	output cs, cg, cd;
	for (int c = 1; c < sizeA; c++) {
		A[c] = A[c - 1] + 1;
		cg = changegreedy(V, sizeV, A[c]);
		cd = changedp(V, sizeV, A[c]);
		cout << A[c] << endl;
		file << A[c] << "," << cg.numCoin << "," << cd.numCoin << endl;
	}

	file << "Amount, changeslow, changegreedy, changedp" << endl;
	A[0] = 0;
	sizeA = 25;
	for (int c = 1; c < sizeA; c++) {
		A[c] = A[c - 1] + 1;
		cs = changeslow(V, sizeV, A[c]);
		cg = changegreedy(V, sizeV, A[c]);
		cd = changedp(V, sizeV, A[c]);
		cout << A[c] << endl;
		file << A[c] << "," << cs.numCoin << "," << cg.numCoin << "," << cd.numCoin << endl;
	}
	return 0;
}

#elif 1
// Question 5
int main() {
	output cs1, cg1, cd1, cs2, cg2, cd2;
	int V1[] = { 1, 2, 6, 12, 24, 48, 60 };
	int sizeV1 = 7;
	int V2[] = { 1, 6, 13, 37, 150};
	int sizeV2 = 5;
	int sizeAa = 202;
	int *Aa = new(int[sizeAa]);
	Aa[0] = 1999;
	cout << "START 5a" << endl;
	ofstream file;
	file.open("data5.csv");
	file << "Part A" << endl;
	file << "Amount, changegreedy V1, changegreedy V2, changedp V1, changedp V2" << endl;
	for (int c = 1; c < sizeAa; c++) {
		Aa[c] = Aa[c - 1] + 1;
		cout << Aa[c] << endl;
		cg1 = changegreedy(V1, sizeV1, Aa[c]);
		cg2 = changegreedy(V2, sizeV2, Aa[c]);
		cd1 = changedp(V1, sizeV1, Aa[c]);
		cd2 = changedp(V2, sizeV2, Aa[c]);
		file << Aa[c] << "," << cg1.numCoin << "," << cg2.numCoin << ",";
		file << cd1.numCoin << "," << cd2.numCoin << endl;
	}

	sizeAa = 16;
	Aa[0] = 0;
	file << endl << "Part B" << endl;
	file << "Amount, changeslow V1, changeslow V2, changegreedy V1, changegreedy V2, changedp V1, changedp V2" << endl;
	for (int c = 1; c < sizeAa; c++) {
		Aa[c] = Aa[c - 1] + 1;
		cout << Aa[c] << endl;
		cs1 = changeslow(V1, sizeV1, Aa[c]);
		cs2 = changeslow(V2, sizeV2, Aa[c]);
		cg1 = changegreedy(V1, sizeV1, Aa[c]);
		cg2 = changegreedy(V2, sizeV2, Aa[c]);
		cd1 = changedp(V1, sizeV1, Aa[c]);
		cd2 = changedp(V2, sizeV2, Aa[c]);
		file << Aa[c] << "," << cs1.numCoin << "," << cs2.numCoin;
		file << "," << cg1.numCoin << "," << cg2.numCoin << ",";
		file << cd1.numCoin << "," << cd2.numCoin << endl;
	}

	return 0;
}

#elif 1
// Question 4
int main() {
	output cs, cg, cd;

	// Question 4a
	int V4a[] = { 1, 5, 10, 25, 50 };
	int sizeA4a = 39;
	int* A4a = new(int[sizeA4a]);
	A4a[0] = 2010;
	for (int c = 1; c < sizeA4a; c++)
		A4a[c] = A4a[c - 1] + 5;
	fstream file4;
	file4.open("data4.csv", ofstream::out | ofstream::trunc);
	file4 << "Data for changegreedy and changedp" << endl;
	file4 << "Amount, Num. changegreedy, Num. changedp" << endl;
	cout << "START 4a" << endl;
	for (int c = 0; c < sizeA4a; c++) {
		cout << A4a[c] << endl;
		cg = changegreedy(V4a, 5, A4a[c]);
		cd = changedp(V4a, 5, A4a[c]);
		file4 << A4a[c] << "," << cg.numCoin << "," << cd.numCoin << endl;
	}

	// Question 4b
	sizeA4a = 18;
	A4a = new(int[sizeA4a]);
	A4a[0] = 1;
	for (int c = 1; c < sizeA4a; c++)
		A4a[c] = A4a[c - 1] + 1;
	file4 << "Data for changeslow, changegreedy and changedp" << endl;
	file4 << "Amount, Num. changeslow, Num. changegreedy, Num. changedp" << endl;
	cout << endl  << "START 4b" << endl;
	for (int c = 0; c < sizeA4a; c++) {
		cout << A4a[c] << endl;
		cs = changeslow(V4a, 5, A4a[c]);
		cg = changegreedy(V4a, 5, A4a[c]);
		cd = changedp(V4a, 5, A4a[c]);
		file4 << A4a[c] << "," << cs.numCoin << "," << cg.numCoin << "," << cd.numCoin << endl;
	}

	return 0;
}

#else
// Debugging
int main() {
	// Tests the code
	int coin1[] = { 1,2,4,8 };
	int numCoin1 = 4;
	int amount1 = 15;
	output cs1 = changeslow(coin1, numCoin1, amount1);
	cout << "Results of changeslow: " << endl;
	printOutput(amount1, coin1, numCoin1, cs1);
	cout << endl;
	output cg1 = changegreedy(coin1, numCoin1, amount1);
	cout << "Results of changegreedy: " << endl;
	printOutput(amount1, coin1, numCoin1, cg1);
	cout << endl;
	output cd1 = changedp(coin1, numCoin1, amount1);
	cout << "Results of changedp: " << endl;
	printOutput(amount1, coin1, numCoin1, cd1);
	cout << endl;

	// Tests the code
	int coin2[] = { 1, 3, 7, 12 };
	int numCoin2 = 4;
	int amount2 = 29;
	output cs2 = changeslow(coin2, numCoin2, amount2);
	cout << "Results of changeslow: " << endl;
	printOutput(amount2, coin2, numCoin2, cs2);
	cout << endl;
	output cg2 = changegreedy(coin2, numCoin2, amount2);
	cout << "Results of changegreedy: " << endl;
	printOutput(amount2, coin2, numCoin2, cg2);
	cout << endl;
	output cd2 = changedp(coin2, numCoin2, amount2);
	cout << "Results of changedp: " << endl;
	printOutput(amount2, coin2, numCoin2, cd2);
	cout << endl;

	// Tests the code
	int coin3[] = { 1, 3, 7, 12 };
	int numCoin3 = 4;
	int amount3 = 31;
	output cs3 = changeslow(coin3, numCoin3, amount3);
	cout << "Results of changeslow: " << endl;
	printOutput(amount3, coin3, numCoin3, cs3);
	cout << endl;
	output cg3 = changegreedy(coin3, numCoin3, amount3);
	cout << "Results of changegreedy: " << endl;
	printOutput(amount3, coin3, numCoin3, cg3);
	cout << endl;
	output cd3 = changedp(coin3, numCoin3, amount3);
	cout << "Results of changedp: " << endl;
	printOutput(amount3, coin3, numCoin3, cd3);
	cout << endl;

	return 0;
}
#endif // 1