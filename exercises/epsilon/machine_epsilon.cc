#include<iostream>
#include<limits>
#include<cstdio>
#include<iomanip>
#include<cmath>

int main()
{

	std::printf("%d. Machine epsilon\n", 1);

	float f = 1.0f;
	while((float) (1.0f + f) != 1.0f) {
		f /= 2.0f;
	} 
	f*= 2.0f;

	double d = 1.0;
	while((double) (1.0 + d) != 1.0) {
		d /= 2.0;
	} 
	d*=2.0;

	long double l = 1.0L;
	while((long double) (1.0L + l) != 1.0L) {
		l /= 2.0L;
	} 
	l*=2.0L;

	std::printf("float eps=%g\n", f);
	std::printf("double eps=%g\n", d);
	std::printf("long double eps=%Lg\n", l);

	std::cout << std::numeric_limits<float>::epsilon() << "\n";
	std::cout << std::numeric_limits<double>::epsilon() << "\n";
	std::cout << std::numeric_limits<long double>::epsilon() << "\n";
	
	float x;	
	x = std::pow(2, -23);

	float y;
	y = std::pow(2, -52);

	std::printf("precision for single (float): %g\n ", x);
	std::printf("precision for double: %g\n", y);

	// Non-commutativity of addition;

	std::printf("%d. Non-commutativity af addition\n", 2);

	double epsilon = std::pow(2, -52);
	double tiny = epsilon / 2;
	double a = 1 + tiny + tiny;
	double b = tiny + tiny + 1;

	std::cout << "a==b ? " << (a==b ? "true":"false") << "\n";
	std::cout << "a>1 ? " << (a>1 ? "true":"false") << "\n";
	std::cout << "b>1 ? " << (b>1 ? "true":"false") << "\n";

	std::printf("Explanation: blah blah...\n");

	std::cout << std::fixed << std::setprecision(17);

	std::cout << "           tiny = " << tiny << "\n";
	std::cout << "1 + tiny + tiny = " << a << "\n";
	std::cout << "tiny + tiny + 1 = " << b << "\n";

	std::printf("%d. Comparing doubles: introduction\n", 3);

	std::printf("d%d is a sum of %d: %d.%d\n", 1, 8, 0, 1);
	std::printf("d%d is %d times %d.%d\n", 2, 8, 0, 1);	

	double d1 = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
	double d2 = 8 * 0.1;

	std::cout << "d1 == d2? " << (d1 == d2 ? "true": "false") << "\n";

	std::cout << std::fixed << std::setprecision(17);
	std::cout << "d1 =" << d1 << "\n";
	std::cout << "d2 =" << d2 << "\n";

	std::printf("Comparing doubles: the task\n");

	// bool approx(double a, double b, double acc=1e-9, double eps=1e-9) {
		// std::cout << "|a-b|<=acc ? " << (|a-b|<=acc ? "true":"false") << "\n";
		// std::cout << "|a-b|/Max(|a|,|b|)<=eps ? " << (|a-b|/Max(|a|,|b|)<=eps ? "tr

	return 0;

}

bool approx(double a, double b, double acc=1e-9, double eps=1e-9) {
	// std::cout << "|a-b|<=acc ? " << (|a-b|<=acc ? "true":"false") << "\n";
	// std::cout << "|a-b|/Max(|a|,|b|)<=eps ? " << (|a-b|/Max(|a|,|b|)<=eps ? "true":"false") << "\n$
        
	double diff = std::abs(a - b);
	if (diff <= acc) return true; // absolute tolerance
	double max_ab = std::max(std::abs(a), std::abs(b));
	return diff <= eps * max_ab; // relative tolerance
}

