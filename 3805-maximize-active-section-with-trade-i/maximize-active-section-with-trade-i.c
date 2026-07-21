#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

int maxActiveSectionsAfterTrade(char* s) {
    int original_ones = 0;
    int max_gain = 0;
    
    int prev_zero_block = 0;
    int curr_zero_block = 0;
    int zero_block_count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            original_ones++;
            if (curr_zero_block > 0) {
                zero_block_count++;
                if (zero_block_count >= 2) {
                    max_gain = MAX(max_gain, prev_zero_block + curr_zero_block);
                }
                prev_zero_block = curr_zero_block;
                curr_zero_block = 0;
            }
        } else {
            curr_zero_block++;
        }
    }

    if (curr_zero_block > 0) {
        zero_block_count++;
        if (zero_block_count >= 2) {
            max_gain = MAX(max_gain, prev_zero_block + curr_zero_block);
        }
    }

    if (zero_block_count < 2) {
        return original_ones;
    }

    return original_ones + max_gain;
}