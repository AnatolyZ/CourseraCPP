#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	string line;
	while (getline (in,line)){
		out << line << endl;
	}
	return 0;
}
