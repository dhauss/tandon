#include <iostream>
#include<string>
using namespace std;

const int LOWER_CASE = 'a' - 'A';

bool isLetter(char currChar);
void makeLowerCase(string& word);
void removeNonLetters(string& line);
int countLetters(string line);
bool isAnagram(string line1, string line2, int arrSize);
int main() {
    string userLine1, userLine2, evalLine1, evalLine2;
    int userLineLetters, userLineLetters2;

    cout<<"Please enter 2 lines of text separated by return:\n";
    getline(cin, userLine1);
    getline(cin, userLine2);

    evalLine1 = userLine1;
    evalLine2 = userLine2;

    removeNonLetters(evalLine1);
    removeNonLetters(evalLine2);
    makeLowerCase(evalLine1);
    makeLowerCase(evalLine2);
    userLineLetters = countLetters(evalLine1);
    userLineLetters2 = countLetters(evalLine2);

        if((userLineLetters == userLineLetters2) && isAnagram(evalLine1, evalLine2, userLineLetters))
            cout<<userLine1<<" and "<<userLine2<<" is an anagram.\n";
        else
            cout<<userLine1<<" and "<<userLine2<<" is not an anagram.\n";

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

int countLetters(string line) {
    int i;
    int stringLength, letterCount;

    stringLength = line.length();
    letterCount = 0;
    for(i = 0; i < stringLength; i++) {
        if (isLetter(line[i]))
            letterCount++;
    }

    return letterCount;
}

void makeLowerCase(string& word) {
    int i;
    int stringLength;

    stringLength = word.length();
    for(i = 0; i < stringLength; i++) {
        if((word[i] >= 'A') && (word[i] <= 'Z'))
            word[i] = word[i] + LOWER_CASE;
    }
}

void removeNonLetters(string& line){
    int i;
    int stringLength;
    string newString;

    stringLength = line.length();
    for(i = 0; i < stringLength; i++) {
        if(((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
            newString += line[i];
    }

    line = newString;
}

bool isAnagram(string line1, string line2, int arrSize) {
    bool isAnagram = true;
    int i, j, letterCount1, letterCount2;
    char alphaArr[26];

    for(i = 0; i < 26; i++)
        alphaArr[i] = 'a' + i;

    for(i = 0; i < 26 && isAnagram; i++) {
        letterCount1 = 0;
        letterCount2 = 0;
        for (j = 0; j < arrSize; j++) {
            if (alphaArr[i] == line1[j])
                letterCount1++;
            if(alphaArr[i] == line2[j])
                letterCount2++;
            }

        if(letterCount1 != letterCount2)
            isAnagram = false;
    }
    return isAnagram;
}
