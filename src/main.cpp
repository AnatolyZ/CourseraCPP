#include <iostream>
#include <vector>
using namespace std;

struct Student{
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main() {
	vector<Student> students_list;
	int sn; // students number
	cin >> sn;
	while (sn){
		Student st;
		cin >> st.name;
		cin >> st.surname;
		cin >> st.day;
		cin >> st.month;
		cin >> st.year;
		students_list.push_back(st);
		--sn;
	}
	int qn; // queries number
	cin >> qn;
	while (qn){
		string cmd;
		if (cmd == ""){

		}else if (cmd == " "){

		}
		--qn;
	}
	return 0;
}
