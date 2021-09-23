#include <iostream>
using namespace std;

int const ARR_SIZE = 4;
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int main() {
    int arr[ARR_SIZE] = {-4, -3, -2, -5};

    cout<<sumOfSquares(arr, ARR_SIZE)<<endl;
    if(isSorted(arr, ARR_SIZE))
        cout<<"Array is in ascending order\n";
    else
        cout<<"Array is not in ascending order\n";

    return 0;
}
int sumOfSquares(int arr[], int arrSize){
    int sum;

    sum = 0;
    if(arrSize == 1) {
        sum += (arr[0] * arr[0]);
        return sum;
    }
    else {
        sum = sumOfSquares(arr, arrSize - 1);
        sum += (arr[arrSize - 1] * arr[arrSize - 1]);
        return sum;
    }
    }

bool isSorted(int arr[], int arrSize){
    bool isAscending;

    if(arrSize == 1)
        return true;
    else{
        isAscending = isSorted(arr, arrSize - 1);
        if(!isAscending)
            return false;
        else
            if(arr[arrSize - 1] >= arr[arrSize - 2])
                return true;
            else
                return false;
    }
}

