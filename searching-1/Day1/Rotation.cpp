//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int s=0,e=n-1;
        while(s<e){
              int mid=s+(e-s)/2;
        if (mid<e && arr[mid] > arr[mid+1]) {
            return mid + 1;
        }
        if (mid>s && arr[mid-1]>arr[mid]) {
            return mid;
        }
        if (arr[s]<=arr[mid]) {
            s=mid+1;
        } else {
            e=mid-1;
        }
        }
        return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends