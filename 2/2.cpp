#include <iostream>
#include <conio.h> 
using namespace std;
class tollBooth {
private:
    unsigned int carCount;
    double revenue;
public:
    // Конструктор
    tollBooth() : carCount(0), revenue(0.0) {}

    // Заплативший автомобиль
    void payingCar() {
        carCount++;
        revenue += 0.50;
    }

    // Бесплатный проезд
    void nopayCar() {
        carCount++;
    }

    // Вывод данных
    void display() const {
        std::cout << "Total cars: " << carCount << "\nTotal revenue: $" << revenue << std::endl;
    }
};

int main() {
    tollBooth booth;
    char ch;

    std::cout << "Press 'P' for paying car, 'N' for non-paying car, 'Esc' to exit\n";

    while (true) {
        ch = _getch(); // Получаем символ с клавиатуры
        if (ch == 27) break; // Если нажата ESC, выход

        if (ch == 'P' || ch == 'p')
            booth.payingCar();
        else if (ch == 'N' || ch == 'n')
            booth.nopayCar();
    }

    booth.display(); // Вывод результата
    return 0;
}

