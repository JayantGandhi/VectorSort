//implementation for the person struct
//person.cpp
//Author: Jayant Gandhi
//Date Created: 10/3/2012
//Date Last Edited:

//#include "stdafx.h"
#include "person.h"
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

ostream& operator<< (ostream& oStr, const person& myPerson)
{
	oStr << myPerson.name <<" - "<< myPerson.age << "yrs old" << endl;
	return oStr;
}

person::person()
{
	name=NULL;
	age=0;
}

person::person(char* personName, int personAge)
{
	//int length = strlen(personName);
	name= personName;
	//for (int i=0; i <20; i++)
		//name[i]=personName[i];
	//name[length]=0;
	age=personAge;
}

person::person(const person& otherPerson)
{
	//int length = strlen(otherPerson.name);
	name= otherPerson.name;
	//for (int i=0; i <20; i++)
		//name[i]=otherPerson.name[i];
	//name[length]=0;
	age=otherPerson.age;
}

person::~person()
{
	initializePerson();
}

void person::initializePerson()
{
	name=NULL;
	age=0;
}

person& person::operator= (const person& rhs)
{
	//int length = strlen(rhs.name);
	//initializePerson();
	name= rhs.name;
	//for (int i=0; i <20; i++)
		//name[i]=rhs.name[i];
	//name[length]=0;
	age=rhs.age;
	return *this;
}

bool person::operator< (const person& rhs) const
{
	int lessThan = strcmp(name, rhs.name);
	if (lessThan<0)
		return true;
	else
		return false;
}
