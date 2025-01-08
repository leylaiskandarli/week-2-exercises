#pragma once

#include <string>

// Class declaration.
// This declares all the member variables and functions for this class,
// but does not give definitions for member functions. Those go inside the cpp file. 
// This is similar to the separation of declarations and implementations that we have 
// seen before in e.g. our vector functions last week. 
class Sphere
{
    public:
    // Constructor. Only constructor and destructor don't have a return type. 
    // There can be multiple constructors! 
    Sphere(double r);

    // Destructor: we actually don't need to define the destructor if it is empty like this
    // as C++ will create a default destructor for us.
    ~Sphere(){}

    // Public variable - this can be read and changed by anyone. 
    std::string colour;

    // Public function: we want people to be able to change the radius.
    // We don't let them change the variable directly, because changing the radius
    // should also the other properties like surface area and volume. 
    void setRadius(double r);

    // Public functions: get information about the sphere (SA)
    double getSurfaceArea();

    double getVolume();

    private:

    // Private functions which do internal calculations but the end user doesn't need
    double calcSurfaceArea();
    double calcVolume();

    // Private variables: these are hidden from the user so that we can ensure internal
    // consistency between radius, surface area, and volume. 
    double radius;
    double surfaceArea;
    double volume;
};