#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

void factor (unsigned long long* n, unsigned long long i) {
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

    for (unsigned long long k=5; k <= sqrt(num); k+=6){
        factor(&num, k);
        factor(&num, k+2);
    }

    if (num > 2) {
        cout << num;
    }

    cout << endl;

    return 0;
}
