#ifndef WORD_H
#define WORD_H
#include <iostream>
#include "list.h"
#include "itemtype.h"

using namespace std;

class word
{
public:
    //constructor:
    word();
    //destructor:
    ~word();
    //modifiers:
    void insert(const string& w, const string& fname);
    void printw();
    bool list_search(string x);
    string get_info(const string& i, int n);

private:
    struct dnode{
        string word;
        dnode* next;
        dnode* prev;
        list* word_list;
    };
    dnode* head;
};

#endif
