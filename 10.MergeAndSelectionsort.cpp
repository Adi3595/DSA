//Write a program to arrange the list of employees as per the average of 
//their height and weight by using Merge and Selection sorting method. 
//Analyse their time complexities and conclude which algorithm will take 
//less time to sort the list. 

#include <iostream>
#include <iomanip>
using namespace std;

struct Employee {
    char name[20];
    float height;
    float weight;
    float avg;
};

void calculateAverage(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        emp[i].avg = (emp[i].height + emp[i].weight) / 2.0;
    }
}

void selectionSort(Employee emp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (emp[j].avg < emp[minIdx].avg)
                minIdx = j;
        }
        if (minIdx != i) {
            Employee temp = emp[i];
            emp[i] = emp[minIdx];
            emp[minIdx] = temp;
        }
    }
}

void merge(Employee emp[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[50], R[50]; 

    for (int i = 0; i < n1; i++)
        L[i] = emp[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = emp[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg)
            emp[k++] = L[i++];
        else
            emp[k++] = R[j++];
    }

    while (i < n1)
        emp[k++] = L[i++];
    while (j < n2)
        emp[k++] = R[j++];
}

void mergeSort(Employee emp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(emp, left, mid);
        mergeSort(emp, mid + 1, right);
        merge(emp, left, mid, right);
    }
}

void display(Employee emp[], int n) {
    cout << "\n--------------------------------------------------\n";
    cout << left << setw(15) << "Name" 
         << setw(10) << "Height"
         << setw(10) << "Weight"
         << setw(10) << "Average\n";
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << emp[i].name
             << setw(10) << emp[i].height
             << setw(10) << emp[i].weight
             << setw(10) << emp[i].avg << "\n";
    }
    cout << "--------------------------------------------------\n";
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[50], emp1[50], emp2[50]; 

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of Employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> emp[i].name;
        cout << "Height(cm): ";
        cin >> emp[i].height;
        cout << "Weight: ";
        cin >> emp[i].weight;
    }

    calculateAverage(emp, n);

    for (int i = 0; i < n; i++) {
        emp1[i] = emp[i];
        emp2[i] = emp[i];
    }

    cout << "\nOriginal List:";
    display(emp, n);

    selectionSort(emp1, n);
    cout << "\nSorted List using Selection Sort:";
    display(emp1, n);

    mergeSort(emp2, 0, n - 1);
    cout << "\nSorted List using Merge Sort:";
    display(emp2, n);


    cout << "\n========== Time Complexity Analysis ==========\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Merge Sort: O(n log n)\n";
    cout << "---------------------------------------------\n";
    cout << "Conclusion: Merge Sort will take less time for large datasets.\n";

    return 0;
}

