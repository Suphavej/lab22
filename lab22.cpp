#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber {                
    public:
        double real;
        double imag;
        ComplexNumber(double = 0, double = 0);
        ComplexNumber operator+(const ComplexNumber &);
        ComplexNumber operator-(const ComplexNumber &);
        ComplexNumber operator*(const ComplexNumber &);
        ComplexNumber operator/(const ComplexNumber &);
        bool operator==(const ComplexNumber &);
        double abs();
        double angle();
        friend ostream& operator<<(ostream &, const ComplexNumber &);
};

ComplexNumber::ComplexNumber(double x, double y) {
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    return (real == c.real) && (imag == c.imag);
}

// Overload operators for double on left side
ComplexNumber operator+(double d, const ComplexNumber &c) {
    return ComplexNumber(d + c.real, c.imag);
}

ComplexNumber operator-(double d, const ComplexNumber &c) {
    return ComplexNumber(d - c.real, -c.imag);
}

ComplexNumber operator*(double d, const ComplexNumber &c) {
    return ComplexNumber(d * c.real, d * c.imag);
}

ComplexNumber operator/(double d, const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((d * c.real) / denominator, (-d * c.imag) / denominator);
}

bool operator==(double d, const ComplexNumber &c) {
    return (d == c.real) && (c.imag == 0);
}

double ComplexNumber::abs() {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() {
    return atan2(imag, real) * (180.0 / M_PI);
}

ostream& operator<<(ostream &out, const ComplexNumber &c) {
    if (c.imag == 0) out << c.real;
    else if (c.real == 0) out << c.imag << "i";
    else out << c.real << (c.imag > 0 ? "+" : "") << c.imag << "i";
    return out;
}
