#include <stdio.h>

int maxArea(int* height, int heightSize);

int min(int a, int b);

int main() {
    int a[] = {1,2,3,4,5};
    int asize = 5;
    printf("maxArea: %d\n", maxArea(a, asize));
    return 0;
}

int maxArea(int* height, int heightSize){
    int maxArea = 0;
    // i/j分别代表头尾双指针，往中间靠拢
    int i = 0, j = heightSize - 1;
    while(i < j) {
        int area = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
        maxArea = (area > maxArea) ? area : maxArea;
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return maxArea;
}
