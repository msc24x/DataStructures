//  Circular Doubly Linked List
//----------SOURCE-CODE----------
//  Author : Maninderpal Singh
//  https://github.com/msc24x

#ifndef CDLL_H
#define CDLL_H
#include <iostream>


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
        node<T>* head = NULL;

        void push(T value);
        void pop();
        T first();
        T next();
        T prev();
        void seek(node<T>* node);
        void seek(int times);
        bool contains(T value);
        int pos(T value);
        int pos(node<T>* node);
        T curr();
        void insert(T value, int index);
        void destroyPos(int index);
        void destroy(T value);
        void wash();



    private:

        node<T>* curr_node = new node<T>;
        node<T>* temp = new node<T>;

        bool EmptyCheck(node<T>* node);
        void link(node<T>* A, node<T>* B);


};

template<typename T>
void CDLL<T>::wash()
{
    while(perimeter) pop();
}

template<typename T>
void CDLL<T>::destroy(T value)
{
    if(head != NULL)
    {
        temp = head;
        do{
            if(temp->val == value)
            {
                if(temp == head)
                {
                    destroyPos(0);
                }else{
                    node<T>* d = new node<T>;
                    d = temp;
                    link(temp->prev, temp->next);perimeter--;
                    delete d;
                }
            }
            temp = temp->next;
            break;
        }while(temp != head);
    }
}

template<typename T>
void CDLL<T>::destroyPos(int index)
{
    if(index > perimeter)
        index %= perimeter;
    if(perimeter == 1 && index == 0)
        pop();
    else if(head != NULL)
    {
        if(index == 0)
        {
            node<T>* d = new node<T>;
            temp = head->next;
            d = head;
            link(head->prev, head->next);perimeter--;
            delete d;
            head = temp;

        }else {
            seek(head);
            seek(index);
            node<T>* d = new node<T>;
            d = curr_node;
            link(curr_node->prev, curr_node->next); perimeter--;
            delete d;
        }
    }
}

template<typename T>
void CDLL<T>::insert(T value, int index)
{
    if(index > perimeter && perimeter != 0)
        index %= perimeter;
    if(head != NULL)
    {
        node<T>* newnode = new node<T>;
        newnode->val = value;
        seek(head);
        seek(index);
        link(curr_node->prev, newnode);
        link(newnode, curr_node);
        perimeter++;
    }
    else{
        push(value);
    }
}


template<typename T>
T CDLL<T>::prev()
{
    if(head != NULL){
        if(curr_node->prev != NULL)
        {
            curr_node = curr_node->prev;
            return curr_node->val;
        }
    }
    return NULL;
}

template<typename T>
T CDLL<T>::curr()
{
    if(curr_node != NULL)
    {
        return curr_node->val;
    }
    return NULL;
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
    if(head != NULL){
        if(curr_node->next != NULL)
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
    if(head != NULL) return head->val;
    return NULL;
}


template<typename T >
void CDLL<T>::pop()
{
    if(head == NULL){}
    else if(head->prev == head || head->next == head)
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
    {
        head = newnode;
        curr_node = head;
    }
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
