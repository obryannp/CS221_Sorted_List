//file name: ItemType.cpp
//purpose: create a class that instantiates an object for use in SortedList.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "ItemType.h"
#include <iostream>
using namespace std;

//default constructor
ItemType::ItemType()
{
	stockNum = 0;
	title = "none";
}

//destructor
ItemType::~ItemType()
{
	//no duties
}

//constructor that allows parameter to be passed
ItemType::ItemType(int userStockNum, string userTitle)
{
	stockNum = userStockNum;
	title = userTitle;
}

//function that returns true if incoming stock num is less than current one
bool ItemType::operator < (const ItemType& userItem)
{
	return userItem.stockNum > stockNum;
}

//function that returns true if incoming stock num is greater than current one
bool ItemType::operator > (const ItemType& userItem)
{
	return userItem.stockNum < stockNum;
}

//function that returns true if incoming stock num is equal to current one
bool ItemType::operator == (const ItemType& userItem)
{
	return userItem.stockNum == stockNum;
}

//function that returns the stock number of an item
int ItemType::GetData()
{
	return stockNum;
}

//function that returns the stock number and title of an item
int ItemType::GetData(string& userTitle)
{
	userTitle = title;
	return stockNum;
}

//function that sets the stock num and title in a specific item
void ItemType::SetData(int userStockNum, string userTitle)
{
	stockNum = userStockNum;
	title = userTitle;
}