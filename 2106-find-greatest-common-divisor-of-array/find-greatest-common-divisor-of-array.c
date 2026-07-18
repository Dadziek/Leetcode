int findGCD(int* nums, int numsSize) {
    int min_num = nums[0];
    int max_num = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > max_num)
        {
            max_num = nums[i];
        }
        else if (nums[i] < min_num)
        {
            min_num = nums[i];
        }
    }

    while (min_num != max_num)
    {
        if (max_num > min_num)
        {
            max_num -= min_num;
        }
        else
        {
            min_num -= max_num;
        }
    }
    return max_num;
}