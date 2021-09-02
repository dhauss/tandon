#include <iostream>
#include<cmath>
using namespace std;

void printDivisors(int num);
int main() {
    int num;

    cout<<"Please enter a positive integer >= 2: ";
    cin>>num;
    printDivisors(num);
    cout<<endl;

    return 0;
}

void printDivisors(int num) {
    int currNum, highDivisor, sqrtNum;

    sqrtNum = sqrt(num);
    for (currNum = 1; currNum <= sqrtNum; currNum++) {      //find divisors < sqrt(num) starting at 1
        highDivisor = num / currNum;
        if ((highDivisor * currNum) == num)
            cout << currNum << " ";
    }
    for (currNum = sqrtNum; currNum > 0; currNum--) {       //find complements of above divisors in reverse order (starting at sqrt(num))
        highDivisor = num / currNum;
        if (((highDivisor * currNum) == num) && (highDivisor != currNum))           //avoid printing square root twice, while still printing 1 as divisor of 2 in above loop
            cout << highDivisor << " ";
    }
}
