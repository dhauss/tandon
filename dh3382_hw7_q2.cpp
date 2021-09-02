#include <iostream>
#include<cmath>
using namespace std;

void printDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
int main() {
    int M;
    int currentInt;
    int countDivs, sumDivs, countDivsAm, sumDivsAm;

    cout<<"Go ahead and type in a positive integer >= 2, then hit return:"<<endl;
    cin>>M;

    cout<<"Check out all the perfect numbers between 2 and "<<M<<":"<<endl;

    for(currentInt = 2; currentInt <= M; currentInt++){
        if(isPerfect(currentInt))
            cout << currentInt<<endl;
    }

    cout<<"And these are all the amicable pairs between 2 and "<<M<<":"<<endl;

    for(currentInt = 2; currentInt <= M; currentInt++){
        printDivisors(currentInt, countDivs, sumDivs);
        printDivisors(sumDivs, countDivsAm, sumDivsAm);
        if((currentInt == sumDivsAm) && (currentInt < sumDivs))
        cout<<"("<<currentInt<<", "<<sumDivs<<")"<<endl;
    }

        return 0;
}

void printDivisors(int num, int& outCountDivs, int& outSumDivs) {
    int currNum, highDivisor, sqrtNum, sumDiv, countDiv;

    sqrtNum = sqrt(num);
    sumDiv = 0;
    countDiv = 0;
    for (currNum = 1; currNum <= sqrtNum; currNum++) {
        highDivisor = num / currNum;
        if (((highDivisor * currNum) == num) && (highDivisor == currNum)) {
            sumDiv += (currNum);
            countDiv++;
        }
        else if ((highDivisor * currNum) == num) {
            sumDiv += (highDivisor + currNum);
            countDiv += 2;
        }
    }

    sumDiv -= num;          //exclude num as divisor from sum and count, only proper divisors
    countDiv--;

    outSumDivs = sumDiv;
    outCountDivs = countDiv;
}

bool isPerfect(int num) {
    int countDivs, sumDivs;
    bool isPerfect = false;

    printDivisors(num, countDivs, sumDivs);
    if(sumDivs == num)
        isPerfect = true;

    return isPerfect;
}
