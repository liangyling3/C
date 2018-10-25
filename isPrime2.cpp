/*找出前100个素数*/
#include <stdio.h>
#include <math.h>

int isPrime(int x, int knownPrimes[], int numberOFknownPrimes);

int main() {
	const int number = 100;
	int primes[number] = {2};
	int count = 1, i = 3;
	while (count < number) {
		if (isPrime(i, primes, count)) {
			primes[count++] = i;
		}
		i ++;
	}
	for (i = 0; i < number; ++ i) {
		printf("%d",primes[i]);
		if ((i+1)%5) printf("\t");
		else printf("\n");
	}
	return 0;
} 

int isPrime(int x, int knownPrimes[], int numberOFknownPrimes){
	int ret = 1;
	int i;
	for (i = 0; i < numberOFknownPrimes; i ++) {
		if (x % knownPrimes[i] == 0) {
			ret = 0;
			break;
		}
	}
	return ret;
}
