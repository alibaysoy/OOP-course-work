#pragma once
#include <iostream>
#include <fstream>
#include<iomanip>
#include "teacher.h"
#include "student.h"
#include "admin.h"
#include "library.h"


using namespace std;

void student_evaluation(int);//write data to binary file
void teachers_page();
void students_result(int);//display data of student
void new_marks(int);//if student already evaluted, this func is used to evaluation
void administrators_page();//admin menu
void delete_data(int);	// delete selected data from binary file
void all_results();	//display all data in horizontal format
void show_all();	//read all records from binary file
void admins_data();
void admin_signin(int, char*);//getting password of admin from binary file
void display_books();//show all books
void library_menu();
void add_book();
void book_borrow();

int main() //main function
{
	char ch;
	int id;
	char pass[20];
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2);

	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. I AM A STUDENT";
		cout << "\n\n\t2. I AM A TEACHER";
		cout << "\n\n\t3. E-LIBRARY";
		cout << "\n\n\t4. SIGN IN AS ADMINISTRATOR";
		cout << "\n\n\t5. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-5) ";
		cin >> ch;
		switch (ch)
		{
		case '1': system("cls"); cout << "\n Enter your VGTU ID:"; cin >> id;
			students_result(id);	break;
		case '2':teachers_page();
			break;
		case '3':library_menu();
			break;
		case '4':system("cls"); cout << "\nPlease,enter your id(id is 123):";
			cin >> id;
			cout << "\nPlease enter your password (your temporary password is password) :";
			cin.ignore();
			cin.getline(pass, 19);
			admin_signin(id, pass); break;
		case '5':return 0;
		default:cout << "\a";
		}
	} while (ch != '5');
	return 0;
}
void teachers_page() {
	system("cls");
	int id;
	char name[50];
	cout << "\nEnter your name:";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nSveiki, teacher " << name;
	cout << "\nEnter Students id:";
	cin >> id;
	student_evaluation(id);

}
void student_evaluation(int n)
{

	bool flag = false;
	student t;
	ofstream outFile;
	ifstream fileIn;
	fileIn.open("database.dat", ios::binary);
	while (fileIn.read(reinterpret_cast<char*> (&t), sizeof(student)))
	{
		if (t.returnID() == n)
			flag = true;
	}
	fileIn.close();
	if (flag == false) {
		outFile.open("database.dat", ios::binary | ios::app);
		t.getid();
		t.getinfo();
		outFile.write(reinterpret_cast<char*> (&t), sizeof(student));
		outFile.close();
		cout << "\n\nStudent has been evaluated";
		cin.ignore();
		cin.get();
		main();
	}
	else {
		new_marks(n);

	}
}
void new_marks(int n)
{
	bool found = false;
	student t;
	fstream File;
	File.open("database.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "Error occured.. File is not found. ";
		cin.ignore();
		cin.get();
		return;
	}
	while (!File.eof() && found == false)
	{

		File.read(reinterpret_cast<char*> (&t), sizeof(student));
		if (t.returnID() == n)
		{
			cout << "Student:" << t.ret_name() << endl;
			t.getinfo();
			int pos = (-1) * static_cast<int>(sizeof(t));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&t), sizeof(student));
			cout << "\n\n\t Student was evaluated.";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Student Not Found ";
	cin.ignore();
	cin.get();
	main();
}
void students_result(int n)
{
	student st;
	ifstream inFile;
	inFile.open("database.dat", ios::binary);
	if (!inFile)
	{
		cout << "Error occured.. File is not found.";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		if (st.returnID() == n)
		{
			st.showinfo();
			flag = true;
			cin.ignore();
			cin.get();
			main();
		}
	}
	inFile.close();
	if (flag == false) {
		cout << "\n\nStudent not graded yet";
		cin.ignore();
		cin.get();
		main();
	}
}


void show_all()
{
	student st;
	ifstream inFile;
	inFile.open("database.dat", ios::binary);
	if (!inFile)
	{
		cout << "Error occured.. File is not found.";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\n\n\t\tStudents database\n\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.showinfo();
		cout << "\n\n--------------------------------------------------------------------\n";
	}
	inFile.close();

	cin.ignore();
	cin.get();
	main();
}

void all_results()
{
	student t;
	ifstream File;
	File.open("database.dat", ios::binary);
	if (!File)
	{
		cout << "Error occured. File not found";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "-----------------------------------------------------------------------------------------------------\n";
	cout << "ID" << setw(20) << "Name" << setw(25) << "Dis.Math." << setw(10) << "Phil." << setw(12) << "Manage." << setw(10) << "OOP" << setw(10) << "Eng." << setw(8) << "OS" << setw(10) << "Grade" << endl;
	cout << "-----------------------------------------------------------------------------------------------------\n";
	while (File.read(reinterpret_cast<char*> (&t), sizeof(student)))
	{
		t.show_horizontal();
	}
	cout << "\nPress ENTER";
	cin.ignore();
	cin.get();
	main();
	File.close();


}

//ADMIN
void admins_data() {
	system("cls");
	admin adm;
	ofstream outFile;
	outFile.open("admin.dat", ios::binary | ios::app);
	cin >> adm;
	outFile.write(reinterpret_cast<char*> (&adm), sizeof(admin));
	outFile.close();
	cout << "\n\nPassword is changed ";
	cin.ignore();
	cin.get();
	administrators_page();
}
void admin_signin(int id, char* pass) {
	admin adm;
	ifstream File;
	File.open("admin.dat", ios::binary);
	if (!File)
	{
		cout << "Error occured. File not found";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag = false;
	while (File.read(reinterpret_cast<char*> (&adm), sizeof(admin)))
	{

		if (strcmp(adm.returnpass(), pass) == 0 && adm.retID() == id)
		{
			administrators_page();
			flag = true;
		}
	}
	File.close();
	if (flag == false) {
		cout << "Password is incorrect";
		cin.ignore();
		cin.get();
		main();
	}

}

void administrators_page() {
	char ch;
	int id;
	system("cls");
	cout << "\n\n\n\tADMINISTRATOR";
	cout << "\n\n\t1. Delete data about students";
	cout << "\n\n\t2. All results";
	cout << "\n\n\t3. Data about all students";
	cout << "\n\n\t4. Change password";
	cout << "\n\n\t5. Back to Main Menu";
	cout << "\n\n\n\tEnter Choice (1/2/3/4/5)? ";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':	cout << "Enter VGTU ID: "; cin >> id; delete_data(id); break;
	case '2':	all_results(); break;
	case '3':	show_all(); break;
	case '4':   admins_data(); break;
	case '5':	main(); break;
	default:	cout << "\a"; main(); break;
	}

}
void delete_data(int n)
{

	student t;
	ifstream File;
	File.open("database.dat", ios::binary);
	if (!File)
	{
		cout << "Error occured.. File is not found.";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("tempo.dat", ios::out);
	File.seekg(0, ios::beg);
	while (File.read(reinterpret_cast<char*> (&t), sizeof(student)))
	{
		if (t.returnID() != n)
		{
			outFile.write(reinterpret_cast<char*> (&t), sizeof(student));
		}
	}
	outFile.close();
	File.close();
	remove("database.dat");
	rename("tempo.dat", "database.dat");
	cout << "\n\n\tStudent data deleted.";
	cin.ignore();
	cin.get();
	administrators_page();
}

void library_menu() {
	system("cls");
	cout << "\n\n\t1.ADD BOOK TO THE LIBRARY";
	cout << "\n\n\t2.SHOW LIST OF THE BOOKS";
	cout << "\n\n\t3.GET A BOOK";
	cout << "\n\n\t4.MAIN MENU	";
	cout << "\n\n Please, choose one option (1/2/3/4):";
	char ch;
	cin >> ch;
	switch (ch)
	{
	case '1':add_book(); break;
	case '2':display_books(); break;
	case '3':book_borrow(); break;
	case '4':main(); break;
	default:
		break;
	}
}
void add_book() {
	system("cls");
	library lib;
	ofstream file;
	file.open("library.dat", ios::binary | ios::app);
	cin >> lib;
	file.write(reinterpret_cast<char*> (&lib), sizeof(library));
	file.close();
	cout << "\n\nBook added";
	cin.ignore();
	cin.get();
	library_menu();
}
void display_books() {
	system("cls");
	library lib;
	ifstream file;
	file.open("library.dat", ios::binary);
	if (!file)
	{
		cout << "Error occured.. File is not found.";
		cin.ignore();
		cin.get();
		library_menu();
	}
	cout << "\n\n\t\tBooks\n\n";
	cout << "---------------------------------------------------------------------------------\n";
	cout << "Book ID" << setw(20) << "Book's Name" << setw(25) << "Book Author" << setw(25) << "Status\n";
	cout << "---------------------------------------------------------------------------------\n";
	while (file.read(reinterpret_cast<char*> (&lib), sizeof(library)))
	{
		cout << lib;
	}
	file.close();
	cout << "\nPress ENTER";
	cin.ignore();
	cin.get();
	library_menu();
}

void book_borrow() {
	system("cls");
	cout << "\nEnter book id:";
	int n;
	char  ch[] = "issued \0";
	bool flag = false;
	cin >> n;
	library lib;
	ifstream inFile;
	inFile.open("library.dat", ios::binary);
	while (inFile.read(reinterpret_cast<char*> (&lib), sizeof(library)))
	{
		if (lib.retbookid() == n && strcmp(ch, lib.return_status()) == 0)
		{
			cout << "Book already taken";
			cin.ignore();
			cin.get();
			library_menu();

		}
	}
	inFile.close();
	bool found = false;
	fstream File;
	File.open("library.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "Error occured.. File is not found. ";
		cin.ignore();
		cin.get();
		return;
	}
	cout << "\nBook found;";
	while (!File.eof() && found == false)
	{

		File.read(reinterpret_cast<char*> (&lib), sizeof(library));
		if (lib.retbookid() == n)
		{
			lib.get_details();
			lib.get_status();
			int pos = (-1) * static_cast<int>(sizeof(library));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&lib), sizeof(library));
			cout << "\n\n\t Book successfully issued";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Book not found";
	cin.ignore();
	cin.get();
	library_menu();
}