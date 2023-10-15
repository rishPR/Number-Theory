#include<bits/stdc++.h>
using namespace std;

vector<int> generatePrimes(int n) {
	vector<bool> isPrime(n + 1, true);
	vector<int> primes;

	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;  
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
		}
	}

	return primes;
}

int main() {
	int n;
	cout << "Enter the limit of numbers:" << endl;
	cin >> n;

	vector<int> primes = generatePrimes(n);

	cout << "Prime numbers up to " << n << ":" << endl;
	for (int prime : primes) {
		cout << prime << endl;
	}

	return 0;
}


//EXPLANATION
/*
We'll use n = 30 as an example:

Initialize the array:
We start with an array of boolean values from 2 to 30 (isPrime[2] to isPrime[30]), all initially set to true.
isPrime[] = [true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true]

Identify the first prime (2):
Since isPrime[2] is true, 2 is identified as the first prime number.
Mark multiples of 2 as not prime: isPrime[4], isPrime[6], isPrime[8], isPrime[10], isPrime[12], isPrime[14], isPrime[16], isPrime[18], isPrime[20], isPrime[22], isPrime[24], isPrime[26], isPrime[28], and isPrime[30] are set to false.
isPrime[] = [true, true, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false]

Identify the next prime (3):
Since isPrime[3] is true, 3 is identified as the next prime number.
Mark multiples of 3 as not prime: isPrime[9], isPrime[15], isPrime[21], isPrime[27] are set to false.
isPrime[] = [true, true, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false]

Identify the next prime (5):
Since isPrime[5] is true, 5 is identified as the next prime number.
Mark multiples of 5 as not prime: isPrime[25] is set to false.
isPrime[] = [true, true, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false]

Identify the next prime (7):
Since isPrime[7] is true, 7 is identified as the next prime number.
Mark multiples of 7 as not prime: isPrime[49] is out of the array bounds.
isPrime[] = [true, true, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false]

Continue the process:Continue this process until there are no more primes to identify. You'll find that the remaining true values correspond to prime numbers.

Result:The prime numbers up to 30 are 2, 3, 5, 7, 11, 13, 17, 19, 23, and 29.
*/
