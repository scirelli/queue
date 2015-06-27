//*************************************************************************************
//Implementation file Queuep.cpp for the ADT queue
//Pointer-based implemention
//**************************************************************************88
#ifndef QueuePImp_h
#define QueuePImp_h

#include <cstddef>
#include <cassert>

Queue:: Queue() : backPtr(NULL), frontPtr(NULL)
{
}//end default constructor

Queue::Queue(const Queue& Q)
{ //Implementation left as an excercise (excercise 4)
}

Queue::~Queue()
{
	while(!isEmpty())
		dequeue();
} //end destructor

bool Queue::isEmpty() const
{
	return bool(backPtr == NULL);
} //end isEmpty

void Queue::enqueue(QueueItemType newItem)
{
	//create a new node
	QueueNode *newPtr = new QueueNode;

	if (newPtr == NULL) //check allocation
		throw QueueException("QueueException: enqueue cannot allocate memory");
	else
	{
		newPtr->item = newItem;
	//insert the new node
		if(isEmpty())
		//insertion into empty queue
			frontPtr = newPtr;
		else
			backPtr->next = newPtr;
			
		backPtr = newPtr; //new node is at back
		
	}
}

void Queue::dequeue()
{
	if(isEmpty())
		throw QueueException("QueueException: empty queue, cannot dequeue");
	else
	{
		QueueNode *tempPtr = frontPtr;
		if(frontPtr == backPtr)
		{//yes, one node in queue
			frontPtr = NULL;
			backPtr = NULL;
		}
		else
			frontPtr = frontPtr->next;

		tempPtr->next = NULL; //defensice strategy
		delete tempPtr;
	}
}//end dequeue

void Queue::dequeue(QueueItemType& queueFront)
{
	if(isEmpty())
		throw QueueException(
		"QueueException: empty queue, cannot dequeue");
	else
	{
		queueFront = frontPtr-> item;
		dequeue(); //delete front
	} //end if
}//end dequeue

void Queue::getFront(QueueItemType& queueFront) const
{
	if (isEmpty())
		throw QueueException(
		"QueueException: empty queue, cannot getFront");
	else
		//queue is not empty; retrieve front
		queueFront = frontPtr->item;
}//end GetFront
//end of implementation file

#endif