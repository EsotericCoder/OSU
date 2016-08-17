/*************************************************
** Title: Ant Coloney TSP
** Desc: Solves the TSP with ant coloney optimisation
** File: Header file
*************************************************/
// Sets up the HPP file
#ifndef ANTHPP
#define ANTHPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

/************************************************
** Name: Constant (namespace)
** Desc: Stores the constant values
************************************************/
namespace constant {
	const double alpha = 1;
	const double beta = 3;
	const int numAnts = 5;
	const double Q = 0.3;
	const double bestAntWeighting = 0.3 * numAnts;
}


/************************************************
** Name: RawCity
** Desc: Holds the raw data for each city
************************************************/
struct RawCity {
	int index;
	int xCoord;
	int yCoord;
};


/************************************************
** Name: Graph
** Desc: Object for the graphs
************************************************/
class Graph {
	public:
		// Constructors
		Graph() { throw; };
		Graph(string fileName);
		~Graph();

		// Public member functions
		int getNumCities() { return numCities; };
		double getDistance(int c1, int c2) { return distance[c1][c2]; };
		double getScent(int c1, int c2) { return pheromone[c1][c2]; };
		void degradePheromone();
		void addPheromone(int city1, int city2, double value);

	private:
		// Private data members
		vector<RawCity> rawCity;
		int numCities;
		double **distance;
		double **pheromone;
		double basePheromone;

		// Private member functions
		void pullRawData(string fileName);
		void setDistances();
		void initPheromones();
		double sumPheromones();
};


/************************************************
** Name: Ant
** Desc: Object for the ants
************************************************/
class Ant {
	public:
		// Constructors/ Destructor
		Ant() { throw; };
		Ant(Graph &Graph);
		~Ant();

		// Public member functions
		void setAnt();
		void moveAnt();
		void addPheromone() { addPheromone((double)1); };
		void addPheromone(double Q);
		void printOrder();
		void printProb();
		void printTour(string fileName);
		double getTourLength() { return tourLength; };
		bool verifyTour();
		void greedyPath();

	private:
		// Private data members
		Graph *G;
		int curCity;
		bool *visitedCity;
		int *visitedOrder;
		int orderIndex;
		double *numProb;
		double tourLength;
		
		// Private member functions
		void moveToCity(int city);
};
#endif // !ANTHPP