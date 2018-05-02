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
			
			// while (getline(ifstr, s)) - это нестандартная операция.. пока что то есть в файле - читаем..
			
			while (!getline(ifstr, s).eof())	// читать пока getline не упрется в конец файла
			// т.е. пока неправда(!), что мы достигли конец файла eof() - продолжаем читать
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
	
	// loop в done() сдвигает все элементы после завершенного, по сути - удаляет завершенный элемент со сдвигом всех последующих влево, 
	// например 1.2.3.4.5, удаляем 2 - получаем 1. .3.4.5, после сдвига получаем 1.3.4.5
	void ToDo::done(int n) {
		
		if (n <= next)
		{
			for (int i = n; i < length - 1; i++) {
				list[i] = list[i + 1]; // [i + 1] - это следующий элемент, который мы ставим на место текущего
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
	
	// int ToDo::getLength() {
	// return length;
	// }