#include <iostream>
#include <fstream>
#include <string>
#include "ToDo.h"

using namespace std;

int main(){
	
	char next;
	int len = 0;
	string action;
	
	cout << endl;
	cout << "	How long do you want your list: ";
	cin >> len;
	
	ToDo list(len);
	
	// Array of ToDo objects
	// Make sure you have a () constructor
	//ToDo manylists[10];
	
	// manylists[2].print();
	// manylists[1].print();
	
	while(next != 'x'){
		cout << endl;
		cout << "Add to list (a)" << endl;
		cout << "Done list item (d)" << endl;
		cout << "Print list (p)" << endl;
		cout << "Exit list app (x)" << endl;
		cout << "What do you want to do: "<< endl;
		cout << endl;
		cin >> next;
		cin.ignore();
		cout << endl;
		
		switch(next){
			case 'a':
				cout << "	Name a todo item: ";
				//cin >> action;
				//ЗДЕСЬ поменяла cin >> action на getline (cin, action)
				getline(cin, action, '\n');
				list.add(action);
				break;
			case 'd': 
				{
				cout << "	Number of the item in the list to delete: ";
				int n;
				cin >> n;
				cin.ignore();
				list.done(n);
				}
				break;
			case 'p':
			
				list.print();
				break;
			case 'x':
				//exit (1); - файл не сохраняется из-за того, что ты выходишь из программы насильно, при помощи exit(1);
				// в этом случае деструктор локальной переменной list не будет вызван
				
				// All done with todo list
				break;
			default : 
		cout << "	Illegal value." << endl;
		cout << endl;
				break;
		}
	}
}