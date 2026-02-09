class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int length_ans = 0;
        string ans;
        if(length == 1) return s;
        bool flag = false;
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                flag = false;
                if(s[i] == s[j]){
                    int left = i, right = j;
                    //回文子串长度为奇数或偶数 
                    //如果是奇数，left = right；如果是偶数，left = right + 1
                    while(left < right && s[left+1] == s[right-1]){
                        left++;right--;
                    }
                    if(left == right || left == right + 1) flag = true;
                    if(flag && (j-i+1) > length_ans){
                        length_ans = j-i+1;
                        ans = "";
                        for(int u=i;u<=j;u++) ans+=s[u];
                    }
                }
            }
        }
        //针对字符串"ac"
        if(length_ans == 0){
            ans += s[0];
            return ans;
        }
        return ans;
    }
};