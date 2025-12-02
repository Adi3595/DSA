// 4.Develop a program to identify and efficiently store a sparse matrix using compact 
// representation and perform basic operations like display and simple transpose.
// 5.Develop a program to compute the fast transpose of a sparse matrix using its 
// compact (triplet) representation efficiently.

#include<iostream>
using namespace std;

struct sparse {
    int row;
    int col;
    int value;
};

int main () {
    int i,j,r,c,ch;
    int arr[10][10];
    struct sparse s[10];
    cout<<"Enter the no of columns : ";
    cin>>c;
    cout<<"Enter the no of rows : ";
    cin>>r;

    do {
        cout<<"\n1. Check for matrix is sparse or not.\n";
        cout<<"2. Compact form of matrix or triplet form of matrix.\n";
        cout<<"3. Matrix operations.\n";
        cout<<"4. Exit.\n\n";
        cout<<"Enter the choice : ";
        cin>>ch;
        switch(ch) {

            case 1 : 
                cout<<"Enter the elements in array : \n";
                for(i=0;i<r;i++) {
                    for(j=0;j<c;j++) {
                        cout<<"A["<<i<<"]["<<j<<"] : ";
                        cin>>arr[i][j];
                    }
                }

                {
                    int z=0,nz=0;
                    for(i=0;i<r;i++) {
                        for(j=0;j<c;j++) { 
                            if (arr[i][j]==0)
                                z++;
                            else
                                nz++;
                        }
                    }
                    if(z>nz)
                        cout<<"The matrix is sparse matrix\n";
                    else
                        cout<<"The matrix is not a sparse matrix\n";
                }
                break;

            case 2 :{
                int k=0;
                for(i=0;i<r;i++) {
                    for(j=0;j<c;j++) { 
                        if (arr[i][j]!=0) {
                            s[k].row=i;
                            s[k].col=j;
                            s[k].value=arr[i][j];
                            k++;
                        }
                    }
                }

                int com[10][3];
                cout<<"\nCompact form of matrix is:\n";
                for(i=0;i<k;i++) {
                    com[i][0]=s[i].row;
                    com[i][1]=s[i].col;
                    com[i][2]=s[i].value;
                }
                for(i=0;i<k;i++) {
                    for(j=0;j<3;j++) {
                        cout<<com[i][j]<<" ";
                    }
                    cout<<"\n";
                }
            }
            break;

            case 3 : {
                int op;
                int temp[10][10],a[10][10];
                int k = 0; 

                do {
                    cout<<"\n1. Addition of matrix.\n";
                    cout<<"2. Substraction of matrix.\n";
                    cout<<"3. Transpose of matrix.\n";
                    cout<<"4. Exiting the operations..!\n";
                    cout<<"Enter the choice of operation : ";
                    cin>>op;

                    cout<<"\nEnter the elements of Matrix A : \n";
                    for(i=0;i<r;i++) {
                        for(j=0;j<c;j++) {
                            cin>>a[i][j];
                        }
                    }

                    switch(op) {
                        case 1 : 
                            cout<<"Addition of A and given Matrix : \n";
                            for(i=0;i<r;i++) {
                                for(j=0;j<c;j++) {
                                    temp[i][j]=arr[i][j]+a[i][j];
                                    cout<<temp[i][j]<<" ";
                                }
                                cout<<"\n";
                            }
                            break;

                        case 2 : 
                            cout<<"Substraction of A matrix from given Matrix : \n";
                            for(i=0;i<r;i++) {
                                for(j=0;j<c;j++) {
                                    temp[i][j]=arr[i][j]-a[i][j];
                                    cout<<temp[i][j]<<" ";
                                }
                                cout<<"\n";
                            }
                            break;

                        case 3 : 
                            cout<<"Transpose of given Matrix : \n";
                            for(i=0;i<r;i++) {
                                for(j=0;j<c;j++) {
                                    temp[j][i]=arr[i][j];
                                }
                            }
                            for(i=0;i<c;i++) {
                                for(j=0;j<r;j++) {
                                    cout<<temp[i][j]<<" ";
                                }
                                cout<<"\n";
                            }
                            break;

                        case 4 : break;

                    }
                }while(op!=4);
            }
            break;

            case 4 : 
                cout<<"Exiting the program ...!\n";
                break;

        }
    }while(ch!=4);

    return 0;
}



