#include <iostream>
#include <vector>
using namespace std;

struct Student{
	string name;
	string surname;
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

int main() {
	vector<Student> students_list;
	unsigned int sn; // students number
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
	unsigned int list_size = students_list.size();
	unsigned int qn; // queries number
	cin >> qn;
	while (qn){
		string cmd;
		cin >> cmd;
		if (cmd == "name"){
			unsigned int arg;
			cin >> arg;
			if (arg == 0 || arg > list_size){
				cout << "bad request" << endl;
			}else{
				--arg;
				cout << students_list[arg].name << ' '
						<< students_list[arg].surname << endl;
			}
		}else if (cmd == "date"){
			unsigned int arg;
			cin >> arg;
			if (arg == 0 || arg > list_size){
				cout << "bad request" << endl;
			}else{
				--arg;
				cout << students_list[arg].day << '.'
						<< students_list[arg].month << '.'
						<< students_list[arg].year << endl;
			}
		}else {
			unsigned int arg;
			cin >> arg;
			cout << "bad request" << endl;
		}
		--qn;
	}
	return 0;
}
