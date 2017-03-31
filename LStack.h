/************************************************************************
* Class: LStack
*
* Purpose: This class is a wrapper around the List class i made in order
*		   to impliment it in a manner like a stack.
*
* Manager functions:
* 	LStack ()
* 		The default size is zero.
*	LStack (const LStack & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const LStack & copy)
*		Sets each data memeber, using the List op= to handle the assignment
*		of the array instead of copying data.
*	~LStack()
*		Resets data memebers to default values, nothind to delete here.
*
* Methods:
*	Push (T data)
*		Push adds some data at the top of the stack, (end of list).
*	T Pop ()
*		Pop removes the top of the stack, (end of list) and returns the value.
*	T Peek ()
*		Peek returns the top of the stack but does not remove it from the list.
*	bool IsEmpty ()
*		This function returns where the stack is empty or not.
*	int Size()
*		Returns the size of the stack.
*	bool IsFull ()
*		This function returns whether the stack is full or not.
*	Print ()
*		This function displays the data in the stack.
*************************************************************************/
#include "List.h"

#ifndef LStack_H
#define LStack_H

template <typename T>
class LStack
{
public:
	LStack();
	~LStack();
	LStack(const LStack<T> & copy);
	LStack<T> & operator=(const LStack<T> & rhs);

	void Push(T data);
	T Pop();
	T Peek();
	int Size();
	bool IsEmpty();
	void Print();
	Node<T> * First();
	Node<T> * Last();

private:
	int m_size;
	List<T> m_LStack;
};

#endif

/**********************************************************************
* Purpose: This function sets default size to 0.
*
* Precondition:	Data members were uninitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
template<typename T>
inline LStack<T>::LStack() : m_size(0)
{
}

/**********************************************************************
* Purpose: This function sets the data mambers back to dafualt values.
*
* Precondition:	Data members were possibly not default values.
*
* Postcondition: Data members are set to default values.
************************************************************************/
template<typename T>
inline LStack<T>::~LStack()
{
	m_size = 0;
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
inline LStack<T>::LStack(const LStack<T> & copy)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function sets m_size to rhs.m_size, m_LStack to rhs.m_lStack.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized to rhs's values.
************************************************************************/
template<typename T>
inline LStack<T>& LStack<T>::operator=(const LStack<T>& rhs)
{
	if (this != &rhs)
	{
		m_size = rhs.m_size;
		m_LStack = rhs.m_LStack;
	}
	return *this;
}

/**********************************************************************
* Purpose: This function adds data to the top of the stack, (end of the
*		   list). It may throw an exception if the stack overflows.
*
* Precondition:	Stack was a certian size.
*
* Postcondition: Stack's size is one greater than previous size.
************************************************************************/
template<typename T>
inline void LStack<T>::Push(T data)
{
	m_LStack.Append(data);
	m_size++;
}

/**********************************************************************
* Purpose: This function removes data from the top of the stack, (end of the
*		   list). It may throw an exception if the stack underflows.
*
* Precondition:	Stack was a certian size.
*
* Postcondition: Stack's size is one smaller than previous size.
************************************************************************/
template<typename T>
inline T LStack<T>::Pop()
{
	T popped_val = m_LStack.Last();
	if (!IsEmpty())
	{
		m_LStack.Extract(popped_val);
		m_size--;
	}
	else
	{
		throw Exception("Underflow");
	}

	return popped_val;
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
inline T LStack<T>::Peek()
{
	return m_LStack.Last();
}

/**********************************************************************
* Purpose: This function returns the current size of the stack.
*
* Precondition:	Stack size was unknown.
*
* Postcondition: Stack's size is known.
************************************************************************/
template<typename T>
inline int LStack<T>::Size()
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
inline bool LStack<T>::IsEmpty()
{
	bool empty = true;
	if (!m_LStack.IsEmpty())
	{
		empty = false;
	}
	return empty;
}

/**********************************************************************
* Purpose: This function prints the data within the stack.
*
* Precondition:	Stack was unprinted.
*
* Postcondition: Stack is printed.
************************************************************************/
template<typename T>
inline void LStack<T>::Print()
{
	int i = 0;
	Node<T> * travel = m_LStack.GetHead();
	while (i < m_size)
	{
		cout << travel->GetData() << " ";
		travel = travel->GetNext();
		i++;
	}
	cout << "\n";
}

/**********************************************************************
* Purpose: This function returns the first node within the list.
*
* Precondition:	The first node within list is inaccessable.
*
* Postcondition: The first node within list is accessable.
************************************************************************/
template<typename T>
inline Node<T> * LStack<T>::First()
{
	return m_LStack.GetHead();
}

/**********************************************************************
* Purpose: This function returns the last node within the list.
*
* Precondition:	The last node within list is inaccessable.
*
* Postcondition: The last node within list is accessable.
************************************************************************/
template<typename T>
inline Node<T>* LStack<T>::Last()
{
	return m_LStack.GetTail();
}
