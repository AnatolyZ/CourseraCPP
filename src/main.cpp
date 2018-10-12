#include <iostream>
#include <string>
#include <set>
#include <exception>
#include <map>
#include <iomanip>
using namespace std;

class Date {
public:
  Date (){
	  year = 0;
	  month = 0;
	  day = 0;
  }
  Date (int y, int m, int d){
	  year = y;
	  if (m > 0 && m < 13){
		  month = m;
	  } else {
		  throw invalid_argument("Month value is invalid: " + to_string(m));
	  }
	  if (d > 0 && d < 31){
		  day = d;
	  } else {
		  throw invalid_argument("Day value is invalid: " + to_string(d));
	  }
  }

  int GetYear() const{
	  return year;
  }
  int GetMonth() const{
	  return month;
  }
  int GetDay() const{
	  return day;
  }
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs){
	if (lhs.GetYear() < rhs.GetYear()){
		return true;
	} else if (lhs.GetYear() > rhs.GetYear()){
		return false;
	} else if (lhs.GetMonth() < rhs.GetMonth()){
		return true;
	} else if (lhs.GetMonth() > rhs.GetMonth()){
		return false;
	} else if (lhs.GetDay() < rhs.GetDay()){
		return true;
	} else return false;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  events_map[date].insert(event);
  };
  bool DeleteEvent(const Date& date, const string& event){
	  if (events_map.count(date) != 0){
		  if (events_map[date].count(event) != 0){
			  events_map[date].erase(event);
			  return true;
		  }
	  }
	  return false;
  };
  int  DeleteDate(const Date& date){
	  if (events_map.count(date) != 0){
		  unsigned int s = events_map[date].size();
		  events_map.erase(date);
		  return s;
	  }
	  return 0;
  }

  set<string> Find(const Date& date) const{
	  if (events_map.count(date) > 0){
		  return events_map.at(date);
	  } else {
		  throw invalid_argument ("Event not found");
	  }
  };
  void Print() const{
	  for (const auto& ev: events_map){
		  for (const auto& s:ev.second){
			  cout << setfill('0');
			  cout << setw(4) << ev.first.GetYear() << '-'
					<< setw(2) << ev.first.GetMonth() << '-'
					<< setw(2) << ev.first.GetDay() << ' '
					<< s << endl;
		  }
	  }
  };
private:
  map<Date,set<string>> events_map;
};

int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
	  if (command != ""){
		  stringstream cmd_stream(command);
		  string cmd;
		  cmd_stream >> cmd;
		  if (cmd == "Add"){
			  string date_str;
			  cmd_stream >> date_str;
			  stringstream date_stream(date_str);
			  int y,m,d;
			  date_stream >> y;
			  try{
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> m;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> d;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  string event;
				  cmd_stream >> event;
				  db.AddEvent({y,m,d},event);
			  } catch (invalid_argument& ia){
				  cout << ia.what() << endl;
			  }
		  } else if (cmd == "Del"){
			  string date_str;
			  cmd_stream >> date_str;
			  stringstream date_stream(date_str);
			  int y,m,d;
			  date_stream >> y;
			  try{
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> m;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> d;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  string event;
				  cmd_stream >> event;
				  if (event != ""){
					  if (db.DeleteEvent({y,m,d},event)){
						  cout << "Deleted successfully" << endl;
					  } else {
						  cout << "Event not found" << endl;
					  }
				  } else {
					  cout << "Deleted " << db.DeleteDate({y,m,d}) << " events" << endl;
				  }
			  } catch (invalid_argument& ia){
				  cout << ia.what() << endl;
			  }
		  } else if (cmd == "Find"){
			  string date_str;
			  cmd_stream >> date_str;
			  stringstream date_stream(date_str);
			  int y,m,d;
			  date_stream >> y;
			  try{
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> m;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  if (date_stream.peek() == '-'){
					  date_stream.ignore(1);
					  date_stream >> d;
				  } else throw invalid_argument("Wrong date format: " + date_str);
				  for (const auto& s:db.Find({y,m,d})){
					  cout << s << endl;
				  }
			  } catch (invalid_argument& ia){
				  cout << ia.what() << endl;
			  }
		  } else if (cmd == "Print"){
			  db.Print();
		  } else {
			  cout << "Unknown command: " << cmd << endl;
		  }
	  }
  }

  return 0;
}
