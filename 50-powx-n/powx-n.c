double fastPow(double x, long long n) {
    if (n == 0) {
        return 1.0;
    }
    
    if (n < 0) {
        return 1.0 / fastPow(x, -n);
    }
    
    double temp = fastPow(x, n / 2);
    
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}

double myPow(double x, int n) {
    return fastPow(x, (long long)n);
}