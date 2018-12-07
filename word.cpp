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

void word::insert(const string& w, const string& fname){
    if(head == NULL){ //empty list, first insertion
        head = new dnode;
        head -> word = w;
        head -> word_list = new list;
        head -> word_list -> add(fname);
    }
    else{
        dnode *n = head;
        while(n){ //check already exists
            if(n -> word == w){
                n -> word_list -> add(fname);
                return;
            }
            n = n -> next;
        }
        n = head;
        if((n -> word) > w){ //before the head
            dnode *temp = new dnode;
            temp -> word = w;
            temp -> word_list = new list;
            temp -> word_list -> add(fname);
            temp -> next = n;
            n -> prev = temp;
            head = temp;            
            return;
	}    
        while((n -> next) != NULL){ //is not the last node
            if((n -> word) < w){
                n = n -> next;
            } //before the given node
            else{
                dnode *temp = new dnode;
                temp -> word = w;
                temp -> word_list = new list;
                temp -> word_list -> add(fname);
                temp -> prev = n -> prev;
                n -> prev = temp;
                temp -> next = n;
                temp -> prev -> next = temp;
                return;
           }
        }
        
        //last node
        if((n -> word) < w){
            dnode *temp = new dnode;
            temp -> word = w;
            temp -> word_list = new list;
            temp -> word_list -> add(fname);
            temp -> prev = n;
            n -> next = temp;
            return;
        }
        else{
            dnode *temp = new dnode;
            temp -> word = w;
            temp -> word_list = new list;
            temp -> word_list -> add(fname);
            temp -> prev = n -> prev;
            n -> prev = temp;
            temp -> next = n;
            temp -> prev -> next = temp;
            return;
        }            
    }
}

void word::printw(){
    dnode* temp = head;
    while(temp){
        cout << temp -> word << endl;
        temp -> word_list -> printl();
        cout << endl;
        temp = temp -> next;
    }
}

dnode* list_search(const string& x){
    dnode *cursor;
    for(cursor = head; cursor != NULL; cursor = cursor -> next){
        if(cursor -> word == x){
            return cursor;
        }
    return NULL;
}





