#include <iostream>
using namespace std;

class ObjectCounter {
private:
    static int count; 
    int num;         

public:
    ObjectCounter() {
        num = ++count;
    }

    void display() const {
        cout << "Мой порядковый номер: " << num << endl;
    }
};

int ObjectCounter::count = 0;

class Fraction {
private:
    int chis;
    int znam;

public:
    Fraction(int num = 0, int den = 1) : chis(num), znam(den) {}
    void input() {
        cout << "Введите дробь (формат a/b): ";cin >> chis >> znam;
    }
    void display() const {
        cout << chis << "/" << znam << endl;
    }
    static int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    Fraction simplify() const {
        int gcd = findGCD(chis, znam);
        return Fraction(znam / gcd, znam / gcd);
    }
    Fraction add(const Fraction& other) const {
        int num = chis * other.znam + other.chis * znam;
        int den = znam * other.znam;
        return Fraction(num, den).simplify();
    }
};

int main() {
    setlocale(LC_ALL, "rus"); 
    char choice;
    do {
        Fraction frac1, frac2;
        frac1.input();
        frac2.input();
        Fraction result = frac1.add(frac2);
        cout << "Сумма: ";
        result.display();
        cout << "Продолжить? (1=да/0=нет): ";
        cin >> choice;
    } while (choice == '1');

    return 0;
}

