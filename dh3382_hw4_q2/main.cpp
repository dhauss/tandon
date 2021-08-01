#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter decimal number:"<<endl;
    cin>>n;
    cout<<n<<" is ";

    while(n/1000 >= 1) {
        cout<<"M";
        n = n - 1000;
    }
    while(n/500 >= 1) {
        cout<<"D";
        n = n - 500;
    }
    while(n/100 >= 1) {
        cout<<"C";
        n = n - 100;
    }
    while(n/50 >= 1) {
        cout<<"L";
        n = n - 50;
    }
    while(n/10 >= 1) {
        cout<<"X";
        n = n - 10;
    }
    while(n/5 >= 1) {
        cout<<"V";
        n = n - 5;
    }
    while(n/1 >= 1) {
        cout<<"I";
        n = n - 1;
    }

    cout<<endl;

    return 0;
}
