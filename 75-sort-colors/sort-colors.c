void sortColors(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[min_index] > nums[j])
            {
                min_index = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[min_index];
        nums[min_index] = temp;
    }
}