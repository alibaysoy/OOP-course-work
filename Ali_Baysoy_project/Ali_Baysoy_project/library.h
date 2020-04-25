#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class library {				//class library
	char book_name[50];
	char book_author[40];
	char person_name[30];
	char status[8];
	int takers_id;
	int book_id;
public:
	library() {
		takers_id = 0;
		book_id = 0;
		status[0] = 'i';
		status[1] = 'n';
		status[2] = ' ';
		status[3] = 's';
		status[4] = 't';
		status[5] = 'o';
		status[6] = 'c';
		status[7] = 'k';
	}
	friend istream& operator>>(istream& input, library& lib) {
		cout << "\nCreate id for book:";
		input >> lib.book_id;
		cout << "\nName of the book:";
		input.ignore();
		input.getline(lib.book_name, 30);
		cout << "\nAuthor of the book:";
		input.ignore();
		input.getline(lib.book_author, 30);
		return input;
	}
	friend ostream& operator<<(ostream& output, const library& lib) {  //ouput operator overloading
		output << lib.book_id << setw(25) << lib.book_name << setw(25) << lib.book_author << setw(25) << lib.status << endl;;
		return output;
	}
	void get_details();
	void get_status();
	char* return_status();
	int return_id();
	int ret_taker_id();
};
