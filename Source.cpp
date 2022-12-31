/*
Name:- suresh khaniya
Date:- 11/21/2022 A.D.
Description:- This program will be to write a version of musical chairs, implemented using a circular, singly-linked list
*/
#include <iostream>
#include <string>    // for variable that has type string.
#include <cstdlib>  
#include <iomanip>
#include <Windows.h>  // for beep sound.



using namespace std;

struct ListNode      // Declaring Struct ListNode 
{
    string data;
    ListNode* next;
};

// Function Prototypes.
void addPlayer(ListNode*&, ListNode*&, string);
void printPlayers(ListNode*, ListNode*, string);
void playRound(ListNode*, ListNode*, long);
void removePlayer(ListNode*&, ListNode*&, string);
void removePlayerAfter(ListNode*&, ListNode*&, ListNode*);
ListNode* listSearch(ListNode*, ListNode*, string);   // no need to use it.

//Add a player to the end of the list when passed the head, tail, and that player’s name.

void addPlayer(ListNode*& head, ListNode*& tail, string nameplayer) {    //from zybooks
    ListNode* newNode;
    newNode = new ListNode;
    newNode->data = nameplayer;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;

    }
}

//Prints all the players in the list, given the head, tail, and the name of the player to draw arrows.
void printPlayers(ListNode* head, ListNode* tail, string nameofplayer) {
    ListNode* currNode;
   
    system("cls");
    if (head != nullptr) {
        currNode = head;
        do {
             cout << left << setw(12)<<currNode->data;
           
            currNode = currNode->next;
        } while (currNode != head);

      
    }

    cout << endl;
    if (head != nullptr) {
        currNode = head;
        do {
            if (currNode->data == nameofplayer) {
                for (int i = 0; i < nameofplayer.length(); i++) {
                    cout << "^";
                }


            }

            else {
                cout << setw(12) << " ";
            }
            currNode = currNode->next;
        } while (currNode != head);

      //  cout << endl;
    }

  
    currNode = head;      //traverse
    int count = 0;

    while (currNode->data != nameofplayer) {
        count = count + 1;
        currNode = currNode->next;

    }

    for (int i = 0; i < count; i++) {
        cout << setw(18) << endl;
    }

    cout << setw(18) << endl;

    cout << endl;

}



void removePlayerAfter(ListNode*& head, ListNode*& tail, ListNode* curNode) {   //from zybooks 17.23 circular lab.
    ListNode* sucNode;
    ListNode* toDelete;
    if (curNode == nullptr && head != nullptr)
    {
        sucNode = head->next;
        toDelete = head;
        head = sucNode;
        if (sucNode == toDelete) {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail->next = head;
        }

    }

    else if (curNode->next != nullptr)
    {
        sucNode = curNode->next->next;
        toDelete = curNode->next;

        curNode->next = sucNode;

        if (sucNode == head) {

            tail = curNode;
            tail->next = head;

        }
        delete toDelete;
    }


}

void removePlayer(ListNode*& head, ListNode*& tail, string nameofPlayers) // from zybooks 17.23(circular Lab)
{


    ListNode* temp;

    if (head != nullptr)
    {

        if (head->data == nameofPlayers)
        {

            removePlayerAfter(head, tail, nullptr);
        }
        else
        {

            temp = head;

            while (temp->next != head && temp->next->data != nameofPlayers)
            {

                temp = temp->next;

            }






            if (temp->next != head)
            {
                removePlayerAfter(head, tail, temp);

            }

        }
    }

}


void playRound(ListNode* head, ListNode* tail, long random1) {
    ListNode* currNode = head;
    long random2 = rand() % 601 + 100;
    int i;

    for (i = 0; i < random1; i++) {
        Beep(500,600);
        printPlayers(head, tail, currNode->data);
        currNode = currNode->next;
        Sleep(random2);
    }
    printPlayers(head, tail, currNode->data);
    cout << currNode->data << endl;
    cout << endl;
    removePlayer(head, tail, currNode->data);

}


int main()
{

    string nameofplayer;
    int numberofplayers;
    long random1;


    ListNode* head = nullptr;  //head point to nullptr
    ListNode* tail = nullptr;  //tail points to nullptr
    ListNode* temp = nullptr;  // temp points to nullptr;
    ListNode* newNode = nullptr;  //NewNode points to nullptr;


    cout << "Enter the number of players : ";
    cin >> numberofplayers;    // Asking from the User.

    random1 = rand() % 3 * numberofplayers + 1;       //random number to loop through as per question.


    while (numberofplayers > 7 || numberofplayers < 2) {   //Data Validation of the Input.
        cout << "Please enter the number of players between 2 and 7 : ";
        cin >> numberofplayers;
    }


    for (int i = 0; i < numberofplayers; i++) {

        cout << "Please enter the player " << i + 1 << " Name : ";
        cin >> nameofplayer;
        addPlayer(head, tail, nameofplayer);

        // passing name of player to addPlayer function.
    }
    do {
        printPlayers(head, tail, nameofplayer);
        playRound(head, tail, random1);
        system("pause");
    } while (head != tail);
    return 0;
}






