


long long modularExponentiation(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus; 
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}
