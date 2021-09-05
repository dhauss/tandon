#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int PIN_LENGTH = 5;
const int USER_PIN [PIN_LENGTH] = {0, 1, 2, 3, 4};

void arrPinPrint(int arr[], int arrSize);
void arrNumPrint(int arr[], int arrSize);
void checkPin(const int pin[], int arrNum[]);
int main() {
    int pinArr[10];
    int numArr[10];
    
    cout<<"Please enter your PIN according to the following mapping:\n";
    arrPinPrint(pinArr, 10);
    arrNumPrint(numArr, 10);
    checkPin(USER_PIN, numArr);

    return 0;
}

void arrPinPrint(int arr[], int arrSize){
    int i;

    cout<<"PIN: ";
    for(i = 0; i < arrSize; i++) {
        arr[i] = i;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void arrNumPrint(int arr[], int arrSize) {
    int i;

    srand(time(0));
    cout<<"NUM: ";
    for(i = 0; i < arrSize; i++) {
        arr[i] = (rand() % 3) + 1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void checkPin(const int pin[], int arrNum[]) {
    bool pinCheck = true;
    int currDigit, currPin, currPinDigit, i;

    cin>>currPin;
    for(i = PIN_LENGTH - 1; i > 0; i--) {
        currDigit = pin[i];
        currPinDigit = currPin % 10;
        
        if(currPinDigit != arrNum[currDigit])
            pinCheck = false;

        currPin /= 10;
    }

    if(pinCheck)
        cout<<"Your PIN is correct\n";
    else
        cout<<"Your PIN is not correct\n";
}
