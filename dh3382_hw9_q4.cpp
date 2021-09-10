#include <iostream>
using namespace std;

void fillArr(int*& arr, int arrSize);
void oddsKeepEvensFlip(int* arr, int arrSize);
int main() {
    int arrSize = 9;
    int* arr = new int[arrSize];

    fillArr(arr, arrSize);
    oddsKeepEvensFlip(arr, arrSize);
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<endl;


    delete[] arr;
    arr = nullptr;
    return 0;
}
void fillArr(int*& arr, int arrSize){
    int i, userNum;
    int* temp = new int[arrSize];

    cout<<"Please type in "<<arrSize<<" integers separated by spaces.\n";
    for(i = 0; i < arrSize; i++){
        cin>>userNum;
        temp[i] = userNum;
    }

    delete [] arr;
    arr = temp;
    }

void oddsKeepEvensFlip(int* arr, int arrSize){
    int i, j;
    int* temp = new int[arrSize];

    j = 0;
    for(i = 0; i < arrSize; i++){       //odd numbers into new array
        if(arr[i] % 2 != 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    for(i = (arrSize - 1); i >= 0; i--){        //even numbers into new array in reverse order
        if(arr[i] % 2 == 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    for(i = 0; i < arrSize; i++)
        arr[i] = temp[i];
}


