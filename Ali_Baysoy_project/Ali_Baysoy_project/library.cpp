#include "library.h"
void library::get_details() {		//function to get data from user
	cout << "\nPlease, enter your ID:";
	cin >> takers_id;
	cout << "\nPlease, enter your name:";
	cin.ignore();
	cin.getline(person_name, 30);

}
int library::retbookid() {
	return book_id;
}
int library::ret_taker_id() {
	return takers_id;
}
void library::get_status() {
	status[0] = 'i';
	status[1] = 's';
	status[2] = 's';
	status[3] = 'u';
	status[4] = 'e';
	status[5] = 'd';
	status[6] = ' ';
	status[7] = '\0';
}
char* library::return_status() {
	return status;
}