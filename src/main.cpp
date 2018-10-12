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
		while (columns){
			int v;
			input >> v;
			cout << setw(10) << v;
			--columns;
		}
		cout << endl;
		--rows;
	}
	return 0;
}
