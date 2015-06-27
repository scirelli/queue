#include "QueueP.h"
#include "QueuePImp.h"
#include "StackP.h"
#include "StackPImp.h"
#include <iostream>
#include <string>
#include <fstream>

void main()
{
	Stack iStack;
	Queue iQ;
	fstream inFile;
	char* fileName= new char[80];
	int iNumber=-1;
	bool same= true;

	//cout<< "Enter file name ";
	//cin.getline(fileName, 80, '\n');

	inFile.open("c:\\mydocu~1\\visual~1\\queue\\test2.txt", ios::in);
	//inFile.open(fileName, ios::in);

	cout<< "\nInput-> ";
	while(!inFile.eof())
	{
		inFile >> iNumber;
		iStack.push(iNumber);
		iQ.enqueue(iNumber);
		cout << iNumber << " ";
	}
	

	iNumber=-1;
	int iNumber2=-1;
	
	while( (same) && ( (!iStack.isEmpty()) && (!iQ.isEmpty()) ) )
	{
		iStack.getTop(iNumber);
		iQ.getFront(iNumber2);
		//iQ.dequeue(iNumber2);
		
		cout<< "\nStack= " << iNumber << "\nQueue= " << iNumber2;
		if(iNumber != iNumber2)
		{
			same= false;
			cout <<"\n\tThey are not palondrones\n";
			return;
		}
		
		iStack.pop();
		iQ.dequeue();
	}
	
	cout<< "\n\tThey are Palondrones\n";
	
	return;
}