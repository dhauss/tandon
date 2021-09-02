#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
int main() {
    printPineTree(5, '#');

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int counter, spaceCount, symbolCount;

    for (counter = 1; counter <= n; counter++) {
        for (spaceCount = (n - counter) + m; spaceCount > 0; spaceCount--) //spaces
            cout<<" ";
        for(symbolCount = 2 * counter - 1; symbolCount > 0; symbolCount--) { //symbols
            cout<<symbol;
        }
        cout<<endl;
    }
}

void printPineTree(int n, char symbol) {
    int currN, currM;

    for (currN = 2, currM = (n - 1); currN <= n + 1; currN++, currM--)
        printShiftedTriangle(currN, currM, symbol);
}
