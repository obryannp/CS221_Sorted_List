//file name: ItemType.h
//purpose: Class definition and function prototypes for ItemType.cpp
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#pragma once
#include <iostream>
#include <string>
using namespace std;

class ItemType
{
private:

	int stockNum = 0;
	string title;

public:

	ItemType();
	ItemType(int userStockNum, string userTitle);
	~ItemType();

	bool operator < (const ItemType& userItem);
	bool operator > (const ItemType& userItem);
	bool operator == (const ItemType& userItem);

	int GetData();
	int GetData(string& title);
	void SetData(int userStockNum, string userTitle);
};

