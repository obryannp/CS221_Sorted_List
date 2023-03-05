//file name: Test_Driver.cpp
//purpose: Tests all functions and classes in ItemType and SortedList
//
//name: Nick O'Bryan
//email: npo0003@uah.edu
//CS 221-02, Spring 2023

#include "ItemType.h"
#include "SortedList.h"

//ItemType Tests
/*ItemType item1;
ItemType item2(30,"ABCDEF");
ItemType item3(40, "ABCDEFG");

int main()
{
	if (item1 < item2)
	{
		cout << "<";
	}

	if (item1 > item2)
	{
		cout << ">";
	}

	if (item1 == item2)
	{
		cout << "==";
	}
}*/

int main()
{
	//SortedList tests
	SortedList list1;
	SortedList list2;
	ItemType item1(10, "1st");
	ItemType item2(9, "2nd");
	ItemType item3(8, "3rd");
	ItemType item4(7, "4th");
	ItemType item5(6, "5th");
	ItemType item6(5, "6th");
	ItemType item7(4, "7th");
	ItemType item8(3, "7th");
	ItemType item9(2, "7th");
	ItemType item10(1, "7th");
	//ItemType item11(11, "7th");
	
	list1.PutItem(item1);
	list1.PutItem(item1);
	list1.PutItem(item3);
	list1.PutItem(item2);
	list1.PutItem(item4);
	list1.PutItem(item5);
	list1.PutItem(item6);
	list1.PutItem(item7);
	list1.PutItem(item8);
	list1.PutItem(item9);
	list1.PutItem(item1);
	//list1.PutItem(item10);
	//list1.PutItem(item11);

	list1.PrintList();

	list1 = list2;

	list1.MakeEmpty();
	list1.PrintList();
	list2.PrintList();
}
