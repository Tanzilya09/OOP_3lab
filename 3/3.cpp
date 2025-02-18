#include <iostream>
using namespace std;
class Time {
private:
    int hours, minutes, seconds;
public:
    // Конструктор по умолчанию
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор с параметрами
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Метод для вывода времени
    void display() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }

    // Метод сложения двух объектов Time
    Time add(const Time& other) const {
        int totalSec = seconds + other.seconds;
        int totalMin = minutes + other.minutes + totalSec / 60;
        int totalHours = hours + other.hours + totalMin / 60;

        return Time(totalHours % 24, totalMin % 60, totalSec % 60);
    }
};

int main() {
    Time time1(2, 45, 50), time2(3, 20, 15), result;

    result = time1.add(time2); // Сложение двух объектов
    result.display(); // Вывод результата

    return 0;
}
