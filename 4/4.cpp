#include <iostream>
using namespace std;
class employee{
private:
	int num;
	float oclad;
public:
	void Vvod(){
		cout << "Введите номер сотрудника: "; cin >> num;
		cout << "Введите оклад сотрудника: ";cin >> oclad;
	}
	void Vyvod() {
		cout << "Номер сотрудника: " << num << endl;
		cout << "Оклад сотрудника: " << oclad << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus"); 
	employee r[3]; 
	for (int i = 0; i < 3; ++i) {
		cout << "Cотрудник " << (i + 1) << ":\n";
		r[i].Vvod();
	}

	cout << "\nВыведенные данные:\n";
	for (int i = 0; i < 3; ++i) {
		r[i].Vyvod();
	}
}
