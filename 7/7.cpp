#include <iostream>
using namespace std;

class angle
{
private:
	int g;
	float m;
	char namp;
public:
    angle(int d, float m, char dir) : g(d), m(m), namp(dir) {}

    void input() {
        cout << "Введите градусы: ";cin >> g;
        cout << "Введите минуты: ";cin >> m;
        cout << "Введите направление (N, S, E, W): ";cin >> namp;
    }

    void display() const {
        cout << g << " " << m << "' " << namp << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    angle cord(149, 34.8, 'W');
    cout << "Координаты бухты Папити: ";
    cord.display(); 

    while (true) {
        angle userAngle(0, 0.0, 'N');
        cout << "Введите координаты (для выхода введите отрицательное значение градусов):\n";
        userAngle.input();
        if (userAngle.display(), cin.fail()) break;
    }

    return 0;
}

