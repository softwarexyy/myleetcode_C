#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows);

int main() {
    char s[] = "ABC";
    int numRows = 1;
    char *rslt = convert(s, numRows);
    printf("%s\n", rslt);

    return 0;
}

char * convert(char * s, int numRows){
    int slen = strlen(s);   // 数组总长度
    if (numRows == 1) {
        return s;
    }
    int space = 2*(numRows - 1);    // 间隔
    char *rslt = malloc(sizeof(char) * (slen+1));
    int rslt_index = 0;
    for (int i = 0; i < numRows; i++) {
        if (i == 0 || i == numRows-1) { // 第一个元素 或 最后一个元素
            for (int j = i; j < slen; j += space) {
                rslt[rslt_index++] = s[j];
            }
        } else {
            for (int x = i, y = space-i; x < slen || y < slen; x += space, y += space) {
                if (x < slen) {
                    rslt[rslt_index++] = s[x];
                }
                if (y < slen) {
                    rslt[rslt_index++] = s[y];
                }
            }
        }
    }
    rslt[rslt_index] = '\0';
    return rslt;
}
