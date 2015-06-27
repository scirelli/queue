#ifndef QueueException_h
#define QueueException_h
#include<exception>
#include<string>

using namespace std;

class QueueException: public exception
{
public:
	  QueueException(const string & message= "")
		  : exception(message.c_str())
	  {}
}; //end QueueException

#endif