#include <iostream>
#include <cstdlib>	#include <cstdlib>
#include <ctime>	#include <ctime>
#include "guessit.h"	#include "guessit.h"
using namespace std;	using namespace std;


/***	/***
    Args:	    Args:
        	
    Returns:	    Returns:
        number (int) : random number in range 1-100	        number (int) : random number in range 1-100
***/	***/
int generateRandomNumber() {	int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100	    // TODO: Return the random number in range 1 to 100
    return 100;	    return rand() % 100 + 1;
}	}




/***	/***
    Args:	    Args:
        	
    Returns:	    Returns:
        number (int) : the number that player guessed	        number (int) : the number that player guessed
***/	***/
int getPlayerGuess() {	int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number	    // TODO: Ask the player guest and return the player's number

    int guess;
    return 1;	    cin>>guess;
    return guess;
}	}




@@ -39,14 +38,19 @@ int getPlayerGuess() {
        answer (string) : answer of computer after checking result	        answer (string) : answer of computer after checking result
***/	***/
string getAnswer(int number, int randomNumber) {	string getAnswer(int number, int randomNumber) {
    /*** 	    /***
        TODO: check number with randomNumber and return the result.	        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."	              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."	              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."	              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/	    ***/
    string answer;	    string answer;

    if (number > randomNumber)
        answer = "Your number is higher.";
    else if (number < randomNumber)
        answer = "Your number is lower.";
    else
        answer = "Congratulation! You win.";
    return answer;	    return answer;
}	}


@@ -59,8 +63,10 @@ string getAnswer(int number, int randomNumber) {
***/	***/
bool checkSuccess(string answer) {	bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong	    // TODO: return the result after checking that player guessed right or wrong

    if (answer == "Congratulation! You win.")
    return true;	        return true;
    else
        return false;
}	}




/***	/***
    Args:	    Args:
        isContinued (char): player's choice	        isContinued (char): player's choice
    Returns:	    Returns:
        result (bool) : continue playing or not	        result (bool) : continue playing or not
***/	***/
bool checkContinuePlaying(char isContinued) {	bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not	    // TODO: return result after checking player continue playing or not
    bool result = false;	    bool result = false;

    if (isContinued == 'Y' || isContinued == 'y') result = true;
    return result;	    return result;
}	}




/***	/***
    Args:	    Args:
        	
    Returns:	    Returns:
        isContinues (char) : player's choice (continue playing or not)	        isContinues (char) : player's choice (continue playing or not)
***/	***/
char getPlayerOpinion() {	char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice	    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;	    char isContinued;

    cin>>isContinued;
    return isContinued;	    return isContinued;
}	}


void playGuessIt() {	void playGuessIt() {
    int randomNumber = generateRandomNumber();	    int randomNumber = generateRandomNumber();
    int number;	    int number;
    string answer;	    string answer;
    	
    do {	    do {
        number = getPlayerGuess();	        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);	        answer = getAnswer(number, randomNumber);
        cout << answer << endl;	        cout << answer << endl;
    } while (!checkSuccess(answer));	    } while (!checkSuccess(answer));
}	}
int run() {	int run() {
    srand(time(0));	    srand(time(0));
    char isContinued;	    char isContinued;
    do {	    do {
        playGuessIt();	        playGuessIt();
        isContinued = getPlayerOpinion();	        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));	    } while (checkContinuePlaying(isContinued));
    return 0;	    return 0;
}	}