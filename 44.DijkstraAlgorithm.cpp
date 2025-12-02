#include<iostream>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
};

Node* adjList[10];
int n;

void addEdge(int u, int v, int w) {
    Node* newNode = new Node();
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        adjList[i] = nullptr;

    int edges, u, v, w;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
}

int findMinVertex(int dist[], bool visited[]) {
    int min = 9999, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int src) {
    int dist[10];
    bool visited[10];
    for (int i = 0; i < n; i++) {
        dist[i] = 9999;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        Node* temp = adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!visited[v] && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
            temp = temp->next;
        }
    }

    cout << "\nShortest Distance from Source " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "To " << i << " = " << dist[i] << endl;
}

int main() {
    int choice, src;
    do {
        cout << "\n     MENU     \n";
        cout << "1. Create Graph\n";
        cout << "2. Find Shortest Paths (Dijkstra)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                cout << "Enter source vertex: ";
                cin >> src;
                dijkstra(src);
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