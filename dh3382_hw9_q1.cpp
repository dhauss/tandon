#include <iostream>
#include<string>
using namespace std;

const int LOWER_CASE = 'a' - 'A';

bool isLetter(char currChar);
void makeLowerCase(string& word);
void removeNonLetters(string& line);
void countWords(string line);
int countLetters(string line);
void countAlphabet(string line, int arrSize);
int main() {
    string userLine;
    int userLineLetters;

    cout<<"Please enter a line of text:\n";
    getline(cin, userLine);
    countWords(userLine);

    removeNonLetters(userLine);
    makeLowerCase(userLine);
    userLineLetters = countLetters(userLine);
    countAlphabet(userLine, userLineLetters);

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

void countWords(string line) {
    int i, wordCount;
    int stringLength;

    stringLength = line.length();
    wordCount = 0;
    for(i = 0; i < stringLength; i++) {
        if(!isLetter(line[i])) {
            while (!isLetter(line[i]) && i < stringLength)
                i++;
        }
        while (line[i] != ' ' && i < stringLength)
            i++;
        wordCount++;
        }

    cout<<wordCount<<"\twords\n";
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

void countAlphabet(string line, int arrSize){
    int i, j, letterCount;
    char alphaArr[26];

    for(i = 0; i < 26; i++)
        alphaArr[i] = 'a' + i;

    for(i = 0; i < 26; i++) {
        letterCount = 0;
        for (j = 0; j < arrSize; j++)
            if (alphaArr[i] == line[j]) {
                letterCount++;
            }
        if (letterCount > 0)
            cout << letterCount << "\t" << alphaArr[i]<<endl;
    }
}
