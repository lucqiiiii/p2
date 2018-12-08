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
   /*            //Order
               ldnode *h = head;
               //count greater than the head
               if(n == head){
                    return;
               }
               if((n -> file).count() > (h -> file).count()){
                   n -> next -> prev = n -> prev;
                   n -> prev -> next = n -> next;
                   n -> next = h;
                   h -> prev = n;
                   head = n;
               }
               else{
                   while((h -> file).count() > (n -> file).count()){
                       h = h -> next;
                   }   
                       n -> next -> prev = n -> prev;
                       n -> prev -> next = n -> next;                       
                       n -> prev = h -> prev;
                       h -> prev = n;
                       n -> next = h;
                       n -> prev -> next = n;
                      
               }        */
               return;
            }
            n = n -> next;
        }
        if((n -> file).filename() == f){ //check last node
            (n -> file).inc_count();
            sort(n);
    /*        if(n -> next == NULL && n -> prev == NULL){ // there is only one node 
                return;
            }
             
             ldnode *h = head;
               //count greater than the head
               if((n -> file).count() > (h -> file).count()){
                   n -> next -> prev = n -> prev;
                   n -> prev -> next = n -> next;
                   n -> next = h;
                   h -> prev = n;
                   head = n;
               }
               else{
                   while((h -> file).count() > (n -> file).count()){
                       h = h -> next;
                   }   
                       n -> next -> prev = n -> prev;
                       n -> prev -> next = n -> next;                       
                       n -> prev = h -> prev;
                       h -> prev = n;
                       n -> next = h;
                       n -> prev -> next = n;
                      
               }      */ 
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
    int n = 0;
    ldnode *ptr = q;
    if(ptr -> next == NULL){ //only one node
        return;
    }
    ldnode *end;
    ldnode *temp;
    
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }
    while(ptr -> prev != NULL){
        end = ptr;
        temp = ptr -> prev;
        ptr = ptr -> prev;
            while(temp != NULL && (temp -> file).count() >= (end -> file).count()){
                temp = temp -> prev;
                n++;
            }
            if(n){
                if(temp == NULL){
                    temp = q;
                    end -> prev = NULL;
                    end -> next = temp;
                    end -> next -> prev = end;
                    q = end;
                }
                else{
                    temp -> prev -> next = end;
                    end -> prev = temp -> prev;
                    temp -> prev = end;
                    end -> next = temp;
                }
                ptr -> next = NULL;
           }
      }
}
void list::printl(){
    ldnode* temp = head;
    while(temp){
        cout << (temp -> file).filename() << " and " << (temp -> file).count() << endl;
        temp = temp -> next;
    }
    
}
