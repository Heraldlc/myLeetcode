/*
双指针相向而行即可
*/

class Solution {
public:
    bool isVowel(char ch)
    {
        string vowelArray = "aeiouAEIOU";
        if (vowelArray.find(ch) != string::npos) return true;
        else return false;
    }
    
    string reverseVowels(string s) {
        int n = s.size();
        if(n==1) return s;
        int left = 0, right = n-1;
        while(left<right)
        {
            while(left<n && !isVowel(s[left])) left++;
            while(right>0 && !isVowel(s[right])) right--;
            // swap
            if(left < right)
            {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }

        }
        return s;
    }
};

