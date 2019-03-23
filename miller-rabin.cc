// C++ program Miller-Rabin primality test
#include <iostream>
#include <gmpxx.h>
#define bint mpz_class 

using namespace std;

/* Utility function to do modular exponentiation.
 * It returns (x^y) % p */
bint power(bint base, bint exponent, bint mod) {
	bint x = 1;
	bint y = base;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			x = ( x * y ) % mod;
		y = (y * y) % mod;
		exponent = exponent / 2;
	}
	return x % mod;
}

/* This function is called for all k trials. It returns
 * false if n is composite and returns false if n is 
 * probably prime.
 * d is an odd number such that d*2<sup>r</sup> = n-1
 * for some r >= 1 */
bool millerTest(bint d, bint n) {
	// Pick a randome number in [2..n-2]
	// Corner cases make sure that n > 4
	bint a = 2 + rand() % (n - 4);

	// Compute a^d % n
	bint x = power(a, d, n);

	if (x == 1 || x == n-1)
		return true;
	/* Keep squaring x while one of the following doesn't 
	 * happen
	 * (i)	 d does not reach n-1
	 * (ii)	 (x^2) % n is not 1
	 * (iii) (x^2) % n is not n-1
	 */
	while (d != n-1) {
		x = (x*x) % n;
		d = d*2;

		if (x==1)	return false;
		if (x== n-1)	return true;
	}
	// Return composite
	return false;
}

/* It returns fales if n is composite and returns true if n
 * is probably prime. k is an input parameter that determines
 * accuracy level. Higher value of k indicates more accuracy.
 */
bool isPrime(bint n, int k) {
	// Corner cases
	if (n <= 1 || n==4)	return false;
	if (n <=3) 		return true;

	// Find r such that n= 2^d * r + 1 for some r>=1
	bint d = n - 1;
	while (d % 2 == 0)
		d = d/2;

	// Iterate given number of 'k' times
	for (int i=0; i<k; i++)
		if (millerTest(d,n) == false)
			return false;

	return true;
}

// Driver program
int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <NUMBER>" << endl;
		return 1;
	}
	string s = argv[1];
	bint num(s,10);
	int k = 20;

	if (isPrime(num, k))
		cout << num << " is prime." << endl;
	else
		cout << num << " is composite." << endl;

	return 0;
}
