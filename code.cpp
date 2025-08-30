#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Dijkstra's Algorithm on NEGATED weights
    // Works for graphs where all edges have NEGATIVE weights,
    // and we want the maximum (least negative) path sum.
    unordered_map<int, int> longestPath(int n, vector<vector<int>>& edges, int src) {
        //  Build adjacency list with NEGATED weights
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, -w});  // negate weight (since original w is negative)
        }

        //  Standard Dijkstra (min-heap)
        unordered_map<int, int> dist;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [currDist, node] = minHeap.top();
            minHeap.pop();

            if (dist.find(node) != dist.end()) continue; // already finalized
            dist[node] = currDist;

            for (auto& [nbr, w] : adj[node]) {
                if (dist.find(nbr) == dist.end()) {
                    minHeap.push({currDist + w, nbr});
                }
            }
        }

        //  Restore original signs of distances
        unordered_map<int, int> result;
        for (int i = 0; i < n; i++) {
            if (dist.find(i) == dist.end()) {
                result[i] = INT_MIN; // unreachable = no path
            } else {
                result[i] = -(dist[i]); // flip sign back to original max path sum
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {
        {0,1,-5}, {0,2,-3}, {1,2,-2}, {1,3,-6}, {2,3,-7}, {3,4,-4}
    };
    int src = 0;

    auto res = sol.longestPath(n, edges, src);
    for (auto& [node, maxPath] : res) {
        cout << "Max path sum to node " << node << " = " <<-(maxPath) << endl;
    }
    return 0;
}
