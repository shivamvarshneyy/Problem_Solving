class Solution {
public:
 //solving it with recursion and memoization i.e top down approach 
    int solvemem(vector<int>&nums,int index,vector<int>&dp){
      if(index>=nums.size()){
        return 0;
      }
      if(dp[index]!=-1){
        return dp[index];
      }

     int include=nums[index]+solvemem(nums,index+2,dp);
     int exclude=0+solvemem(nums,index+1,dp);
     dp[index]=max(include,exclude);
     return dp[index];
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       int ans=solvemem(nums,0,dp);
        return ans;
    }
};


 //bottom up approach or tabulation method
 int solvebu(vector<int>&nums,int index,vector<int>&dp){
        int n=nums.size();
        dp[nums.size()-1]=nums[nums.size()-1];
        int tempans;
        for(int i=n-2;i>=0;i--){
            if(i+2>=n){
                tempans=0;
            }else{
                tempans=dp[i+2];
         }
        int include=nums[i]+tempans; int exclude=0+dp[i+1];
        dp[i]=max(include,exclude);
        }
        return dp[index];
 }
int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans=solvebu(nums,0,dp);
         return ans;
    }
};