class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue < pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        pq.push({0, {0,0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        int trow[]={-1,0,1,0};
        int tcol[]={0,1,0,-1};
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1) return dis;
            for(int i=0;i<4;i++){
                int nrow = row+trow[i];
                int ncol = col+tcol[i];
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n){
                    int x = max(dis , abs(grid[nrow][ncol]-grid[row][col]) );
                    if(x<dist[nrow][ncol]){
                        dist[nrow][ncol]=x;
                        pq.push({x,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};