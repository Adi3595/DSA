//WAP to implement Bubble sort and Quick Sort on a 1D array of Student 
//structure (contains student_name, student_roll_no, total_marks), with key
//as student_roll_no. And count the number of swap performed by each method.

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    int total_marks;
};

int bubbleSort(Student arr[], int n) {
    int swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount++;
            }
        }
    }
    return swapCount;
}

int partition(Student arr[], int low, int high, int &swapCount) {
    int pivot = arr[high].roll_no;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].roll_no < pivot) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swapCount++;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    swapCount++;
    return i + 1;
}

void quickSort(Student arr[], int low, int high, int &swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

void display(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr[i].roll_no<<endl;
        cout<<arr[i].name<<endl;
        cout<<arr[i].total_marks<<endl;
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    Student s[100];
    int n = 0, choice;

    do {
        cout<<"\n--- Menu ---\n";
        cout<<"1. Add Students\n";
        cout<<"2. Display Students\n";
        cout<<"3. Bubble Sort\n";
        cout<<"4. Quick Sort\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch (choice) {
            case 1: {
                cout<<"Enter number of students to add: ";
                cin>>n;
                for (int i = 0; i < n; i++) {
                    cout<<"Enter Name: ";
                    cin>>s[i].name;
                    cout<<"Enter Roll No: ";
                    cin>>s[i].roll_no;
                    cout<<"Enter Total Marks: ";
                    cin>>s[i].total_marks;
                }
                break;
            }

            case 2:
                display(s, n);
                break;

            case 3: {
                Student arr[100];
                for (int i = 0; i < n; i++) arr[i] = s[i];
                int swaps = bubbleSort(arr, n);
                cout<<"\nAfter Bubble Sort : \n";
                display(arr, n);
                cout<<"Swaps : "<<swaps<<endl;
                break;
            }


            case 4: {
                Student arr[100];
                for (int i = 0; i < n; i++) arr[i] = s[i];
                int swaps = 0;
                quickSort(arr, 0, n - 1, swaps);
                cout<<"\nAfter Quick Sort : \n";
                display(arr, n);
                cout<<"Swaps : "<<swaps<<endl;
                break;
            }

            case 5:
                cout<<"Exiting...\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
