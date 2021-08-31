/*
有关括号问题，你只要记住以下性质，思路就很容易想出来：

1、一个「合法」括号组合的左括号数量一定等于右括号数量，这个很好理解。

2、对于一个「合法」的括号字符串组合 p，必然对于任何 0 <= i < len(p) 都有：子串 p[0..i] 中左括号的数量都大于或等于右括号的数量。

在这道回溯问题中，我们需要明确做的选择是什么，既然选择只能是'('或')'，那就不需要进行遍历，做两种选择即可
*/

class Solution {
public:
    vector<string> res; // result = []
    vector<string> generateParenthesis(int n) {        
        string track;
        backtrack(track, n, n);
        return res;
    }

    void backtrack(string &track, int left, int right){
        // left,right表示剩下的
        // 若左边剩下的多，一定不合法
        if(left > right) return ;
        // 数量小于0也不合法
        if(left < 0 || right < 0) return ;
        // 所有剩余都用完，表示找到了一条合法
        if(left == 0 && right == 0){
            res.push_back(track);
            return ;
        }
        // 尝试选择 左括号
        track.push_back('(');
        backtrack(track, left-1, right);
        track.pop_back();

        // 尝试选择 右括号
        track.push_back(')');
        backtrack(track, left, right-1);
        track.pop_back();
    }
};