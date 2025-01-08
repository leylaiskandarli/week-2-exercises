#include <math.h>

// Need to include the declaration of the class 
#include "Sphere.h"

// Implementations of class functions. 
// We need to tell the compiler that the functions we're implementing are part of the 
// Sphere class. We do this using "Sphere::" for each of our definitions. 
Sphere::Sphere(double r)
{
    setRadius(r);
}

void Sphere::setRadius(double r)
{
    radius = r;
    surfaceArea = calcSurfaceArea();
    volume = calcVolume();
}

double Sphere::calcSurfaceArea()
{
    return 4 * M_PI * radius * radius;
}

double Sphere::calcVolume()
{
    return 4 / 3 * M_PI * std::pow(radius, 3);
}

double Sphere::getSurfaceArea()
{
    return surfaceArea;
}

double Sphere::getVolume()
{
    return volume;
}