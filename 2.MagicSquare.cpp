//Write a program to construct and verify a magic square of order 'n' 
//(for both even & odd) such that all rows, columns, and diagonals 
//sum to the same value.

#include<iostream>
using namespace std;

int main() {
    int n,a[10][10];
    cout<<"Enter the dimensions of n*n matrix : ";
    cin>>n;
    for (int i =0;i<n;i++) {
        for(int j=0;j<n;j++) {
            a[i][j]=0;
        }
    }

    int i,j,k;
    i=n/2,j=n-1,k=2;

    a[i][j]=1;
    while(k<=(n*n)) {
        --i;
        ++j;
        if(i==-1 && j==n) {
            j=n-2;
            i=0;
        }
        if(i==-1) {
            i=n-1;
        }
        if(j==n) {
            j=0;
        }
        if(a[i][j]!=0) {
            i=i+1;
            j=j-2;
        }
        a[i][j]=k++;
    }
    cout<<"\n==========Magical Matrix==========\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}