//  Circular Doubly Linked List
// ----COMMANDLINE-INTERFACE----
//  Author : Maninderpal Singh
//  https://github.com/msc24x

#include <iostream>
#include "include/CDLL.h"
using namespace std;

string cmds[] = {"default", "push", "pop", "first", "next", "seek", "contains", "pos", "curr",
                "perimeter", "cls", "exit", "prev", "insert", "destroy", "destroypos", "show",
                "help", "wash"};

template <typename T>
void printit(CDLL<T> *L)
{
	cout << "{ ";
	L->seek(L->head);
	if(L->perimeter != 0)cout << L->curr() << ", ";
	else cout << "EMPTY, ";
	for (int t = 0; t < L->perimeter - 1; t++)
	{
		cout << L->next() << ", ";
	}
	cout << "\b\b }\n";
}

void help()
{
    for (int t = 1; t <= sizeof(cmds)/sizeof(string); t++)
        cout << "         " << cmds[t] << "\n" ;
}

const int map(string cmd)
{
	for (int t = 1; t <= sizeof(cmds)/sizeof(string); t++)
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
	int arg, intc, arg2;

	while (1)
	{
		cout << "/msc24x-CDLL-d-int-" << d.perimeter << "/- ";
		cin >> c;
		for(int i = 0; i <sizeof(c)/sizeof(char); i++)c[0+i] =  std::tolower(c[0+i]);
		intc = map(c);

		switch (intc)
        {
        case 1:
            cin >> arg;
            d.push(arg);
            break;

		case 2:
			d.pop();
			break;

		case 3:
			cout << d.first();
			break;

		case 4:
			cout << d.next();
			break;

		case 5:
			cin >> arg;
			d.seek(arg);
			break;

		case 6:
			cin >> arg;
			cout << d.contains(arg);
			break;

		case 7:
			cin >> arg;
			cout << d.pos(arg);
			break;
		case 8:
			cout << d.curr();
			break;

		case 9:
			cout << d.perimeter;
			break;

		case 10:
			system("cls");
			break;

		case 11:
			return 0;

        case 12:
            cout << d.prev();
            break;

        case 13:
            cin >> arg >> arg2;
            d.insert(arg, arg2);
            break;

        case 14:
            cin >> arg;
            d.destroy(arg);
            break;

        case 15:
            cin >> arg;
            d.destroyPos(arg);
            break;

        case 16:
            printit(&d);
            break;

        case 17:
            help();
            break;

        case 18:
            d.wash();
            break;

		default:
			cout << "unrecognized command: try using \"help\"\n";
		}
	}
	return 0;
}
