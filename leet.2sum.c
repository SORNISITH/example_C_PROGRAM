#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 5
#define TARGET -8

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(int argc, char* argv[])
{
    int num[SIZE] = { -1, -2, -3, -4, -5 };
    int rSize;
    int* x = twoSum(num, SIZE, TARGET, &rSize);

    printf("%d-", x[0]);
    printf("%d", x[1]);
    free(x);
    return EXIT_SUCCESS;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* re = malloc(2 * sizeof(int));
    int* p = nums;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize && j != i; j++) {
            if (*p > target) {
                i++;
                j++;
                p++;
            }
            if ((nums[i]) + (nums[j]) == target) {
                *re = i;
                *(re + 1) = j;
                *returnSize = 2;
                return re;
            }
        }
    }
    return re;
}
