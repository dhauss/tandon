#include <iostream>
using namespace std;

const int ARR_SIZE = 6;

void printArray(int* arr, int arrSize);
int* findMissing(int arr[], int n, int& resArrSize);
int main() {
    int arr[ARR_SIZE] = {3, 1, 3, 0, 6, 4};
    int resArrSize;
    int* resArr = nullptr;

    resArr = findMissing(arr, ARR_SIZE, resArrSize);
    cout<<"ResArrSize: "<<resArrSize<<endl;
    printArray(resArr, resArrSize);

    delete [] resArr;
    resArr = nullptr;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int* countArr = new int[n + 1];
    int count;

    for(int i = 0; i < n; i++) {
        countArr[arr[i]]++;
    }

    int* missingArr = new int[n];

    count = 0;
    for(int i = 0; i < n; i++) {
        if (countArr[i] == 0) {
            missingArr[count] = i;
            count++;
        }
    }

    delete [] countArr;
    resArrSize = count;
    return missingArr;
}

void printArray(int* arr, int arrSize) {
    cout<<"Array: \n";
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<endl;
}