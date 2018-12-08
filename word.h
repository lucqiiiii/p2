#ifndef WORD_H
#define WORD_H
#include <iostream>
#include "list.h"
#include "itemtype.h"

using namespace std;

struct dnode{
        string word;
        dnode* next;
        dnode* prev;
        list* word_list;
    };

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
    dnode* get_head(){ return head; }
  //  string get_info(const string& i, int n);

private:
    dnode* head;
};

/*dnode* list_search(dnode* head, const string& x){
    dnode *cursor;
    for(cursor = head; cursor != NULL; cursor = cursor -> next){
        if(cursor -> word == x){
            return cursor;
        }
    return NULL;
}*/
#endif
