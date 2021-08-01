#include <iostream>
using namespace std;
int n;
int currentInt, evalInt;
int evenCount, oddCount, oddEven;

int main() {
    cout<<"Be a pal and input a positive integer: ";
    cin>>n;

    for(currentInt = 1; currentInt <= n; currentInt++){           //produce all int's 1 through n
        evenCount = 0;
        oddCount = 0;
        for(evalInt = currentInt; evalInt > 0; evalInt /= 10) {  //evaluate int digits
            oddEven = evalInt%2;
            if(oddEven == 0)
                evenCount++;
            else
                oddCount++;
        }

        if(evenCount > oddCount)                                 //output only the numbers with more even than odd digits
            cout<<currentInt<<endl;

    }

    return 0;
}
