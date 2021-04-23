#include <stdio.h>

int isPalindrome(int x);

int main() {
    printf("%d\n", isPalindrome(12321));
    return 0;
}

/**
    返回1代表是回文数字，-1代表不是回文
    leetcode中允许C语言使用bool，这里改成int
**/
int isPalindrome(int x){
    if (x < 0) {
        return -1;
    }
    if (x < 10) {
        return 1;
    }
    int bits = 1;
    for (int y = x; y/10 != 0; bits++, y/=10);
    int * nums = malloc(sizeof(int) * bits);
    for (int i = 0; i < bits; i++) {
        nums[i] = x % 10;
        x /= 10;
    }
    for (int i = 0, j = bits - 1; i<j ; i++, j--) {
        if (nums[i] != nums[j]){
            free(nums);
            return -1;
        }
    }
    free(nums);
    return 1;
}
