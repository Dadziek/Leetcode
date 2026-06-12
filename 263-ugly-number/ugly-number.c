bool isUgly(int n) {
    if(n <= 0){
        return false;
    }
    else if (n == 1){
        return true;
    }
    

    int fac = 2;

    while(fac * fac <= n){
        while(n % fac == 0){
            if(fac > 5){
                return false;
            }
            n /= fac;
        }
        if(fac > 5){
                return false;
            }
        fac++;
    }
    if(n > 5){
        return false;
    }
    return true;
}