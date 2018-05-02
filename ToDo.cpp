#include <iostream>
#include <fstream>
#include <cstring> 
#include <string> // look for file in standard library
#include "ToDo.h" // look for the file here (custom file header)

using namespace std;

	ToDo::ToDo () {
	//	ToDo (5);
	}

//create list of length len
	ToDo::ToDo (int len){
		length=len;
		list = new string [length]; // length -кол-во слов;
		file_read();
	}
	
	
	
	// need destructor to free memory
	// Destructor Delete the list - don't need to call it, it will be called automatically when the object is out of scope 
	ToDo::~ToDo () {
		
		//add save file
		file_save();
		delete[] list;
		
	}
	
	void ToDo::file_save() {
		
		ofstream ofstr(file_name);
		if (!ofstr.fail()) {
			for (int i = 0;i < next;i++) {
				ofstr << list[i] << endl;
			}
			 ofstr.close();
			 //flush( );
		} 
		// else {
			// cout << "Input file opening failed.\n";
			// exit(1);
		// }
	}
	
	void ToDo::file_read() {
		
		ifstream ifstr(file_name);
		if (!ifstr.fail())
		{
			string s;
			while (getline(ifstr, s))
			{
				add(s);
			}
		}
	} 
	
	//ЗДЕСЬ поменяла string item на getline (cin, item) 
	void ToDo::add (string item){	
		//getline (cin, item);
		
		if (next <length) {
			list [next] = item;
			next++;
		}
	}// add stuff to list
	
	void  ToDo::done ()	{
		next --;
		list [next] = "";
	}	// finish - delete the last thing in list
	
	void ToDo::done(int n) {
		
		if (n <= next)
		{
			for (int i = n; i < length - 1; i++) {
				list[i] = list[i + 1];
			}
			//set last element to ""
			// list[length - 1] = "";//it is not necessary since we correct next
			next--;
		}
	}

	
	// 
	void ToDo::print ()	{
		for (int i=0;i<next; i++) {
			cout << " 	" << i << ": " << list[i] << endl;
		}
	}
	
	int ToDo::getLength() {
	return length;
	}