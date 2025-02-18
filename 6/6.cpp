#include <iostream>
using namespace std;

class Date {
private:
    int month, day, year;

public:
    void getdate() {
        char s;
        cout << "Введите дату приема на работу (MM/DD/YYYY): ";
        cin >> month >> s >> day >> s >> year;
    }

    void showdate() const {
        cout << "Дата приема на работу: " << month << "/" << day << "/" << year << "\n";
    }
};

enum class Etype { LABORANT, SECRETARY, MANAGER, ENGINEER };

class Employee {
private:
    int num;
    float oclad;
    Date hireDate;
    Etype status;

public:
    void getemploy() {
        int statusInput;
        cout << "Введите номер сотрудника: ";cin >> num;
        cout << "Введите оклад сотрудника: ";cin >> oclad;
        hireDate.getdate();
        cout << "Введите статус сотрудника (0 - Лаборант, 1 - Секретарь, 2 - Менеджер, 3 - Инженер): ";cin >> statusInput;
        status = Etype(statusInput); 
    }

    void putemploy() const {
        cout << "Номер сотрудника: " << num << ", Оклад: " << oclad << "\n";
        hireDate.showdate();
        cout << "Статус сотрудника: ";
        switch (status) {
        case Etype::LABORANT: cout << "Лаборант"; break;
        case Etype::SECRETARY: cout << "Секретарь"; break;
        case Etype::MANAGER: cout << "Менеджер"; break;
        case Etype::ENGINEER: cout << "Инженер"; break;
        }
        cout << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    Employee employees[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Сотрудник " << (i + 1) << ":\n";
        employees[i].getemploy();
    }

    cout << "\nВыведенные данные:\n";
    for (int i = 0; i < 3; ++i) {
        employees[i].putemploy();
    }

    return 0;
}



