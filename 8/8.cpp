#include <iostream>
using namespace std;
class ObjectCounter {
private:
    static int count; 
    int num;         

public:
    ObjectCounter() {
        num = count++;
    }

    void display() const {
        cout << "Мой порядковый номер: " << num << endl;
    }
};

int ObjectCounter::count = 0;
int main() {
    setlocale(LC_ALL, "rus");
    ObjectCounter obj1, obj2, obj3;

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}


