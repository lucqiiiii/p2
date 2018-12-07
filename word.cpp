//Qi Guo Project2
#include "word.h"
#include <iostream>
using namespace std;

//Constructor
word::word(){
    head = NULL;
}

//Destructor
word::~word(){
    dnode *n = head;
    while(n){
        dnode *garbage = n;
        n = n -> next;
        delete garbage;
    }
}

void word::insert(const string& w){
    //dnode* wordnode = new dnode(word,NULL,NULL);
    if(head == NULL){
        head = new dnode;
        head -> word = w;
    }
    else{
        dnode *n = head;
        if((n -> word) > w){
            dnode *temp = new dnode;
            temp -> word = w;
            temp -> next = n;
            n -> prev = temp;
            head = temp;
            return;
        }    
        while((n -> word) < w && (n -> next) != NULL){ //to get to the spot
            n = n -> next;
        }
        dnode *temp = new dnode;
        temp -> word = w;
        temp -> prev = n;
        n -> next = temp;
    }
}

void word::printw(){
    dnode* temp = head;
    while(temp){
        cout << temp -> word << endl;
    }
}
