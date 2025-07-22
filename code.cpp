#include <bits/stdc++.h>
using namespace std;

/**
 * Graph with weighted edges representing max packet sizes.
 * We assume an undirected network; to support directed links,
 * simply remove the second push in addEdge().
 */
class RouterNetwork {
public:
    int V;                                         // number of routers
    vector<vector<pair<int,int>>> adj;             // adj[u] = list of {neighbor, max_packet_size}

    RouterNetwork(int n) : V(n), adj(n) {}

    // add an undirected link (u <-> v) with capacity w
    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    /**
     * Compute the maximum transmissible packet size from src to dst.
     * This is the “widest path” problem: maximize min-edge-weight on path.
     * We use a max‑heap variant of Dijkstra in O(E log V).
     */
    int maxPacketSize(int src, int dst) {
        vector<int> best(V, 0);                // best[u] = maximin capacity to u
        best[src] = INT_MAX;                   // start with infinite capacity
        priority_queue<pair<int,int>> pq;      // {capacity, node}, sorted by largest capacity
        pq.push({best[src], src});

        while (!pq.empty()) {
            auto [cap, u] = pq.top(); 
            pq.pop();
            if (cap < best[u]) continue;       // stale entry
            if (u == dst) break;               // we’ve found the best for dst

            // relax all edges out of u
            for (auto [v, w] : adj[u]) {
                int via = min(best[u], w);
                if (via > best[v]) {
                    best[v] = via;
                    pq.push({best[v], v});
                }
            }
        }
        return best[dst];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    // N = number of routers; M = number of links
    cin >> N >> M;

    RouterNetwork net(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // if your input is 1‑indexed, uncomment:
        // --u; --v;
        net.addEdge(u, v, w);
    }

    int src, dst;
    cin >> src >> dst;
    // if 1‑indexed input, uncomment:
    // --src; --dst;

    int result = net.maxPacketSize(src, dst);
    if (result > 0) {
        cout << "Maximum transmissible packet size from "
             << src << " to " << dst << " = " << result << "\n";
    } else {
        cout << "No path exists between routers "
             << src << " and " << dst << "\n";
    }
    return 0;
}
