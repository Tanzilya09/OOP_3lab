#include <iostream>
#include <cstdlib>  
using namespace std;

class Fraction {
private:
    long num, den;
    void lowterms() {
        long tnum = abs(num);
        long tden = abs(den);
        long temp, gcd;
        if (tden == 0) {
            cout << "Недопустимый знаменатель!" << endl;
            exit(1);
        }
        else if (tnum == 0) {
            num = 0;
            den = 1;
            return;
        }
        while (tnum != 0) {
            if (tnum < tden) {
                temp = tnum;
                tnum = tden;
                tden = temp;
            }
            tnum = tnum - tden;
        }
        gcd = tden;
        num /= gcd;
        den /= gcd;
    }

public:
    Fraction(long numerator = 0, long denominator = 1) {
        num = numerator;
        den = denominator;

    }
    void input() {
        cout << "Введите числитель: "; cin >> num;
        cout << "Введите знаменатель: "; cin >> den;
    }

    void output() const {
        cout << num << "/" << den << endl;
    }
    Fraction multiply(const Fraction& other) {
        long chis = num * other.num;
        long znam = den * other.den;
        return Fraction(chis, znam);
    }

    bool ZeroAndOne() const {
        return num > 0 && num < den;
    }

    long getDenominator() const {
        return den;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    long znam;
    cout << "Введите знаменатель: ";cin >> znam;

    int s = znam - 1;
    Fraction* fractions = new Fraction[s]; 

    int index = 0;
    for (long i = 1; i < znam; ++i) {
        Fraction f(i, znam); 
        if (f.ZeroAndOne()) {
            fractions[index++] = f;
        }
    }

    for (int i = 0; i < index; ++i) {
        fractions[i].output();
        cout << "\t";
    }
    cout << endl;

    // Выводим разделитель
    for (int i = 0; i < index; ++i) {
        cout << "-------------------------------\t";
    }
    cout << endl;

    // Выводим таблицу умножения для дробей
    for (int i = 0; i < index; ++i) {
        for (int j = 0; j < index; ++j) {
            Fraction result = fractions[i].multiply(fractions[j]);
            result.output();
            cout << "\t";
        }
        cout << endl;
    }

    return 0;
}


