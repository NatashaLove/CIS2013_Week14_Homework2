#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 
using namespace std;

// g++ main.cpp ToDo.cpp

class ToDo {
	private: 
	string file_name = "todo.dat";
	string *list; // will be array - list of strings (words);
	int length =0;
	int next=0;
	string item;
	void file_read();
	void file_save();
	
	
	public:
		
	// default constructor
	ToDo ();
	
	//create list of length len
	ToDo (int len);
	
	~ToDo (); // Destroy the list
	
	// add stuff to list
	//ЗДЕСЬ поменяла string item на getline (cin, item) 
	void add (string item);
	void done (); // finish/deletes the last thing in list
	void done(int n); // deletes the chosen item
	// 
	void print ();
	
	// int getLength(); - думал записывать в файл кол-во элементов, чтобы не обрезать при чтении из файла, т.е. всегда создавать лист достаточной длины
	// но сейчас при чтении из файла, добавляем в лист только те элементы, которые влезают
	
	
};