#include <string>

using namespace std;

class IntSet {
private:

	int length; 
	int defaultUpper;
	int defaultLower;

public:
	int* data;
	IntSet();
	IntSet(int, bool);
	IntSet(int, int, int, bool);
	void generate(int, int, int, bool);
	void generate(int, bool);
	bool saveToFile(string, char);
	string toString();
	//friend ostream& operator<<(ostream&, IntSet&);
};