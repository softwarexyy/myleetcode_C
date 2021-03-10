int lengthOfLongestSubstring(char * s){
    int length = 0;
    int max = 0;

    // 给定字符串
    char *p1 = s;
    char *p2 = s;

    int times[128] = {0};   // 初始化数组

    while (*p2 != '\0') {
        length++;
        times[(int)*p2]++ ;
        if (times[(int)*p2] > 1) {       // 当p2所指的字符已经出现过
            max = (length-1) > max ? length-1 : max; // 更新最大值
            while (times[(int)*p2] > 1) {   // 将p1一直移动到 p1p2之间没有重复字符 为止
                times[(int)*p1]--;
                p1++;
                length--;
            }
        }
        p2++;
    }
    max = length>max ? length : max;

    return max;
}

/**
1、用数组记录每个字符出现的次数，数组下标是各个字符，例如 times['A']可用来记录字符A出现的次数
2、移动p1和p2，让它们分别指向 不重复字符的最大子串的 首尾位置
3、当p2指向的字符出现次数>1（times[(int)*p2] > 1）的时候，p1后移、使p1p2范围变短，一直到该字符出现次数变成1为止（说明串中不包含重复字符）
*/
