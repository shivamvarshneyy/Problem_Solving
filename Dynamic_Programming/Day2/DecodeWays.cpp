class Solution {
private:
    int getWays(int index, int n, string& s) {
        if(index >= n) 
        return 1;
        if(s[index] == '0') 
        return 0;
        
        int oneDigitWays = getWays(index + 1, n, s, dp);
        int twoDigitWays = 0;
        if(index + 1 < n) {
            int firstDigit = s[index] - '0';
            int secondDigit = s[index + 1] - '0';
            int combo = firstDigit * 10 + secondDigit;
            if(combo <= 26) {
                twoDigitWays = getWays(index + 2, n, s, dp);
            }
        }

        return oneDigitWays + twoDigitWays;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        return getWays(0, n, s);
    }
};