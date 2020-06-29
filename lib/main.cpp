#include <iostream>
#include "include\structures.h"
using namespace std;

template<typename T>
void printit(CDLL<T>* L)
{
    cout << '\n';
    for(int t = 0; t < L->perimeter; t++)
    {
        cout  << ' ' << L->curr() << ' ';
        L->seek(1);
    }
    cout << '\n';
}

/*
        void push(T value);
        void link(node<T>* A, node<T>* B);
        bool EmptyCheck(node<T>* node);
        void pop();
        T first();
        T next();
        void seek(node<T>* node);
        void seek(int times);
        bool contains(T value);
        int pos(T value);
        int pos(node<T>* node);
        T curr();
*/

int main()
{
    CDLL<int> d;
    char* c;
    int arg;

    while(1)
    {
        cout << "\n/msc24x/- ";
        cin >> c;

        switch (c):
        {
        case "push":
            cin >> arg;
            d.push(arg);
            break;
        case "pop":
            d.pop();
            break;
        case "first":
            cout << d.first;
            break;
        case "next":
            cout << d.next();
            break;
        case "seek":
            cin >> arg;
            d.seek(arg);
            break;
        case "contains":
            cin >> arg;
            cout << d.contains(arg);
            break;
        case "pos":
            cin >> arg;
            cout << d.pos(arg);
            break;
        case "curr":
            cout << d.curr();
            break;
        case "perimeter":
            cout << d.perimeter;
            break;
        case "cls":
            system(cls);
            break;
        case "exit":
            return 0;
        default:
            cout << "unrecognized command\n";
        }
    }
    return 0;
}
