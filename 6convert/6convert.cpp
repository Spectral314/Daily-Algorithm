class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        if(length == 1) return s;
        string ans;
        if(numRows == 1){
            for(int i=0;i<=length-1;i++) ans+=s[i];
            return ans;
        }
        int term = 2 * numRows - 2; //周期
        //第一行和第numRows行取一个数
        int cycle = length / term;
        if(length % term > 0) cycle++; //增加一轮，在之后下标超出则跳过，即增加轮数不满的部分。
        for(int i=1;i<=numRows;i++){
            for(int j=1;j<=cycle;j++){
                int biao = term*(j-1)+i-1;
                if(biao>length-1) continue;
                ans += s[biao];
                if(i>1 && i<numRows){
                    int mobiao = term*j-i+1;
                    if(mobiao>length-1) continue;
                    ans+=s[mobiao];
                }
            }
        }
        return ans;
    }
};