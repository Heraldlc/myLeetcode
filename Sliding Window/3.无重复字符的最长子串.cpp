class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        //for(char c : s) need[c]++;
        
        int left = 0, right = 0;
        int res = 0;
        while(right < s.size()){
            char r = s[right];
            right++;
            window[r]++;

            while(window[r]>1){
                // result
                char l = s[left];
                left++;
                window[l]--;

            }
            res = max(res, right-left);
        }
        return res;
    }
};