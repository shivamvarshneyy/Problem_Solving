class Solution {
public:
    vector<int>par;
    vector<int>rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size()+1);
        rank.resize(edges.size()+1);

        for(int i = 0 ; i < edges.size() ; i++){
            par[i] = i;
            rank[i] = 1;
        }

        for(int i = 0 ; i < edges.size() ;++i){
            int u = edges[i][0];
            int v = edges[i][1];
            bool flag = Union(u,v);
            if(flag == false)
            return edges[i];
        }
        vector<int>ans;
        return ans;
    }

    bool Union(int x,int y)
    {
        int px = find(x);
        int py = find(y);

        if(px == py)
        {
            return false;
        }

        if(rank[px] > rank[py]){
            par[py]=px;
        }
        else if(rank[px] < rank[py]){
            par[px]=py;
        }
        else{ 
            par[px] = py;
            rank[py]++;
        }
        return true;
    }

    int find(int x)
    {
        if(x == par[x])
        return x;
        int temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
};