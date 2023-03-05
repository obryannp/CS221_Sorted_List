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
	SortedList* newList = new SortedList[MaxArraySize];
}

//constructor that accepts MaxArraySize parameter
SortedList::SortedList(int userMaxArraySize)
{
	MaxArraySize = userMaxArraySize;
	length = 0;
	curPos = 0;
	SortedList* newList = new SortedList[MaxArraySize];

	//identification
	cout << "Nick O'Bryan, CS221-02, Program 3\n";
}

//destructor
SortedList::~SortedList()
{
	MakeEmpty();
}

//copy constructor
/*void SortedList::operator = (SortedList& listToCopy)
{

	int copyLength = listToCopy.GetLength();

	SortedList* tempList = new SortedList[copyLength];

	for (int index = 0; index < copyLength; index++)
	{
		tempList[index] = listToCopy[index];
	}

	MaxArraySize = listToCopy.MaxArraySize;
	length = listToCopy.GetLength();

}*/

bool SortedList::PutItem(ItemType userItem)
{
	if (this->GetLength() == MaxArraySize)
	{
		cout << "Array is full.";
		return false;
	}

	for (int index = 0; index > MaxArraySize; index++)
	{
		if 
	}
	return true;
}

ItemType SortedList::GetItem(ItemType userItem, bool& found)
{
	if (MaxArraySize != 0 && length != 0)
	{
		if (binarySearch(this, userItem, 0, MaxArraySize - 1) < 0)
		{
			cout << "Item not found.\n";
			found = false;
			return userItem;
		}

		cout << "Item was found.\n";
		found = true;
		return userItem;
	}

	cout << "Item not found.\n";
	found = false;
	return userItem;
}

bool SortedList::DeleteItem(ItemType userItem)
{
	return true;
}

ItemType SortedList::ResetList()
{
	return ;
}

void SortedList::MakeEmpty()
{

}

void SortedList::PrintList()
{

}

ItemType SortedList::GetNext()
{

}

int SortedList::GetLength()
{
	return 0;
}

int SortedList::binarySearch(SortedList* array, ItemType userItem, int low, int high)
{
	bool found;

	if (low > high)
	{
		return -1;
	}

	else
	{
		int middle = (low + high) / 2;
		if (userItem == array[middle].GetItem(userItem, found))
		{
			return middle;
		}

		else if (userItem > array[middle].GetItem(userItem, found))
		{
			return binarySearch(array, userItem, middle + 1, high);
		}

		else
		{
			return binarySearch(array, userItem, low, middle - 1);
		}
	}

}