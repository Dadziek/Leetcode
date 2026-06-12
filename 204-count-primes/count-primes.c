int countPrimes(int n) {
    if(n == 0 || n == 1){
        return 0;
    }

    int *tab = malloc(n * sizeof(int));

    if(tab == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    tab[0] = tab[1] = 0;

    for(int i = 2; i < n; i++){
        tab[i] = 1;
    }

    for(int i = 2; i < n; i ++){
        if(tab[i] == 1){
            for(int j = i+i; j < n; j+=i){
                tab[j] = 0;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += tab[i];
    }

    free(tab);
    tab = NULL;

    return sum;
}