#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s);

int expand(char *s, int left, int right);

char *fetch_mem(int size_char);

int main()
{
//    char s[] = "aaaaaaaaaaaaaaaa";
//    printf("%s\n", longestPalindrome(s));
    printf("%s\n", fetch_mem(4));
    return 0;
}

char *fetch_mem(int size_char) {
    char *mem = malloc(sizeof(char) * size_char);
    memset(mem, '0', size_char - 1);
    mem[size_char - 1] = '\0';
    return mem;
}


char * longestPalindrome(char * s)
{
    if (strlen(s) == 0) {
        return "";
    }
    int i = 0, start = 0, end = 0;  // start是开始下标，end是结束下标的下一个
    for (i = 0; i < strlen(s); i++) {
        int len1 = expand(s, i, i + 1);   // 两个元素为中心
        int len2 = expand(s, i, i);     // 单个元素为中心
        int len = len1 > len2 ? len1 : len2;
        if(len > end - start) { // 更新头尾值
            start = i - (len - 1)/2;
            end = i + len/2 + 1;
        }
    }
    char *dest = malloc(sizeof(char) * (end - start + 1));
    strncpy(dest, s + start, end - start);
    dest[end-start]='\0';
    return dest;
}

// 向两端扩展
int expand(char *s, int left, int right)
{
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;    // 长度
}
