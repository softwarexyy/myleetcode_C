#include <stdio.h>
#include <string.h>

int romanToInt(char * s);

int main()
{
    int x = romanToInt("IV");
    printf("%d\n", x);
    return 0;
}

int romanToInt(char * s)
{
    int sum = 0;
    int length = strlen(s);
    char *romans[6] = {"CM", "CD", "XC", "XL", "IX", "IV"};
    int nums[6] = {900, 400, 90, 40, 9, 4};
    char romans2[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int nums2[7] = {1000, 500, 100, 50, 10, 5, 1};
    int i = 0;
    while (i < length) {
        int step = 1;
        int j = 0, k = 0;
        for (j = 0; j < 6; j++) {   // 匹配两位罗马
            char temp[3];
            strncpy(temp, s+i, 2);
            temp[2] = '\0';
            if (strcmp(temp, romans[j]) == 0) {
                sum += nums[j];
                step = 2;
                break;
            }
        }
        if (step != 2) {
            for (k = 0; k < 7; k++) {   // 匹配一位罗马
                if (s[i] == romans2[k]) {
                    sum += nums2[k];
                    step = 1;
                }
            }
        }
        i += step;
    }
    return sum;
}
