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
	itemList = new ItemType[10];

}

//constructor that accepts MaxArraySize parameter
SortedList::SortedList(int userMaxArraySize)
{
	MaxArraySize = userMaxArraySize;
	length = 0;
	curPos = 0;
	itemList = new ItemType[MaxArraySize];

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
	bool found = false;
	int iterator = 0;

	//checks if list is full before adding item
	if (this->GetLength() == MaxArraySize)
	{
		cout << "Array is full.";
		return false;
	}

	//this is true if item is not in list
	if (BinarySearch(itemList, userItem, 0, MaxArraySize - 1) < 0)
	{
		bool tempA = GetLength() < MaxArraySize;
		bool tempB = itemList[iterator] < userItem;

		while (GetLength() < MaxArraySize && itemList[iterator] < userItem)
		{
			iterator++;
		}

		iterator++;
		int indexToAdd = iterator;

		iterator = GetLength();

		for (iterator; iterator >= indexToAdd; iterator--)
		{
			itemList[iterator + 1] = itemList[iterator];
		}

		itemList[indexToAdd] = userItem;
	}

	return false;
}

ItemType SortedList::GetItem(ItemType userItem, bool& found)
{
	if (MaxArraySize != 0 && length != 0)
	{
		if (BinarySearch(itemList, userItem, 0, MaxArraySize - 1) < 0)
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
	ItemType item1;
	return item1;
}

void SortedList::MakeEmpty()
{

}

void SortedList::PrintList()
{

}

ItemType SortedList::GetNext()
{
	ItemType item1;
	return item1;
}

int SortedList::GetLength()
{
	return 0;
}

int SortedList::BinarySearch(ItemType* array, ItemType userItem, int low, int high)
{
	bool found;

	if (low > high)
	{
		return -1;
	}

	else
	{
		int middle = (low + high) / 2;
		if (userItem == array[middle])
		{
			return middle;
		}

		else if (userItem > array[middle])
		{
			return BinarySearch(array, userItem, middle + 1, high);
		}

		else
		{
			return BinarySearch(array, userItem, low, middle - 1);
		}
	}

}