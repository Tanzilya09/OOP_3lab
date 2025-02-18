#include <iostream>
using namespace std;
class Int {
private:
    int value;
public:
    Int() : value(0) {}
    Int(int val) : value(val) {}

    void setZero() {
        value = 0;
    }
    void display() const {
        cout << "Value: " << value << endl;
    }

    Int add(const Int& other) const {
        return Int(value + other.value);
    }
};

int main() {
    Int num1(10), num2(20), num3;
    num3 = num1.add(num2); 
    num3.display(); 
    return 0;
}

