#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main (int argc, char* argv[])
{
	stringstream convert(argv[1]);
	unsigned long long num;
	convert >> num;
	if (num == 1) 
	{
		cout << "1 is not prime.\n";
		return 0;
	}
	if (num > 2 && num % 2 == 0)
	{
		cout << "Even numbers larger than 2 are not prime\n";
		return 0;
	}	
	if (num > 3 && num % 3 == 0)
	{
		cout << num << " is divisible by 3\n";
		return 0;
	}
	for (long k=1; (36*k*k-12*k) <= num; ++k)
	{
		if (num % (6*k-1) == 0 || num % (6*k+1) == 0)
		{
			cout << num << " has a factor when K is " << k << endl;
			return 0;
		}
	}
	cout << num << " must be prime.\n";
	return 0;
}