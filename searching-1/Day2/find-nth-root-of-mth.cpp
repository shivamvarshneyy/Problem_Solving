//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
    	long long int s=0;
    	long long int e=m;
    	if(n<=0 || m<0)
    	return -1;
    	while(s<=e)
    	{
    	    long long int mid=s+(e-s)/2;
    	    if(m==pow(mid,n))
    	    {
    	        return mid;
    	    }
    	    else if(m<pow(mid,n))
    	    {
    	        e=mid-1;
    	    }
    	    else
    	    {
    	        s=mid+1;
    	    }
    	}
    	return -1;
    }  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends