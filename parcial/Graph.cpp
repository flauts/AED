#include <vector>
#include <cmath>
using namespace std;
struct Node {
    int val;
    vector<pair<Node*,int>> next;
    Node(int val): val(val), next({}){};
};

class Graph {
    vector<Node*> nodes;
    public:
    Graph(int n, int edges[][3]) {
        for(int i = 0; i < n;i++) {
            auto node = new Node(i);
            nodes.push_back(node);
        }
        for(int i = 0; i<n ;i++) {
                int from = edges[i][0];
                int to = edges[i][1];
                int cost = edges[i][2];
                auto node = nodes[from];
                node->next.emplace_back(nodes[to],cost);
            }
        }

    void addEdge(int edge[3]) {
        int from = edge[0];
        int to = edge[1];
        int cost = edge[2];
        auto node = nodes[from];
        node->next.emplace_back(nodes[to],cost);
    }

    int shortestPath(int node1,int node2) {
        auto from = nodes[node1];
        int answer = INT_MAX;
        auto edges = from->next;
        for(int i = 0; i < edges.size();i++) {
            int next_from = edges[i].first->val;
            int cost = edges[i].second;
            if(next_from == node2) return cost;
            int s = abs(cost + shortestPath(next_from,node2));
            answer = s < answer ? s:answer;
        }
        return answer;
    }
};