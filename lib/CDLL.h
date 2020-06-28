#ifndef CDLL_H
#define CDLL_H
#include <iostream>
using namespace std;
template <typename T> class node
{
    public:
        node* prev;
        T val;
        node* next;
};

template <typename T> class CDLL
{
   public:
        void push(T value);
        void link(node<T>* A, node<T>* B);
        void pop();
        
        T first();
        //T next();
        //bool contains(T value);
        //int pos(T value);

    private:
      node<T>* head = NULL;
};

template<typename T >
T CDLL<T>::first()
{
   try
   {
      if(head == NULL){ throw 0; }
   }
   catch(int EC)
   {
      cout << EC << ":EmptyList";
   }
   return head->val;
}


template<typename T >
void CDLL<T>::pop()
{
   try
   {
      if(head == NULL){ throw 0; }
   }
   catch(int EC)
   {
      cout << EC << ":EmptyList";
   }
   node<T>* tail = head->prev;
   link(tail->prev, head);
   delete tail;
}

template <typename T>
void CDLL<T>::push(T value)
{
    node<T>* newnode;
    newnode->prev = NULL;
    newnode->val = value;
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else
    {
        node<T>* temp = head;
        while(temp->next != head)
            temp = temp->next;
        link(temp, newnode);
        link(newnode, head);
    }
}

template <typename T>
void CDLL<T>::link(node<T>* A, node<T>* B)
{
    A->next = B;
    B->prev = A;
}
#endif // CDLL_H
