#include <iostream>
using namespace std;

int main() {
    int n;
    int evenN, counter;

    cout << "Enter a positive integer: ";
    cin >> n;

    counter = 1;   //while loop version
    evenN = 2;
    while (counter <= n) {
        cout << evenN << endl;
        evenN += 2;
        counter++;
    }

    for(counter = 1; counter <= n; counter++) { //for loop version
        evenN = counter * 2;
        cout << evenN << endl;
    }

return 0;
}
