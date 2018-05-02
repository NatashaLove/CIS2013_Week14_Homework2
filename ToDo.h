#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 
using namespace std;

// g++ main.cpp ToDo.cpp

class ToDo {
	private: 
	string file_name = "todo.txt";
	string *list; // will be array - list of strings (words);
	int length =0;
	int next=0;
	string item;
	
	public:
	
	void file_read();
	void file_save();
	
	// default constructor
	ToDo ();
	
	//create list of length len
	ToDo (int len);
	
	~ToDo (); // Destroy the list
	
	// add stuff to list
	//ЗДЕСЬ поменяла string item на getline (cin, item) 
	void add (string item);
	void  done (); // finish/deletes some thing in list
	
	// 
	void print ();
	
	int getLength();
	
	
};