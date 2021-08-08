#include <iostream>
using namespace std;

int main() {
    int userN;
    int lineCount, intAdd, intCount, intTable;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>userN;

    lineCount = 1;
    while(lineCount <= userN) {                          //print out userN number of lines
        for(intCount = 1, intAdd = lineCount, intTable = intAdd;
        intCount <= userN;
        intAdd = (lineCount * intCount), intTable = lineCount + intAdd, intCount++) { //print out lines of integers adding 1++, 2 + 2+2 + 2*2*2... to each number
            if(intTable < 1000)
                cout << intTable << "\t\t";
            else
                cout << intTable << "\t";
        }
        cout<<endl;
        lineCount += 1;
    }

    return 0;
}
