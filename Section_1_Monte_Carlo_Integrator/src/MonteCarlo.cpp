#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <functional>

// TestFunction
using TestFunction = std::function<bool(double, double, double)>;

bool InsideUnitSphere(double x, double y, double z)
{
    return ((x*x + y*y + z*z) <= 1);
}

double IntegrateMonteCarlo3D(int n_points, double min, double max, int seed, TestFunction testPoint)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    std:: mt19937 rng_mt(seed); // Mersenne-Twister Random number generator

    // defininf a uniform distribution 
    std::uniform_real_distribution<double> uniform_dist(min, max); 

    auto random_point = std::bind(uniform_dist, std::ref(rng_mt));


    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = random_point();
        double y = random_point();
        double z = random_point();
        if(testPoint(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main(int argc, char** argv)
{
    int N_points = 1000000;  // Use a large number of points for better accuracy
    int seed = 0;  // Default seed

    // Parse command-line arguments for the seed
    if (argc > 1) {  
        seed = std::stoi(argv[1]);  // Convert input string to an integer
    }

    // Call the Monte Carlo integration function with the given seed
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, seed, InsideUnitSphere);

    // Print the estimated volume
    std::cout << "Volume estimate of sphere using " << N_points 
              << " points and seed " << seed << " = " << UnitSphereVol << std::endl;

    return 0;
}