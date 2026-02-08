#include<cmath>
#include<complex>
#include<iostream>
#include<numbers>
#include"sfuns.h"

// for first task;

using complex = std::complex<double>;
constexpr double π = 3.14159265358979324;
constexpr double E = 2.71828182845904523;
constexpr complex I = complex(0, 1);

// for second task;

namespace sfuns{
constexpr double PI = std::numbers::pi;
// constexpr double PI = 3.14159265358979323846; // pre- c++20
double fgamma(double x){
	if(x<0) return PI/std::sin(PI*x)/fgamma(1-x);
	if(x<9) return fgamma(x+1)/x;
	double lnfgamma=x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*PI/x)/2;
	return std::exp(lnfgamma);
	}
}

int main(){

	std::printf("Math exercise\n");

	std::printf("Task %d.\n", 1);

	std::cout << "sqrt(2)=" << std::sqrt(2) << "\n";
	std::cout << "2^(1/5)=" << std::pow(2, 1.0/5.0) << "\n";
	std::cout << "E^π=" << std::pow(E, π) << "\n";
	std::cout << "E^I=" << std::pow(E, I) << "\n";
	std::cout << "π^E=" << std::pow(π, E) << "\n";	

	std::cout << "π^I=" << std::pow(π, I) << "\n";
	std::cout << "E^I=" << std::pow(E, I) << "\n";
	std::cout << "I^I=" << std::pow(I, I) << "\n";
	std::cout << "log(I)=" << std::log(I) << "\n";
	
	return 0; 

}
