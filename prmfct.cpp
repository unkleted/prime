#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void factor (unsigned long long* number, unsigned long long* n) {
        while ( *number % *n == 0) {
                cout << *n << " ";
                *number /= *n;
        }
}

int main (int argc, char* argv[]) {
        stringstream convert(argv[1]);
        unsigned long long num;
        convert >> num;
	unsigned long long j=2;

        factor(&num, &j);
	j++;
        factor(&num, &j);

	long double root = sqrt(num);

        for (unsigned long long i=5; i <= root; i+=6){
                factor(&num, &i);
		unsigned long long k=i+2;
                factor(&num, &k);
        }

        if ( num > 2 ) {
                cout << num ;
        }

        cout << endl;
        return 0;
}

