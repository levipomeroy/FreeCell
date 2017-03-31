/*****************************************************************************
* Class: List
*
* Purpose: This class is a data structure to hold data in the form of a doubly
*		   linked list.
*
* Manager functions:
* 	List ()
* 		m_head and m_tail are both set to nullptr.
*	List (const List & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	operator= (const List & copy)
*		Purges the old list and copies over all the data from list to new list.
*	~List()
*		Purges the list and sets m_head to nullptr and m_tail to nullptr.
*
* Methods:
*	bool IsEmpty()
*		Returns whether the list is empty or not.
*	T & First() const
*		Returns the first node in the list.
*	T & Last() const
*		Returns the last node in the list.
*	Prepend(T val)
*		Adds new data onto the front of the list.
*	Append(T val)
*		Adds new data onto the end of the list.
*	Purge()
*		Removes every node within the list.
*	Extract(T item)
*		Removes a specific node within the list, based on the value at that node.
*	InsertAfter(T item, T Data)
*		Inserts a new node directly after a specified value in the list.
*	InsertBefore(T item, T data)
*		Inserts a new node directly before a specified value in the list.
*	Node<T> * GetHead()
*		Returns a pointer to the head of the list.
*	Node<T> * GetTail();
*		Returns a pointer to the tail of the list.
*	PrintForwards()
*		Print the list from the beginning to the end.
*	PrintBackwards()
*		Print the list from the end to the beginning.
**********************************************************************************/
#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Exception.h"
using std::cout;
using std::endl;

template <typename T>
class List
{
private:
	Node<T> * m_Head;	//Pointer to beggining of list
	Node<T> * m_Tail;	//Pointer to end of list

public:
	List();	//Default ctor
	List(const List<T> & copy);	//Copy ctor
	List<T> & operator=(const List<T> & rhs); //Assigment operator
	~List();	//Destructor

	bool IsEmpty();
	T & First() const;		//Returns refernce to data in first element
	T & Last() const;		//Returns refernce to data in last element
	void Prepend(T val);	//Adds node to front of list
	void Append(T val);		//Adds node to end of list
	void Purge();			//Remove all items from list
	void Extract(T item);
	void InsertAfter(T item, T Data);
	void InsertBefore(T item, T data);

	//****Testing only****
	Node<T> * GetHead();	//Returns the head pointer
	Node<T> * GetTail();	//Returns the Tail pointer
	void PrintForwards();	//Prints list foward
	void PrintBackwards();	//Prints list backwards
};
#endif 

/**********************************************************************
* Purpose: This function sets m_Head to nullptr and sets m_Tail to nullptr.
*
* Precondition:	Data members were unitialized.
*
* Postcondition: Data members are initialized.
************************************************************************/
template<typename T>
inline List<T>::List() :m_Head(nullptr), m_Tail(nullptr)
{
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
inline List<T>::List(const List<T> & copy) : m_Head(nullptr), m_Tail(nullptr)
{
	*this = copy;
}

/**********************************************************************
* Purpose: This function purges the list and then copies over all the 
*		   data from the list into the new list.
*
* Precondition:	Data in the new list was uninitialized.
*
* Postcondition: Data in the new list is initialized.
************************************************************************/
template<typename T>
inline List<T> & List<T>::operator=(const List<T> & rhs)
{
	if (this != &rhs)
	{
		if (!this->IsEmpty())
		{
			Purge();
		}
		Node<T> * temp = rhs.m_Head;	//Create traveler
		while (temp != nullptr)
		{
			this->Append(temp->m_Data);
			temp = temp->m_Next;
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: This function purges the list and then resets the data members
*		   to default valuies.
*
* Precondition:	Data members are possibly initialized.
*
* Postcondition: Data members are initialized to default values
************************************************************************/
template<typename T>
inline List<T>::~List()
{
	Purge();
	delete m_Head;	//Delete
	delete m_Tail;
	m_Head = nullptr; //Reset
	m_Tail = nullptr;
}

/**********************************************************************
* Purpose: This function returns whether the list is empty or not.
*
* Precondition:	List's emptiness status was unknown.
*
* Postcondition: List's emptiness status is known.
************************************************************************/
template<typename T>
inline bool List<T>::IsEmpty()
{
	bool Empty = false;	//Is not empty

	if (m_Head == nullptr && m_Tail == nullptr)
	{
		Empty = true;	//Is empty
	}

	return Empty;
}

/**********************************************************************
* Purpose: This function returns the value at the first node in the list.
*
* Precondition:	List's first nodes value was unknown.
*
* Postcondition: List's first nodes value is known.
************************************************************************/
template<typename T>
inline T & List<T>::First() const
{
	if (m_Head == nullptr)
	{
		throw Exception("No first to return");
	}

	return m_Head->m_Data;	//Return reference to first node of list
}

/**********************************************************************
* Purpose: This function returns the value at the last node in the list.
*
* Precondition:	List's lst nodes value was unknown.
*
* Postcondition: List's last nodes value is known.
************************************************************************/
template<typename T>
inline T & List<T>::Last() const
{
	if (m_Tail == nullptr)
	{
		throw Exception("No last to return");
	}
	return m_Tail->m_Data;	//Return reference to last node of list
}

/**********************************************************************
* Purpose: This function adds a new node at the beginning of the list.
*
* Precondition:	List was a certian size.
*
* Postcondition: List is one bigger.
************************************************************************/
template<typename T>
inline void List<T>::Prepend(T val)
{
	Node<T> * temp = new Node<T>;	//Create new node
	if (IsEmpty()) //for first node 
	{
		temp->m_Previous = nullptr;	//set new nodes prev to null
		temp->m_Next = nullptr;	//set new nodes next to null
		temp->m_Data = val;		//Assign data to node
		m_Tail = temp;
		m_Head = temp;	//set head to new node
	}
	else
	{
		temp->m_Previous = nullptr;	//set new nodes prev to null
		temp->m_Next = m_Head;	//set new nodes next to head
		m_Head->m_Previous = temp;
		temp->m_Data = val;	//Assign data to node
		m_Head = temp;	//Reassign head to temp
	}
}

/**********************************************************************
* Purpose: This function adds a new node at the end of the list.
*
* Precondition:	List was a certian size.
*
* Postcondition: List is one bigger.
************************************************************************/
template<typename T>
inline void List<T>::Append(T val)
{
	Node<T> * temp = new Node<T>;	//Create new node
	if (IsEmpty()) //for first node 
	{
		temp->m_Previous = nullptr;	//set new nodes prev to null
		temp->m_Next = nullptr;	//set new nodes next to null
		temp->m_Data = val;		//Assign data to node
		m_Tail = temp;
		m_Head = temp;	//set head to new node
	}
	else
	{
		temp->m_Next = nullptr;  //set new nodes next to null
		temp->m_Previous = m_Tail; //set new nodes prev to tail
		m_Tail->m_Next = temp; //set tails next to new node
		temp->m_Data = val;	//assign data value to node
		m_Tail = temp;	//Reassign position of tail
	}
}

/**********************************************************************
* Purpose: This function removes everything in the list.
*
* Precondition:	List was not necessarily empty.
*
* Postcondition: List is empty.
************************************************************************/
template<typename T>
inline void List<T>::Purge()
{
	while (m_Head != nullptr)
	{
		Node<T> * temp = m_Head;	//Create temporary node

		m_Head = m_Head->m_Next;	//move head up one 
									//m_Head->m_Previous = nullptr;

		delete temp; //Delete temp
		temp = nullptr;
	}	//Repeat until all items in list are purged
	m_Tail = nullptr;
	m_Head = nullptr;
}

/**********************************************************************
* Purpose: This function removes a node at a certian spot in the list.
*
* Precondition:	Node is in list.
*
* Postcondition: Node was extracted from list.
************************************************************************/
template<typename T>
inline void List<T>::Extract(T item)
{
	bool not_found = true;
	Node<T> * temp = m_Head;	//Create temporary node

	while (temp != nullptr && not_found)
	{
		if (temp->m_Data != item)
		{
			temp = temp->m_Next;
		}
		else
		{
			not_found = false;
		}
	}

	if (not_found)
	{
		throw Exception("The item is not in the list");
	}
	if (temp->m_Data == m_Tail->m_Data && temp->m_Data == m_Head->m_Data)
	{
		m_Tail = nullptr;
		m_Head = nullptr;
		delete temp;
		temp = nullptr;
	}
	else if (temp->m_Data == m_Tail->m_Data) //if value to delete is tail
	{
		m_Tail = m_Tail->m_Previous;	//reassign tail
		temp->m_Next = nullptr;
		temp->m_Previous->m_Next = nullptr;
		delete temp;	//Delete
		temp = nullptr;
	}
	else if (temp->m_Data == m_Head->m_Data)	//if value to delete is head 
	{
		m_Head = m_Head->m_Next;	//Reassign head 
		delete temp;	//Delete
		temp = nullptr;
	}
	else
	{
		temp->m_Next->m_Previous = temp->m_Previous;	//Reassign pointers of surrounding nodes
		temp->m_Previous->m_Next = temp->m_Next;
		delete temp;	//Delete
		temp = nullptr;
	}
}

/**********************************************************************
* Purpose: This function adds a node directly after a specified node 
*		   in the list.
*
* Precondition:	Node is not in list.
*
* Postcondition: Node is in list, directly after specified node.
************************************************************************/
template<typename T>
inline void List<T>::InsertAfter(T item, T data)
{
	bool not_found = true;
	Node<T> * temp = m_Head;	//Create temporary node

	while (temp != nullptr && not_found)	//if not done and notfound = true
	{
		if (temp->m_Data != item)
		{
			temp = temp->m_Next;	//move up one
		}
		else
		{
			not_found = false;	//it was fouund in list
		}
	}
	if (not_found)
	{
		throw Exception("The item is not in the list");
	}

	if (temp->m_Data == m_Tail->m_Data) //if value to delete is tail
	{
		Append(data);	//No need for duplicate code..
	}
	else
	{
		Node<T> * nn = new Node<T>;	//Create new node to place after item's node
		nn->m_Next = temp->m_Next;	//adjust pointers
		nn->m_Previous = temp;
		temp->m_Next = nn;
		nn->m_Next->m_Previous = nn;
		nn->m_Data = data;	//Assign data to node
	}
}

/**********************************************************************
* Purpose: This function adds a node directly before a specified node
*		   in the list.
*
* Precondition:	Node is not in list.
*
* Postcondition: Node is in list, directly before the specified node.
************************************************************************/
template<typename T>
inline void List<T>::InsertBefore(T item, T data)
{
	bool not_found = true;
	Node<T> * temp = m_Head;	//Create travel node

	while (temp != nullptr && not_found)	//if not done and notfound = true
	{
		if (temp->m_Data != item)
		{
			temp = temp->m_Next;	//Move up one
		}
		else
		{
			not_found = false;	//found in list
		}
	}
	if (not_found)
	{
		throw Exception("The item is not in the list");
	}
	if (temp->m_Data == m_Head->m_Data)	//if value is head prepend new node before it
	{
		Prepend(data);	//Call existing function to do this
	}
	else
	{
		Node<T> * nn = new Node<T>;	//Create new node for before item''s node
		nn->m_Next = temp;	//Allign pointers
		nn->m_Previous = temp->m_Previous;
		temp->m_Previous = nn;
		temp->m_Previous->m_Previous->m_Next = nn;
		nn->m_Data = data;	//Assign data to node
	}
}

/**********************************************************************
* Purpose: This function returns the head of the list.
*
* Precondition:	List's head is not available.
*
* Postcondition: List's head is available.
************************************************************************/
template<typename T>
inline Node<T> * List<T>::GetHead()
{
	return m_Head;	//Return head
}

/**********************************************************************
* Purpose: This function returns the tail of the list.
*
* Precondition:	List's tail is not available.
*
* Postcondition: List's head is available.
************************************************************************/
template<typename T>
inline Node<T> * List<T>::GetTail()
{
	return m_Tail;	//Return tail
}

/**********************************************************************
* Purpose: This function prints the list fowards.
*
* Precondition:	List is not printed.
*
* Postcondition: List is printed.
************************************************************************/
template<typename T>
inline void List<T>::PrintForwards()
{
	Node<T> * nnode = m_Head;	//Create temporary node
	if (nnode == nullptr)
	{
		throw Exception("The list is empty!!");
	}
	while (nnode != nullptr)
	{
		cout << nnode->m_Data << " ";	//print temporary
		nnode = nnode->m_Next;
	}	//Repeat until all are printed
	cout << "\n\n";
	delete nnode;
	nnode = nullptr;
}

/**********************************************************************
* Purpose: This function prints the list backwards.
*
* Precondition:	List is not printed.
*
* Postcondition: List is printed.
************************************************************************/
template<typename T>
inline void List<T>::PrintBackwards()
{
	Node<T> * temp = m_Tail;	//Create temporary node
	if (temp == nullptr)
	{
		throw Exception("The list is empty!!");
	}
	while (temp != nullptr)
	{
		cout << temp->m_Data << " ";	//print temporary
		temp = temp->m_Previous;
	}	//Repeat until all are printed
	cout << "\n\n";
	delete temp;
}