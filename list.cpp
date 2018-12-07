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
        while(n){ //check have that fname
            if((n -> file).filename() == f){
               (n -> file).inc_count();
            }
            n = n -> next;
        }
        //does not have that fnmae
        ldnode *temp = new ldnode;
        (temp -> file).set_filename(f);
        (temp -> file).inc_count();
        
    }
}

void list::printl(){
    ldnode* temp = head;
    while(temp){
        cout << (temp -> file).filename() << " and " << (temp -> file).count() << endl;
        temp = temp -> next;
    }
    
}
