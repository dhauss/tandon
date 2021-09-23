#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);
int main() {
    int maxStars = 4;
    int rulerN = 4;

    cout<<"A. Print triangle:\n";
    printTriangle(maxStars);
    cout<<endl;
    cout<<"B. Print opposite triangle:\n";
    printOppositeTriangles(maxStars);
    cout<<endl;
    cout<<"C. Print ruler:\n";
    printRuler(rulerN);

    return 0;
}

void printTriangle(int n){
    if(n == 1)
        cout<<'*'<<endl;
    else{
        printTriangle(n - 1);
        for(int i = 0; i < n; i++)
            cout << '*';
        cout<<endl;
    }
}

void printOppositeTriangles(int n){
    if(n == 1)
        cout<<'*'<<endl;
    else{
        for(int i = 0; i < n; i++)
            cout << '*';
        cout<<endl;
        printOppositeTriangles(n - 1);
        for(int i = 0; i < n; i++)
            cout << '*';
        cout<<endl;
    }
}

void printRuler(int n){
    if(n == 1)
        cout<<"- "<<endl;
    else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++)
            cout << "- ";
        cout << endl;
        printRuler(n - 1);
    }
}

