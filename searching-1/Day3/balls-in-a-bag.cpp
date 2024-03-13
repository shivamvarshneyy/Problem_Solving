class Solution {
public:

	int minimumSize(vector<int>& nums, int maxOperations) {
		int s=1,e,ans;
        for(auto i:nums)
        {
            e=max(e,i);
        }
        ans=e;
		while(s<=e){
			int mid=s+(e-s)/2;
			int c=0;
			for(int i=0;i<nums.size();i++)
            {
				c+=(nums[i]/mid);
				if(nums[i]%mid==0)
                c--;
			}
			if(c<=maxOperations)
            {
				ans=mid;
				e=mid-1;
			}
			else
            {
				s=mid+1;
			}
		}
		return ans;
	}
};