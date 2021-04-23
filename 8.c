#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INT_MAX     2147483647              //int值上限
#define INT_MIN     -2147483648         //int值下限

int myAtoi(char * s);

int main() {
    printf("%d\n", myAtoi("-2147483649"));

    return 0;
}

int myAtoi(char * s){
    int length = strlen(s);
    if (length == 0)
        return 0;

    int i = 0;

    // 跳过空格
    for (i = 0; i < length && s[i] == ' '; i++);

    // 跳过空格后为空串了
    if (i == length)
        return 0;

    // 跳过空格后，第一位不是+/-，也不是数字字符，则为0
    if (s[i]!='-' && s[i]!='+' && (s[i] < '0' || s[i] > '9'))
        return 0;

    // 跳过空格后，第一位是符号且第二位非数字，则为0
    if (length - i > 1 && (s[i]=='-' || s[i]=='+') && (s[i+1] < '0' || s[i+1] > '9'))
        return 0;

    // 记录正负
    int negative_flag = 1;
    if (s[i] == '-' || s[i] == '+') {
        negative_flag = (s[i] == '-') ? -1 : 1;
        i++;    // 跳过第一个+/-
    }

    // 记录数字字符串
    int j = 0;
    char *nums = malloc(sizeof(char) * (length + 1));
    for (i; i < length; i++) {
        if (s[i] <= '9' && s[i] >= '0'){    // 收录是数字的字符
            nums[j] = s[i];
            j++;
        } else {
            break;
        }
    }
    nums[j] = '\0';
    length = strlen(nums);

    // 将数字字符串转化成int
    int res = 0;
    for (int j = 0; j < length; j++) {
        int current_abs = (int)nums[j] - 48;    // 当前数字位的绝对值
        int current = negative_flag > 0 ? current_abs : -current_abs ;  //当前数字位实际值
        // 正数且即将超过最大值
        if (res > INT_MAX/10 || (res == INT_MAX/10 && current > 7)){
            free(nums);
            return INT_MAX;
        }
        if (res < INT_MIN/10 || (res == INT_MIN/10 && current < -8)){
            free(nums);
            return INT_MIN;
        }
        res = res * 10 + current;
    }
    free(nums);
    return res;
}
