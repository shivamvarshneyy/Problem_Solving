class Solution {
    private:
    int pivot(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]>=nums[0])
            {
                i=mid+1;
            }
            else
            {
                j=mid;
            }
        }
        return i;
    }
     int binarySearch(vector<int>& nums,int i,int j,int target) {
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                j=mid-1;
            }
            else
            {
                i=mid+1;
            }
        }
      return -1;
    }
public:
    int search(vector<int>& nums, int target) {
       int p=pivot(nums, target);
       int i=0,j=nums.size()-1;
       if(j==0)
       return (target==nums[0]?0:-1);
       int mid=i+(j-i)/2;
       if(target<=nums[p-1] && nums[i]<=target)
       {
           return binarySearch(nums,0,p-1,target);
       }
       else
       {
           return binarySearch(nums,p,j,target);
       }
       return 0;
    }
};