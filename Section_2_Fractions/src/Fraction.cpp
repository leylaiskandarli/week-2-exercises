#include "../include/Fraction.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>


Fraction::Fraction(int a, int b) : numerator(a), denominator(b) {
    if (b == 0) {
        throw std::invalid_argument("Denominator can not be zero.");
    }
    simplify();
}

void Fraction::simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd; 

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction Fraction::reciprocal() const{
    if (numerator == 0) {
        throw std::domain_error("Can not take reciprocal of zero.");
    }
    return Fraction(denominator, numerator);
}

Fraction Fraction::multiply(int a) const{
    return Fraction(numerator*a, denominator);

} 

double Fraction::toDouble() const{
    return static_cast<double>(numerator) / denominator;
}

std::string Fraction::toString() const{
    if (numerator == 0) {
        return "0";
    }
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}