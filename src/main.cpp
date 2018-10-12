#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream in("input.txt");
	double value;
	cout << fixed << setprecision(3);
	while (in >> value){
		cout << value << endl;
	}
	return 0;
}
