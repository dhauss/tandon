#include <iostream>
#include<vector>
using namespace std;

void printArray(int* arr, int arrSize);
int* main1(int& arrSize);
void numArrSearch(int* arr, int arrSize);
void printVector(vector<int> vector);
vector<int> main2();
void numVectorSearch(vector<int> vector);
int main() {
    int arrSize;
    int* intArr = nullptr;
    vector<int> intVector;

    cout<<"Array Version:\n";
    cout<<"Please enter a sequence of positive integers, each in a separate line\n";
    cout<<"End your input by typing -1\n";
    intArr = main1(arrSize);
    numArrSearch(intArr, arrSize);

    cout<<endl;
    cout<<"Array elements:\n";
    printArray(intArr, arrSize);
    cout<<endl;

    cout<<"Vector version:\n";
    cout<<"Please enter a sequence of positive integers, each in a separate line\n";
    cout<<"End your input by typing -1\n";
    intVector = main2();
    numVectorSearch(intVector);

    cout<<endl;
    cout<<"Vector elements:\n";
    printVector(intVector);
    cout<<endl;


    delete [] intArr;
    intArr = nullptr;
    return 0;
}
void printArray(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<endl;
}

void numArrSearch(int* arr, int arrSize){
    int userNum, numOccurInd;
    int* numOccurArr = new int[arrSize];
    bool seenNum = false;

    cout<<"Please enter a number you want to search.\n";
    cin>>userNum;

    numOccurInd = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == userNum){
            numOccurArr[numOccurInd] = i + 1;
            numOccurInd++;
            seenNum = true;
        }
    }

    if(!seenNum)
        cout<<"Your number does not occur in the sequence.";
    else {
        cout << userNum << " shows in line(s) ";
        for (int i = 0; i < numOccurInd; i++) {
            cout << numOccurArr[i];
            if (i !=  (numOccurInd - 1))
                cout<<", ";
        }
    }
    cout<<endl;
}

int* main1(int& arrSize) {
    int currNum;
    int *intArr = new int[1];
    bool seenNegative = false;
    int arrPhysicalSize;

    arrSize = 0;
    arrPhysicalSize = 1;
    while (!seenNegative) {
        cin >> currNum;
        if (currNum == -1)
            seenNegative = true;
        else {
            if (arrSize == arrPhysicalSize) {
                int *newTempArr = new int[arrPhysicalSize * 2];

                for (int i = 0; i < arrSize; i++)
                    newTempArr[i] = intArr[i];

                delete[] intArr;
                intArr = newTempArr;
                arrPhysicalSize *= 2;
            }

            intArr[arrSize] = currNum;
            arrSize++;
        }
    }
    return intArr;
}

void printVector(vector<int> vector){
    for(int i: vector)
        cout<<i<<endl;
}

vector<int> main2(){
    vector<int> intVector;
    bool seenNegative = false;
    int currNum;

    while (!seenNegative) {
        cin >> currNum;
        if (currNum == -1)
            seenNegative = true;
        else
            intVector.push_back(currNum);
    }

    return intVector;
}

void numVectorSearch(vector<int> vector){
    int userNum, numOccurInd, vectorInd;
    int* numOccurArr = new int[vector.size()];
    bool seenNum = false;

    cout<<"Please enter a number you want to search.\n";
    cin>>userNum;

    numOccurInd = 0;
    vectorInd = 0;
    for(int x : vector){
        if(x == userNum){
            numOccurArr[numOccurInd] = vectorInd + 1;
            numOccurInd++;
            seenNum = true;
        }
        vectorInd++;
    }

    if(!seenNum)
        cout<<"Your number does not occur in the sequence.";
    else {
        cout << userNum << " shows in line(s) ";
        for (int i = 0; i < numOccurInd; i++) {
            cout << numOccurArr[i];
            if (i !=  (numOccurInd - 1))
                cout<<", ";
        }
    }
    cout<<endl;

    delete[] numOccurArr;
}
