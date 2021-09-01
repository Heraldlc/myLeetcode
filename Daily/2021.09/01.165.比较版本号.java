// 模拟题
// 学到了java的String.split函数用法，这是将字符串分割使用，注意返回值为String[]
// 学到了Integer.parseInt(String s)用法，这是将字符串转为整形计算

class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        for(int i=0; i<v1.length || i<v2.length; i++){
            int num1=0, num2=0;
            if(i < v1.length){
                num1 = Integer.parseInt(v1[i]);
            }
            if(i < v2.length){
                num2 = Integer.parseInt(v2[i]);
            }
            if(num1 > num2) return 1;
            if(num1 < num2) return -1;
            
        }
        return 0;
    }
}


class Solution {
public:
    int compareVersion(string version1, string version2) {

        int len1=version1.size(), len2=version2.size(), i=0, j=0;

        while(i<len1||j<len2){
            int num1=0, num2=0;
            while(i<len1&&version1[i]!='.'){
                num1=num1*10+version1[i++]-'0';
            }
            if(i<len1-1) ++i;//跳过上次遇到的'.' 
            //事实上可以不判断上面循环是遍历到头退出还是由于'.'造成的退出，直接自增一下也可。
            //但某种程度上，判断一下再自增可能比较安全。

            while(j<len2&&version2[j]!='.'){
                num2=num2*10+version2[j++]-'0';
            }
            if(j<len2-1) ++j;//跳过上次遇到的'.'
            //同上，这里不判断直接++j也是可以的
            
            if(num1>num2) return 1;
            else if(num1<num2) return -1;
        }
        return 0;
    }
};

