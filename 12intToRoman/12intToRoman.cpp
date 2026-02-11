class Solution {
public:
    string intToRoman(int num) {
        char yi[5] = {'I','X','C','M'};
        char wu[4] = {'V','L','D','U'};
        string ans;
        int digit[4], u=0;
        for(int i=0;i<4;i++)digit[i]=0;
        while(num>0){
            digit[u++] = num % 10;
            num /= 10;
        }
        int length = sizeof(digit) / sizeof(int);
        for(int i=length-1;i>=0;i--){
            if(digit[i]==0) continue;
            else if(digit[i]>5){
                if(digit[i]==9) {
                    ans+=yi[i];ans+=yi[i+1];
                }
                else{
                    ans+=wu[i];
                    int cha = digit[i]-5;
                    for(int j=cha;j>0;j--)ans+=yi[i];
                }
            }
            else{
                if(digit[i]==5) ans+=wu[i];
                else if(digit[i]==4){
                    ans+=yi[i];ans+=wu[i];
                }
                else{
                    for(int j=digit[i];j>0;j--)ans+=yi[i];
                }
            }
        }
        return ans;
    }
};