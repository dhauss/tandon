#include <iostream>
using namespace std;

int main() {
    int n;
    int lineCountDown, starCountTop, spaceCountTop;
    int lineCountUp, starCountBottom, spaceCountBottom;

    cout << "Kindly input a positive integer: ";
    cin >> n;
    cout<<endl;

    for(lineCountDown = n; lineCountDown >= 1; lineCountDown--) {
        for(spaceCountTop = (n - lineCountDown); spaceCountTop > 0; spaceCountTop--)
            cout << " ";
        for(starCountTop = ((2 * lineCountDown) - 1); starCountTop > 0; starCountTop-- )
            cout << "*";
        cout<<endl;
    }

    for(lineCountUp = 1; lineCountUp <= n; lineCountUp++) {
        for(spaceCountBottom = (n - lineCountUp); spaceCountBottom > 0; spaceCountBottom--)
            cout << " ";
        for(starCountBottom = ((2 * lineCountUp) - 1); starCountBottom > 0; starCountBottom--)
            cout << "*";
        cout<<endl;
    }

    return 0;
}

//1 + 2(n-1)
//1, 1+2, 1+4, 1+6
//n - n--