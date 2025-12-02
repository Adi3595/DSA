//Write a program to input marks of n students Sort the marks in ascending 
//order using the Quick Sort algorithm without using built-in library 
//functions and analyse the sorting algorithm pass by pass. 
//Find the minimum and maximum marks using Divide and Conquer (recursively).

#include <iostream>
using namespace std;

// Swap two numbers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort with pass by pass display
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Display array after this partition
        cout << "After pivot " << arr[pi] << ": ";
        for (int i = 0; i <= high; i++)
            cout << arr[i] << " ";
        cout << endl;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Recursive function to find min and max
void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {
    if (low == high) {
        if (arr[low] < minVal) minVal = arr[low];
        if (arr[low] > maxVal) maxVal = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    findMinMax(arr, low, mid, minVal, maxVal);
    findMinMax(arr, mid + 1, high, minVal, maxVal);
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[n];
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    cout << "\n--- Quick Sort Pass by Pass ---\n";
    quickSort(marks, 0, n - 1);

    cout << "\nSorted Marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    cout << endl;

    int minVal = marks[0];
    int maxVal = marks[0];
    findMinMax(marks, 0, n - 1, minVal, maxVal);

    cout << "Minimum Marks: " << minVal << endl;
    cout << "Maximum Marks: " << maxVal << endl;

    return 0;
}
