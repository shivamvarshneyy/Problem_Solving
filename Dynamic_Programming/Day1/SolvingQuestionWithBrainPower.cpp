class Solution {
public:
long long dp[100001];
long long solve(int i, vector<vector<int>>& ques, int n){
    if(i>=ques.size()) 
    return 0;
    if(dp[i]!=-1) 
    return dp[i];
    long long take=ques[i][0]+solve(i+1+ques[i][1],ques, n); 
    long long nottake=solve(i+1,ques,n); 
    return dp[i]=max(take,nottake); 

}
    long long mostPoints(vector<vector<int>>& ques) {
        int n=ques.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,ques,n);
    }
};