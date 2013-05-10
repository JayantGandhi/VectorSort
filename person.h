//definition for the person struct
//person.h
//Author: Jayant Gandhi
//Date Created: 10/3/2012
//Date Last Edited:
#ifndef PERSON_H
#define PERSON_H

//#include "stdafx.h"
#include <iostream>
#include <string>

struct person
{
	friend std::ostream& operator<< (std::ostream&, const person&);
		//overloaded stream insertion operator for person class
		//precondition: must have an initialized person object

	person();
		//default constructor
		//postcondition: name is initialized to NULL and age is set to 0
	person(char*, int);
		//constructor with parameters
		//postcondition: name is set to char* and age is set to int
	person(const person&);
		//copy constructor
		//assigns name and age values from passed person object to created object
	~person();
		//destructor
		//deallocates allocated memory
	void initializePerson();
		//function to deallocate allocated memory, used by destructor
	person& operator= (const person&);
		//overloaded assignment operator
		//assigns name and age values from passed person object to created object
	bool operator< (const person&) const;
		//overloaded less than operator
		//used for comparisons done during sorting
	
	char* name;
	int age;
};//end of struct definition

#endif