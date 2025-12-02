#include<iostream>
using namespace std;

#define MAX 10

struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

void enqueue(Queue &q, int val) {
    if (q.rear == MAX - 1)
        cout << "Queue Full\n";
    else {
        if (q.front == -1) q.front = 0;
        q.data[++q.rear] = val;
    }
}

int dequeue(Queue &q) {
    int val;
    if (isEmpty(q)) {
        cout << "Queue Empty\n";
        return -1;
    } else {
        val = q.data[q.front];
        if (q.front == q.rear)
            q.front = q.rear = -1;
        else
            q.front++;
        return val;
    }
}

void bfs(int adj[MAX][MAX], int n, int start) {
    Queue q;
    initQueue(q);
    int visited[MAX] = {0};
    enqueue(q, start);
    visited[start] = 1;

    cout << "BFS Traversal: ";
    while (!isEmpty(q)) {
        int v = dequeue(q);
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void dfsRecursive(int adj[MAX][MAX], int n, int v, int visited[MAX]) {
    cout << v << " ";
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfsRecursive(adj, n, i, visited);
    }
}

void dfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    cout << "DFS Traversal: ";
    dfsRecursive(adj, n, start, visited);
    cout << endl;
}

int main() {
    int n, adj[MAX][MAX], choice, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    }

    do {
        cout << "\n     MENU     \n";
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter starting vertex: ";
                cin >> start;
                bfs(adj, n, start);
                break;

            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                dfs(adj, n, start);
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