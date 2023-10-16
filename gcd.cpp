#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a = 24, b = 18;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}
/*
The Euclidean algorithm is an ancient and efficient method for finding the Greatest Common Divisor (GCD) of two integers. The GCD is the largest positive integer that divides both numbers without leaving a remainder. The algorithm is based on the observation that the GCD of two numbers is the same as the GCD of the smaller number and the remainder of the division of the larger number by the smaller number. This process is repeated until the remainder becomes zero, at which point the GCD is found.
*/
