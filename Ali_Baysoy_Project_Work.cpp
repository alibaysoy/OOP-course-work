#include<iostream>
#include<iomanip>

using namespace std;

void student_evaluation(int); 
void teachers_page();	
void students_result();	

int main() //main function
{
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); 
	
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t1. I AM A STUDENT";
		cout << "\n\n\t2. I AM A TEACHER";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> ch;
		switch (ch)
		{
		case '1':students_result(id);	break;
		case '2':teachers_page();
			break;
		case '3':break;
		default:cout << "\a";
		}
	} while (ch != '3');
	return 0;
}
void teachers_page() {
	system("cls");
	char name[50];
	cout << "\nEnter your name:";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nSveiki, teacher " << name;
	student_evaluation();
	
}


