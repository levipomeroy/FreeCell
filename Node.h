/*****************************************************************************
* Class: Node
*
* Purpose: This class manages the data and pointers associated with each node,
*		   to be used within the linked list.
*
* Manager functions:
* 	Node ()
* 		Sets next and previous pointers to nullptr and sets data to 0.
*	Node (const Node & copy)
*		Sets this pointer to copy, calling th op= to do operations.
*	Node(T Data, Node<T> * Next, Node<T> * Previous)
*		Sets m_data to data, m_next to next and m_previous to previous.
*	operator= (const Node & copy)
*		Assigns data in new node to data in old.
*	~Node()
*		Resets data members to their default values.
*
* Methods:
*	Node<T> * GetNext()
*		This function returns a pointer the next node.
*	Node<T> * GetPrevious()
*		This function returns a pointer the previous node.
*	T GetData()
*		This function returns the data of a node.
**********************************************************************************/
#ifndef NODE_H
#define NODE_H

template <typename T>
class List;	//foward declaration


template <typename T>
class Node
{
	friend class List<T>;

private:
	T m_Data;
	Node<T> * m_Next;
	Node<T> * m_Previous;

public:
	Node();
	Node(T Data, Node<T> * Next, Node<T> * Previous);	 //3 arg
	Node<T> & operator=(const Node<T> & rhs);
	Node(const Node<T> & copy);
	~Node();

	Node<T> * GetNext();
	Node<T> * GetPrevious();
	T GetData();

};

#endif

/**********************************************************************
* Purpose: This function initializes m_next and m_previous to nullptr.
*
* Precondition:	All data members were unassigned.
*
* Postcondition: Data members are assigned.
************************************************************************/
template<typename T>
inline Node<T>::Node() : m_Next(nullptr), m_Previous(nullptr)
{
}

/**********************************************************************
* Purpose: This function initializes m_next to next and m_previous to 
*		   previous and m_data to data.
*
* Precondition:	All data members were unassigned.
*
* Postcondition: Data members are assigned.
************************************************************************/
template<typename T>
inline Node<T>::Node(T Data, Node<T>* Next, Node<T>* Previous) : m_Data(Data), m_Next(Next), m_Previous(Previous)
{
}

/**********************************************************************
* Purpose: This function copies Nodes data members to a new node.
*
* Precondition:	New nodes data members were unassigned.
*
* Postcondition: New nodes data members are assigned.
************************************************************************/
template<typename T>
inline Node<T>::Node(const Node<T> & copy) : m_Data(copy.m_Data), m_Next(copy.m_Next), m_Previous(copy.m_Previous)
{
}

/**********************************************************************
* Purpose: This function resets data members to their default values.
*
* Precondition:	All data members were possibly assigned.
*
* Postcondition: Data members are assigned to default values.
************************************************************************/
template<typename T>
inline Node<T>::~Node()
{
	m_Next = nullptr;
	m_Previous = nullptr;
}

/**********************************************************************
* Purpose: This function returns a pointer to next.
*
* Precondition:	Next pointer was inaccessable.
*
* Postcondition: Next pointer is accessable.
************************************************************************/
template<typename T>
inline Node<T>* Node<T>::GetNext()
{
	return m_Next;	//Return pointer to next node
}

/**********************************************************************
* Purpose: This function returns a pointer to previous.
*
* Precondition:	Previous pointer was inaccessable.
*
* Postcondition: Previous pointer is accessable.
************************************************************************/
template<typename T>
inline Node<T> * Node<T>::GetPrevious()
{
	return m_Previous;	//Return pointer to previous node
}

/**********************************************************************
* Purpose: This function returns the data in a node.
*
* Precondition:	Data in node was inaccessable.
*
* Postcondition: Data in node is accessable.
************************************************************************/
template<typename T>
inline T Node<T>::GetData()
{
	return m_Data;	//Return data
}

/************************************************************************
* Purpose: This function assigns data of new node to the data of the old node.
*
* Precondition:	New nodes data was unassigned.
*
* Postcondition: New nodes data is assigned.
************************************************************************/
template<typename T>
inline Node<T> & Node<T>::operator=(const Node<T> & rhs)
{
	if (this != &rhs)
	{
		m_Data = rhs.m_Data;
	}
	return *this;
}
