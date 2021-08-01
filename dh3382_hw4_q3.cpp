#include <iostream>
#include <cmath>
using namespace std;

const int BINARY_BASE = 2;
int main() {
    int n;
    int exp, highestTwoToTheExp;

    cout<<"Enter decimal number:"<<endl;
    cin>>n;
    cout<<"The binary representation of "<<n<<" is ";

    for (exp = 0; highestTwoToTheExp <= n; exp++)
        highestTwoToTheExp = pow(BINARY_BASE, exp);

while(highestTwoToTheExp > 1) {
    while (n > 0) {
        highestTwoToTheExp /= 2;

        while (highestTwoToTheExp > n) {
            cout << "0";
            highestTwoToTheExp /= 2;
        }

        cout << "1";
        n = (n - highestTwoToTheExp);
    }

    if((n == 0) && (highestTwoToTheExp != 1))
            cout<<"0";

    highestTwoToTheExp /= 2;
}

cout<<endl;

    return 0;
}
