class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=1,minprod=1,ans=nums[0];
        for(int i=0;i<nums.size();i++){
            int tmx=maxprod,tmn=minprod;
            if(nums[i]>=0){
                maxprod=max(nums[i],tmx*nums[i]);
                minprod=min(nums[i],tmn*nums[i]);
            }
            else{
                maxprod=max(tmn*nums[i],nums[i]);
                minprod=min(tmx*nums[i],nums[i]);
            }
            ans=max(maxprod,ans);
        }
        return ans;
    }
};