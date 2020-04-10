#pragma once
#include <iostream>

using namespace std;
class teacher
{
protected:
	int disc_math_mark, phil_mark, manage_mark, oop_mark, english_mark, os_mark;
	double gpa;
	void calculate_gpa();	//function to calculate gpa
public:
	teacher() {
		disc_math_mark = 0;
		phil_mark = 0;
		manage_mark = 0;
		oop_mark = 0;
		english_mark = 0;
		os_mark = 0;
		gpa = 0;
	}

	void getinfo();		//function to accept data 

}; //class ends here