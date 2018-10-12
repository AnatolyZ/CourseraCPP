#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    //throw invalid_argument("");
    return "12:12:12";
}

class TimeServer {
public:
    string GetCurrentTime() {
    	try {
    		LastFetchedTime = AskTimeServer();
    	} catch(system_error& serr){
    		cout << "System error";
    	}
    	return LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    // ћен€€ реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
