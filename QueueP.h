//Header file QueueP.h for the ADT queue.
//Pointer-based implementation.
//*******************************************************************************
#ifndef QueueP_h
#define QueueP_h
#include "QueueException.h"
typedef int QueueItemType;

class Queue
{
public:
//constructor and destructor:
	Queue();								//default contructor
	Queue(const Queue& Q);                 //copy constructor
	~Queue();

//Queue operations:
	bool isEmpty() const;
	//Determines whethere the queue is empty
	//Precondtion: None
	//Postcondition: Returns true if the queue if the queue is empty
	//otherwise returns false.
	void enqueue(QueueItemType newItem) throw (QueueException);
	//insert an item at the back of a queue
	//Precondition: newItem is the item to be inserted.
	//Postcondition: If the insertion is successful, newItem
	//is at the back of the queue
	//Exception: Throws QueueException if newItem cannot
	//be place on the queue/

	void dequeue() throw(QueueException);
	//Dequeue the front of a queue 
	//Precondition: None
	//Postcondition: If the queue is not empty, the item
	//that was added to the queue earliest is deleted
	//Exception: throws QueueException if the queue is empty

	void dequeue(QueueItemType& queueFront)
		throw(QueueException);
	//Retrieves and deletes the front of a queue  
	//Precondition: None
	//PostCondition: If the queue is not empty, queueFront
	//contains the item that was added to the queue
	//earliest, and the item is deleted
	//Exception: Throws QueueException if the queue is
	//empty

	void getFront(QueueItemType& queueFront) const
		throw (QueueException);
	//Retrieves the item at the front of a queue
	//Precondition: None.
	//Postcondition: If the queue is not empty, queueFront 
	//contains the item that was added to the queue 
	//earliest 
	//Exception: Throws QueueException if the queue is 
	//empty

private:
	 //the queue is implemented as a linked list
	//with one external pointer to the front of the queue
	//and a second external pointer to the back of the 
	//queue
	struct QueueNode
	{
		QueueItemType item;
		QueueNode	  *next;
	};
	QueueNode *frontPtr;
	QueueNode *backPtr;
};
//End of header file

#endif