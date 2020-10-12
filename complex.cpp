#include <iostream>
#include <cmath>
//#include "complex.hpp"

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double re, double im) {
        real = re;
        imaginary = im;
    }
    void set(const Complex& complex1) {
        real = complex1.real;
        imaginary = complex1.imaginary;
    }
    void set(double re, double im) {
        real = re;
        imaginary = im;
    }
    void add(const Complex& complex1) {
        real += complex1.real;
        imaginary += complex1.imaginary;
    }
    void add(double re, double im) {
        real += re;
        imaginary += im;
    }
    void sub(const Complex& complex1) {
        real -= complex1.real;
        imaginary -= complex1.imaginary;
    }
    void sub(double re, double im) {
        real -= re;
        imaginary -= im;
    }
    void mul(const Complex& complex1) {
        double re_tmp;
        double im_tmp;

        re_tmp = real*complex1.real - imaginary*complex1.imaginary;
        im_tmp = real*complex1.imaginary + imaginary*complex1.real;

        real = re_tmp;
        imaginary = im_tmp;
    }
    void mul(double re, double im) {
        double re_tmp;
        double im_tmp;
        
        re_tmp = real*re - imaginary*im;
        im_tmp = real*im + imaginary*re;

        real = re_tmp;
        imaginary = im_tmp;
    }
    void div(const Complex& complex1) {
        double re_tmp;
        double im_tmp;

        re_tmp = (real*complex1.real + imaginary*complex1.imaginary)/(complex1.real*complex1.real + complex1.imaginary*complex1.imaginary);
        im_tmp = (imaginary*complex1.real - real*complex1.imaginary)/(complex1.real*complex1.real + complex1.imaginary*complex1.imaginary);

        real = re_tmp;
        imaginary = im_tmp;
    }
    void div(double re, double im) {
        double re_tmp;
        double im_tmp;

        re_tmp = (real*re + imaginary*im)/(re*re + im*im);
        im_tmp = (im*re - re*im)/(re*re + im*im);

        real = re_tmp;
        imaginary = im_tmp;
    }
    void conj() {
        imaginary *= -1;
    }
    double mod() {
        return sqrt(real*real + imaginary*imaginary);
    }
    bool equ(const Complex& complex1) {
        return (real == complex1.real) && (imaginary = complex1.imaginary);
    }

    const Complex operator+(const Complex& complex1) {
        Complex new_complex(*this);
        new_complex.add(complex1);
        return new_complex;
    }
    const Complex operator-(const Complex& complex1) {
        Complex new_complex(*this);
        new_complex.sub(complex1);
        return new_complex;
    }
    const Complex operator*(const Complex& complex1) {
        Complex new_complex(*this);
        new_complex.mul(complex1);
        return new_complex;
    }
    const Complex operator/(const Complex& complex1) {
        Complex new_complex(*this);
        new_complex.div(complex1);
        return new_complex;
    }
    bool operator==(const Complex& complex1) {
        return this->equ(complex1);
    }
    bool operator!=(const Complex& complex1) {
        return !(this->equ(complex1));
    }
    friend std::ostream& operator<< (std::ostream &out, const Complex &complex) {
        out << "(" << complex.real << ", " << complex.imaginary << "i)";
        return out;
    }
};