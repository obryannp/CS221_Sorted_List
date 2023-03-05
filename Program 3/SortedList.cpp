//file name: SortedList.cpp
//purpose: Class designed to help instantiate a sorted list and all of its functions
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "SortedList.h"
using namespace std;

//default constructor
SortedList::SortedList()
{
	MaxArraySize = 10;
	length = 0;
	curPos = 0;
	itemList = NULL;
}

//constructor that accepts MaxArraySize parameter
SortedList::SortedList(int userMaxArraySize)
{
	MaxArraySize = userMaxArraySize;
	length = 0;
	curPos = 0;
	itemList = NULL;
	
	//identification
	cout << "Nick O'Bryan, CS221-02, Program 3\n";
}

//destructor
SortedList::~SortedList()
{
	MakeEmpty();
}

//copy constructor
void SortedList::operator = (SortedList& listToCopy)
{

	int copyLength = listToCopy.GetLength();

	SortedList* tempList = new SortedList[copyLength];

	for (int index = 0; index < copyLength; index++)
	{
		tempList[index] = listToCopy[index];
	}

	MaxArraySize = listToCopy.MaxArraySize;
	length = listToCopy.GetLength();

}

bool SortedList::PutItem(ItemType userItem)
{
	return true;
}

ItemType GetItem(ItemType userItem, bool& found)
{
	return userItem;
}

bool DeleteItem(ItemType userItem)
{
	return true;
}

ItemType ResetList()
{
	return ;
}

void MakeEmpty()
{

}

void PrintList()
{

}

ItemType GetNext()
{

}

int GetLength()
{
	return 0;
}