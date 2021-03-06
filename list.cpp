//Qi Guo Project2
#include "list.h"
#include <iostream>
using namespace std;

//Constructor
list::list(){
    head = NULL;
}

//Destructor
list::~list(){
    ldnode *n = head;
    while(n){
        ldnode *garbage = n;
        n = n -> next;
        delete garbage;
    }
}

void list::add(const string& f){
    if(head == NULL){ //the list is empty
        head = new ldnode;
        (head -> file).set_filename(f);
        (head -> file).inc_count();
    }
    else{ //already a list for that word
        ldnode *n = head;
        while(n -> next){ //check not the last node
            if((n -> file).filename() == f){ //check have that fname
               (n -> file).inc_count();
               sort(n);
               return;
            }
            n = n -> next;
        }
        if((n -> file).filename() == f){ //check last node
            (n -> file).inc_count();
            sort(n); 
            return;
        }
        //does not have that fnmae
        ldnode *temp = new ldnode;
        (temp -> file).set_filename(f);
        (temp -> file).inc_count();
        // insert to the right spot
        ldnode *h = head;
        temp -> prev = n;
        n -> next = temp;
        
    }
}

void list::sort(ldnode* q){
    if(q == head){ //head
        return;
    }
    if((q -> prev -> file).count() >= (q -> file).count()){
        return;
    }
    if(q -> next == NULL){ // tail
        ldnode *ptr = q;
        q -> prev -> next = NULL;
        ldnode *cursor = head;
        while((cursor -> file).count() >= (q -> file).count()){
            cursor = cursor -> next;
        }
        if(cursor != head){
        ptr -> prev = cursor -> prev;
        cursor -> prev = ptr;
        ptr -> next = cursor;
        ptr -> prev -> next = ptr;
        }
        else{
        ptr -> prev = NULL;
        cursor -> prev = ptr;
        ptr -> next = cursor;
        head = ptr;
        }
        return;
    }

    if((q -> file).count() <= (q -> prev -> file).count()){
        return;
    }

    else{
        ldnode *ptr = q;
        q -> next -> prev = q -> prev;
        q -> prev -> next = q -> next;
        ldnode *cursor = head;
        while((cursor -> file).count() > (q -> file).count()){
            cursor = cursor -> next;
        }
        if(cursor != head){
        ptr -> prev = cursor -> prev;
        cursor -> prev = ptr;
        ptr -> next = cursor;
        ptr -> prev -> next = ptr;
        }
        else{
        ptr -> prev = NULL;
        cursor -> prev = ptr;
        ptr -> next = cursor;
        head = cursor;
        }
        return;
    }
}

void list::printl(){
    ldnode* temp = head;
    while(temp){
        cout << (temp -> file).filename() << " and " << (temp -> file).count() << endl;
        temp = temp -> next;
    }
    
}
