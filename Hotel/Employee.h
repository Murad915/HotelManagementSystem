#pragma once
#define Employee_H
#include "person.h"
#include <iostream>
#include <string>

using namespace std;

class Employee :public Person {

	string postion;
	int age;
	int workingsince;

public:

	Employee(string name_e, int ID_e, string postion_e, int age_e, int workingsince_e) : Person(name_e, ID_e), postion(postion_e),
		age(age_e), workingsince(workingsince_e) {}


	Employee(const Employee& theother) {
		name = theother.name;
		ID = theother.ID;
		postion = theother.postion;
		age = theother.age;
		workingsince = theother.workingsince;
	}

	Employee() :Person("", 0), postion(""), age(0), workingsince(0) {
	}

	
	//setters which we can use later during out operations with the objects
	void setname(string a) { name = a; }
	void setID(int i) { ID = i; }
	void setPosition(string p) { postion = p; }
	void setAge(int ag) { age = ag; }
	void setWorkDuration(int w) { workingsince = w; }

	// to check if the current Employee is already registered or not
	bool is_employee( Employee* Employees, int& total) {
		int i = 0;
		while (i < total) {
			if (Employees[i].ID == ID) {
				return true;
			}
			i++;
		}
		return false;
	}

	// to add a new employee

	Employee* AddEmployee(Employee *Employees,int &total) {

		if (!is_employee(Employees, total)) {

			Employee* new_employee =new Employee[total + 1];
			for (int i = 0;i < total;i++) {
				new_employee[i] = Employees[i];
			}
			new_employee[total].name = name;
			new_employee[total].ID = ID;
			new_employee[total].postion= postion;
			new_employee[total].age = age;
			new_employee[total].workingsince = workingsince;

			delete[]Employees;
			Employees = new_employee;
			total++;
			cout << "Employee has been added " << endl;
		}
		else {
			cout << "Already employeed " << endl;
		}

		return Employees;

	}

	// to remove
	Employee* RemoveEmployee(Employee * Employees, int &total) {
		if (Employees!=nullptr && is_employee(Employees, total)) {
			Employee* new_employee = new Employee[total - 1];
			int i = 0,j=0;
			while(i<total) {
				if (Employees[i].ID != ID) {
					new_employee[j++] = Employees[i];
				}
				i++;
			}
			delete[]Employees;
			Employees = new_employee;
			total--;
			cout << "Employee has been removed from the system " << endl;
		}
		else {
			cout << "You dont work in this hotel" << endl;
		}

		return Employees;

	}

	// change position
	Employee* ChangePosition(Employee* Employees, int& total, string new_pos) {
		if (is_employee(Employees, total)) {

			for (int i = 0;i < total;i++) {

				if (Employees[i].ID == ID) {

					Employees[i].postion = new_pos;

						break;
				}
			}
		}
		else {
			cout<<"not in the system"<<endl;

		}
		return Employees;
	}

	friend istream& operator >>(istream& input, Employee& Employees) {

		cout << endl;
		cout << "Enter name:" << endl;
		input >> Employees.name;
		cout << "Enter ID:" << endl;
		input >> Employees.ID;
		if (Employees.ID < 10 || Employees.ID>100000) {
			cout << "incorrect ID , enter again : " << endl;
			input >> Employees.ID;
		}

		cout << "Enter position" << endl;
		input >> Employees.postion;
		cout << "Enter age" << endl;
		input >> Employees.age;

		if (Employees.age < 18) {
			cout << "not allowed age , enter again" << endl;
			input >> Employees.age;
		}
		cout << "Employee has been working for :" << endl;
		input >> Employees.workingsince;

		if (Employees.workingsince < 0 || Employees.workingsince>50) {
			cout << "not allowed Duration , enter again" << endl;
			input >> Employees.workingsince;
		}
		return input;
	}
	
	friend ostream& operator <<(ostream& output, const Employee& Employees) {

		cout << " name : "<<Employees.name << endl;
		cout << " ID : " << Employees.ID << endl;
		cout << " position : " << Employees.postion << endl;
		cout << "age : " << Employees.age << " years old " << endl;
		cout << "Employee has been working here for : " << Employees.workingsince << " years " << endl;

		return output;
	}



	friend Employee* Current_Employees( int& totalEmp);

	friend void UpdateFileEmployees(Employee* Employees, int& t);

};

