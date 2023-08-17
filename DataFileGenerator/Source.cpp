// Written by: Charles Strovel
// Program produces sample data sets for use with
// programs that need to load, format, and process
// data sets 
#include "IntSet.h"
#include <random>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

const string fPath = "";
const string fName = "sampleData";
const string fileExt = ".txt";
const char delimit = '\n';

int  main() {
	srand(time(NULL));
	IntSet* set1  = new IntSet(5000, 25000, 0, true);
	cout << set1->toString();
	set1->saveToFile(fPath + fName + fileExt, delimit);
}


