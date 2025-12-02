// Implement matrix multiplication and analyse its performance using 
// row-major vs column-major order access patterns to understand 
// how memory layout affects cache performance.

#include <iostream>
using namespace std;

const int MAX = 1000;

void matmul_row_major(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void matmul_col_major(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    static int BT[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            BT[j][i] = B[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * BT[j][k];
            }
            C[i][j] = sum;
        }
    }
}

void print_matrix(int M[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int n, choice;
    static int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout<<"Enter size of matrices (n x n): ";
    cin>>n;

    cout<<"Enter elements of matrix A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>A[i][j];
        }
    }

    cout<<"Enter elements of matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>B[i][j];
        }
    }

    do {
        cout<<"\n--- Menu ---\n";
        cout<<"1. Multiply using Row-major order\n";
        cout<<"2. Multiply using Column-major\n";
        cout<<"3. Print Matrix A\n";
        cout<<"4. Print Matrix B\n";
        cout<<"5. Print Result Matrix C\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                matmul_row_major(A, B, C, n);
                cout<<"Row-major multiplication completed.\n";
                break;
            case 2:
                matmul_col_major(A, B, C, n);
                cout<<"Column-major multiplication completed.\n";
                break;
            case 3:
                cout<<"Matrix A:\n";
                print_matrix(A, n);
                break;
            case 4:
                cout<<"Matrix B:\n";
                print_matrix(B, n);
                break;
            case 5:
                cout<<"Matrix C:\n";
                print_matrix(C, n);
                break;
            case 6:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
