#include <iostream>
using namespace std;
class Date {
private:
	int month;
	int day;
	int year;
public:
	void Getdate() {
		char s; 
		cout << "Введите дату приема на работу (MM/DD/YYYY): ";
		cin >> month >> s >> day >> s >> year;  
	}
	void Showdate() {
		cout << "Вывод даты в формате(MM/DD/YY): "<< month <<"/"<< day <<"/"<< year <<endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");
	Date d; 
	d.Getdate();
	d.Showdate();
}

