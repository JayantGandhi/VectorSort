// VectorSort.cpp : main project file.

//#include "stdafx.h"
/*#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>*/
#include <iostream>
#include "vectorClass.h"
#include "person.h"
#include <cstdlib>
#include <exception>

using namespace std;

int main()
{
	//create some vectors
	vectorClass<int> aVector;
	vectorClass<person> anotherVector;
	//populate those vectors
	aVector.insert(5);
	aVector.insert(3);
	aVector.insert(9);
	aVector.insert(1);
	aVector.insert(15);
	aVector.insert(2);
	aVector.insert(4);
	aVector.insert(6);
	aVector.insert(10);
	aVector.insert(8);
	aVector.insert(11);
	aVector.insert(14);
	aVector.insert(12);
	aVector.insert(13);
	aVector.insert(7);
	anotherVector.insert(person("Bobby", 74));
	anotherVector.insert(person("Toni", 23));
	anotherVector.insert(person("Jez", 27));
	anotherVector.insert(person("Marc", 28));
	anotherVector.insert(person("Jonas", 99));
	anotherVector.insert(person("Art", 44));
	anotherVector.insert(person("Carl", 11));
	anotherVector.insert(person("Vinny", 55));
	anotherVector.insert(person("Rory", 49));
	anotherVector.insert(person("Elijah", 8));
	anotherVector.insert(person("Tony", 11));
	//display unsorted vectors
	for (int i=0; i<(aVector.size()); i++)
	{
		cout<<aVector[i]<<" ";
	}
	cout<<endl;
	for (int i=0; i<(anotherVector.size()); i++)
	{
		cout<<anotherVector[i];
	}
	//sort the vectors
	anotherVector.insertionSort();
	aVector.quickSort(0,aVector.size()-1);
	//display sorted vectors
	for (int i=0; i<(aVector.size()); i++)
	{
		cout<<aVector[i]<<" ";
	}
	cout<<endl;
	for (int i=0; i<(anotherVector.size()); i++)
	{
		cout<<anotherVector[i];
	}
    return 0;
}
