/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    
    int *ans = malloc(*returnSize * sizeof(int));

    for(int i = 0; i < *returnSize; i++){
        if(i == 0){
            ans[i] = 0;
            continue;
        }
        int j = i;
        int counter = 0;
        while(j > 0){
            if((j % 2) == 1){
                counter++;
            }
            j /= 2;
        }
        ans[i] = counter;         
    }

    return ans;
}