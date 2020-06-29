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

int map(char* cmd)
{
   char* cmds[] = {"default", "push", "pop", "first", "next", "seek", "contains", "pos", "curr", "perimeter", "cls", "exit"};
   for(int t= 1 ; t< 12; t++)
   {
      if(cmds[t] == cmd)   return t;
   }
   return 0;
}

int main()
{
    CDLL<int> d;
    char* c;
    int arg;

    while(1)
    {
        cout << "\n/msc24x/- ";
        cin >> c;

        switch (map(c)):
        {
        case map("push"):
            cin >> arg;
            d.push(arg);
            break;
        case map("pop)":
            d.pop();
            break;
        case map("first"):
            cout << d.first;
            break;
        case map("next"):
            cout << d.next();
            break;
        case map("seek"):
            cin >> arg;
            d.seek(arg);
            break;
        case map("contains"):
            cin >> arg;
            cout << d.contains(arg);
            break;
        case map("pos"):
            cin >> arg;
            cout << d.pos(arg);
            break;
        case map("curr"):
            cout << d.curr();
            break;
        case map("perimeter"):
            cout << d.perimeter;
            break;
        case map("cls"):
            system(cls);
            break;
        case map("exit"):
            return 0;
        default:
            cout << "unrecognized command\n";
        }
    }
    return 0;
}
