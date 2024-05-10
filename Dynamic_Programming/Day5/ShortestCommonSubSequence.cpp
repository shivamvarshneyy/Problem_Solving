class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.length();
        int m = b.length();

        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i = n,j = m;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                ans += a[i-1];
                i--,j--;
            }else {

                if(dp[i][j-1]>dp[i-1][j]){
                    ans+=b[j-1];
                    j--;
                }else{
                    ans+=a[i-1];
                    i--;
                }
            }
        }
        while(i>0){
            ans+=a[i-1];
            i--;
        }
        while(j>0){
            ans+=b[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

