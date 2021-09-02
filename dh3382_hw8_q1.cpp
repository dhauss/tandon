#include <iostream>
using namespace std;

int const MAX_ARRAY_SIZE = 20;

void readArray(int arr[], int arrPhysicalSize);
int minInArray(int arr[], int arrSize);
void minIndexesInArray(int arr[], int arrSize, int minInArr);
int main() {
    int arr[MAX_ARRAY_SIZE];
    int minArrElement;

    readArray(arr, MAX_ARRAY_SIZE);
    minArrElement = minInArray(arr, MAX_ARRAY_SIZE);
    cout<<"The minimum value is "<<minArrElement<<" and it is located in the following indices: ";
    minIndexesInArray(arr, MAX_ARRAY_SIZE, minArrElement);

    return 0;
}

void readArray(int arr[], int arrPhysicalSize){
    int i;

    cout<<"Please enter "<<arrPhysicalSize<<" integers separated by a space:\n";
    for(i = 0; i < arrPhysicalSize; i++) {
        cin >> arr[i];
    }
}

int minInArray(int arr[], int arrSize) {
    int i, currMinArr;

    currMinArr = arr[0];
    for(i = 1; i < arrSize; i++) {     //currMinArr initialized to arr[0], loop can start at arr[1]
        if(arr[i] < currMinArr)
            currMinArr = arr[i];
    }

    return currMinArr;
}

void minIndexesInArray(int arr[], int arrSize, int minInArr) {
    int i;

    for(i = 0; i < arrSize; i++) {
        if(arr[i] == minInArr)
            cout<<i<<" ";
    }
    cout<<endl;
}
