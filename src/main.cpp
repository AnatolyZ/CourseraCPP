#include <iostream>
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
int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
