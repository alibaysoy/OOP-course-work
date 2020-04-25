#include "student.h"
void student::getid() {
	cout << "\nEnter student's ID again: ";
	cin >> vgtu_id;
	cout << "\nEnter student's first and last name: ";
	cin.ignore();
	cin.getline(students_name, 50);
}
void student::showinfo() const
{
	cout << "\nStudent: " << students_name;
	cout << "\nID of student : " << vgtu_id;
	cout << "\nMarks for this semester:\n";
	cout << "\n Discrete Math : ";
	if (disc_math_mark != 0)
		cout << disc_math_mark;
	else
		cout << "NG";
	cout << "\n Management : ";
	if (manage_mark != 0)
		cout << manage_mark;
	else cout << "NG";
	cout << "\n Philosophy: ";
	if (phil_mark != 0)
		cout << phil_mark;
	else cout << "NG";
	cout << "\n English : ";
	if (english_mark != 0)
		cout << english_mark;
	else cout << "NG";
	cout << "\n Object-Oriented Programming :";
	if (oop_mark != 0)
		cout << oop_mark;
	else cout << "NG";
	cout << "\n Operating Systems :";
	if (os_mark != 0)
		cout << os_mark;
	else cout << "NG";
	cout << "\n GPA of Student :" << gpa;

}
void student::show_horizontal() const //show data horizontally
{
	cout << vgtu_id << setw(25);
	cout << students_name << setw(15);
	if (disc_math_mark != 0)
		cout << disc_math_mark << setw(12);
	else
		cout << "NG" << setw(12);
	if (phil_mark != 0)
		cout << phil_mark << setw(11);
	else cout << "NG" << setw(11);
	if (manage_mark != 0)
		cout << manage_mark << setw(12);
	else cout << "NG" << setw(12);
	if (oop_mark != 0)
		cout << oop_mark << setw(10);
	else cout << "NG" << setw(10);
	if (english_mark != 0)
		cout << english_mark << setw(10);
	else cout << "NG" << setw(9);
	if (os_mark != 0)
		cout << os_mark << setw(9);
	else cout << "NG" << setw(10);
	cout << gpa << setw(15) << "\n";

}
char* student::ret_name() {
	return students_name;
}
int  student::return_id() const
{
	return vgtu_id;
}