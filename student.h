#pragma once
/*-----------------------------------------------------------------------
* Date :- 10/1/2022 A.D.
*Name :- Suresh khaniya
*Submitted To:- Professor Michael E.Thompson.
*Description:- This is the header file(student.h).
*/

#ifndef STUDENT_H
#define STUDENT_H



#include <string>            //for string Input from C++ Library or Directory




using namespace std;          // from C++ Directory




class Student 

{
private:                         //Data Member that are not available to every classes.
    string stdfirstName;

    string stdlstName;

    double Ttlcrdt;

    double Ttlpnts;



public:                     // function Data Member that are available across every classes.


    string getLastName() const;

    double getCredits() const;

    double getPoints() const;

    double getGPA() const;    // Accessor

    string getfirstName() const;

   
    void  studentsdetail(string, string, double, double);  //constructor 

    Student();       //default constructor 



};



#endif

