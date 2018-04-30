#include <iostream>
#include <fstream>
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
		ofstream out_stream;
		//add save file
		out_stream.open("outfile.dat");
		
		// файл сохраняется, НО не список... Список НЕ сохраняется..
		
		if (out_stream.is_open()) {
			
		   for(int i=0; i <length; i++)				 
			//  out_stream << item[i] <<endl;
		   out_stream << list [i];
		   
		} else if (out_stream.fail())
			{
			cout << "Input file opening failed.\n";
			exit(1);
			}
		//out_stream << 
		//delete [] list;
		
		out_stream.close( );
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