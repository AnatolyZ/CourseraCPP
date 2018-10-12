#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	string line;
	cout << setprecision(3);
	while (getline (in,line)){
		cout << line << endl;
	}
	return 0;
}
