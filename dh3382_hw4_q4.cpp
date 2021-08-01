#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int userN;                                  //list headed by size
    int sequenceCount;
    double sequenceLength, productAllN, geoMean;

    cout<<"Section A\n";

    cout << "Please enter the length of the sequence: ";
    cin >> sequenceLength;
    cout << "Please enter your sequence:" << endl;

    productAllN = 1;
    for (sequenceCount = 1; sequenceCount <= sequenceLength; sequenceCount++) {
        cin >> userN;
        productAllN *= userN;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geoMean = pow(productAllN, 1 / sequenceLength);
    cout << "The geometric mean is " << geoMean << endl;

    cout<<"Section B\n";                             //list ended with a sentinel value

    int userNB;
    double sequenceLengthB, productAllNB, geoMeanB;

    cout<<"Please enter a non-empty sequence of positive integers, ";
    cout<<"each one in a separate line. End your"<<endl;
    cout<<"sequence by typing -1:"<<endl;
    cin >> userNB;

    productAllNB = 1;
    for(sequenceLengthB = 0; userNB > 0; sequenceLengthB++) {
        productAllNB *= userNB;
        cin >> userNB;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geoMeanB = pow(productAllNB, 1/sequenceLengthB);
    cout<<"The geometric mean is "<<geoMeanB<<endl;

    return 0;
}
