#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {
	double x;
	while( std::cin >> x ){
		std::cout << x <<" "<< std::sin(x) <<" "<< std::cos(x) << std::endl;
	}
	return 0;
}
