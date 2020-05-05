//
// Created by aiger on 05.05.2020.
//
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        // Р РµР°Р»РёР·СѓР№С‚Рµ РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїРѕ СѓРјРѕР»С‡Р°РЅРёСЋ
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {
        // Р РµР°Р»РёР·СѓР№С‚Рµ РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ
        if(!new_denominator)
            throw invalid_argument("Invalid argument");
        if (!new_numerator) {
            numerator = new_numerator;
            denominator = 1;
        } else {
            if ((new_numerator < 0 && new_denominator < 0) || (new_numerator > 0 && new_denominator < 0 )) {
                new_numerator = - new_numerator;
                new_denominator = - new_denominator;
            }
            int pos_numerator = abs(new_numerator);
            int pos_denominator = abs(new_denominator);
            while (pos_numerator > 0 && pos_denominator > 0) {
                if (pos_numerator > pos_denominator) {
                    pos_numerator %= pos_denominator;
                } else {
                    pos_denominator %= pos_numerator;
                }
            }
            int nod = pos_numerator + pos_denominator;
            numerator = new_numerator / nod;
            denominator = new_denominator / nod;
        }
    }
    friend const Rational operator+(const Rational &lhs, const Rational &rhs) {
        return Rational((lhs.Numerator() * rhs.Denominator()) + (lhs.Denominator()*rhs.Numerator()),(lhs.Denominator()*rhs.Denominator()));
    }

    friend const bool operator==(const Rational &lhs, const Rational &rhs) {
        return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
    }

    friend const Rational operator-(const Rational &lhs, const Rational &rhs) {
        return Rational((lhs.Numerator() * rhs.Denominator()) - (lhs.Denominator()*rhs.Numerator()),(lhs.Denominator()*rhs.Denominator()));
    }

    friend const Rational operator*(const Rational &lhs, const Rational &rhs) {
        return Rational(lhs.Numerator() * rhs.Numerator(),(lhs.Denominator()*rhs.Denominator()));
    }

    friend const Rational operator/(const Rational &lhs, const Rational &rhs) {
        if(!rhs.Numerator())
            throw domain_error("Division by zero");
        return Rational(lhs.Numerator() * rhs.Denominator(),(lhs.Denominator()*rhs.Numerator()));
    }

    friend ostream& operator<<(ostream& stream, const Rational& rat) {
        stream << rat.Numerator() << "/" << rat.Denominator();
        return stream;
    }

    friend istream& operator>>(istream& stream, Rational& rat) {
        int num = rat.Numerator(), denom = rat.Denominator();
        char del = '/';
        stream >> num;
        stream.ignore(32000 ,'/');
        if(stream >> denom)
            rat = Rational(num, denom);
        return stream;

    }
    friend bool operator<(const Rational& lhs, const Rational& rhs) {
        return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
    }

    int Numerator() const {
        // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
        return numerator;
    }

    int Denominator() const {
        // Р РµР°Р»РёР·СѓР№С‚Рµ СЌС‚РѕС‚ РјРµС‚РѕРґ
        return denominator;
    }

private:
    // Р”РѕР±Р°РІСЊС‚Рµ РїРѕР»СЏ
    int numerator;
    int denominator;
};

int main12() {
    Rational r1, r2;
    char operation;
    try{
        cin >> r1 >> operation >> r2;
        if(operation == '+')
            cout << r1 + r2 << endl;
        else if(operation == '-')
            cout << r1 - r2;
        else if (operation == '*')
            cout << r1 * r2;
        else if (operation == '/')
            cout << r1 / r2;
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    return 0;
}
