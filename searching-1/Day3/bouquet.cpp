class Solution {
public:

    int possibleBouquets(vector<int> &bloomDay, int n, int k, long long mid) {
        int bouquets=0, adjCount=0;
        for(int i=0;i<n;i++) 
        {
            if(bloomDay[i]<=mid) 
            {
                adjCount++;
            }
            else 
            {
                bouquets+=(adjCount/k);
                adjCount=0;
            }
        } 
        bouquets+=(adjCount/k);
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int n = bloomDay.size();
        if(n/k<m)
        {
            return -1;
        }
        int s=1,e=INT_MIN;
        for(auto i:bloomDay)
        {
            e=max(e,i);
        }
        long long ans=e;
        while(s<=e) {
            long long mid=s+(e-s)/2;
            int bouquets=possibleBouquets(bloomDay, n, k, mid);
            if(bouquets>=m) 
            {
                ans=min(ans,mid);
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