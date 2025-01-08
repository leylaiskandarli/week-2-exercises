#include "Fraction.h"
#include <iostream>

int main()
{
    int a, b;
    std::cout << "Please enter two numbers (numerator and denominator) separated by a space" << std::endl;
    std::cin >> a;
    std::cin >> b;

    Fraction frac(a, b);

    std::cout << frac.toString() << " = " << frac.toDouble() << std::endl;
    
    return 0;
}