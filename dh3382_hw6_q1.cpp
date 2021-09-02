#include <iostream>
using namespace std;

int fib(int n);
int main() {
    int num;

    cout<<"Please enter a positive integer: ";
    cin>>num;
    cout<<fib(num)<<endl;

    return 0;
}

int fib(int n){
    int counter, currDigit, lastDigit, temp;

    currDigit = 1;
    lastDigit = 0;
    for(counter = 1; counter < n; counter++) {
        temp = currDigit;
        currDigit += lastDigit;
        lastDigit = temp;
    }

    return currDigit;
};
