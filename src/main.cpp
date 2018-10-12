#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	string line;
	while (getline (in,line)){
		cout << line << endl;
	}
	return 0;
}
