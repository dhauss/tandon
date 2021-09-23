#include <iostream>
#include<string>
using namespace std;

bool isLetter(char currChar);
int countWords(string line);
string* createWordsArray(string sentence, int& outWordsArrSize);
int main() {
    string userLine;
    int wordsArrSize;
    string* wordsArr = nullptr;

    cout<<"Please enter a line of text:\n";
    getline(cin, userLine);

    wordsArr = createWordsArray(userLine, wordsArrSize);
    cout<<"Your string is now a fancy new array containing "<<wordsArrSize<<" words, which are:\n";        //test
    for(int i = 0; i < wordsArrSize; i++)
        cout<<wordsArr[i]<<endl;

    delete [] wordsArr;
    wordsArr = nullptr;
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

int countWords(string line) {
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

    return wordCount;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    string* wordsArr = nullptr;
    int wordCount, stringLength, currWordLength, wordStartInd;
    int wordsArrIndex;
    string currWord;

    wordCount = countWords(sentence);
    wordsArr = new string[wordCount];
    wordsArrIndex = 0;
    wordStartInd = 0;
    stringLength = sentence.length();
    for(int i = 0; i < stringLength; i++) {
        wordStartInd = i;
        if (!isLetter(sentence[i])) {
            while (!isLetter(sentence[i]) && i < stringLength) {
                i++;
                wordStartInd++;
            }
        }
        while (sentence[i] != ' ' && i < stringLength)
            i++;

        currWordLength = (i - wordStartInd);
        currWord = sentence.substr(wordStartInd, currWordLength);
        wordsArr[wordsArrIndex] = currWord;
        wordsArrIndex++;
    }

    outWordsArrSize = wordCount;
    return wordsArr;
}