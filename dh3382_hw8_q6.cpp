#include <iostream>
#include<string>
using namespace std;

bool isLetter(char currChar);
void changeDigits(string line);
int main() {
    string userLine;

    cout<<"Please enter a line of text:\n";
    getline(cin, userLine);
    changeDigits(userLine);

    return 0;
}

bool isLetter(char currChar) {
    bool isLetter;

    if(((currChar >= 'a') && (currChar <= 'z')) || ((currChar >= 'A') && (currChar <= 'Z')))
        isLetter = true;
    else
        isLetter = false;

    return isLetter;
}

void changeDigits(string line) {
   int i;
   int stringLength;

    stringLength = line.length();
    for(i = 0; i < stringLength; i++){
        if((line[i] >= '0') && (line[i] <= '9'))
            line[i] = 'x';
        else if(isLetter) {                     //if letter, skip ahead to next space or end of string
            while (line[i] != ' ' && i < stringLength)
                i++;
        }
    }
    cout<<line<<endl;
}
