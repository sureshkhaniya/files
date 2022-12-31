
/*
Coded:- Suresh khaniya
Subject :- CSC 225( Data structures and Algorithms)
Submitted to :- professor Michael Thompson
Description:- This is the .cpp file .
*/

#include <iostream>
#include "Log.h"  //Including header file.
 

  
Log::Log() {                             
	redAcorn = "_";
	GreenAcorn = "_";
	BlueAcorn = "_";
	PurpleAcorn = "_";
	YellowAcorn = "_";
}
bool Log::hasWon() {

	if (redAcorn == "_" || GreenAcorn == "_" || BlueAcorn == "_" || PurpleAcorn == "_" || YellowAcorn == "_") {
		return false;
	}
	else{
		return true;

	}

}

string Log :: getState() {
	return (redAcorn +" "+ GreenAcorn+ " "+ BlueAcorn +" "+ PurpleAcorn +" " + YellowAcorn);


}

// passes character to add to the log.
void Log::addAcorn(char addacorn) {
	
	if (addacorn == 'R') {
		redAcorn = "R";
	}
	else if (addacorn == 'G') {
		GreenAcorn = "G";
	}
	else if (addacorn == 'B') {
		BlueAcorn = "B";
	}
	else if (addacorn == 'P') {
		PurpleAcorn = "P";
	}
	else if (addacorn == 'Y') {
		YellowAcorn = "Y";
	}


}

bool Log::stealAcorn(char steal) {

	//using switch statement for stealAcorn.
	switch (steal)
	{
	case 'P':

		if (PurpleAcorn == "P") {
			PurpleAcorn = "_";
			return true;
		}
		else
			return false;
		break;

	case 'B':
		if (BlueAcorn == "B")
		{
			BlueAcorn = "_";
			return true;
		}
		else
			return false;

		break;

	case 'R':
		if (redAcorn == "R")
		{
			redAcorn = "_";
			return true;
		}
		else
			return false;

		break;


	case 'Y':
		if (YellowAcorn == "R")
		{
			YellowAcorn = "_";
			return true;
		}
		else
			return false;
		break;

	case 'G':


		if (GreenAcorn == "G")
		{
			GreenAcorn = "_";
			return true;
		}

		else
			return false;

		break;


	}
}

	void Log:: storm() {
		redAcorn = "_";
		GreenAcorn = "_";
		BlueAcorn = "_";
		PurpleAcorn = "_";
		YellowAcorn = "_";

	}




