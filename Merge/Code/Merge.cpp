#include<iostream>
#include <Merge.h>

using namespace std;

/* insert the node's data into the list */
RESULT list::insertlist(int data)
{
    Node *Temp = N;
    /* If its first node */
    if (Temp == NULL)
    {
          N = new Node();
          N->data = data;
          N->next= NULL;

          return TRUE;
    }
    /* If its middle node */
    else
    {
        while (Temp->next != NULL)
        {
            Temp= Temp->next;
        }

        Temp->next = new Node();
        Temp->next->data = data;
        Temp->next->next = NULL;
    }
    return TRUE;
}

/* print the list */

RESULT list::printlist()
{
   Node *Temp = N;
   while (Temp!= NULL)
   {
        cout<<" "<<Temp->data<<" ";
        Temp= Temp->next;
    }

    return TRUE;

}

RESULT list::printlist(Node *node)
{

   while (node!= NULL)
   {
        cout<<" "<<node->data<<" ";
        node= node->next;
    }

    return TRUE;

}

/*Merging Two Already Sorted Linked Lists */

Node* list::mergelist( Node* head1 , Node* head2)
{
    list l3;


    /* If both lists are empty*/
    if((head1 == NULL) && (head2 == NULL))
        return NULL;

    /* If both lists are not empty*/
    while ( (head1 != NULL) && (head2 != NULL))
    {
        /* if list1 node's data less than the list2 node's data */
        if(head1->data<head2->data)
        {
            l3.insertlist(head1->data);
            head1 = head1->next;
            continue;
        }
        /* if list2 node's data less than the list1 node's data */
        else
        {
            l3.insertlist(head2->data);
            head2 = head2->next;
            continue;
        }

        /* if list2 node's data equal to the list1 node's data */
        if(head1->data == head2->data)
        {
            l3.insertlist(head1->data);
            l3.insertlist(head2->data);
            head1 = head1->next;
            head2 = head2->next;
        }

    }

   /* If list2 is empty */
   if(head1!=NULL)
    {
        while (head1!= NULL)
        {
            l3.insertlist(head1->data);
            head1= head1->next;
        }

    }

    /* If list1 is empty */
    if(head2!=NULL)
    {
        while (head2!= NULL)
        {
            l3.insertlist(head2->data);
            head2= head2->next;
        }

    }

   return l3.getheadptr();

}

