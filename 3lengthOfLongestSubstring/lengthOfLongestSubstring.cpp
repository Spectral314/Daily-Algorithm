class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length_ans = 0;
        int length = s.length();
        if(length == 0) return 0;
        if(length == 1) return 1;
        int head = 0, tail = 1;
        while(true){
            //所有判断中考虑空格，空格是字符
            //判断新进的末尾数是否与前面的数相同
            //如此判断，只在出现重复时才更新length，而s本身就是非重复字符则不行
            for(int i=tail-1;i>=head;i--){
                if(i == tail-1 && s[tail] == s[tail-1]){
                    
                    head = tail;
                    break;
                }
                if(i!=tail-1 && s[tail] == s[i]){
                    
                    head = i+1;
                    break;
                }
            }
            length_ans = ((tail-head+1) > length_ans) ? (tail-head+1) : length_ans;
            tail++;
            if(tail > length-1) break;
        }
        return length_ans;
    }
};