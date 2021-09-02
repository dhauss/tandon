#include <iostream>
using namespace std;

double eApprox(int n);
int main() {

//    cout<<eApprox(0);

    cout.precision(30);
    for (int n = 0; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl; }


    }


double eApprox(int n) {
    int currN, sumFactorial;
    double e;

    e = 1;                                     //initialize at 1 to add 1/0! value
    sumFactorial = 1;
    for(currN = 1; currN <= n; currN++) {
        if (n == 0)
            e = 1;
        else {
            sumFactorial *= currN;
            e += (1.0 / sumFactorial);          //1.0 for implicit cast to double
        }
    }

    return e;
}


