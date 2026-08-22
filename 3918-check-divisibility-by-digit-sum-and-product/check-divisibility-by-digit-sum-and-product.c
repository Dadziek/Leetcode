bool checkDivisibility(int n) {
    int sum = 0;
    int product = 1;
    
    int temp = n;
    while (n > 0){
        int digit = n % 10;

        sum += digit;

        if (product != 0){
            product *= digit;
        }

        n /= 10;
    }

    int divisor = sum + product;

    if (divisor == 0){
        return false;
    }

    return temp % divisor == 0;
}