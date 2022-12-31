
/*-----------------------------------------------------------------------
* Date :- 10/1/2022 A.D.
*Name :- Suresh khaniya
*Submitted To:- Professor Michael E.Thompson.
*Description:- This is the studentmain.cpp.
*/


#include <iostream>
#include <string>
#include "student.h"            //source of header file
 



using namespace std;



Student::Student()        
{
    stdfirstName = "N/A";
    stdlstName = " N/A";
    Ttlcrdt = 0;
    Ttlpnts = 0;




}

string Student::getLastName() const
{
    return stdlstName;
}
double Student::getCredits() const
{
    return Ttlcrdt;
}
double Student::getPoints() const
{
    return Ttlpnts;
}
void Student::studentsdetail(string first, string last, double credt, double pnt)
{
    stdfirstName = first;
    stdlstName = last;
    Ttlcrdt = credt;
    Ttlpnts = pnt;
}



double Student::getGPA() const
{
   
    if (Ttlcrdt == 0) {
        return -1;
    }
    return Ttlpnts / Ttlcrdt;



}