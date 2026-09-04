#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int firstStableIndex(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
         return -1;
    }

    int* suff_min = (int*)malloc(numsSize * sizeof(int));

    suff_min[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        suff_min[i] = MIN(suff_min[i + 1], nums[i]);
    }

    int pref_max = nums[0];
    int result = -1;

    for (int i = 0; i < numsSize; i++) {
        pref_max = MAX(pref_max, nums[i]);
        
        if (pref_max - suff_min[i] <= k) {
            result = i;
            break; 
        }
    }

    free(suff_min);
    return result;
}