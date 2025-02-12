#include "algorithms.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Компоненты связности

Дан неориентированный невзвешенный граф, состоящий из N вершин и M ребер. Необходимо посчитать количество его компонент связности и вывести их.

Напомним:

Компонента связности в неориентированном графе - это подмножество вершин, таких что все вершины достижимы друг из друга.

Формат ввода
Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны 
по два числа i и j (1 ≤ i, j ≤ N), которые означают, что вершины i и j соединены ребром.

Формат вывода
В первой строчке выходного файла выведите количество компонент связности. Далее выведите сами компоненты связности в следующем формате: 
в первой строке количество вершин в компоненте, во второй - сами вершины в произвольном порядке.
*/

void dfs(const vector<vector<int>>& graph, int v, vector<bool>& visited, vector<int>& component) {
    visited[v] = true;
    component.push_back(v + 1);
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, component);
        }
    }
}

void connectivity_component() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);
    vector<vector<int>> components;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N; ++i) {
        if (visited[i] == false) {
            vector<int> temp_component;
            dfs(graph, i, visited, temp_component);
            components.push_back(temp_component);
        }
    }

    cout << components.size() << endl;
    for (vector<int> component : components) {
        cout << component.size() << endl;
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}