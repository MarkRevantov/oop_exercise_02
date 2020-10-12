#include <iostream>

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double real_, double imaginary_);
    void set(const Complex& complex1);
    void set(double re, double im);
    void add(const Complex& complex1);
    void add(double re, double im);
    void sub(const Complex& complex1);
    void sub(double re, double im);
    void mul(const Complex& complex1);
    void mul(double re, double im);
    void div(const Complex& complex1);
    void div(double re, double im);
    void equ(const Complex& complex1);
    void conj();

    const Complex operator+(const Complex& complex1);
    const Complex operator-(const Complex& complex1);
    const Complex operator*(const Complex& complex1);
    const Complex operator/(const Complex& complex1);
    const Complex operator==(const Complex& complex1);
    const Complex operator!=(const Complex& complex1);
    friend std::ostream& operator<< (std::ostream &out, const Complex &complex);
};