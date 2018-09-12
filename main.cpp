/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on August 16, 2018, 10:39 PM
 */

#include <cstdlib>
//#include <cstdint>
#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

/*
 * 
 */

struct Node {
    int data;
    Node* next;
};

Node* headGlobalVar = NULL;

/////// Inserting Node to Beginning of The List ///////////////////////
/////// If Global Variable is not used as Node* head at the top ///////

void InsertToBeginnigOfListWithLocalVar(Node** head, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (*head != NULL)
        temp->next = *head;
    *head = temp;
}
////////////////////////////////////////////////////////////


/////// Inserting Node to Beginning of The List ////////////////////
/////// If Global Variable is used as Node* head at the top ///////

void InsertToBeginnigOfListWithGlobalVar(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (headGlobalVar != NULL)
        temp->next = headGlobalVar;
    headGlobalVar = temp;
}
/////////////////////////////////////////////////////////////////////

/////// Inserting Node to Nth Position of The List ////////////////////
/////// If Global Variable is used as Node* head at the top ///////

void InsertToNthPositionOfList(int x, int n) {

    cout << "//////Inserting nth pos ////////" << endl;
    Node* temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;

    if (n == 0) {
        InsertToBeginnigOfListWithGlobalVar(x);
        return;
    }

    Node* temp = headGlobalVar;

    int f = M_PI; // Pi sayısı

    for (uint8_t i = 0; i \
            < n - 1; i++) {
        temp = temp->next;
    }

    temp1->next = temp->next;
    temp->next = temp1;

}
/////////////////////////////////////////////////////////////////////

/////// Inserting Node to Nth Position of The List ////////////////////
/////// If Global Variable is used as Node* head at the top ///////

void DeleteFromNthPositionOfList(int n) {

    Node* temp1 = headGlobalVar;

    if (n == 0) {
        headGlobalVar = temp1->next;
        delete temp1;
        return;
    }

    //Node* before;

    for (int i = 0; i < n - 2; i++)
        temp1 = temp1->next;
    cout << "temp1 datası  :" << temp1->data << endl;

    Node* nthNode = temp1->next;

    cout << "nthNode datası  :" << nthNode->data << endl;

    temp1->next = nthNode->next;
    delete nthNode;


    //    cout << "before datası  :" << before->data << endl;
    //    cout << "temp1 datası  :" << temp1->data << endl;
    //    before->next = temp1->next;
}

Node* ReverseLinkListWithIterativeMethod(Node* head) {
    cout << "iterative method begins" << endl;
    Node *prev, *current, *next;

    prev = NULL;
    current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    headGlobalVar = prev;

    return headGlobalVar;


}

void ReverseLinkListWithRecursionGlobalVar(Node* p) {

    if (p == NULL)
        return;

    if (p->next == NULL) {
        headGlobalVar = p;
        return;
    }
    ReverseLinkListWithRecursionGlobalVar(p->next);
    Node *q = p->next;
    q->next = p;
    p->next = NULL;


}

/////////////Aşağıdaki fonksiyonun Doğru olup olmadığını bilmiyorum.

Node* ReverseLinkListWithRecursionLocalVar(Node* head) {

    Node* temp = head;

    if (temp == NULL)
        return NULL;

    if (temp->next == NULL) {
        head = temp;
        return head;
    }
    ReverseLinkListWithRecursionLocalVar(temp->next);
    Node* q = temp->next;
    q->next = temp;
    temp->next = NULL;
}

int main(int argc, char** argv) {

    bitset<8> inputBits (8);
    
    string getInfo;
    getline(cin, getInfo);

    cout << getInfo.length() << endl;

    // cout<<getInfo<<endl;

    Node* headLocalVar;

    for (unsigned short i = 0; i < 5; i++) {
        InsertToBeginnigOfListWithLocalVar(&headLocalVar, i);
    }

    for (int i = 0; i < 5; i++) {
        InsertToBeginnigOfListWithGlobalVar(i);
    }

    while (headLocalVar->next != NULL) {
        cout << headLocalVar->data << endl;
        headLocalVar = headLocalVar->next;
    }

    Node* temp = headGlobalVar;

    while (temp->next != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }


    InsertToNthPositionOfList(2, 0);
    InsertToNthPositionOfList(4, 0);
    InsertToNthPositionOfList(45, 5);

    DeleteFromNthPositionOfList(1);



    Node* temp1 = headGlobalVar;

    while (temp1 != NULL) {
        cout << temp1->data << endl;

        temp1 = temp1->next;

    }



    headGlobalVar = ReverseLinkListWithIterativeMethod(headGlobalVar);

    temp1 = headGlobalVar;

    cout << "iterative method with global var begins" << endl;

    while (temp1 != NULL) {
        cout << temp1->data << endl;

        temp1 = temp1->next;

    }
    //   cout<<"global var ın adresi  :  "<<headGlobalVar<<endl;


    ReverseLinkListWithRecursionGlobalVar(headGlobalVar);

    cout << "recursion method with global var begins" << endl;
    //    cout<<"global var ın fonksiyon sonu adresi  :  "<<headGlobalVar<<endl;

    temp1 = headGlobalVar;

    while (temp1 != NULL) {
        cout << temp1->data << endl;
        temp1 = temp1->next;
    }




    return 0;
}

