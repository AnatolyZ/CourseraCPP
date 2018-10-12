#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int p, int q) {
    	if ((p < 0 && q < 0)||(p > 0 && q < 0)){
    		p *= -1;
    		q *= -1;
    	}
    	if (p == 0) q = 1;
    	int lcd = LCD(p,q);
    	numerator = p/lcd;
    	denominator = q/lcd;
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int denominator;
    int numerator;
    int LCD (int a, int b){
    	a = abs(a);
    	b = abs(b);
		while (a > 0 && b > 0){
			if (a > b) {
				a %= b;
			}else{
				  b %= a;
			}
		}
		return a + b;
    }
};
Rational operator+(const Rational& lhs,const Rational& rhs){
    	return Rational(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(),
				lhs.Denominator()*rhs.Denominator());
    }

bool operator==(const Rational& lhs,const Rational& rhs){
	if (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator()) return true;
	return false;
}

Rational operator-(const Rational& lhs,const Rational& rhs){
    	return Rational(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(),
				lhs.Denominator()*rhs.Denominator());
    }

Rational operator/(const Rational& lhs,const Rational& rhs){
    	return Rational(lhs.Numerator() * rhs.Denominator(),
    			        lhs.Denominator() * rhs.Numerator());
    }

Rational operator*(const Rational& lhs,const Rational& rhs){
    	return Rational(lhs.Numerator() * rhs.Numerator(),
    			        lhs.Denominator() * rhs.Denominator());
    }
ostream& operator<<(ostream& outstr,const Rational& r){
	outstr << r.Numerator() << '/' << r.Denominator();
	return outstr;
}

istream& operator>>(istream& instr,Rational& r){
		int n,d;
		if (instr >> n){
			instr.ignore(1);
			if (instr >> d) r = {n,d};
		}

	return instr;
}

bool operator<(const Rational& lhs,const Rational& rhs){
    	return lhs.Numerator()*rhs.Denominator() < rhs.Numerator()*lhs.Denominator();
    }

int main() {
    {

        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
