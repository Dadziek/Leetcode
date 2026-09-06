int numDistinct(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    if (m < n) return 0;

    unsigned int* dp = (unsigned int*)calloc(n + 1, sizeof(unsigned int));

    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = n; j > 0; j--) {
            if (s[i] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }

    int result = (int)dp[n];
    free(dp);
    
    return result;
}