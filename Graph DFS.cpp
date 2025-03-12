#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(int start, vector<vector<int>>& adj) {
    stack<int> s;
    vector<bool> visited(adj.size(), false);
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    DFS(0, graph); 
}
