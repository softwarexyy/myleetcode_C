#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b);
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 测试如何修改一维数组的长度和元素值
void changeArr(int** array, int *aSize);

int main()
{
    int *a = malloc(sizeof(int) * 5);
    for (int i=0; i<5; i++){
        a[i] = i;
    }
    int aSize = 5;

    changeArr(&a, &aSize);
    for (int i = 0; i < aSize; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
// 测试如何修改一维数组
void changeArr(int** array, int *aSize) {
    *array = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++) {
        (*array)[i] = i+10;
    }
    *aSize = 10;
}

int cmp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **res = malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;        // 行数

    qsort(nums, numsSize, sizeof(int), cmp_int);
    for (int first = 0; first < numsSize - 2; first ++) {
        if (first != 0 && nums[first] == nums[first-1])     // first去重
            continue;
        // 以下采用双指针
        int second = first + 1;     // second = first后一位
        int third = numsSize - 1;   // third = 末尾一位
        while(second < third) {
            if (second != first+1 && nums[second]==nums[second-1]) {     // second 去重
                second++;
                continue;
            }
            int sum = nums[first] + nums[second] + nums[third];
            if (sum == 0) {
                res[*returnSize] = malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[first];
                res[*returnSize][1] = nums[second];
                res[*returnSize][2] = nums[third];
                (*returnColumnSizes)[*returnSize] = 3;  // 每一个三元组中的数量
                (*returnSize)++;        // 三元组数量
                second ++;              // 探寻下一个second
            }
            else if (sum < 0) second++;
            else if (sum > 0) third --;
        }
    }
    return res;
}
