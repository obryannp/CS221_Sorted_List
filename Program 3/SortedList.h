//file name: SortedList.h
//purpose: Class definition and function prototypes for SortedList.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#pragma once
#include "ItemType.h"

class SortedList
{
private:

	int MaxArraySize = 0;
	ItemType* itemList = NULL;
	int length = 0;
	int curPos = 0;

public:

	SortedList();
	SortedList(int userMaxArraySize);
	~SortedList();

	//copy constructor
	//void operator = (SortedList& listToCopy);

	bool PutItem(ItemType userItem);
	ItemType GetItem(ItemType userItem, bool& found);
	bool DeleteItem(ItemType userItem);
	ItemType ResetList();
	void MakeEmpty();
	void PrintList();
	ItemType GetNext();
	int GetLength();
	int binarySearch(SortedList* array, ItemType userItem, int low, int high);
};