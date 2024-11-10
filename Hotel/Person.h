#pragma once

#define PERSON_H
#include <iostream>
#include <string>


class Person
{
protected:
	std::string name ;
	int ID;

public: 
	Person() {
		name = "";
		ID = 0;
	}

	Person(std::string name_i, int ID_i) : name(name_i), ID(ID_i) {}

	Person(const Person& other) {
		name = other.name;
		ID = other.ID;
	}
	
	~Person(){}

	
	
};
