#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Edge{
	int source,destination,weight;
};






bool bellmanFord(int vertices, int edges, vector<Edge>& edgeList, int source) {
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (int j = 0; j < edges; ++j) {
            int u = edgeList[j].source;
            int v = edgeList[j].destination;
            int weight = edgeList[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (int j = 0; j < edges; ++j) {
        int u = edgeList[j].source;
        int v = edgeList[j].destination;
        int weight = edgeList[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            return false;
        }
    }

    for (int i = 0; i < vertices; ++i) {
        cout << "Distance to vertex " << i << ": " << distance[i] << endl;
    }
    return true;
}

int main() {
    int vertices, edges, source;
    cin >> vertices >> edges;
    vector<Edge> edgeList(edges);
    for (int i = 0; i < edges; ++i) {
        cin >> edgeList[i].source >> edgeList[i].destination >> edgeList[i].weight;
    }
    cin >> source;
    if (!bellmanFord(vertices, edges, edgeList, source)) {
        cout << "Graph contains a negative weight cycle." << endl;
    }
    return 0;
}
