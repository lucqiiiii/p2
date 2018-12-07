#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "itemtype.h"
using namespace std;

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
private:
    struct ldnode{
        itemtype file;
        ldnode* next;
        ldnode* prev;
    };
    ldnode* head;
};

#endif
