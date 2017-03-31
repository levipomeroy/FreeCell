#pragma once
#include "Exception.h"
/************************************************************************
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be
*		   started at any index.
*
* Manager functions:
* 	Array ()
* 		The default size is zero and the start_index is zero.
*	Array (int length, int start_index = 0)
*		Creates an appropriate sized array with the starting index
*       either zero or the supplied starting value.
*	Array (const Array & copy)
*		Creates a new array of size m_length and copies over the data
*		from existing array into the new one.
*	operator= (const Array & rhs)
*		Checks for self-assignment, and if not self assigned, creates a
*		new array of size m_length and copies over the data from the old
*		array into the new one.
*	~Array()
*		Gives back allocated/borrowed memory.
*
Methods:
*	operator[](int index)
*		Overloads the subscript operator to allow indexing for this array
*		type. Returns (index-srating_index).
*	GetStartIndex() const
*		Returns the starting index of the array.
*	SetStartIndex(int start_index)
*		Sets the starting index of the array to the index passed into it.
*	GetLength() const
*		Returns the length of the array.
*	SetLength(int length)
*		Sets the length of the array to the length passed into it.
*************************************************************************/
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
private:
	T * m_array;
	int m_length;	//Length of array
	int m_start_index;	//Starting index of array

public:
	Array();	//Default constructor
	Array(int length, int start_index = 0);	//2 arg constructor, default start index is 0
	Array(const Array<T> & copy);	//Copy constructor
	~Array();	//Destructor
	Array<T> & operator=(const Array<T> & rhs);	//Assigment operator
	T & operator[](int index);	//Subscript operator override
	int GetStartIndex() const;	//Get index
	void SetStartIndex(int start_index);	//Set index
	int GetLength() const;	//Get length of array
	void SetLength(int length);	//Set length of array
};

#endif
/**********************************************************************
* Purpose: This function initialized m_length to zero, m_start_index to
*		   zero, and m_array to nullptr.
*
* Precondition:	All data members were unassigned.
*
* Postcondition: m_length is set to zero, m_start_index is set to zero,
*			     and m_array is set to nullptr.
************************************************************************/
template<typename T>
inline Array<T>::Array() :m_length(0), m_start_index(0), m_array(nullptr)
{
}

/**********************************************************************
* Purpose: This function initialized m_length to length, m_start_index to
*		   start_index, and m_array to nullptr. It then creates a new array
*		   the size of m_length;
*
* Precondition:	Data members were unassigned.
*
* Postcondition: m_length is set to length, m_start_index is set to start_index,
*			     and m_array is set to nullptr, and there is a new array(type T).
************************************************************************/
template <typename T>
inline Array<T>::Array(int length, int start_index) : m_length(length), m_start_index(start_index), m_array(nullptr)
{
	if (m_length < 0)
	{
		throw Exception("Length cannot be a negative value");
	}
	m_array = new T[m_length];
}

/**********************************************************************
* Purpose: This function set m_length to copy.m_length and m_start_index
*		   to copy.m_start_index. It then creates a new array the size of
*		   m_length and sets its data to the data of the original array.
*
* Precondition:	Copy's data members were unnassigned and it's array was empty.
*
* Postcondition: m_length is set to copy.m_length, m_start_index is set to
*				 copy.m_start_index, and there is a new array with the data
*				 from the original array.
************************************************************************/
template <typename T>
inline Array<T>::Array(const Array<T> & copy) :m_length(copy.m_length), m_start_index(copy.m_start_index)
{

	m_array = new T[m_length];	//Create new array to correct length

	for (int i = m_start_index; i < m_length; i++)	//copy over data
	{
		m_array[i] = copy.m_array[i];
	}
}

/**********************************************************************
* Purpose: This function set m_length to rhs.m_length and m_start_index
*		   to rhs.m_start_index. It then creates a new array the size of
*		   m_length and sets its data to the data of the original array.
*
* Precondition:	rhs's data members were unnassigned and it's array was empty.
*
* Postcondition: m_length is set to rhs.m_length and m_start_index is set to
*				 rhs.m_start_index, and there is a new array with the data
*				 from the original array.
************************************************************************/
template<typename T>
inline Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)	//Check for self assignment
	{

		delete[] m_array;

		m_length = rhs.m_length;	//copy length
		m_start_index = rhs.m_start_index;	//copy start index 

		m_array = new T[m_length];	//Create new array
		for (int i = 0; i < m_length; i++)	//copy elements of m_array into new array
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: This function deletes m_array and resets it to nullptr
*
* Precondition:	m_array still exists and is not nessecarily set to nullptr
*
* Postcondition: m_array is deleted and is reset to equal nullptr.
************************************************************************/
template <typename T>
inline Array<T>::~Array()
{
	delete[] m_array;	//delete
	m_array = nullptr;	//reset
}

/**********************************************************************
* Purpose: This function overloads the subscript operator in order to
*		   specify an index for this array type.
*
* Precondition:	The subscript operator is unable to specify an index within
*				this array type.
*
* Postcondition: The subscript operator is able to specify an index within
*				 this array type.
************************************************************************/
template<typename T>
inline T & Array<T>::operator[](int index)
{
	index = index - m_start_index;	//index is now: passed (index - starting index) 

	if (index < 0)	//throw ex if negative
	{
		throw Exception("Index cannot be negative");
	}

	return m_array[index];	//return (passed index - starting index)
}

/**********************************************************************
* Purpose: This function returns m_start_index.
*
* Precondition: m_start_index is not available.
*
* Postcondition: m_start_index is available.
************************************************************************/
template <typename T>
inline int Array<T>::GetStartIndex() const
{
	return m_start_index;
}

/**********************************************************************
* Purpose: This function sets m_start_index to the start_inde passed into
*		   it.
*
* Precondition: m_start_index is not set.
*
* Postcondition: m_start_index is set to start_index.
************************************************************************/
template <typename T>
inline void Array<T>::SetStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**********************************************************************
* Purpose: This function returns m_length.
*
* Precondition: m_length is not available.
*
* Postcondition: m_length is available.
************************************************************************/
template <typename T>
inline int Array<T>::GetLength() const
{
	return m_length;
}

/**********************************************************************
* Purpose: This function sets m_length to length. It creates a new array
*		   of size length and then copies the data from m_array into the
*		   new array. Then it assigns m_array back to the new array.
*
* Precondition: m_length is unchanged.
*
* Postcondition: m_length is set to a new length, deleting the correct data.
************************************************************************/
template <typename T>
inline void Array<T>::SetLength(int length)
{
	if (length >= 0)
	{
		T * temp = new T[length];	//make new temp array

		for (int i = 0; i < m_length && i < length; i++)
		{
			temp[i] = m_array[i];	//copy over
		}

		delete[] m_array;	//delete old
		m_array = nullptr;	//reset old
		m_array = temp;

		m_length = length;	//reassign length
	}

	else //if length is negative, throw ex
	{
		throw Exception("Invalid length");
	}
}

