#ifndef WORD_H
#define WORD_H
#include <iostream>
using namespace std;

class word
{
public:
    //constructor:
    word();
    //destructor:
    ~word();
    //modifiers:
    void insert(const string& w);
    void printw();
private:
    struct dnode{
        string word;
        dnode* next;
        dnode* prev;
    };
    dnode* head;
};

#endif
