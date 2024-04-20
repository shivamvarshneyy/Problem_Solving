class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt=0;
    int n=isConnected.size();
    vector<int> visited(n,0);
    for (int i = 0; i < n; i++) {
      if (visited[i]==0) 
      {
          cnt++;
          visited[i]=1;
          queue<int> q;
          q.push(i);
          while(!q.empty()){
              int t=q.front();
              q.pop();
              for (int j = 0; j < n; j++) {
                if(isConnected[t][j] ==1 && visited[j]==0) {
                    visited[j]=1;
                    q.push(j);
                }
              }
          }
      }
    }
    return cnt;
    }
};