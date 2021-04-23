#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INT_MAX     2147483647              //intֵ����
#define INT_MIN     -2147483648         //intֵ����

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

    // �����ո�
    for (i = 0; i < length && s[i] == ' '; i++);

    // �����ո��Ϊ�մ���
    if (i == length)
        return 0;

    // �����ո�󣬵�һλ����+/-��Ҳ���������ַ�����Ϊ0
    if (s[i]!='-' && s[i]!='+' && (s[i] < '0' || s[i] > '9'))
        return 0;

    // �����ո�󣬵�һλ�Ƿ����ҵڶ�λ�����֣���Ϊ0
    if (length - i > 1 && (s[i]=='-' || s[i]=='+') && (s[i+1] < '0' || s[i+1] > '9'))
        return 0;

    // ��¼����
    int negative_flag = 1;
    if (s[i] == '-' || s[i] == '+') {
        negative_flag = (s[i] == '-') ? -1 : 1;
        i++;    // ������һ��+/-
    }

    // ��¼�����ַ���
    int j = 0;
    char *nums = malloc(sizeof(char) * (length + 1));
    for (i; i < length; i++) {
        if (s[i] <= '9' && s[i] >= '0'){    // ��¼�����ֵ��ַ�
            nums[j] = s[i];
            j++;
        } else {
            break;
        }
    }
    nums[j] = '\0';
    length = strlen(nums);

    // �������ַ���ת����int
    int res = 0;
    for (int j = 0; j < length; j++) {
        int current_abs = (int)nums[j] - 48;    // ��ǰ����λ�ľ���ֵ
        int current = negative_flag > 0 ? current_abs : -current_abs ;  //��ǰ����λʵ��ֵ
        // �����Ҽ����������ֵ
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
