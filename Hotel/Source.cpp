#include <iostream>
#include "Person.h"
#include "Guest.h"
#include "Employee.h"
#include <string>
#include<fstream>

using namespace std;

// to extract the existing employees in the system 
Employee* Current_Employees(int& totalEmp) {

	Employee* Employees = nullptr;

	try {
		int total = 0;

		std::ifstream employeeFile("Employees.txt");

		if (!employeeFile.is_open()){
			cout << endl;
		    cout << endl;
		    throw std::runtime_error("Failed to open Employees.txt for reading.");
		    
	        }

		std::string line;

		while (std::getline(employeeFile, line))
			++total;

		employeeFile.close();

		totalEmp = total / 5;

		Employees = new Employee[totalEmp];

		employeeFile.open("Employees.txt");
		

		for (int i = 0; i < totalEmp; i++) {
			employeeFile >> Employees[i].name;
			employeeFile >> Employees[i].ID;
			employeeFile >> Employees[i].postion;
			employeeFile >> Employees[i].age;
			employeeFile >> Employees[i].workingsince;
		}

		employeeFile.close();
	}
	catch (const std::exception& ex) {
		std::cerr << "Exception occurred while reading Employees file: " << ex.what() << std::endl;
		delete[] Employees;
		Employees = nullptr;
		
	}

	return Employees;
}


// to extract the existing Guests in the system 
Guest* Current_Guests(int& totalGuests) {
	Guest* Guests = nullptr;

	try {
		int total = 0;
		std::ifstream GuestsFile("Guests.txt");

		if (!GuestsFile) {
			cout << endl;
			cout << endl;
			throw std::runtime_error("Failed to open Guests file for reading.");
		}

		std::string line;
		while (std::getline(GuestsFile, line)) {
			++total;
		}

		GuestsFile.close();

		totalGuests = total / 5;
		Guests = new Guest[totalGuests];

		GuestsFile.open("Guests.txt");
		

		for (int i = 0; i < totalGuests; i++) {
			GuestsFile >> Guests[i].name;
			GuestsFile >> Guests[i].ID;
			GuestsFile >> Guests[i].PhoneNumber;
			GuestsFile >> Guests[i].reserved_room;
			GuestsFile >> Guests[i].DurationOfStay;
		}

		GuestsFile.close();
	}
	catch (const std::exception& ex) {
		std::cerr << "Exception occurred while reading Guests file: " << ex.what() << std::endl;
		delete[] Guests;
		Guests = nullptr;
		
	}

	return Guests;
}


//after modification in the state of the Guests objects the update is  here
void UpdateFileGuests(Guest* Guests, int& t) {

	
	fstream GuestsFile;
	GuestsFile.open("Guests.txt", ios::out);

	
		for(int i=0;i<t;i++){
			GuestsFile << Guests[i].name << std::endl;
			GuestsFile << Guests[i].ID << std::endl;
			GuestsFile << Guests[i].PhoneNumber << std::endl;
			GuestsFile << Guests[i].reserved_room << std::endl;
			GuestsFile << Guests[i].DurationOfStay << std::endl;
		
	}
		GuestsFile.close();
}

//after modification in the state of the employees objects the update is  here
void UpdateFileEmployees(Employee* Employees, int& t) {
	fstream EmployeesFile;
	EmployeesFile.open("Employees.txt", std::ios::out);

	
	for (int i = 0;i < t;i++) {
			EmployeesFile << Employees[i].name << std::endl;
			EmployeesFile << Employees[i].ID << std::endl;
			EmployeesFile << Employees[i].postion << std::endl;
			EmployeesFile << Employees[i].age << std::endl;
			EmployeesFile << Employees[i].workingsince << std::endl;
			
			
	}
	EmployeesFile.close();

}


int main() {

	int totalGuests = 0;
	int totalEmployees = 0;

	

	Guest* Guests = Current_Guests(totalGuests);
	Employee* Employees = Current_Employees(totalEmployees);
	

	int i;
	std::cout << "            ###############################" << endl;
	std::cout << "              WELCOME TO MARIOTT HOTEL " << endl;
	std::cout << "            ###############################" << endl;
	std::cout << endl;

	std::cout << "To access Guests system press 1 " << endl;
	std::cout << "To access Employees system press 2 " << endl;
	std::cout << "Please choose" << endl;
	
	std::cin >> i;


	while (i < 1 || i>2) {
		fflush(stdin);
		std::cout << "That is not an option , please choose again" << endl;
		std::cin >> i;
		
	}

	if (i == 1) {
		system("cls");
		int x;
		cout << endl;
		cout << endl;
		std::cout << "Welcome to the Guests menu :" << endl;
		std::cout << "press 1 to Check in " << endl;
		std::cout << "press 2 to Check out " << endl;
		std::cout << "press 3 to change room for a guest" << endl;

		std::cin >> x;


		while (x < 1 || x>3) {
			std::cout << "That is not an option , please choose again" << endl;
			std::cin >> x;
		}
		

		if (x == 1) {
			Guest gu;
			cin>>  gu;
			Guests=gu.checkin(Guests, totalGuests);
			cout << "The data : " << endl << endl;
			cout << gu;
			


		}

		else if (x == 2) {
			int id;
			cout << "enter ID of the Guest"<<endl;
			cin >> id;
			Guest nw;
			nw.setID(id);
			Guests=nw.checkout(Guests, totalGuests);
			

		}

		else if (x == 3) {

			int id;
			int sh;
			cout << "enter ID of the Guest" << endl;
			cin >> id;
			Guest nw;
			nw.setID(id);
			cout << "Please Enter the room you would like to change to " << endl;
			cin >> sh;
			nw.setroom(sh);
			nw.changeroom(Guests, totalGuests,sh);
		}
	


	}



	else if (i == 2) {
		system("cls");
		int y;
		std::cout << "press 1 to add an employee" << endl;
		std::cout << "press 2 to remove an employee " << endl;
		std::cout << "press 3 to change change a position for an employee" << endl;

		std::cin >> y;

		while (y < 1 || y>3) {
			std::cout << "That is not an option , please choose again" << endl;
			std::cin >> y;
		}

		if (y == 1) {
			Employee em;
			cin >> em;
			Employees=em.AddEmployee(Employees, totalEmployees);
			cout << "The data : " << endl;
			cout << em;
			
			
		}

		else if (y == 2) {
			int id;
			cout << "Please enter the ID of the employee you would like to remove" << endl;
			cin >> id;
			Employee em;
			em.setID(id);
			
			Employees=em.RemoveEmployee(Employees, totalEmployees);
			
			


		}

		else if (y == 3) {
			int id;
			string po;
			cout << "enter ID of the Employee " << endl;
			cin >> id;
			Employee em;
			em.setID(id);
			cout << "Enter the new position : " << endl;
			cin >> po;
			Employees=em.ChangePosition(Employees, totalEmployees, po);
			

		}

		
	}


	UpdateFileEmployees(Employees, totalEmployees);

	UpdateFileGuests(Guests, totalGuests);
    
	delete[]Guests;
	delete[]Employees;

	int d;
	cout << "press 1 -> back to main menu" << endl << "press any other key to log out" << endl;
	cin >> d;

	if (d == 1) {
		system("cls");
		main();
	}

	
	

}