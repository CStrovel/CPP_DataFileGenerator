#include "IntSet.h"
#include <random>
#include <fstream>

using namespace std;

IntSet::IntSet() {
	this->data = new int[1];
	this->length = 1;
	this->defaultUpper = 999999999;
	this->defaultLower = 0;
}

IntSet::IntSet(int size, bool randomize) : IntSet() {
	this->generate(size, randomize);
}

IntSet::IntSet(int size, int upperValueBound, int lowerValueBound, bool randomize) : IntSet() {
	this->defaultUpper = upperValueBound;
	this->defaultLower = lowerValueBound;
	this->generate(size, randomize);
}

void IntSet::generate(int numDataPoints, int upperBound, int lowerBound, bool randomize) {
	// configure member vars for loading
	delete this->data;
	this->data = new int[numDataPoints];
	this->length = numDataPoints;

	// load data aray depending on passed params 
	for (int i = 0; i < this->length; i++) {
		if (randomize) {
			this->data[i] = rand() % (upperBound - lowerBound) + lowerBound;
		}
		else {
			this->data[i] = i + lowerBound;
		}
	}
}

void IntSet::generate(int numDataPoints, bool randomize) {
	this->generate(numDataPoints,  this->defaultUpper, this->defaultLower, randomize);
}

bool IntSet::saveToFile(string  fPath, char delimit) {
	ofstream outFile(fPath);
	if (outFile.is_open()) {
		for (int i = 0; i < this->length; i++) {
			outFile << this->data[i];
			if (i < this->length - 1) {
				outFile << delimit;
			}
		}
		outFile.close();
		return true;
	}
	return false; 
}

string IntSet::toString() {
	string rtn = "[";
	for (int i = 0; i < this->length; i++) {
		rtn += to_string(this->data[i]);
		if (i < this->length - 1) {
			rtn += ", ";
		}
	}
	rtn += ']';
	return rtn;

}

/*ostream& operator<<(ostream& out, IntSet& setOfIntegers) {
	out << setOfIntegers.toString();
	return out;
}*/