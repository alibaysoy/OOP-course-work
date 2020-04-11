#pragma once
#include <iostream>
#include <fstream>
#include<iomanip>
#include "teacher.h"
#include "student.h"


using namespace std;

void student_evaluation(int);//write data to binary file
void teachers_page();
void students_result(int);//display data of student
void new_marks(int);//if student already evaluted, this func is used to evaluation
void administrators_page();//admin menu

int main() //main function
{
	char ch;
	int id;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2);

	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. I AM A STUDENT";
		cout << "\n\n\t2. I AM A TEACHER";
		cout << "\n\n\t3. Administrator";
		cout << "\n\n\t4. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> ch;
		switch (ch)
		{
		case '1': system("cls"); cout << "\n Enter your VGTU ID:"; cin >> id;
			students_result(id);	break;
		case '2':teachers_page();
			break;
		case '3':administrators_page(); break;
		case '4': break;
		default:cout << "\a";
		}
	} while (ch != '3');
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
void administrators_page() {
	main();
}
