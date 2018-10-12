#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <exception>

using namespace std;

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int p, int q) {
    	if (q == 0) throw invalid_argument();
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
		if (rhs.Numerator() == 0) throw domain_error();
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
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
