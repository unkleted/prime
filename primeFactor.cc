#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

bool factor (unsigned long long* n, unsigned long long i) {
    bool found=false;
    int exp=0;
    while (*n % i == 0) {
        found = true;
        *n /= i;
        exp++;
    }
    if (found) {
        cout << i;
        if (exp > 1) {
            cout << "^" << exp;
        }
        cout << " ";
    }
    return found;
}
int main (int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <NUMBER>" << endl;
        return 1;
    }
    string s = argv[1];
    unsigned long long num = stoull(s);

    factor(&num, 2);
    factor(&num, 3);
    double root = sqrt(num);
    for (unsigned long long k=5; k <= root; k+=6){
        if ( factor(&num, k) ){
	    root = sqrt(num);
	}

	if ( factor(&num, k+2) ){
	    root = sqrt(num);
	}
    }

    if (num > 2) {
        cout << num;
    }

    cout << endl;

    return 0;
}
