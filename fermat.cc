#include <iostream>
#include <gmpxx.h>
#define bigint mpz_class

using namespace std;

bigint power( bigint base, bigint exponent, bigint mod) {
	bigint x=1;
	bigint y = base;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			x = (x*y) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

bool isPrime(bigint n, int k) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	while (k>0) {
		bigint a = 2 + rand() % (n - 4);
//		bigint a = rand();
		//cout << a << endl;

		if (power(a, n-1, n) != 1)
			return false;
		k--;
	}
	return true;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <NUMBER" << endl;
		return 1;
	}	
	string s = argv[1];
	bigint num(s, 10);
	int k = 20;

	if (isPrime(num, k)) 
		cout << num << " is prime!" << endl;
	else 
		cout << num << " is NOT prime :(" << endl;

	return 0;
}

