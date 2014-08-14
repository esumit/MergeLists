
#ifndef _H_MERGE_H_
#define _H_MERGE_H_

#include <cstdlib>

/* node represents one node in a linked list */
class Node
{

public:
    Node():data(0),next(NULL){};
    int data;
    Node *next;
};

/* enum RESULT to return the staus of the function */
enum RESULT { TRUE,FALSE};

/* class lists - to create single linked lists , and then merge together */
class list
{

public:

RESULT insertlist(int );
RESULT printlist();
RESULT printlist(Node*);
Node* mergelist( Node* head1 , Node* head2);
Node* getheadptr() const { return N;}

list():N(NULL){};

private:

    Node *N;

};

#endif // _H_MERGE_H_
