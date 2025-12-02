#include<iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

Edge edges[20];
int parent[20];
int n, e;

int findParent(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionNodes(int i, int j) {
    int a = findParent(i);
    int b = findParent(j);
    parent[a] = b;
}

void sortEdges() {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
}

void kruskal() {
    int cost = 0, count = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (findParent(u) != findParent(v)) {
            cout << u << " - " << v << "  (Cost: " << w << ")\n";
            unionNodes(u, v);
            cost += w;
            count++;
        }
    }
    cout << "Total Minimum Cost: " << cost << endl;
}

int main() {
    int choice;
    do {
        cout << "\n     MENU     \n";
        cout << "1. Create Graph\n";
        cout << "2. Display MST using Kruskal’s Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                kruskal();
                break;

            case 3:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid\n";
        }
    } while (choice != 3);

    return 0;
}