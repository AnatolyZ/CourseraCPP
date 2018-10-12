#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	while (in){
		string line;
		getline (in,line);
		cout << line << endl;
	}
	return 0;
}
