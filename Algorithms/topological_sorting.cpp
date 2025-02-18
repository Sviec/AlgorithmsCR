#include "algorithms.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topsort() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<int> in_degree(N, 0);
    vector<int> order;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order.push_back(v + 1);

        for (int to : graph[v]) {
            if (--in_degree[to] == 0) {
                q.push(to);
            }
        }
    }

    if (order.size() != N) {
        cout << -1;
    }
    else {
        for (int v : order) {
            cout << v << " ";
        }
    }
}
