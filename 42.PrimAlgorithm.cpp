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

    Node* newNode2 = new Node();
    newNode2->vertex = u;
    newNode2->weight = w;
    newNode2->next = adjList[v];
    adjList[v] = newNode2;
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
    }
}

int findMinVertex(int cost[], bool visited[]) {
    int min = 9999, vertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[i] < min) {
            min = cost[i];
            vertex = i;
        }
    }
    return vertex;
}

void primMST() {
    int parent[10], cost[10];
    bool visited[10];

    for (int i = 0; i < n; i++) {
        cost[i] = 9999;
        visited[i] = false;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cost[start] = 0;
    parent[start] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = findMinVertex(cost, visited);
        visited[u] = true;

        Node* temp = adjList[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            int w = temp->weight;
            if (!visited[v] && w < cost[v]) {
                cost[v] = w;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    int total = 0;
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "  (Cost: " << cost[i] << ")\n";
            total += cost[i];
        }
    }
    cout << "Total Minimum Cost: " << total << endl;
}

int main() {
    int choice;
    do {
        cout << "\n     MENU     \n";
        cout << "1. Create Graph\n";
        cout << "2. Display MST using Prim's Algorithm\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                primMST();
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