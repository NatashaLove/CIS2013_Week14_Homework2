#include <iostream>
#include <cstring>
#include <string> 
using namespace std;

// g++ main.cpp ToDo.cpp

class ToDo {
	private: 
	string *list; // will be array - list of strings (words);
	int length =0;
	int next=0;
	string item;
	
	public:
	
	// default constructor
	ToDo ();
	
	//create list of length len
	ToDo (int len);
	
	~ToDo (); // Destroy the list
	
	// add stuff to list
	//ЗДЕСЬ поменяла string item на getline (cin, item) 
	void add (string item);
	void  done (); // finish/deletes the last thing in list
	
	// почему то печатается БЕЗ первого слова..
	void print ();
	
	
	
};