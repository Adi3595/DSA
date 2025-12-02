//In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. 
//Assume that all these students are on ground for a function. We need to 
//identify a student of S.Y. div. (X) whose name is "XYZ" and roll no. is 
//"17". Apply appropriate Searching method to identify the required student.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string Name;
    string year;
    string div;
    int roll;
};

int main() {
    Student s[100];
    int n = 0, choice;

    do {
        cout<<"\n--- Menu ---\n";
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1: {
                cout<<"Enter Name: ";
                cin>>s[n].Name;
                cout<<"Enter Year (FY/SY/TY/BTech): ";
                cin>>s[n].year;
                cout<<"Enter Division: ";
                cin>>s[n].div;
                cout<<"Enter Roll No: ";
                cin>>s[n].roll;
                n++;
                cout<<"Student Added Successfully!\n";
                break;
            }

            case 2: {
                cout << "\n--- Student List ---\n";
                for (int i = 0; i < n; i++) {
                    cout<<"Name: "<<s[i].Name<<endl;
                    cout<<"Year: " <<s[i].year<<endl;
                    cout<<"Division: " <<s[i].div<<endl;
                    cout<<"Roll No: "<<s[i].roll<<endl;
                }
                break;
            }

            case 3: {
                string Name, Year, Div;
                int Roll;
                cout<<"Enter Name: ";
                cin>>Name;
                cout<<"Enter Year: ";
                cin>>Year;
                cout<<"Enter Division: ";
                cin>>Div;
                cout<<"Enter Roll No: ";
                cin>>Roll;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (s[i].Name == Name && s[i].year == Year &&
                        s[i].div == Div && s[i].roll == Roll) {
                        cout<<"Student Found at Index : "<<i<<endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout <<"Student Not Found.\n";
                }
                break;
            }
            
            case 4:
                cout<<"Exiting...\n";
                break;
        }
    } while(choice != 4);

    return 0;
}
