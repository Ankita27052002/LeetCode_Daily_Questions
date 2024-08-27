// LeetCode Problem 1514 : Path with Maximum Probability (Medium)

// T.C : O(E*log(V))
// S.C : O(V + E)

class Solution {
public:
  typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // sloving using Dijkstra's Aligorithm

        // making an adjacency list
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n,0);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<P> pq; // max heap

        result[start_node] = 1;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            int currNode = pq.top().second;
            double currProb = pq.top().first;

            pq.pop();

            for(auto &child : adj[currNode]){
                if(result[child.first] < currProb*child.second){
                    result[child.first] = currProb*child.second;
                    pq.push({result[child.first], child.first});
                }
            }

        }
        return result[end_node];
    }
};
