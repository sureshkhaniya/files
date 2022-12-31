/*
Name:- Suresh Khaniya
Submitted to :- Professor Michael Thompson
Description:- To develop a program that simulates the First Come First Served and Round Robin methods of CPU scheduling
*/
#include <iostream>
#include "Process.h"  // include of header file.
#include <fstream>  //Enables use of the file stream class
#include <string>  // for string type
#include <iomanip> // for setw

using namespace std;

struct ProcessNode {  //declaring structure ProcessNode
    Process data;    // class is Process; That is why data type is Process.
    ProcessNode* next;

};

//function prototypes
void appendProcess(ProcessNode*&, ProcessNode*&, Process);
void removeProcess(ProcessNode*&, ProcessNode*&, Process);
void printProcesses(ProcessNode*, int);

// Appends a process to the circular list
void appendProcess(ProcessNode*& head, ProcessNode*& tail, Process val) {
    ProcessNode* temp;
    temp = new ProcessNode;  // Making a newNode 
    temp->data = val;
    temp->next = nullptr;

    if (head == nullptr) {       // when list is empty
        head = temp;
        tail = head;
        head->next = head;
    }
    else {
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }
}


void removeProcess(ProcessNode*& head, ProcessNode*& tail, Process processVal) {   //Removes the Process from the circular list having the same name as the Process passed to the function
    ProcessNode* tempNode;
    if (head != nullptr) {
        if (head->data.getName() == processVal.getName())
        {
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                tail->next = head;
            }
        }
        else
        {
            tempNode = head;
            while (tempNode->next != head && tempNode->next->data.getName() != processVal.getName())
            {
                tempNode = tempNode->next;

            }

            if (tempNode->next != head)

            {
                if (tempNode->next == tail) {
                    tail = tempNode;
                    tail->next = head;
                }
                else
                {
                    tempNode->next = tempNode->next->next;
                }
            }

        }
    }

}



void printProcess(ProcessNode* head, int numval) {   //  sort of traverse for Singly Linked list (from zybooks)
    ProcessNode* currNode;
    currNode = head;

    if (head != nullptr) {

        cout << setw(8) << right << "Name" << " " << setw(12) << right << "Duration" << " " << setw(9) << right << "Wait" << " ";
        cout << endl;

        do {
            cout << setw(8) << right << currNode->data.getName() << " " << setw(12) << right << currNode->data.getDuration() << " " << setw(9) << right << currNode->data.getWait() << " ";
            cout << endl;
            currNode = currNode->next;
        } while (currNode != head);
    }

    double sum = 0;   
    double average = 0;

   // To calculate the average  of waittime.
    for (int i = 0; i < numval; i++) {
        sum += currNode->data.getWait();
        currNode = currNode->next;
    }
    average = sum / numval;
    cout << setw(20) << right << "Average Wait is " << fixed << setprecision(3) << average << endl;



}



int main() {


    ProcessNode* head = nullptr;//circular list 1
    ProcessNode* tail = nullptr;


    ProcessNode* head2 = nullptr; //circular list 2
    ProcessNode* tail2 = nullptr;

    ProcessNode* temp1 = head; //for FCFS 
    ProcessNode* temp2 = head2;//for ROundRobin


    //variables for file.
    ifstream infs;
    string  userfilename;
    int numdata;
    string infsname;
    double infsduration;
    Process temprun;



    int quantum;


    cout << "Please enter the name of the file with extension (.txt) to open : ";
    cin >> userfilename;

    infs.open(userfilename);  // opening the file 


    system("cls");
    if (!infs.is_open()) {//if(in.is_open() == false
        do {
            cout << "Error!. It is a wrong file name or it does not exist!";
            cout << endl;
            cout << " Please enter the Correct file name with .txt extension : ";
            cout << endl;
            cin >> userfilename;
            infs.open((userfilename));
           
        } while (!infs.is_open());    //User file validation.
    }

    // taking input from the file
    infs >> numdata;
    for (int i = 0; i < numdata; i++) {  // data entry from file depending on numdata;
        infs >> infsname;
        infs >> infsduration;
        temprun.init(infsname, infsduration);
        appendProcess(head, tail, temprun);
    }

     

    system("cls");
   
    char input;
    cout << " Please  F/f for FCFS (First come first served) or R/r for (Round Robin) " << endl;
    cin >> input;

    while (input != 'F' && input != 'f' && input != 'R' && input != 'r') {  // char Validation
        cout << "Please enter a valid character for the game :";
        cin >> input;
    }

    double time = 0;
    switch (input) {
    case 'F':
    case 'f':
        while (head != nullptr) {
         
            temp1->data.calculateWait(time);
            temp1->data.run(temp1->data.getDuration());
            time += temp1->data.getDuration();

            removeProcess(head, tail, temp1->data);
            appendProcess(head2, tail2, temp1->data);
            temp1 = temp1->next;
        }
        break;

    case 'R':
    case 'r':
        cout << "Enter a quantum number ";
        cin >> quantum;

        while (quantum < 0) {   // Quantum time  Validation 

            cout << "Please enter the valid time :";
            cin >> quantum;
        }

        while (head != nullptr) {

           
            temp2->data.calculateWait(time);
            time = time +  temp2->data.run(quantum);
            if (temp2->data.getRemaining() == 0) {
                removeProcess(head, tail, temp2->data);
                appendProcess(head2, tail2, temp2->data);
            }
            else {

                temp2->data.setWaitStart(time);
            }
            temp2 = temp2->next;
        }
        break;


    }

    printProcess(head2,numdata);
    infs.close(); //closing file.
    return 0;



}



