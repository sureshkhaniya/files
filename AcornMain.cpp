
/*
Coded:- Suresh khaniya
Subject :- CSC 225( Data structures and Algorithms)
Submitted to :- professor Michael Thompson

*/
#include <iostream>
#include "Log.h"
#include <iomanip>
#include <ctime>

using namespace std;

//function prototypes

long spin();
void printState(Log[], long);
char pickColor();
void playTurn(Log[], long, long);


long spin() {   // stimulates a spin of a wheel by returning a random number.
	long wheel;
	wheel = rand() % 9;

	return wheel;

}

char pickColor() {  //Validate entered character and return Upper case character.
	system("pause");
	char choice;
	cin >> choice;
	
	//validate a character from the user.

	while (choice != 'R' && choice != 'r' && choice != 'Y' && choice != 'y' && choice != 'G' && choice != 'g' && choice != 'b' && choice != 'B' && choice != 'P' && choice != 'p') {
		cout << "Invalid color Color. Please enter again : ";
		cin >> choice;

	}

	//selection of  a upper case version.

	switch (choice) {
	
	case 'R':
	case 'r':
		return 'R';
		break;

	case 'B':
	case 'b':
		return 'B';
		break;

	case 'G':
	case 'g':
		return 'G';
		break;

	case 'P':
	case 'p':
		return 'P';
		break;

	case 'y':
	case 'Y':
		return 'Y';
		break;
	}


}



//prints the current state of the game when passes array of Log objects.
void printState(Log plays[], long numOfPlayers) {
	system("CLS");

	for (int i = 0; i < numOfPlayers; ++i) {
		cout << "Player " << i + 1 << "      ";

	}
	cout << endl; 
	for (int i = 0; i < numOfPlayers; ++i) {
		cout << plays[i].getState() << "     ";


	}
}


//simulates turns.
void playTurn(Log plays[], long curPlayer, long numOfPlayers) {
	cout << "Player " << curPlayer << "'s turn:\n";
	char c = pickColor();
	plays[curPlayer - 1].addAcorn(c);

}
const long MAX_ARRAY = 4;     //global constant.


int main(void) {       //void = blank
	
	int numofplayers;

	cout << "Please enter the number of players : ";
	cin >> numofplayers;

	//variable declaratiobn
	while (numofplayers < 2 || numofplayers >4) {
		cout << "Please enter the number of player between (2 to 4) :";
		cin >> numofplayers;
	}
	
	Log Logs[MAX_ARRAY];
	bool done = false; 
	while (done == false) {
		cout << "Pick turn start" << endl; 
		for (int i = 0; i < numofplayers; i++) {
			playTurn(Logs, i + 1, numofplayers);    //it determines player turns.
			cout << endl;
			printState(Logs, numofplayers);
			cout << endl;
			if (Logs[i].hasWon()) {
				cout << "Player " << i + 1 << " has won the game";
				done = false;
				break;
			}
		}
		cout << endl;
		cout << "Sneaky Squirrel! Steal an Acron!" << endl;

		for (int i = 0; i < numofplayers; ++i) {

			cout << "Player " << i + 1 << "'s turn:" << endl;

			cout << "Enter the player you want to steal from:";

			int steal;
			while (true) {
				cin >> steal;
				if (steal > 0 && steal <= numofplayers && steal != i + 1) {
					break;    // to break out the while loop.
				}
				else {
					cout << "Invalid player. Please enter again:";
				}
			}
			char c = pickColor();
			Logs[steal - 1].stealAcorn(c);
			cout << endl;
			printState(Logs, numofplayers);
			cout << endl;
		}

	}
	

	return 0;

}
