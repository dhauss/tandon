#include <iostream>
using namespace std;

void fillArr(int*& arr, int arrSize);
int countPos(int* arr, int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int main() {
    int arrSize = 6;
    int* arr = new int[arrSize];
    int outPosArrSize;                                //v1
    int* outPosArrSizePtr = &outPosArrSize;            //v2
    int* outPosArr = new int;                         //v3
    int** outPosArrPtr;                                //v4
    outPosArrPtr = &outPosArr;

    fillArr(arr, arrSize);
    arr = getPosNums1(arr, arrSize, outPosArrSize);        //v1
    cout<<"Version 1\n";
    cout<<"outPosArrSize is "<<outPosArrSize<<endl;
    for(int i = 0; i < outPosArrSize; i++)
        cout<<arr[i]<<endl;

    fillArr(arr, arrSize);
    arr = getPosNums2(arr, arrSize, outPosArrSizePtr);      //v2
    cout<<"Version 2\n";
    cout<<"*outPosArrSizePtr is "<<*outPosArrSizePtr<<endl;
    for(int i = 0; i < *outPosArrSizePtr; i++)
        cout<<arr[i]<<endl;

    fillArr(arr, arrSize);
    getPosNums3(arr, arrSize, outPosArr, outPosArrSize);        //v3
    cout<<"Version 3\n";
    cout<<"outPosArrSize is "<<outPosArrSize<<endl;
    for(int i = 0; i < outPosArrSize; i++)
        cout<<outPosArr[i]<<endl;

    fillArr(arr, arrSize);
    getPosNums4(arr, arrSize, outPosArrPtr, outPosArrSizePtr);      //v4
    cout<<"Version 4\n";
    cout<<"*outPosArrSizePtr is "<<*outPosArrSizePtr<<endl;
    for(int i = 0; i < *outPosArrSizePtr; i++)
        cout<<*(*outPosArrPtr + i)<<endl;

    delete [] arr;
    arr = nullptr;
    delete outPosArr;
    outPosArr = nullptr;
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

int countPos(int* arr, int arrSize){
    int i, counter;

    counter = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] > 0){
            counter++;
        }
    }

    return counter;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int i, j;
    outPosArrSize = countPos(arr, arrSize);
    int *posArr= new int [outPosArrSize];

    j = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    delete [] arr;
    return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int i, j;
    *outPosArrSizePtr = countPos(arr, arrSize);
    int *posArr = new int[*outPosArrSizePtr];

    j = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            posArr[j] = arr[i];
            j++;
        }
    }

    delete [] arr;
    return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int i, j;
    outPosArrSize = countPos(arr, arrSize);
    int* temp = new int[outPosArrSize];

    j = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    delete [] outPosArr;
    outPosArr = temp;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int i, j;
    *outPosArrSizePtr = countPos(arr, arrSize);

    j = 0;
    for(i = 0; i < arrSize; i++) {
        if(arr[i] > 0) {
            *(*outPosArrPtr + j) = arr[i];
            j++;
        }
    }
}