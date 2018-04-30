#include <iostream>
#include <cstring> 
#include <string> // look for file in standard library
#include "ToDo.h" // look for the file here (custom file header)

using namespace std;

	ToDo::ToDo () {
		ToDo (5);
	}

//create list of length len
	ToDo::ToDo (int len){
		length=len;
		list = new string [length]; // length -кол-во слов;
	}
	
	
	
	// need destructor to free memory
	// Destructor Delete the list - don't need to call it, it will be called automatically when the object is out of scope 
	ToDo::~ToDo () {
		//add save file
		delete [] list;
	}
	
	
	//ЗДЕСЬ поменяла string item на getline (cin, item) 
	void ToDo::add (string item){	
		getline (cin, item);
		
		if (next <length) {
			list [next] = item;
			next++;
		}
	}// add stuff to list
	
	void  ToDo::done ()	{
		next --;
		list [next] = "";
	}	// finish - delete the last thing in list
	
	// почему то печатается БЕЗ первого слова..
	void ToDo::print ()	{
		for (int i=0;i<next; i++) {
			cout << i << list [i] << endl;
		}
	}