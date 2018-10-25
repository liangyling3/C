//input a number n, set up a table concluding all primes that <= n
#include <iostream>
#include <cmath>
using namespace std;

int main()  {
	int number;
	cin >> number;
	int *primes, *numbers;
	numbers = new int[number-1];
	for (int i = 2; i <= number; ++ i) {
		numbers[i] = i;
	}
	
	
}
