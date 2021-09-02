#include <iostream>
#include<string>
using namespace std;

const int LOWER_CASE = 'a' - 'A';

void makeLowerCase(string& word);
bool isPalindrome(string str);
int main() {
    bool isPal;
    string userWord;

    cout<<"Please enter a word: ";
    cin>>userWord;

    makeLowerCase(userWord);
    isPal = isPalindrome(userWord);
    if(isPal)
        cout<<userWord<<" is a palindrome\n";
    else
        cout<<userWord<<" is not a palindrome\n";

    return 0;
}

void makeLowerCase(string& word) {
    int i;
    int stringLength;

    stringLength = word.length();
    for(i = 0; i < stringLength; i++) {
        if((word[i] >= 'A') && (word[i] <= 'Z'))
            word[i] = (int)word[i] + LOWER_CASE;
    }
}

bool isPalindrome(string str){
    bool isPalindrome = false;
    int i, stringLength, halfStringIndex;
    string firstHalfStr, secondHalfStrReverse;

    stringLength = str.length();
    halfStringIndex = stringLength/2;

    if(stringLength % 2 == 0)        //even number of characters
        firstHalfStr = str.substr(0, halfStringIndex);
    else                              //odd number of characters
        firstHalfStr = str.substr(0, halfStringIndex + 1);

    secondHalfStrReverse = "";
    for(i = stringLength - 1; i >= (halfStringIndex); i--)
        secondHalfStrReverse += str.at(i);

    if(firstHalfStr == secondHalfStrReverse)
        isPalindrome = true;

    return isPalindrome;
}
