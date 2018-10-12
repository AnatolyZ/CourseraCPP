#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream input ("input.txt");
	int rows;
	input >> rows;
	int columns;
	input >> columns;

	while (rows){
		int c = columns;
		while (c){
			int v;
			input >> v;
			input.ignore(1);
			cout << setw(10) << v;
			--c;
		}
		if (--rows) cout << endl;
	}
	return 0;
}
