#pragma once
#include "teacher.h"
#include <iostream>
#include <iomanip>
class student :public teacher { //class student which is child class
	int vgtu_id;
	char students_name[50];
public:
	void showinfo() const; //func to display data
	int return_id() const;
	void show_horizontal()const;
	void getid();
	char* ret_name();
};						//end of class
