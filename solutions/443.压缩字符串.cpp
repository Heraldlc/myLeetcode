class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0, write = 0;
        for(int read = 0; read < n; read++)
        {
            if(read == n-1 || chars[read] != chars[read+1])
            {
                chars[write++] = chars[read];
                int len = read - left + 1;
                // 短除法
                if(len > 1)
                {
                    int anchor = write;
                    while(len > 0){
                        chars[write++] = len % 10 + '0';
                        len /= 10;
                    }
                    reverse(&chars[anchor], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};
