/*--------------------------------------------------------------------------------------
* Date :- 10/1/2022 A.D.
Name :- Suresh khaniya
Submitted to :- Professor  Michael E. Thompson
Description :- Rest of the information goes here.
*/
#include <iostream>
#include <iomanip>   // for setprecison, setw, ctime.
#include <string>
#include "student.h"              // from header file 



using namespace std;

// function prototype given 

void enterStudentInfo(Student[], int);   
void printStudents(Student[], int);
void sortLastName(Student[], int);
void sortGPA(Student[], int);



const int MAX_STUDENTS = 6;   //global constant above int main(given)

int main() {
    string firstName;
    string lastName;
    double  credits;
    double points;
    int nostds;
    Student students[MAX_STUDENTS];
    double GPA;



    cout << "Please enter the number of students : " << endl;
    cin >> nostds;


    // Data validation as per asked.
    //using while loop.


    while (nostds > MAX_STUDENTS && nostds <=0)
    {
        cout << "Please enter a number of student between 0 to 6 :" << endl;
    }



    for (int i = 0; i < nostds; i++)
    {
        enterStudentInfo(students, i);
    }


    // sorted by last name and GPA

    cout << "Students by Last Name:" << endl;
    sortLastName(students, nostds);
    printStudents(students, nostds);



    cout << "Students by GPA: " << endl;
    sortGPA(students, nostds);
    printStudents(students, nostds);
}



void enterStudentInfo(Student array[], int stdnumber)
{
    string frstname;
    string lastName;
    double credits;
    double points;

    //given the format

    cout << "Please enter the first name of student: " << stdnumber << ".";
    cin >> frstname;
    cout << "Please enter the lase name of student " << stdnumber << ".";
    cin >> lastName;
    cout << "Please enter the total credits of student " << stdnumber << ".";
    cin >> credits;
    cout << "Please enter the total points of student " << stdnumber << ".";
    cin >> points;


    // credit validation
    while (credits < 0)
    {
        cout << "Please enter a valid number of credits: ";
        cin >> credits;
    }

    //point validation
    while (points < 0 || points > 0)
    {
        cout << "Please enter a valid number of points: ";
        cin >> points;



    }
    array[stdnumber].studentsdetail(frstname, lastName, credits, points);
}




// table of output for the array
void printStudents(Student array[], int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << left << setw(12) << array[i].getfirstName();
        cout << left << setw(12) << array[i].getLastName();
        cout << right << setw(7) << setprecision(3) << array[i].getGPA() << endl;



    }
}

// sorting array here.


void sortLastName(Student array[], int khaniya)
{
    int i = 0;
    int j = 0;
    Student temp;



    for (i = 1; i < khaniya; ++i) {
        j = i;



        while (j > 0 && array[j].getLastName() < array[j - 1].getLastName()) {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            --j;
        }
    }
}