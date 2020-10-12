/*
Student: Mikhail Gorokhov
Group: М8О-208Б-19
Github: https://github.com/MarkRevantov/oop_exercise_02

Комплексное число в алгебраической форме представляются парой действительных чисел (a, b), где a – действительная часть, b – мнимая часть. Реализовать класс Complex для работы с комплексными числами.
Обязательно должны быть присутствовать операции
-              сложения add, (a, b) + (c, d) = (a + c, b + d);
-              вычитания sub, (a, b) – (c, d) = (a – c, b – d);
-              умножения mul, (a, b) ´ (c, d) = (ac – bd, ad + bc);
-              деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2)
-              сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
-              сопряженное число conj, conj(a, b) = (a, –b). Реализовать операции сравнения модулей. 
 
Операции сложения, вычитания, умножения, деления, сравнения на равенство должны быть выполнены в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа Complex.
*/

#include <iostream>
#include "complex.cpp"

void help() {
    std::cout << "set1(set2) <real> <imaginary>\n";
    std::cout << "add1(add2) <real> <imaginary>\n";
    std::cout << "sub1(sub2) <real> <imaginary>\n";
    std::cout << "mul1(mul2) <real> <imaginary>\n";
    std::cout << "div1(div2) <real> <imaginary>\n";
    std::cout << "conj1(conj2)\n";
    std::cout << "mod1(mod2)\n";
    std::cout << "equ12\n";
    std::cout << "print1(print2)\n";
    std::cout << "add <real1> <imaginary1> <real2> <imaginary2>\n";
    std::cout << "sub <real1> <imaginary1> <real2> <imaginary2>\n";
    std::cout << "mul <real1> <imaginary1> <real2> <imaginary2>\n";
    std::cout << "div <real1> <imaginary1> <real2> <imaginary2>\n";
    std::cout << "equ <real1> <imaginary1> <real2> <imaginary2>\n";
    std::cout << "mod <real> <imaginary>\n";
    std::cout << "conj <real> <imaginary>\n\n";
    std::cout << "exit (or quit)\n";
}


int main() {
    std::cout << "Студент-программист: Михаил Горохов\nGithub: https://github.com/MarkRevantov/oop_exercise_02\n\n"; 
    help();
    std::cout << ">>> ";
    std::string cmd;

    Complex complex1(0,0);
    Complex complex2(0,0);

    double re1, im1, re2, im2;

    while (std::cin >> cmd) {
        if(cmd == "quit" || cmd == "exit") {
            break;
        }
        else if (cmd == "set1" || cmd == "set2" || cmd == "add1" || cmd == "add2" || cmd == "sub1" || cmd == "sub2" ||
                 cmd == "mul1" || cmd == "mul2" || cmd == "div2" || cmd == "conj" || cmd == "mod") {
            std::cin >> re2;
            std::cin >> im2;
            
            if(cmd == "set1") complex1.set(re2, im2);
            else if(cmd == "set2") complex2.set(re2, im2);
            else if(cmd == "add1") complex1.add(re2, im2);
            else if(cmd == "add2") complex2.add(re2, im2);
            else if(cmd == "sub1") complex1.sub(re2, im2);
            else if(cmd == "sub2") complex2.sub(re2, im2);
            else if(cmd == "mul1") complex1.mul(re2, im2);
            else if(cmd == "mul2") complex2.mul(re2, im2);
            else if(cmd == "div1") complex1.div(re2, im2);
            else if(cmd == "div2") complex2.div(re2, im2);
            else if(cmd == "conj") {
                Complex complex_tmp = Complex(re2, im2);
                complex_tmp.conj();
                std::cout << complex_tmp << std::endl;
            }
            else if(cmd == "mod") {
                std::cout << Complex(re2, im2).mod() << std::endl;
            }
        }
        else if (cmd == "conj1" || cmd == "conj2" || cmd == "equ12" || cmd == "print1" || cmd == "print2" || cmd  == "mod1" || cmd == "mod2") {
            if(cmd == "conj1") complex1.conj();
            else if(cmd == "conj2") complex2.conj();
            else if(cmd == "equ12") complex1.equ(complex2);
            else if(cmd == "print1") std::cout << complex1 << std::endl;
            else if(cmd == "print2") std::cout << complex2 << std::endl;
            else if(cmd == "mod1") std::cout << complex1.mod() << std::endl;
            else if(cmd == "mod2") std::cout << complex2.mod() << std::endl;
        }
        else if (cmd == "add" || cmd == "sub" || cmd == "mul" || cmd == "div" || cmd == "equ") {
            std::cin >> re1;
            std::cin >> im1;
            std::cin >> re2;
            std::cin >> im2;

            if(cmd == "add") std::cout << Complex(re1, im1) + Complex(re2, im2) << std::endl;
            else if(cmd == "sub") std::cout << Complex(re1, im1) - Complex(re2, im2) << std::endl;
            else if(cmd == "mul") std::cout << Complex(re1, im1) * Complex(re2, im2) << std::endl;
            else if(cmd == "div") std::cout << Complex(re1, im1) / Complex(re2, im2) << std::endl;
            else if(cmd == "equ") std::cout << (Complex(re1, im1) == Complex(re2, im2)) << std::endl;
        }

        std::cout << ">>> ";
    }
    return 0;
}