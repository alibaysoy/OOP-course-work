#include "teacher.h"

void teacher::calculate_gpa()
{
	gpa = (disc_math_mark + phil_mark + manage_mark + oop_mark + english_mark + os_mark) / 10.0;

}

void teacher::getinfo()
{

	char ch;
	cout << "\n\tPlease, choose subject you are teaching:";
	cout << "\n\t1. Discrete math";
	cout << "\n\t2. Philosophy:";
	cout << "\n\t3. OOP:";
	cout << "\n\t4. Management:";
	cout << "\n\t5. OS:";
	cout << "\n\t6. Enslish:";
	cout << "\nPlease, select one option(1,2,3,4,5,6):";
	cin >> ch;
	switch (ch)
	{
	case '1':	cout << "\n Please, enter student's mark mark in Discrete Math: ";
		cin >> disc_math_mark; break;
	case '2':	cout << "\n Please enter student's mark in Philosophy: ";
		cin >> phil_mark; break;
	case '3':	cout << "\n Please enter student's mark in Object-Oriented Programming: ";
		cin >> oop_mark; break;
	case '4':	cout << "\n Please enter student's mark in Management: ";
		cin >> manage_mark; break;
	case '5':	cout << "\n Please enter student's mark in Operating Systems: ";
		cin >> os_mark; break;
	case '6':	cout << "\n Please enter student's mark in English :";
		cin >> english_mark; break;
	}
	calculate_gpa();
}