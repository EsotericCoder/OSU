/*************************************************
** Title: Ant Coloney TSP
** Desc: Solves the TSP with ant coloney optimisation
** File: Implementation file
*************************************************/
// Includes the hpp (all other includes in hpp)
#include "ant.hpp"


/************************************************
** Name: Graph - File Constructor
** Desc: Builds the graph from a file
************************************************/
Graph::Graph(string fileName) {
	// Pulls the raw data
	cout << "Reading the graph from the file" << endl;
	Graph::pullRawData(fileName);

	// Sets the number of cities
	Graph::numCities = Graph::rawCity.size();

	// Calculates the distance between all cities
	cout << "Calculating the graph distances" << endl;
	Graph::setDistances();

	// Initialises the pheromone trails
	cout << "Initialising the pheromone trails" << endl;
	Graph::initPheromones();
	cout << "Finished creating the graph object" << endl;
}


/************************************************
** Name: Graph::pullRawData
** Desc: Reads and pulls the raw data from the text file
************************************************/
void Graph::pullRawData(string fileName) {
	// Opens the file
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "File failed to open" << endl;
		cout << "Input File Name is: " << fileName << endl;
		throw;
	}

	// Reads the raw data from the text file
	char *line = new char[255];
	bool foundX, foundY, indexSet, xSet;
	int index, x, y, curIndex;
	RawCity *pCity;
	while (!file.eof()) {
		// Prepares the next line (skips blank lines)
		file.getline(line, 255);

		// Skips blank lines
		if (line[0] == 0) continue;
		bool foundIndex = false, foundX = false, foundY = false;
		bool xDelim = false, yDelim = false;
		int index = 0, x = 0, y = 0;

		// Converts the string to an integer
		for (int c = 0; line[c] != '\0'; c++) {
			// Check the character is a ASCII number
			if ((line[c] >= '0') && (line[c] <= '9')) {
				// Check for the start of the index, X, Y
				if (!foundIndex) foundIndex = true;
				else if (!foundX && xDelim) foundX = true;
				else if (!foundY && yDelim) foundY = true;

				// Calculates the Y value
				if (foundY)
					y = y * 10 + line[c] - 48;
				else if (foundX)
					x = x * 10 + line[c] - 48;
				else // found Index
					index = index * 10 + line[c] - 48;
			}

			// Every other character is a delimitor
			else {
				// Sets the x delimitor as found
				if (foundIndex) xDelim = true;

				// Sets the y delimitor as found
				if (foundX) yDelim = true;
			}
		}
		

		// Saves the data into the rawCity vector
		Graph::rawCity.push_back(RawCity());
		curIndex = Graph::rawCity.size() - 1;
		Graph::rawCity[curIndex].index = index;
		Graph::rawCity[curIndex].xCoord = x;
		Graph::rawCity[curIndex].yCoord = y;
	}
	delete line;
	file.close();
}


/************************************************
** Name: Graph::~Graph()
** Desc: Destructor that frees memory
************************************************/
Graph::~Graph() {
	// Frees the distance memory
	int size = Graph::rawCity.size();
	for (int c = 0; c < size; c++)
		delete Graph::distance[c];
	delete Graph::distance;

	// Frees the pheromone memory
	for (int c = 0; c < size; c++)
		delete Graph::pheromone[c];
	delete Graph::pheromone;
}


/************************************************
** Name: Graph::setDistances()
** Desc: Calculates the distance between all cities
************************************************/
void Graph::setDistances() {
	// Creates the 2D array to save the distances into
	int size = Graph::rawCity.size();
	Graph::distance = new double*[size];
	for (int c = 0; c < size; c++)
		Graph::distance[c] = new double[size];

	// Calculates the distances
	double deltaX, deltaY;
	int dist;
	int firstIndex, secondIndex;
	for (int first = 0; first < size; first++) {
		firstIndex = Graph::rawCity[first].index;
		Graph::distance[firstIndex][firstIndex] = 0;
		for (int second = first + 1; second < size; second++) {
			secondIndex = Graph::rawCity[second].index;
			deltaX = Graph::rawCity[first].xCoord - Graph::rawCity[second].xCoord;
			deltaY = Graph::rawCity[first].yCoord - Graph::rawCity[second].yCoord;
			dist = round(sqrt(pow(deltaX, 2) + pow(deltaY, 2)));
			Graph::distance[firstIndex][secondIndex] = dist;
			Graph::distance[secondIndex][firstIndex] = dist;
		}
	}
}


/************************************************
** Name: Graph::initPheromones()
** Desc: Initialises the pheromone trails to 1
************************************************/
void Graph::initPheromones() {
	// Initialiss the pheromone variables
	int size = Graph::rawCity.size();
	double phero;
	Graph::pheromone = new double*[size];

	// Sets the pheromone
	for (int c = 0; c < size; c++) {
		Graph::pheromone[c] = new double[size];
		for (int k = 0; k < size; k++)
			pheromone[c][k] = 1 / Graph::getDistance(c, k);
	}

	// Sets the base pheromone levels
	Graph::basePheromone = Graph::sumPheromones();
}


/************************************************
** Name: Graph::sumPheromones()
** Desc: Sums the pheromone table
************************************************/
double Graph::sumPheromones() {
	int size = Graph::numCities;
	double sum = 0, phero;
	for (int c = 0; c < size; c++) {
		for (int k = 0; k < size; k++) {
			phero = Graph::pheromone[c][k];
			if (!isinf(phero))
				sum += phero;
		}
	}
	return sum;
}


/************************************************
** Name: Graph::degradePheromone()
** Desc: Degrades the pheromone trail
************************************************/
void Graph::degradePheromone() {
	// Degrades the pheromones back down to the base level
	double rho = Graph::basePheromone / Graph::sumPheromones();

	// Degrades the pheromones
	for (int c = 0; c < Graph::numCities; c++) {
		for (int k = c + 1; k < Graph::numCities; k++) {
			Graph::pheromone[c][k] *= rho;
			Graph::pheromone[k][c] *= rho;
		}
	}
}


/************************************************
** Name: Graph::addPheromone(int city1, int city2, double value)
** Desc: Adds pheromone to the trail
************************************************/
void Graph::addPheromone(int city1, int city2, double value) {
	// Multiples the value by a set factor
	value *= constant::Q;
	Graph::pheromone[city1][city2] += value;
	Graph::pheromone[city2][city1] += value;
}


/************************************************
** Name: Ant::Ant(Graph G)
** Desc: Initialises an ant on the graph
************************************************/
Ant::Ant(Graph &Graph) {
	// Sets the graph the ant is on
	int numCities = Graph.getNumCities();
	Ant::G = &Graph;

	// Sets up the ants visited city memory
	Ant::visitedCity = new bool[numCities];

	// Creates the array for the visted city order
	Ant::visitedOrder = new int[numCities + 1];

	// Creates the probability array
	Ant::numProb = new double[numCities];
}


/************************************************
** Name: Ant::~Ant()
** Desc: Destructor - Frees memory
************************************************/
Ant::~Ant() {
	delete Ant::visitedCity;
	delete Ant::visitedOrder;
	delete Ant::numProb;
}


/************************************************
** Name: Ant::setAnt()
** Desc: Sets the start city
************************************************/
void Ant::setAnt() {
	int numCities = Ant::G->getNumCities();

	// Resets all ant data
	for (int c = 0; c < numCities; c++) {
		Ant::visitedCity[c] = false;
		Ant::visitedOrder[c] = -1;
	}
	Ant::orderIndex = 0;
	Ant::tourLength = 0;
	
	// Finds and moves the ant to the start city
	Ant::moveToCity(rand() % numCities);
}


/************************************************
** Name: Ant::moveAnt()
** Desc: Sets the start city
************************************************/
void Ant::moveAnt() {
	int numCities = Ant::G->getNumCities();

	// Calculates the probabilities
	// NOTE: The denominator is the sum of the numerators
	double denomProb = 0;
	double scent_alpha, dist_beta, dist_gamma;
	int dupCoord = -1;
	bool setProbability = false;
	for (int c = 0; c < numCities; c++) {
		if (!Ant::visitedCity[c]) {
			scent_alpha = pow(Ant::G->getScent(Ant::curCity, c), constant::alpha);
			dist_beta = pow(Ant::G->getDistance(Ant::curCity, c), constant::beta);
			Ant::numProb[c] = (scent_alpha / dist_beta);
			denomProb += Ant::numProb[c];

			// Handles points that share the same cooridantes (aka infinite scent)
			if (isinf(scent_alpha))
				dupCoord = c;

			// Sets that a probability has been set
			setProbability = true;
		}
		else
			Ant::numProb[c] = 0;
	}

	// Returns the ant home if the ant has visited all the cities
	if (!setProbability) {
		Ant::tourLength += Ant::G->getDistance(Ant::curCity, Ant::visitedOrder[0]);
		return;
	}

	// Randomly generates a probabilitity value (aka 0 <= random < denomProb)
	double random = (double)rand() / RAND_MAX * denomProb;
	
	// Moves the ant to the city corresponding to rand
	double cProb = numProb[0]; // Cumulative Probability
	int city;
	for (city = 0; (cProb < random) && (city < numCities); city++)
		cProb += numProb[city + 1];

	// Overides the probabilites if two cities share cooridnates
	// The ant MUST move to the other city regardless of probabilities
	if (dupCoord != -1)
		city = dupCoord;

	// Moves the ant to the city
	Ant::tourLength += Ant::G->getDistance(Ant::curCity, city);
	Ant::moveToCity(city);
}


/************************************************
** Name: Ant::moveToCity(int city)
** Desc: Moves the ant to the city
************************************************/
void Ant::moveToCity(int city) {
	Ant::visitedCity[city] = true;
	Ant::visitedOrder[orderIndex] = city;
	orderIndex++;
	Ant::curCity = city;
}


/************************************************
** Name: Ant::addPheromone(double Q)
** Desc: Updates the pheromone trail
************************************************/
void Ant::addPheromone(double Q) {
	double amount;
	int curCity, nextCity, firstCity;
	for (int c = 0; c < Ant::G->getNumCities() - 1; c++) {
		curCity = Ant::visitedOrder[c];
		nextCity = Ant::visitedOrder[c + 1];
		amount = Q / Ant::G->getDistance(curCity, nextCity);
		Ant::G->addPheromone(curCity, nextCity, amount);
	}
	firstCity = Ant::visitedOrder[0];
	amount = Q / Ant::G->getDistance(nextCity, firstCity);
	Ant::G->addPheromone(nextCity, firstCity, amount);
}


/************************************************
** Name: Ant::printOrder()
** Desc: Prints the order the ant visited the cities
************************************************/
void Ant::printOrder() {
	for (int c = 0; c < Ant::G->getNumCities(); c++)
		cout << c << " : " << Ant::visitedOrder[c] << endl;
}


/************************************************
** Name: Ant::printProb()
** Desc: Prints the probabilities
************************************************/
void Ant::printProb() {
	for (int c = 0; c < Ant::G->getNumCities(); c++)
		cout << c << " : " << Ant::numProb[c] << endl;
}


/************************************************
** Name: Ant::printTour(string fileName)
** Desc: Prints the data to the .tour file
************************************************/
void Ant::printTour(string fileName) {
	// Opens the file
	fileName.append(".tour");
	ofstream file;
	file.open(fileName);

	// Prints the data
	file << (int)Ant::getTourLength() << endl;
	for (int c = 0; c < Ant::G->getNumCities(); c++)
		file << Ant::visitedOrder[c] << endl;

	// Closes the file
	file.close();
}


/************************************************
** Name: Ant::verifyTour(e)
** Desc: Verifies that all cities are present in the tour
** Post: True if all cities our found, else false
************************************************/
bool Ant::verifyTour() {
	// Creates the found matrix
	int size = Ant::G->getNumCities();
	bool *found = new bool[size];
	for (int c = 0; c < size; c++)
		found[c] = false;

	// Records all the cities if they are found
	int city;
	for (int c = 0; c < size; c++) {
		city = Ant::visitedOrder[c];
		if ((0 <= city) && (city < size)) // Checks for valid index
			found[city] = true;
	}

	// Returns if all the cities are found
	for (int c = 0; c < size; c++) {
		if (!found[c]) {
			cout << "INVALID TOUR FOUND" << endl;
			return false;
		}
	}
	return true;
}


/************************************************
** Name: Ant::greedyPath()
** Desc: Uses the nearest neigbour algorithm to find the path
************************************************/
void Ant::greedyPath() {
	int numCities = Ant::G->getNumCities();

	// Visits each city of the graph
	int curCity, nextCity;
	int shortDist, dist;
	int totalDist = 0;
	for (int index = 0; index < numCities - 1; index++) {
		// Gets the current city
		curCity = Ant::visitedOrder[index];

		// Finds the first city the ant hasn't visited
		nextCity = 0;
		while (Ant::visitedCity[nextCity])
			nextCity++;
		
		// Checks the nextCity index is valid
		if (nextCity >= numCities)
			throw;

		// Finds the closest city
		shortDist = Ant::G->getDistance(curCity, nextCity);
		for (int c = nextCity + 1; c < numCities; c++) {
			// Checks the ant's memory for the city
			if (!Ant::visitedCity[c]) {
				// Checks if the city is closer and swaps it
				dist = Ant::G->getDistance(curCity, c);
				if (dist < shortDist) {
					nextCity = c;
					shortDist = Ant::G->getDistance(curCity, nextCity);
				}
			}
		}

		// Moves the ant to the closest city
		totalDist += shortDist;
		Ant::moveToCity(nextCity);
	}

	// Calculates the tour length
	for (int c = 0; c < (numCities - 1); c++)
		Ant::tourLength += Ant::G->getDistance(Ant::visitedOrder[c], Ant::visitedOrder[c + 1]);
	
	// Adds the return trip home
	Ant::tourLength += Ant::G->getDistance(Ant::visitedOrder[numCities - 1], Ant::visitedOrder[0]);
}