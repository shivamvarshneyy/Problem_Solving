class Solution {
public:
    int helper(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (target==0)
        return 1;
        if (i<0)
        return -1e9;
        if (dp[i][target]!= -1)
        return dp[i][target];
        int take= -1e9;
        if (nums[i]<=target){
            take= 1+helper(i-1,target-nums[i],nums,dp);
        }
        int notTake= helper(i-1,target,nums,dp);
        return dp[i][target]= max(take,notTake);
    } 
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans= helper(n-1,target,nums,dp)-1;
        return max(ans,-1);
    }
};