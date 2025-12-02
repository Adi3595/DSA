// Implement basic string operations such as length calculation, copy, 
// reverse, and concatenation using character single dimensional arrays 
// without using built-in string library functions.

#include<iostream>
using namespace std;

int main() {
    int n,ch,len=0,c,la,lb;
    char str[20],copy[20],rev[20];
    char a[20],b[20];
    cout<<"Enter the string : ";
    cin>>str;
    do {
        cout<<"~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~\n";
        cout<<"1. Length of string.\n";
        cout<<"2. Copy string.\n";
        cout<<"3. Reverse the string.\n";
        cout<<"4. Concatenate two strings.\n";
        cout<<"5.Exit.\n";
        cout<<"Enter the choice : ";
        cin>>ch;
        switch(ch) {
            case 1 :
            for(int i=0;str[i]!='\0';i++) {
                len++;
            }
            cout<<"Length of string : "<<len<<endl;
            cout<<"\n";
            break;
            
            case 2 : 
            for(int i=0;i<=len;i++) {
                copy[i]=str[i];
            }
            cout<<"Copied string : "<<copy<<endl<<"\n";
            break;

            case 3 : c=0;
            for(int i=len-1;i>=0;i--) {
                rev[c++]=str[i];
            }
            rev[c]='\0';
            cout<<"Reversed string : "<<rev<<endl<<"\n";
            break;

            case 4 : la=0,lb=0;
            cout<<"Enter the string 1 : ";
            cin>>a;
            cout<<"Enter the string 2 : ";
            cin>>b;
            for(int i=0;a[i]!='\0';i++) {
                la++;
            }
            cout<<"String 1 : "<<a<<endl;
            for(int i=0;b[i]!='\0';i++) {
                lb++;
            }
            cout<<"String 2 : "<<b<<endl;
            c=0;
            for(int i=la;i<=lb+la;i++) {
                a[i]=b[c++];
            }
            cout<<"Concatenated string : "<<a<<endl<<"\n";
            break;

            case 5 : cout<<"Exiting program..!\n";
            break;
        }
    }while(ch!=5);

    return 0;
}
