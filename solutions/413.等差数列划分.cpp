// 问题分解
// 从等差数列的定义角度来看就是数列中相邻元素的差值。那么我们只需要记录这个差值的最大长度就可以了。

// 求定长子数组个数
// 此时问题就转换成：“给定一个长度n的等差数列，求长度大于3的子数组个数”
// 可以列举几个例子：
// n   | 3 | 4 | 5 |  6 | ……
// num | 1 | 3 | 6 | 10 | ……
// 根据数学归纳法 n 长度的 有n-2个长度为3的子序列、n-3个长度为4的子序列、……、1个长度为n的序列
// 那么结算公式 settlement = 1 + 2 + …… + n-2 = (((n-2) + 1)(n-2))/2 = (n-1)(n-2)/2
// 当 n = 1, 2时, settlement = 0, 公式仍然成立。
// 综上：settlement = ((n - 1) * (n - 2)) / 2
// 即` int settlement(int n) {return ((n - 1) * (n - 2)) / 2;} `

//  如何求长度
// 给定两个指针`left`和`right`，两者构成的窗口内是一个等差数列。`right`再向右扩的过程中检查`right+1`与公差`diff`，相等就`right++`。否则`left`来到`right`的位置，`right++`，并且更新窗口内的公差。



class Solution {
public:
    int count(int n)
    {
        return ((n-1)*(n-2))/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if( n<3) return 0;
        int left = 0, right = 1;
        int diff = nums[1] - nums[0];
        int res = 0;
        while(right+1 < n)
        {
            if(nums[right+1] - nums[right] == diff)
            {
                right++;
            }
            else
            {
                //结算个数
                res += count(right - left + 1);
                left = right;
                right = left +1;
                diff = nums[right] - nums[left];
            }
        }
        res += count(right - left +1);
        return res;
    }
};