

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int sum = nums1Size + nums2Size;    // 数组总个数
    int i = 0, j = 0;           // i j - 游标
    double chosed = 0;         // 缓存每次选中的数
    double m = 0, n = 0;       // 有偶数个元素时，两个中位数的下标
    while (i + j < sum) {
        if (j == nums2Size || (i < nums1Size && nums1[i] < nums2[j])) {
            // 如果nums1[i] < nums2[j]，或者nums2已遍历完
            chosed = nums1[i];
            i++;
        } else if (j < nums2Size) {
            chosed = nums2[j];
            j++;
        }
        if (sum%2 == 0) {   // 如果有偶数个元素
            if (i+j == sum/2) {
                m = chosed;
            }
            if (i+j == sum/2 + 1) {
                n = chosed;
                return (m + n)/2;
            }
        }
        if (sum%2 == 1)     // 如果有奇数个元素
            if (i+j == sum/2 + 1)
                return chosed;
    }
    return 0;
}

/**
  1.同时遍历两个数组，遍历过程中，哪个元素小、取哪个放入chosed备用
  2.如果元素总数是偶数，取中间两个数的平均值；如果元素总数是奇数，取中间的那个元素
**/
