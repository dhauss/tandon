#include <iostream>
using namespace std;

void swapArrayElements(int arr[], int i1, int i2);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[],int arrSize);

void printArray(int arr[], int arrSize);    //testing program
int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}                                   //end testing program

void swapArrayElements(int arr[], int i1, int i2){
    int temp;

    temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void reverseArray(int arr[], int arrSize) {
    int i, j;

    for(i = 0, j = (arrSize - 1); i < j; i++, j--) {
        swapArrayElements(arr, i, j);
    }
}

void removeOdd(int arr[], int& arrSize){
    int i, j;
    for(i = 0, j = 1; j < (arrSize - 1); i++, j++){
        if((arr[i] % 2) == 1 || (arr[i] % 2) == -1) {
            while((arr[j] % 2) == 1 || (arr[j] % 2) == -1)
                j++;
            swapArrayElements(arr, i, j);
        }
    }
    arrSize = i;
}

void splitParity(int arr[],int arrSize) {
    int i, j;

    for(i = 0, j = (arrSize - 1); i < j; i++, j--) {
        if ((arr[i] % 2) == 0) {
            while ((arr[j] % 2) == 0)
                j--;
            swapArrayElements(arr, i, j);

        }
        else if((arr[j] % 2 == 1) || (arr[j] % 2 == -1)){
            while ((arr[i] % 2 == 1) || (arr[i] % 2 == -1))
                i++;
            swapArrayElements(arr, i, j);
        }
    }
}
