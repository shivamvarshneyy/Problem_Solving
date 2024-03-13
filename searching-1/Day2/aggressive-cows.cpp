//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool ispossible(vector<int> &stalls,int k,int mid)
    {
        int c=1;
        int lastpos=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if((stalls[i]-lastpos)>=mid)
            {
                c++;
                if(c==k)
                return true;
                lastpos=stalls[i];
            }
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    int s=0;
    int m=-1;
    for(int i=0;i<stalls.size();i++)
    {
        m=max(m,stalls[i]);
    }
    int e=m;
    int r=-1;
    sort(stalls.begin(),stalls.end());
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(ispossible(stalls,k,mid)){
            r=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return r;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends