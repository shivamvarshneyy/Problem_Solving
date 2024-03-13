#include<bits/stdc++.h>
using namespace std;
int countPainters(vector<int> &boards, int time) {
    int n=boards.size();
    int painters=1;
    long long boardsPainter=0;
    for (int i=0;i<n;i++) {
        if (boardsPainter+boards[i]<=time) {
            boardsPainter+=boards[i];
        }
        else {
            painters++;
            boardsPainter=boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0,sum=0,n=boards.size()-1;
    for(int i=0;i<=n;i++)
    {
        sum+=boards[i];
    }
    int e=sum;
    while (s<=e) {
        int mid=s+(e-s)/2;
        int painters=countPainters(boards,mid);
        if (painters > k)
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
    }
    return s;
}