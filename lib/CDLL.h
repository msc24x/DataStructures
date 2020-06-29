#ifndef CDLL_H
#define CDLL_H
#include <iostream>
#include <vector>

using namespace std;

template <typename T> class node
{
    public:
        node<T>* prev;
        T val;
        node<T>* next;
};

template <typename T> class CDLL
{
    public:
        int perimeter = 0;

        void push(T value);
        void pop();
        T first();
        T next();
        void seek(node<T>* node);
        void seek(int times);
        bool contains(T value);
        int pos(T value);
        int pos(node<T>* node);
        T curr();



    private:
        node<T>* head = NULL;
        node<T>* curr_node = head;
        node<T>* temp = new node<T>;

        bool EmptyCheck(node<T>* node);
        void link(node<T>* A, node<T>* B);


};

template<typename T>
T CDLL<T>::curr()
{
    if(curr_node != NULL)
    {
        return curr_node->val;
    }
}

template<typename T>
int CDLL<T>::pos(node<T>* node)
{
    int indx = 0;
    if(EmptyCheck(head))
    {
        temp = head;
        do
        {
            if(temp == node) return indx;
            temp = temp->next; indx++;
        }while(temp != head);
    }
    return NULL;
}


template<typename T>
int CDLL<T>::pos(T value)
{
    int indx = 0;
    if(EmptyCheck(head))
    {
        temp = head;
        do
        {
            if(temp->val == value) return indx;
            temp = temp->next; indx++;
        }while(temp != head);
    }
    return NULL;
}

template<typename T>
bool CDLL<T>::contains(T value)
{
    if(EmptyCheck(head))
    {
        temp = head;
        while(temp->next != head)
        {
            if(temp->val == value) return true;
            temp = temp->next;
        }
        return false;
    }
    return false;
}


template<typename T>
void CDLL<T>::seek(int times)
{
    if(EmptyCheck(curr_node))
    {
        if(times < 0)
        {
            times *= (-1);
            for(int t = 0; t < times; t++)
                curr_node = curr_node->prev;
        }
        else
        {
            for(int t = 0; t < times; t++)
                curr_node = curr_node->next;
        }
    }
}


template<typename T>
void CDLL<T>::seek(node<T>* node)
{
    curr_node = node;
}

template <typename T>
bool CDLL<T>::EmptyCheck(node<T>* node)
{
    try{if(node == NULL){ throw 0; }}catch(int EC){return false;}
    return true;
}

template<typename T >
T CDLL<T>::next()
{
    if(EmptyCheck(head)){
        if(EmptyCheck(curr_node->next))
        {
            curr_node = curr_node->next;
            return curr_node->val;
        }
    }
    return NULL;
}

template<typename T >
T CDLL<T>::first()
{
    if(EmptyCheck(head)) return head->val;
    return NULL;
}


template<typename T >
void CDLL<T>::pop()
{
    if(!EmptyCheck(head)){}
    else if(head->prev == head)
    {
        head = NULL;
        perimeter = 0;
    }
    else{
        node<T>* tail =  new node<T>;
        tail = head->prev;
        link(tail->prev, head);
        delete tail;
        perimeter--;
    }
}

template <typename T>
void CDLL<T>::push(T value)
{
    node<T>* newnode =  new node<T>;
    newnode->prev = newnode;
    newnode->val = value;
    newnode->next = newnode;
    if(head == NULL)
        head = newnode;
    else
    {
        link(head->prev, newnode);
        link(newnode, head);
    }
    perimeter++;
}

template <typename T>
void CDLL<T>::link(node<T>* A, node<T>* B)
{
    A->next = B;
    B->prev = A;
}
#endif // CDLL_H
