#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex() {}

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    void show() {
        cout << "Real part = " << real << endl;
        cout << "Imaginary part = " << imag << endl;
    }

    Complex operator+(Complex op2);

    bool operator==(Complex op2);

    bool operator>(Complex op2);

    Complex operator=(Complex op2);
};

Complex Complex::operator+(Complex op2) {
    Complex temp;
    temp.real = real + op2.real;
    temp.imag = imag + op2.imag;
    return temp;
}

bool Complex::operator==(Complex op2) {
    return (real == op2.real && imag == op2.imag);
}

bool Complex::operator>(Complex op2) {
    double mod1 = real * real + imag * imag;
    double mod2 = op2.real * op2.real + op2.imag * op2.imag;
    return mod1 > mod2;
}

Complex Complex::operator=(Complex op2) {
    real = op2.real;
    imag = op2.imag;
    return *this;
}

int main() {
    Complex a(3, 4), b(1, -2), c;

    cout << "Complex number a:" << endl;
    a.show();

    cout << "Complex number b:" << endl;
    b.show();

    c = a + b;
    cout << "Result a + b:" << endl;
    c.show();

    if (a == b)
        cout << "a = b" << endl;
    else
        cout << "a =! b" << endl;

    if (a > b)
        cout << "a > b" << endl;
    else
        cout << "a <= b" << endl;

    a = b;
    cout << "After a = b,  a:" << endl;
    a.show();

    return 0;
}