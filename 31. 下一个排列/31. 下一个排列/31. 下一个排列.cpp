// 31. 下一个排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int index = sz - 1;
        int lastVal = nums[index];
        bool swap = false;
        stack<int> stk;
        stk.push(index);
        index--;
        while (index >= 0) {
            int top = stk.top();
            if (nums[index] > nums[top]) {
                stk.push(index);
            }
            else {
                while (!stk.empty() && nums[top]  > nums[index]) {
                    stk.pop();
                    if (!stk.empty() && nums[stk.top()] > nums[index]) {
                        top = stk.top();
                    }
                }
                int tmp = nums[index];
                nums[index] = nums[top];
                nums[top] = tmp;
                swap = true;
                break;
            }
            index--;
        }
        if (swap) {
            sort((nums.begin() + index + 1), nums.end());
        }
        else {
            reverse(nums.begin(), nums.end());
        }

    }
};

int main()
{
    Solution slt;
    vector<int> v{ 5,1,1 };
    slt.nextPermutation(v);
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
