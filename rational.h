#pragma once
#include <iostream>
#include <ciso646>
class rational
{
    int num;
    int den;
    int gcd(int a, int b)
    {
        int tmp;
        while (b != 0)
        {
            tmp = b;
            a = a % b;
            b = a;
            a = tmp;
        }
        return (a >= 0) ? a : -a;
    }
public:
    // Конструкторы
    rational(); // По-умолчанию
    rational(int num_, int den_); // Параметрический
    rational(const int& a); // Преобразования
    rational(const rational& another); // Копирования
    //
    // Сложение
    friend rational operator+(const rational& a, const rational& b); // Базовое сложение
    friend rational& operator++(rational& a); // Префиксный инкремент
    friend rational operator++(rational& a, int); // Постфиксный инкремент
    rational& operator+=(const rational& another);
    //
    // Вычитание
    friend rational operator-(const rational& a, const rational& b); // Базовое вычитание
    friend rational& operator--(rational& a); // Префиксный декремент
    friend rational operator--(rational& a, int); // Постфиксный декремент
    rational& operator-=(const rational& a);
    friend rational& operator-(rational& a); // Минус
    //
    // Умножение
    friend rational operator*(const rational& a, const rational& b); // Базовое умножение
    rational& operator*=(const rational& another);
    //
    // Деление
    friend rational operator/(const rational& a, const rational& b); // Базовое деление
    rational& operator/=(const rational& another);
    //
    // Присваивание
    rational& operator=(const rational& another);
    //
    // Сравнение
    friend bool operator==(const rational& lhs, const rational& rhs); // ==
    friend bool operator!=(const rational& lhs, const rational& rhs); // !=
    friend bool operator>(const rational& lhs, const rational& rhs); // >
    friend bool operator<(const rational& lhs, const rational& rhs); // <
    friend bool operator>=(const rational& lhs, const rational& rhs); // >=
    friend bool operator<=(const rational& lhs, const rational& rhs); // <=
    //
    // Перегрузка побитового сдвига (вывод в консоль)
    friend std::ostream& operator<<(std::ostream& os, const rational& another);
};
