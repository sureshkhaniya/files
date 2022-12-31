#pragma once
/*
Coded:- Suresh khaniya
Subject :- CSC 225( Data structures and Algorithms)
Submitted to :- professor Michael Thompson 
Description:- This is the header file (LogAcorn.h) with class Log that hold colored acorns.
*/

#ifndef LOGACORN_H  
#define LOGACORN_H

#include <string>

using namespace std; 

class Log             //class Log
{
private:

	//Functions only for the class to use, location/name/losses/wins
	// Five Data Members of type string.

	string redAcorn;
	string GreenAcorn;
	string BlueAcorn;
	string PurpleAcorn;
	string YellowAcorn;

public:    //Functions/Data members that are available across all classes
	Log();            //Default constuctor
	bool hasWon();   // it returns either true or false .
	string getState(); // it returns a string representing the current state of the log.
	void addAcorn(char); //it passes a character representing the color of acorn to add to the log.
	 bool stealAcorn(char); // it steals acorn from the log and passes a character representing the color of acorn.
	void storm();   //removes all acorns from the log.

	

};

#endif

