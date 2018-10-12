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

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
