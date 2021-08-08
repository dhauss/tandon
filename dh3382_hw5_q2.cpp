#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    int userGuess;
    int randNum, numGuessesLeft, numGuesses, minGuess, maxGuess;
    string bigSmall;
    bool guessedRight = false;

    srand(time(0));

    randNum = (rand() % 100) + 1;
    minGuess = 1;
    maxGuess = 100;

    cout<<"I thought of a random number between 1 and 100! Try to guess it."<<endl;
    for(numGuessesLeft = 5; (numGuessesLeft > 0) && !guessedRight; numGuessesLeft--) {
        cout<<"Range: ["<<minGuess<<", "<<maxGuess<<"], Number of guesses left: "<<numGuessesLeft<<endl;
        cout << "Your guess: ";
        cin >> userGuess;

        if (userGuess > randNum) {                   //user guess too high
            bigSmall = "smaller";
            if (userGuess < maxGuess)                  //update range unless user guesses number outside existing range
                maxGuess = userGuess - 1;
        }
        else if (userGuess == randNum) {              //user guess just right
            numGuesses = 6 - numGuessesLeft;
            guessedRight = true;                        //end loop, cancel 'out of guesses' message

            cout << "Congrats! You guessed my number in " << numGuesses << " guesses." << endl;
        }
        else {                                          //user guess too low
            bigSmall = "bigger";
            if (userGuess > minGuess)                  //update range unless user guesses number outside existing range
                minGuess = userGuess + 1;
        }

        if(numGuessesLeft > 1 && !guessedRight)
            cout<<"Wrong! My number is "<<bigSmall<<endl<<endl;
    }

        if(!guessedRight)
            cout<<"Out of guesses! My number is "<<randNum<<endl;

    return 0;
}
