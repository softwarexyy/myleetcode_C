#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INT_MAX     2147483647              //int值上限
#define INT_MIN     -2147483648         //int值下限

int reverse(int x);

int main() {
    printf("%d\n", reverse(-1234));
    return 0;
}

int reverse(int x){
    int sum = 0;
    for (x; x!= 0; x /= 10) {
        int pop = x % 10;
        if (sum > INT_MAX/10 || (sum == INT_MAX/10 && pop > 7))
            return 0;
        if (sum < INT_MIN/10 || (sum == INT_MIN/10 && pop < -8))
            return 0;
        sum = sum * 10 + pop;
    }
    return sum;
}
