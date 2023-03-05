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
void SortedList::operator = (const SortedList& listToCopy)
{

	int copyLength = listToCopy.length;

	//SortedList* tempList = new SortedList(copyLength);
	SortedList tempList;

	for (int index = 0; index < copyLength; index++)
	{
		tempList.itemList[index] = listToCopy.itemList[index];
	}

	MaxArraySize = listToCopy.MaxArraySize;
	length = listToCopy.length;
	curPos = 0;

}

bool SortedList::PutItem(ItemType userItem)
{
	//variables
	int iterator = 0;

	//checks if list is full before adding item
	if (this->GetLength() == MaxArraySize)
	{
		cout << "Array is full.\n";
		return false;
	}

	//this is true if item is not in list
	int tempSearch = BinarySearch(itemList, userItem, 0, length);
	if (tempSearch < 0)
	{
		//checks if list is empty
		if (GetLength() == 0)
		{
			itemList[0] = userItem;
			curPos = 0;
		}

		//if list already has items
		else
		{
			bool tempA = GetLength() < MaxArraySize;
			bool tempB = itemList[iterator] < userItem;
			bool tempC = iterator >= GetLength();

			//iterates through list until spot is found for new item
			while (tempA && tempB && !tempC)
			{
				iterator++;
				tempB = itemList[iterator] < userItem;
				tempC = iterator >= GetLength();
				if (tempC)
				{
					itemList[iterator] = userItem;
					length++;
					return true;
				}
			}

			int indexToAdd = iterator;

			for (int index = GetLength(); index > indexToAdd; index--)
			{
				itemList[index] = itemList[index - 1];
			}

			itemList[indexToAdd] = userItem;
		}

		length++;
		return true;
	}

	return false;
}

ItemType SortedList::GetItem(ItemType userItem, bool& found)
{
	if (MaxArraySize != 0 && length != 0)
	{
		if (BinarySearch(itemList, userItem, 0, length) < 0)
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
	length--;
	return true;
}

ItemType SortedList::ResetList()
{
	ItemType item1;
	return item1;
}

void SortedList::MakeEmpty()
{
	for (int index = 0; index < MaxArraySize; index++)
	{
		itemList[index].SetData(0, "");
	}

	length = 0;
	curPos = 0;
}

void SortedList::PrintList()
{
	for (int index = 0; index < length; index++)
	{
		cout << this->itemList[index].GetData() << " ";
	}
	cout << "length: " << length << " curPos: " << curPos << "\n";
}

ItemType SortedList::GetNext()
{
	ItemType item1;
	return item1;
}

int SortedList::GetLength()
{
	return length;
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