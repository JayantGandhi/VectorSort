//header file for custom vector class
//vector.h
//Author: Jayant Gandhi
//Date Created: 10/2/2012
//Date Last Edited:

#ifndef VECTORCLASS_H
#define VECTORCLASS_H

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

template <class T>
class vectorClass
{
public:
	vectorClass(int initialSize=10);
		//default contructor with default parameter
		//creates a vector object with a default size of 10 unless otherwise specified
	vectorClass(const vectorClass<T>&);
		//copy constructor
		//creates a vector object with all the data from passed vector object
	~vectorClass();
		//destructor
		//deallocates allocated memory to vector
	vectorClass<T>& operator=(const vectorClass<T>&);
		//overloaded assignment operator for vector objects
		//sets values of this vector object to all the data from passed vector object
	T& operator[](int);
		//overloaded accessor operator
		//used to access specific members of the vector based on indicies
	const T& operator[](int) const;
		//overloaded accessor operator
		//used to access specific members of the vector based on indiciesr
	void insert(const T&);
		//insert function
		//adds a new member to the back of the vector
	void erase(int);
		//erase function
		//removes an element of the vector at the specified index
	int size();
		//size function
		//returns the number of elements in the vector
	void insertionSort();
		//insertion sort function
		//implements an insertion sort algorithm to sort the vector
	void quickSort(int left, int right);
		//quicksort function
		//implements a quicksort algorithm to sort the vector

private:
	int median3 (int, int);
		//medain of three function
		//used by quicksort function to pick optimal pivot point
	void copyVector (const vectorClass<T>&);
		//copyVector function
		//used by assignment operator and copy constructor to copy elements of one
		//vector to another
	void swap(int index1, int index2);
		//swap function
		//used by sorting functions to switch elements to their proper place
	void reserveMoreMemory();
		//reserve more memory function
		//increases the size of the vector when it is full so new items can be inserted
		//doubles the size each time
	int count; //variable to store the number of elements in the vector
	int maxSize; //variable to keep track of when the vector is full
	T *base; //pointer variable to hold the elements of the vector
};
//end of class definition

//vectorClass implementation
template <class T>
vectorClass<T>::vectorClass(int initialSize)
{
	count=0;
	maxSize=initialSize;
	base= new T[initialSize];
}

template <class T>
vectorClass<T>::vectorClass(const vectorClass<T>& myVector)
{
	copyVector(myVector);
}

template <class T>
vectorClass<T>::~vectorClass()
{
	count=0;
	maxSize=0;
	delete []base;
}

template <class T>
vectorClass<T>& vectorClass<T>::operator= (const vectorClass<T>& rhs)
{
	copyVector(rhs);
}

template <class T>
T& vectorClass<T>::operator[] (int index)
{
	return base[index];
}

template <class T>
const T& vectorClass<T>::operator[] (int index) const
{
	return base[index];
}

template <class T>
void vectorClass<T>::insert (const T& newElement)
{
	if (count>=maxSize) //reallocate more memory if vector is full
	{
		reserveMoreMemory();
	}

	base[count]=newElement; //insert the new element after the last elemet in the previous sequence

	count++;//increment count to keep track of number of elements in the vector
}

template <class T>
void vectorClass<T>::erase (int index)
{
	base[index]=NULL;
	for (int i=index+1; i<count; i++) //move all elements after erased element back to ensure continuity
		base [i-1]=base[i];//move the element at i back one
	count--;//decrement count to keep track of number of elements in the vector
}

template <class T>
int vectorClass<T>::size()
{
	return count;
}

template <class T>
void vectorClass<T>::insertionSort()
{
	int j;

	for(int p =1; p<size();p++)
	{
		T temp=base[p];
		for (j=p; j>0 && temp<base[j-1]; j--)
			base[j]=base[j-1];
		base[j]=temp;
	}
}

template <class T>
void vectorClass<T>::quickSort(int left, int right)
{
	if(left<right)
	{

		T pivot = median3(left,right); //assign the pivot value
	
		//begin partitioning
		int i=left, j=right-1;
		for(;;)
		{
			while(base[++i] < pivot){}
			while(pivot<base[--j]){}
			if (i<j)
				swap(i, j);
			else
				break;
		}

		swap(i,right-1);//restore the pivot to its rightful spot

		quickSort(left, i-1); //sort small elements
		quickSort(i+1, right);
	}//end if
	if (right==count-1)
		swap(right,right-1); //No idea why, but this is needed...
}

template <class T>
int vectorClass<T>::median3(int left, int right)
{
	//Median of Three method to find a pivot
	int center = (left+right)/2;
	if(base[center] < base[left])
		swap(left,center);
	if(base[right]<base[left])
		swap(left,right);
	if(base[right]<base[center])
		swap(center,right);
	//place pivot at position right-1
	swap(center,right-1);
	return base[right-1];
}

template <class T>
void vectorClass<T>::copyVector(const vectorClass<T>& otherVector)
{
	count=otherVector.count;
	maxSize=otherVector.maxSize;
	for (int i=0; i<count; i++) //deep copy elements of the vector
		base[i]=otherVector.base[i];
}

template <class T>
void vectorClass<T>::swap (int index1, int index2)
{
	T temp; //temporary variable to allow the swap
	temp=base[index1];
	base[index1]=base[index2];//assign value at index2 to index1
	base[index2]=temp; //assign value that was at index1 to index2
}

template <class T>
void vectorClass<T>::reserveMoreMemory()
{
	try
	{
		maxSize = maxSize*2; //double the size of the vector
		T *temp = new T[maxSize]; //create a new temporary array to hold new vector
		for(int i=0; i<maxSize;i++)
		{
			temp[i]=base[i]; //copy elements of base into the temp array
		}
		delete []base; //free memory allocated to base
		base = temp; //copy info back to base
	}//end try
	catch (bad_alloc ba)
	{
		cout<< "ERROR: " <<ba.what()<< endl;
	}//end catch
}

#endif