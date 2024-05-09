class Solution {
public:
class DSU {
    private:   
        int parent[1001];
        int rank[1001];   
    public:
        DSU(int n) {
           for(int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }

        }

        int ultparent(int node) {
            if(parent[node] == node) return node;
            return parent[node] = ultparent(parent[node]);
        }

        bool connected(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return true;
            else return false;

        }

        void unionbyrank(int node1, int node2) {
            
            int parent1 = ultparent(node1);
            int parent2 = ultparent(node2);

            if(parent1 == parent2) return;
            else {
                if(rank[parent1] < rank[parent2]) {
                    parent[parent1] = parent2;
                } else if(rank[parent1] > rank[parent2]) {
                    parent[parent2] = parent1;
                } else {
                    parent[parent1] = parent2;
                    rank[parent2]++;
                }
            }

        }

    };

    vector<bool> friendRequests(int n, vector<vector<int>>& res, vector<vector<int>>& req) {
        
        DSU graph(n);
        vector<bool>ans(req.size());

        for(int i = 0; i < req.size(); i++) {
            
            int u = req[i][0];
            int v = req[i][1];

            DSU dummyGraph(n);
            dummyGraph = graph;

            dummyGraph.unionbyrank(u, v);

            bool successful = true;


            for(int j = 0; j < res.size(); j++) {
                
                int a = res[j][0];
                int b = res[j][1];

                if(dummyGraph.connected(a, b)) {
                    successful = false;
                }
            }
            if(successful) {
                ans[i] = true;
                graph.unionbyrank(u, v);
            } else {
                ans[i] = false;
            }

        }
        return ans;
    } 
};