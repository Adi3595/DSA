//Write a program using Bubble sort algorithm, assign the roll nos. to 
//the students of your class as per their previous years result. i.e. 
//topper will be roll no. 1 and analyse the sorting algorithm pass by pass.

#include<iostream>
#include<string>
using namespace std;

struct student {
    int roll;
    string name;
    int marks;
};

int main() {
    student s[100];
    int n;
    cout<<"Enter the no of students : ";
    cin>>n;

    for(int i=0;i<n;i++) {
        cout<<"Enter the Name : ";
        cin>>s[i].name;
        cout<<"Enter the previous year marks of student : ";
        cin>>s[i].marks;
        cout<<"\n";
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(s[j].marks <s[j+1].marks) {
                student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }

        cout<<"After Pass "<<i + 1<<": ";
        for (int k = 0; k < n; k++) {
            cout<<s[k].name<<"("<<s[k].marks<<") ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++) {
        s[i].roll=i+1;
    }
    
    cout<<"\nAll students after ranking according to marks : "<<endl;
    for(int i=0;i<n;i++) {
        cout<<"Name : "<<s[i].name<<endl;
        cout<<"Roll No. : "<<s[i].roll<<endl;
        cout<<"Marks : "<<s[i].marks<<endl;
        cout<<"\n";
    }

    return 0;
}