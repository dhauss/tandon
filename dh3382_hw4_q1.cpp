#include <iostream>
using namespace std;

int main() {
    int n;
    int evenN, counter;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout<<"Section A\n";                         //while loop version

    counter = 1;
    evenN = 2;
    while (counter <= n) {
        cout << evenN << endl;
        evenN += 2;
        counter++;
    }

    cout<<"Section B\n";                        //for loop version

    for(counter = 1; counter <= n; counter++) {
        evenN = counter * 2;
        cout << evenN << endl;
    }

return 0;
}
