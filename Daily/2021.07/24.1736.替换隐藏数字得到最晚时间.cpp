// 1736.替换隐藏数字得到最晚时间

// 按照四种情况判断即可，注意格式是hh:mm，:也占了一位，所以表示时间的是`time[0],time[1], time[3], time[4]`

// - time[4]没有要求，最大为9
// - time[3]没有要求，最大为5
// - time[1]需要判断：如果是time[0]是2，则只能最大为3，因为一天最大23时；如果time[0]是0或1，最大为9；
// - time[0]需要看time[1]，time[1]如果小于等于3，则time[0]最大为2，否则就要最大为1


class Solution {
public:
    string maximumTime(string time) {
        //四个判断，格式为hh:mm
        if (time[4] == '?') time[4] = '9';
        if (time[3] == '?') time[3] = '5';
        if (time[1] == '?'){
            if ( time[0] == '0' || time[0] == '1')
            time[1] = '9';
            else
            time[1] = '3';
        }
        if (time[0] == '?'){
            if(time[1]=='0'||time[1]=='1'||time[1]=='2'||time[1]=='3') time[0]='2';
            else time[0]='1';
        }
        return time;
    }
};