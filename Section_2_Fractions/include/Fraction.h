#ifndef FRACTION_H
#define FRACTION_H
#pragma once
#include <string>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();

public: 

    Fraction(int a, int b);
    Fraction reciprocal() const;
    Fraction multiply(int a) const;
    double toDouble() const; 
    std::string toString() const;
};

#endif
