/*************************************************
** Title: Ant Coloney TSP
** Desc: Solves the TSP with ant coloney optimisation
** File: Main running code
*************************************************/
#include "ant.hpp"
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

/************************************************
** Name: main()
** Desc: main running code
************************************************/
int main(int argc, char* argv[]) {
	// Sets up the timer
	time_t startTime = time(0);
	double totalTime =  3 * 60;
	double freshHoldTime = totalTime - 4;

	// Converts the file name input to a string
	string fileName = "";
	fileName.append(argv[1]);

	// Seeds the random number generator
	srand(4);

	// Creates the graph + pheromone trails
	Graph G(fileName);

	// Creates the ants
	Ant **pAnt = new Ant*[constant::numAnts];
	for (int c = 0; c < constant::numAnts; c++)
		pAnt[c] = new Ant(G);
	cout << "Number of ants: " << constant::numAnts << endl;

	// Sets up the bestAnt variable
	Ant *bestAnt = new Ant(G);
	Ant *temp;
	int bestIndex;
	double bestLength;

	// Solves for the best ant using the greedy algorithm
	bestAnt->setAnt();
	bestAnt->greedyPath();
	bestAnt->printTour(fileName);
	cout << "Loop: " << 0 << ", Shortest path: " << bestAnt->getTourLength();
	cout << ", Time Elapsed: " << time(0) - startTime << "s";
	cout << ", Max Time = " << totalTime << "s" << endl;

	// Solves the TSP
	int numLoops = 1000;
	int bestAntWeighting;
	int cSetBestAnt;
	bool nextLoop = true;
	int loopCount = 0;
	while (nextLoop) {
		loopCount++;
		// Each ant preforms its trail
		for (int c = 0; (c < constant::numAnts) && (nextLoop); c++) {
			// Checks the time remaining
			if (double(time(0) - startTime) > freshHoldTime)
				nextLoop = false;

			// Sets and completes the ant tour
			pAnt[c]->setAnt();
			for (int k = 0; (k < G.getNumCities()) && (nextLoop); k++)
				pAnt[c]->moveAnt();
		}

		// Add the pheromones
		for (int c = 0; (c < constant::numAnts) && (nextLoop); c++)
			pAnt[c]->addPheromone();

		// Updates the best ant
		if (nextLoop) {
			// Finds the index of the best ant
			bestIndex = -1;
			bestLength = bestAnt->getTourLength();
			for (int c = 0; c < constant::numAnts; c++) {
				if ((pAnt[c]->getTourLength() < bestLength) && (pAnt[c]->getTourLength() > 0.5 * bestLength)) {
					bestLength = pAnt[c]->getTourLength();
					bestIndex = c;
				}
			}

			// Assigns the ant as the best ant (if it is valid)
			if ((bestIndex != -1) && (pAnt[bestIndex]->verifyTour())) {
				temp = bestAnt;
				bestAnt = pAnt[bestIndex];
				pAnt[bestIndex] = temp;
				temp = 0;
			}

			// The best Ant lays down more pheromone
			bestAnt->addPheromone(constant::bestAntWeighting);

			// Degrades the trails
			G.degradePheromone();
		}

		// Prints the loop information
		std::cout << "Loop: " << loopCount << ", Shortest path: " << bestAnt->getTourLength();
		std::cout << ", Time Elapsed: " << time(0) - startTime << "s";
		std::cout << ", Max Time = " << totalTime << "s" << endl;
	}

	// Prints the results to the .tour file
	bestAnt->printTour(fileName);

	// Frees dynamic memory
	for (int c = 0; c < constant::numAnts; c++)
		delete pAnt[c];
	delete pAnt;
	delete bestAnt;
	return 0;
}