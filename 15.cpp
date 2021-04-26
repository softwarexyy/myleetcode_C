#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    int numsSize = nums.size();
    sort(nums.begin(), nums.end()); // 排序
    vector<vector<int>> res;

    for (int first = 0; first < numsSize - 2; first ++) {
        if (first > 0 && nums[first] == nums[first-1]) {
            continue;
        }
        // 如果是首位元素或者 当前元素和前一个元素不相等 则当前元素有效 否则跳过当前元素直接往后走
        // 以下采用双指针
        int second = first + 1;     // second = first后一位
        int third = numsSize - 1;   // third = 末尾一位
        while(second < third) {
            if (second != first + 1 && nums[second]==nums[second-1] && second < numsSize) {
                // 如果非首元素且和上一个元素相等，则跳过
                second++;
                continue;
            }

            int sum = nums[first] + nums[second] + nums[third];
            if (sum == 0) {
                // todo：记录三个值
                res.push_back({nums[first], nums[second], nums[third]});
                printf("%d %d %d\n", nums[first], nums[second], nums[third]);
                second++;
            }
            if (sum < 0) second++;
            if (sum > 0) third--;
        }
    }
    return res;
}

int main()
{
    vector<int> vi = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(vi);

    return 0;
}

