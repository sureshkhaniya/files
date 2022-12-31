/*
Name:- Suresh Khaniya
Submitted to :- Professor Michael Thompson
Description:- Headerfile.
*/
#ifndef PRCOCESS_H
#define PROCESS_H
#include <string> //for string Input from C++ Library or Directory.

using namespace std;  

class Process{   //class name Process.

private:   // Data Member that are not available to every classes.(Private)
	double Wait;
	double Remaining;
	string Name;
	double Duration;
	double currentTime;

public:  // // function Data Member that are available across every classes.
	
	void init(string, double);// takes the name of the process and its duration.
	double run(double);       //Represents the process running for an amount of time. 
	string getName();        //Accessor methods for the name.
	double getDuration();    //Accessor methods for the duration.
	double getRemaining();   //Accessor methods for time remaining.
	double getWait();       //Accessor methods for total wait time.
	void calculateWait(double);
	void setWaitStart(double);
	//Process();          // we do not need Default Constructor.

};

#endif
