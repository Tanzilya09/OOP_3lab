#include <iostream>
#include <string>
using namespace std;

class angle {
private:
    int g;
    float m;
    char namp;
public:
    angle() : g(0), m(0.0), namp('N') {}  

    void input() {
        cout << "Введите градусы: "; cin >> g;
        cout << "Введите минуты: "; cin >> m;
        cout << "Введите направление (N, S, E, W): "; cin >> namp;
    }

    void display() const {
        cout << g << " " << m << "' " << namp;
    }
};

class Ship {
private:
    static int count;
    int shipN;
    angle shirot;
    angle dolg;

public:
    Ship() {
        shipN = ++count;
    }

    void inputShip() {
        cout << "Корабль №" << shipN << endl;
        cout << "Введите широту:\n";
        shirot.input(); 
        cout << "Введите долготу:\n";
        dolg.input();  
    }

    void displayShip() const {
        cout << "Корабль №" << shipN << " расположен по координатам: ";
        shirot.display();
        cout << ", ";
        dolg.display();
        cout << endl;
    }
};

int Ship::count = 0;

int main() {
    setlocale(LC_ALL, "rus");
    Ship ships[3];

    for (int i = 0; i < 3; i++) {
        ships[i].inputShip();
    }

    cout << "\nИнформация о кораблях:\n";
    for (int i = 0; i < 3; i++) {
        ships[i].displayShip();
    }

    return 0;
}
