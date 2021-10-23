// 673. 最长递增子序列的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void FindLastIndex(int index, vector<int>& nums, vector<pair<int, int>>& vecOfMaxLengthAndCnt)
    {
        unordered_multimap<int, int> mp;
        int maxLength = 1;
        for (int j = 0; j < index; j++) {
            if (nums[index] > nums[j]) {
                maxLength = max(maxLength, nums[j] + 1);
                mp.insert({ maxLength, j });
            }
        }
        int cnt = mp.count(maxLength);
        auto iter = mp.find(maxLength);
        int num = 0;
        for (int k = 0; k < cnt; k++) {
            num += vecOfMaxLengthAndCnt[iter->second].second;
            iter++;
        }
        vecOfMaxLengthAndCnt.push_back({ index, cnt > 0 ? num : 1 });
    }

    int CountNumberOfLIS(vector<pair<int, int>>& vecOfMaxLengthAndCnt)
    {
        int maxLen = 0;
        int cnt = 0;
        for (int i = 0; i < vecOfMaxLengthAndCnt.size(); i++) {
            cout << vecOfMaxLengthAndCnt[i].first << "  " << vecOfMaxLengthAndCnt[i].second << endl;
            if (vecOfMaxLengthAndCnt[i].first > maxLen) {
                maxLen = vecOfMaxLengthAndCnt[i].first;
                cnt = vecOfMaxLengthAndCnt[i].second;
            }
            else if (vecOfMaxLengthAndCnt[i].first > maxLen) {
                cnt += vecOfMaxLengthAndCnt[i].second;
            }
        }
        return cnt;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<pair<int, int>> vecOfMaxLengthAndCnt;
        vecOfMaxLengthAndCnt.push_back({ 1, 1 });
        for (int i = 1; i < sz; i++) {
            FindLastIndex(i, nums, vecOfMaxLengthAndCnt);
        }
        return CountNumberOfLIS(vecOfMaxLengthAndCnt);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
