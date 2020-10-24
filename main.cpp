// Юревич Виталий М8О-207Б-19
// Вариант 2
// 
// Комплексное число в тригонометрической форме
// представляются парой действительных чисел (r, fi), где r – радиус, fi  – угол.
// Реализовать класс Complex для работы с комплексными числами. 
// Обязательно должны быть присутствовать операции:
// сложения, вычитания, умножения, деления, 
// сравнение equ, (r1, fi1) = (r2, fi2), если (r1 = r2) и (fi1 = fi2), 
// сопряженное число conj(r, fi) = (r, –fi).
// Реализовать операции сравнения по действительной части.
// Операции сложения, вычитания, умножения, деления, сравнения на равенство
// должны быть выполнены в виде перегрузки операторов. 
// Необходимо реализовать пользовательский литерал
// для работы с константами типа Complex.

#include <iostream>
#include <limits>
#include "Complex.h"

const float POSITIVE_FLOAT = 0.0;

void EnterComplex(TComplex& value) {
    bool check = true;
    int j = 1;
    float radius;
    float angle;
    while(check) {
        std::cout << "Укажите радиус: ";
        std::cin >> radius;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else if (radius < POSITIVE_FLOAT) {
            std::cout << "Ошибка ввода. Радиус не может быть отрицательным." << std::endl;
        }
        else if (FloatEqu(radius, POSITIVE_FLOAT)) {
            std::cout << "Ошибка ввода. Для нулевого радиуса, угол неопределён." << std::endl;
        }
        else {
            value.radius = radius;
            check = false;
        }
    }
    while(!check) {
        std::cout << "Укажите угол: ";
        std::cin >> angle;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Повторите ввод." << std::endl;
        }
        else {
            value.angle = angle;
            check = true;
        }
    }
    std::cout << std::endl;
}

int main() {
    TComplex ob1 = "1.324 , -0.91"_complex;;
    TComplex ob2(1.0, 0.0);
    std::cout << "Объект, созданный с помощью литерала: " << ob1 << std::endl;
    std::cout << "Введите число 1" << std::endl;
    EnterComplex(ob1);
    std::cout << "Введите число 2" << std::endl;
    EnterComplex(ob2);
    std::cout << "Число 1: " << ob1 << std::endl;
    std::cout << "Число 2: " << ob2 << std::endl;
    std::cout << "Произведение: ";
    std::cout << ob1 * ob2 << std::endl;
    std::cout << "Частное: ";
    std::cout << ob1 / ob2 << std::endl;
    std::cout << "Cумма: ";
    std::cout << ob1 + ob2 << std::endl;
    std::cout << "Разность: ";
    std::cout << ob1 - ob2 << std::endl;
    std::cout << "Отношение по действительной части: ";
    if (ob1 == ob2) {
        std::cout << ob1 << " == " << ob2 << std::endl;
    }
    else if (ob1 < ob2) {
        std::cout << ob1 << " < " << ob2 << std::endl;
    }
    else if (ob1 > ob2) {
        std::cout << ob1 << " > " << ob2 << std::endl;
    }
    if (Equ(ob1, ob2)) {
        std::cout << "Числа " << ob1 << " и " << ob2 << " равны по радиусу и углу" << std::endl;
    }
    else {
        std::cout << "Числа " << ob1 << " и " << ob2 << " НЕ равны по радиусу или углу" << std::endl;
    }

    if (Conj(ob1, ob2)) {
        std::cout << "Числа " << ob1 << " и " << ob2 << " являются споряжёнными" << std::endl;
    }
    else {
        std::cout << "Числа " << ob1 << " и " << ob2 << " НЕ являются споряжёнными" << std::endl;
    }
    return(0);
}