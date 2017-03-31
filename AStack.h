/************************************************************************
* Class: AStack
*
* Purpose: This class is a wrapper around the array class i made in order 
*		   to impliment it in a manner like a stack.
*
* Manager functions:
* 	AStack ( )
* 		The default size is zero and the total size is set to 13 because
*		there are 13 cards in a suit.
*	AStack (int size)
*		Sets default size to 0 and the total size to size passed to it.
*	AStack (const AStack & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const AStack & copy)
*		Sets each data memeber, using the Array op= to handle the assignment
*		of the array instead of copying data.
*	~AStack()
*		Resets data memebers to default values, nothind to delete here.
*
* Methods:
*	Push (T data)
*		Push adds some data at the top of the stack, (end of array).
*	T Pop ()
*		Pop removes the top of the stack, (end of array) and returns the value.
*	T Peek ()
*		Peek returns the top of the stack but does not remove it from the list.
*	bool IsEmpty ()
*		This function returns where the stack is empty or not.
*	bool IsFull ()
*		This function returns whether the stack is full or not.
*	Print ()
*		This function displays the data in the stack.
*************************************************************************/

#include "Array.h"

#ifndef AStack_H
#define AStack_H

template <typename T>
class AStack
{
private:
	int m_total_size;
	int m_size;
	Array<T> m_AStack;

public:
	AStack();
	AStack(int size);
	AStack(const AStack<T> & copy);
	AStack<T> & operator=(const AStack<T> & rhs);
	~AStack();

	void Push(T data);	//Add data onto stack
	T Pop();			//Remove data from stack
	T Peek();			//View value at top of stack
	int Size();			//Returns current size of stack
	bool IsEmpty();		//Refelects whether stack is empty
	bool IsFull();		//Refelects whether stack is full
	void Print();		//Displays data in stack
};

#endif

/**********************************************************************
* Purpose: This function sets default size to 0 and total size to 13, for
*		   the 13 cards of a suit.
*
* Precondition:	Data members were uninitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
template<typename T>
inline AStack<T>::AStack() :m_size(0), m_total_size(13) //13 cards of a suit
{
}

/**********************************************************************
* Purpose: This function sets default size to 0 and total size to the size
*		   passed into it.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
template<typename T>
inline AStack<T>::AStack(int size) : m_size(0), m_total_size(size)
{
	m_AStack.SetLength(size);
}

/**********************************************************************
* Purpose: This function sets this to copy, calling the op= to handle 
*		   operations.
*
* Precondition:	N/A
*
* Postcondition: Copied.
************************************************************************/
template<typename T>
inline AStack<T>::AStack(const AStack<T>& copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets m_size to rhs.m_size, m_AStack to rhs.m_AStack,
*		   and m_total_size to rhs.m_total_size.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized to rhs's values.
************************************************************************/
template<typename T>
inline AStack<T>& AStack<T>::operator=(const AStack<T>& rhs)
{
	if (this != &rhs)
	{
		m_size = rhs.m_size;
		m_AStack = rhs.m_AStack;
		m_total_size = rhs.m_total_size;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function sets the data mambers back to dafualt values.
*
* Precondition:	Data members were possibly not default values.
*
* Postcondition: Data members are set to default values.
************************************************************************/
template<typename T>
inline AStack<T>::~AStack()
{
	m_size = 0;
	m_total_size = 0;
}

/**********************************************************************
* Purpose: This function adds data to the top of the stack, (end of the
*		   array). It may throw an exception if the stack overflows.
*
* Precondition:	Stack was a certian size.
*
* Postcondition: Stack's size is one greater than previous size.
************************************************************************/
template<typename T>
inline void AStack<T>::Push(T data)
{
	if (m_size <= m_total_size)
	{
		Array<T> temp(m_size + 1);

		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_AStack[i];
		}
		temp[m_size] = data;
		m_size++;

		m_AStack.SetLength(m_size);
		m_AStack = temp;
	}
	else
	{
		throw Exception("Overflow");
	}
}

/**********************************************************************
* Purpose: This function removes data from the top of the stack, (end of the
*		   array). It may throw an exception if the stack underflows.
*
* Precondition:	Stack was a certian size.
*
* Postcondition: Stack's size is one smaller than previous size.
************************************************************************/
template<typename T>
inline T AStack<T>::Pop()
{
	T hold_val = m_AStack[m_size - 1];

	if (m_size > 0)
	{
		m_size--;

		Array<T> temp(m_size);

		for (int i = 0; i < m_size; i++)
		{
			temp[i] = m_AStack[i];
		}

		m_AStack.SetLength(m_size);
		m_AStack = temp;
	}
	else
	{
		throw Exception("Underflow");
	}
	return hold_val;
}

/**********************************************************************
* Purpose: This function returns the data at the top of the stack. It does
*		   not remove it.
*
* Precondition:	Stack top was unknown.
*
* Postcondition: Stack's top is known.
************************************************************************/
template<typename T>
inline T AStack<T>::Peek()
{
	return m_AStack[m_size - 1];
}

/**********************************************************************
* Purpose: This function returns the current size of the stack.
*
* Precondition:	Stack size was unknown.
*
* Postcondition: Stack's size is known.
************************************************************************/
template<typename T>
inline int AStack<T>::Size()
{
	return m_size;
}

/**********************************************************************
* Purpose: This function returns whether the stack is empty or not.
*
* Precondition:	Stack emptiness status was unknown.
*
* Postcondition: Stack's emptiness status is known.
************************************************************************/
template<typename T>
inline bool AStack<T>::IsEmpty()
{
	bool empty = true;
	if (m_size > 0)
	{
		empty = false;
	}
	return empty;
}

/**********************************************************************
* Purpose: This function returns whether the stack is full or not.
*
* Precondition:	Stack fullness status was unknown.
*
* Postcondition: Stack's fullness status is known.
************************************************************************/
template<typename T>
inline bool AStack<T>::IsFull()
{
	bool full = true;
	if (m_total_size - m_size > 0)
	{
		full = false;
	}
	return full;
}

/**********************************************************************
* Purpose: This function prints the data within the stack.
*
* Precondition:	Stack was unprinted.
*
* Postcondition: Stack is printed.
************************************************************************/
template<typename T>
inline void AStack<T>::Print()
{
	m_AStack.Print();
}
