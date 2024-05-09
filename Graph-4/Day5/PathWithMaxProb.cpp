class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& successProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({successProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({successProb[i], edges[i][0]});
        }
        vector<double> prob(n, 0);
        vector<int> parent(n, -1);
        priority_queue<pair<double, int>> pq;
        prob[start_node] = 1;
        pq.push({1, start_node});
        while (!pq.empty())
        {
            pair<double, int> it = pq.top();
            pq.pop();
            double pro = it.first;
            int v = it.second;
            for (auto i : adj[v])
            {
                int adjNode = i.second;
                double w = i.first;
                if (prob[adjNode] < prob[v] * w)
                {
                    prob[adjNode] = prob[v] * w;
                    parent[adjNode] = v;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return prob[end_node];
    }
};