#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main (int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <NUMBER>" << endl;
        return 1;
    }
    string s = argv[1];
    unsigned long long num = stoull(s);

    if (num == 1) {
        cout << "One is not prime." << endl;
        return 0;
    }

    if (num % 2 == 0 && num > 2){
        cout << num << " is divisible by two." << endl;
        return 0;
    }

    if (num % 3 == 0 && num > 3) {
        cout << num << " is divisible by three." << endl;
        return 0;
    }
    
    double root =  sqrt(num);
    for (unsigned long long i=5; i <= root; i+=6) {
        if (num % i == 0) {
            cout << num << " has a factor of " << i << endl;
            return 0;
        }
        if (num % (i+2) == 0 ) {
            cout << num << " has a factor of " << i+2 << endl;
            return 0;
        }
    }

    cout << num << " is prime." << endl;
    return 0;
}
