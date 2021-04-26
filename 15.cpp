#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
    int numsSize = nums.size();
    sort(nums.begin(), nums.end()); // ����
    vector<vector<int>> res;

    for (int first = 0; first < numsSize - 2; first ++) {
        if (first > 0 && nums[first] == nums[first-1]) {
            continue;
        }
        // �������λԪ�ػ��� ��ǰԪ�غ�ǰһ��Ԫ�ز���� ��ǰԪ����Ч ����������ǰԪ��ֱ��������
        // ���²���˫ָ��
        int second = first + 1;     // second = first��һλ
        int third = numsSize - 1;   // third = ĩβһλ
        while(second < third) {
            if (second != first + 1 && nums[second]==nums[second-1] && second < numsSize) {
                // �������Ԫ���Һ���һ��Ԫ����ȣ�������
                second++;
                continue;
            }

            int sum = nums[first] + nums[second] + nums[third];
            if (sum == 0) {
                // todo����¼����ֵ
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

