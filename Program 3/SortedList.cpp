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
	//delete itemList;
}

//copy constructor
void SortedList::operator = (const SortedList& listToCopy)
{
	//placeholder variables
	int tempNum;
	string tempStr;

	//length of original array
	int copyLength = listToCopy.length;

	//iterates over list and deep copies all items to new list
	for (int index = 0; index < copyLength; index++)
	{
		tempNum = listToCopy.itemList[index].GetData(tempStr);
		itemList[index].SetData(tempNum, tempStr);
	}

	//copies all other info from original list to new list, sets curPos to 0
	MaxArraySize = listToCopy.MaxArraySize;
	length = listToCopy.length;
	curPos = 0;

}

bool SortedList::PutItem(ItemType userItem)
{
	cout << "PutItem():   ";
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
			//added these so conditional statements are easier to read
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
					string tempStr;
					cout << "Added: " << userItem.GetData(tempStr) << "  " << tempStr << "\n";
					itemList[iterator] = userItem;
					length++;
					return true;
				}
			}

			int indexToAdd = iterator;

			//iterates through list and moves items out to make space for new item
			for (int index = GetLength(); index > indexToAdd; index--)
			{
				itemList[index] = itemList[index - 1];
			}

			//adds new item to the list in open spot
			itemList[indexToAdd] = userItem;
		}

		//increments length and prints statement to user
		string tempStr;
		cout << "Added: " << userItem.GetData(tempStr) << "  " << tempStr << "\n";
		length++;
		return true;
	}

	cout << "Item is already in the list.\n";
	return false;
}

//function that searches for item in the list
ItemType SortedList::GetItem(ItemType userItem, bool& found)
{
	//default itemtype to return if item not found
	ItemType defaultItem;

	//checks if the list is initialized and there are items in the list
	if (MaxArraySize != 0 && length != 0)
	{
		//runs if item is not found in binary search
		if (BinarySearch(itemList, userItem, 0, length) < 0)
		{
			cout << "Item not found.\n";
			found = false;
			return defaultItem;
		}
		//runs if item is found
		cout << "Item was found.\n";
		found = true;
		return userItem;
	}

	cout << "Item not found, array has no items.\n";
	found = false;
	return defaultItem;
}

bool SortedList::DeleteItem(ItemType userItem)
{
	cout << "\nDeleteItem():\n";
	//this is true if item is in the list
	int indexToRemove = BinarySearch(itemList, userItem, 0, length);
	if (indexToRemove >= 0)
	{
		//moves all items over and deletes item to be deleted
		for (int index = indexToRemove; index < length; index++)
		{
			itemList[index] = itemList[index + 1];
		}

		//decrements length and returns true
		cout << "Deleted, Stock Number: " << userItem.GetData() << "\n";
		length--;
		return true;
	} 

	//if item is not found/list empty
	cout << "Item not found.\n";
	return false;
}

//function that resets list
ItemType SortedList::ResetList()
{
	curPos = 0;
	return itemList[curPos];
}

//function that makes the list empty and sets length to 0
void SortedList::MakeEmpty()
{
	for (int index = 0; index < MaxArraySize; index++)
	{
		itemList[index].SetData(0, "");
	}

	length = 0;
	curPos = 0;
}

//iterates over list and prints each item
void SortedList::PrintList()
{
	cout << "\nPrintList()\n";
	//temporary string variable
	string tempStr;

	//iterate list
	for (int index = 0; index < length; index++)
	{
		cout << this->itemList[index].GetData(tempStr) << "   " << tempStr << "  --  ";
	}
	cout << "\n" << endl;
}

ItemType SortedList::GetNext()
{
	curPos++;
	return itemList[curPos];
}


//function that returns variable length
int SortedList::GetLength()
{
	return length;
}

//binary search function that searches through list to find a specific stock number
int SortedList::BinarySearch(ItemType* array, ItemType userItem, int low, int high)
{
	//if item is not in the list, returns -1
	if (low > high)
	{
		return -1;
	}

	//recursive aspect
	else
	{
		int middle = (low + high) / 2;
		cout << "Searching... " << array[middle].GetData() << "   ";
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
	cout << "\n";
}