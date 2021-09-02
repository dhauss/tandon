#include <iostream>
#include<string>
using namespace std;

void nameFormat(string first, string middle, string last);
int main() {
    string first, last, mI;

    cout<<"Please input your first name, middle name or middle initial, and last name:\n";
    cin>>first>>last>>mI;
    nameFormat(first, last, mI);

    return 0;
}

void nameFormat(string first, string middle, string last) {
    cout<<last<<", "<<first<<" "<<middle[0]<<".\n";
}

