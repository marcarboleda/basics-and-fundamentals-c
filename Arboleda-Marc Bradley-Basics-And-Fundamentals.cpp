#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// print the array
void displayElements(const int array[], int count) {
    for (int i = 0; i < count; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Input elements into an array
void inputElements(int elements[], int& count) {
    cout << "Enter the number of elements (maximum of " << MAX_SIZE << "): ";
    cin >> count;
    while (count > MAX_SIZE) {
        cout << "Number of elements exceeds the limit. \nEnter a valid number: ";
        cin >> count;
    }
    cout << "Enter the elements: ";
    for (int i = 0; i < count; ++i) {
        cin >> elements[i];
    }
}

// Merge two arrays
void mergeElements(const int firstArray[], int firstCount, const int secondArray[], int secondCount, int combinedArray[], int& totalCount) {
    totalCount = firstCount + secondCount;
    for (int i = 0; i < firstCount; ++i) {
        combinedArray[i] = firstArray[i];
    }
    for (int i = 0; i < secondCount; ++i) {
        combinedArray[firstCount + i] = secondArray[i];
    }
}

// Sort the array in descending order using Bubble Sort
void sortDescending(int array[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int firstArray[MAX_SIZE], secondArray[MAX_SIZE], combinedArray[2 * MAX_SIZE];
    int firstCount, secondCount, totalCount;

    cout << "First Array:\n";
    inputElements(firstArray, firstCount);

    cout << "Second Array:\n";
    inputElements(secondArray, secondCount);

    mergeElements(firstArray, firstCount, secondArray, secondCount, combinedArray, totalCount);

    sortDescending(combinedArray, totalCount);

    cout << "Combined and Sorted Array in Descending Order: ";
    displayElements(combinedArray, totalCount);

    return 0;
}
