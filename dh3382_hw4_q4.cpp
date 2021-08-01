#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int userN;                                  //list headed by size
    int sequenceCount;
    double sequenceLength, productAllN, geoMean;

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

    return 0;

    int userN;                                  //list ended with a sentinel value
    double sequenceLength, productAllN, geoMean;

    cout<<"Please enter a non-empty sequence of positive integers, ";
    cout<<"each one in a separate line. End your"<<endl;
    cout<<"sequence by typing -1:"<<endl;
    cin >> userN;

    productAllN = 1;
    for(sequenceLength = 0; userN > 0; sequenceLength++) {
        productAllN *= userN;
        cin >> userN;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geoMean = pow(productAllN, 1/sequenceLength);
    cout<<"The geometric mean is "<<geoMean<<endl;

    return 0;
}
