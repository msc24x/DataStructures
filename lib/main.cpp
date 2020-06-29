#include <iostream>
#include "structures.h"
using namespace std;

template <typename T>
void printit(CDLL<T> *L)
{
	cout << '\n';
	for (int t = 0; t < L->perimeter; t++)
	{
		cout << ' ' << L->curr() << ' ';
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

const int map(string cmd)
{
	string cmds[] = {"default", "push", "pop", "first", "next", "seek", "contains", "pos", "curr", "perimeter", "cls", "exit"};
	for (int t = 1; t < 11; t++)
	{
		if (cmds[t] == cmd)
			return t;
	}
	return 0;
}

int main()
{
	CDLL<int> d;
	string c;
	int arg, intc;

	while (1)
	{
		cout << "\n/msc24x/- ";
		cin >> c;
		intc = map(c);

		switch (intc)
			{
			case 1:{
				cin >> arg;
				d.push(arg);
				break;}
		case 2:{
			d.pop();
			break;}
		case 3:{
			cout << d.first();
			break;}
		case 4:{
			cout << d.next();
			break;}
		case 5:{
			cin >> arg;
			d.seek(arg);
			break;}
		case 6:{
			cin >> arg;
			cout << d.contains(arg);
			break;}
		case 7:{
			cin >> arg;
			cout << d.pos(arg);
			break;}
		case 8:{
			cout << d.curr();
			break;}
		case 9:{
			cout << d.perimeter;
			break;}
		case 10:{
			//system(cls);
			break;}
		case 11:{
			return 0;}
		default:{
			cout << "unrecognized command\n";}
		}
	}
	return 0;
}
