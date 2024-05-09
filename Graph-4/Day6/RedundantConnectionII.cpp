class DSU{
    private:
        vector<int>parent,size;
    public:
        DSU(int n){
            parent.resize(n + 1);
            size.resize(n + 1, 1);
            for(int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int findPar(int a){
            if(a == parent[a])
                return a;
            return parent[a] = findPar(parent[a]);
        }
        bool join(int a, int b){
            int par_a = findPar(a);
            int par_b = findPar(b);
            if(par_a == par_b)
                return false;
            parent[par_a] = par_b;
            size[par_b] += size[par_a];
            return true;
        }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int>ans;

        int ans1 = -1 , ans2 = -1;
        vector<int>indegree(n+ 1, -1);
        for(int i = 0; i < n; i++){
            if(indegree[edges[i][1]] != -1){
                ans1 = i;
                ans2 = indegree[edges[i][1]];
            }
            indegree[edges[i][1]] = i; 
        }
        for(int i =0; i < n; i++){
            if(i != ans1 && !dsu.join(edges[i][0], edges[i][1])){
                if(ans2 != -1)
                    return edges[ans2];
                return edges[i];
            }
        }
        return ans = edges[ans1];
    }
};