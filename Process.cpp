
#include "Process.h"   //to include header file.
#include <iostream>
#include  <string>   / //for string Input from C++ Library or Directory.

using namespace std;

void Process::init(string name, double  n) {

    Wait = 0;
    currentTime = 0;
    Name = name ;
    Duration = n;
    Remaining = n;
}
string Process::getName() {

    return Name;
}

double Process::getDuration() {
    return Duration;
}

double Process::run(double x) {
    double val;
    if (Remaining >x) {
        Remaining =  Remaining - x;
        return x;
    }
    else {  
        val = Remaining;
        Remaining = 0;
        return val;
    }

}

double Process::getRemaining() {
    return Remaining;
}

double Process::getWait() {
	return Wait;
}
void Process::setWaitStart(double s) {
    currentTime = s;

}

void Process::calculateWait(double nettime) {
	Wait =Wait + nettime - currentTime;
}

