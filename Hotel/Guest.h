#pragma once
#define GUEST_H
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;


class Guest :public Person {

	string PhoneNumber;
	  int  reserved_room;
	int  DurationOfStay;

	

public:

	Guest(string name_a, int ID_a, string phone_num, int res_room, int res_d)
		:Person(name, ID), PhoneNumber(phone_num),reserved_room(res_room),DurationOfStay(res_d)
	{
		

	}

	Guest(const Guest& theother) {
		name = theother.name;
		ID = theother.ID;
		PhoneNumber = theother.PhoneNumber;
		reserved_room = theother.reserved_room;
		DurationOfStay = theother.DurationOfStay;
	
	}

	Guest() :Person("", 0), PhoneNumber(""), reserved_room(0), DurationOfStay(0) {
	}
	~Guest() {
	
	}
	// getters
	
	int getID()const { return ID; }
	string getPhoneNum() const { return PhoneNumber; }

	int getResRoom()const { return reserved_room; }

	int getResDate() const { return DurationOfStay; }

	// setters 
	void setname(string a) { name = a; }
	void setID(int i) { ID = i; }
	void setPhone(string p) { PhoneNumber = p; }
	void setroom(int r) { reserved_room = r; }
	void setduration(int d) { DurationOfStay = d; }


	// to check if an Guest is already existing based on ID
	bool is_guest( Guest* Guests, int &total) const{

		int i = 0;
		while (i < total) {
			if (Guests[i].ID == ID) {
				return true;
			}
			i++;
		}
		return false;
	}

	// to check if a room is already reserved
	bool occupied_room(const Guest* Guests, int &total)const {
		int i = 0;
		while(i <total) {
			if (Guests[i].reserved_room == reserved_room) {
				return true;
			}
			i++;
		}
		return false;
	}


	// to register an new Guest to the system 
	Guest* checkin(Guest* Guests, int& total) {
		if (!is_guest(Guests, total)  ){

			if (!occupied_room(Guests, total)) {
				Guest* new_Guests = new Guest[total + 1];
				for (int i = 0;i < total;i++) {
					new_Guests[i] = Guests[i];
				}

				new_Guests[total].name = name;
				new_Guests[total].ID = ID;
				new_Guests[total].PhoneNumber = PhoneNumber;
				new_Guests[total].reserved_room = reserved_room;
				new_Guests[total].DurationOfStay = DurationOfStay;

				delete[]Guests;
				Guests = new_Guests;
				total++;
				cout << "Guest has been added" << endl;
			}
			else {
				cout << "Room is already occupied" << endl;
				return Guests;
			}
			
		}
		else {
			cout << "you are already a guest of this hotel " << endl;
		}

		return Guests;

	}

	// to remove a Guest from the system 
	Guest* checkout(Guest* Guests, int&total) {
		if (Guests!=nullptr && is_guest(Guests, total)) {

			Guest* new_Guests = new Guest [total - 1];
			for (int i = 0, j = 0;i < total;i++) {
				if (Guests[i].ID != ID) {
					new_Guests[j++] = Guests[i];
				}
			}
			delete[]Guests;
			Guests = new_Guests;
			total--;

			cout << "Guest has been removed" << endl;
		}
		else {
			cout << "you are not a guest of the hotel " << endl;
		}
		return Guests;
	}

	// to change a room for Guest
	Guest* changeroom(Guest* Guests, int &total, int nr) {
		if (is_guest(Guests, total)) {

			if (!occupied_room(Guests, total)) {

				for (int i = 0;i < total;i++) {
					if (Guests[i].ID == ID) {
						Guests[i].reserved_room = nr;
						cout << "room has been changed" << endl;
						break;
					}

				}
			}
			else {
				cout << "the room is occupied" << endl;
			}

		}

		else {

			cout << "you are not a Guest of this hotel" << endl;
		}
			
		

		return Guests;
				
	}

	
	
	friend istream& operator >>(istream& input, Guest& Guests) {

		cout << endl;
		cout << "Enter name:" << endl;
		input >> Guests.name;
		cout << "Enter ID:" << endl;
		input >> Guests.ID;
		if ( Guests.ID < 10 || Guests.ID>100000) {
			cout << "incorrect ID , enter again : " << endl;
			input >> Guests.ID;
		}
		cout << "Enter phone number" << endl;
		input >> Guests.PhoneNumber;
		cout << "Enter room" << endl;
		input >> Guests.reserved_room;

		if (Guests.reserved_room < 1 || Guests.reserved_room>50) {
			cout << "invalid room , pick another room" << endl;
			input >> Guests.reserved_room;
		}

		cout << "Enter Duration of stay :" << endl;
		input >> Guests.DurationOfStay;

		return input;

	}

	friend ostream& operator <<(ostream& output, const Guest& Guests) {

		cout << "name : " << Guests.name << endl;
		cout << "ID : " << Guests.ID << endl;
		cout << "phone number : " << Guests.PhoneNumber << endl;
		cout << "reserved room : " << Guests.reserved_room << endl;
		cout << "Duration of stay : " << Guests.DurationOfStay << endl;

		return output;
	}


	friend Guest* Current_Guests( int& totalGuests);
	friend void UpdateFileGuests(Guest* Guests, int& total);


};


