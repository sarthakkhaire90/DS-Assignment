#include <iostream>
using namespace std;

template <typename T>
class Geek {
public:
    T x;
    T y;

    Geek(T val1, T val2) : x(val1), y(val2) {}

    void getValues() {
        cout << x << " " << y;
    }
};

int main() {
    Geek<int> intGeek(10, 20);
    Geek<double> doubleGeek(3.14, 6.28);

    intGeek.getValues();
    cout << endl;

    doubleGeek.getValues();

    return 0;
}
