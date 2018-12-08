#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "itemtype.h"
using namespace std;

struct ldnode{
        itemtype file;
        ldnode* next;
        ldnode* prev;
    };

class list
{
public:
    //constructor:
    list();
    //destructor:
    ~list();
    //modifiers:
    void add(const string& w);
    void printl();
    
    ldnode* get_head(){ return head; }
private:
    ldnode* head;
};

#endif
