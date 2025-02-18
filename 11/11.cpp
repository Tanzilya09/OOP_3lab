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
        cout << "Введите числитель: ";cin >> num;
        cout << "Введите знаменатель: ";cin >> den;
    }

    void output() const {
        cout << num << "/" << den << endl;
    }

    Fraction add(const Fraction& other) {
        long chis = num * other.den + den * other.num;
        long znam = den * other.den;
        return Fraction(chis, znam);
    }
    Fraction subtract(const Fraction& other) {
        long chis = num * other.den - den * other.num;
        long znam = den * other.den;
        return Fraction(chis, znam);
    }
    Fraction multiply(const Fraction& other) {
        long chis = num * other.num;
        long znam = den * other.den;
        return Fraction(chis, znam);
    }
    Fraction divide(const Fraction& other) {
        if (other.num == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            exit(1);
        }
        long chis = num * other.den;
        long znam = den * other.num;
        return Fraction(chis, znam);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Fraction f1(2, 3), f2(3, 4);

    cout << "Первая дробь: ";
    f1.output();
    cout << "Вторая дробь: ";
    f2.output();

    Fraction r = f1.add(f2);
    cout << "Сумма дробей: ";
    r.output();

    r = f1.subtract(f2);
    cout << "Разность дробей: ";
    r.output();

    r = f1.multiply(f2);
    cout << "Произведение дробей: ";
    r.output();

    r = f1.divide(f2);
    cout << "Частное дробей: ";
    r.output();

    return 0;
}
