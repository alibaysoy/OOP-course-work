#pragma once
#include <iostream>
#include "teacher.h"
class admin :public teacher { //class admin
	char password[20];
	int admins_id;
public:
	admin() {
		admins_id = 0;
	}
	char* returnpass();
	int retID();
	friend istream& operator>>(istream& input, admin& ad) { //input operator overloading
		cout << "\nPlease enter administrator ID:";
		input >> ad.admins_id;
		cout << "\nPlease, enter password:";
		input.ignore();
		input.getline(ad.password, 20);
		return input;
	} //input operator overloading

};  //end of class
