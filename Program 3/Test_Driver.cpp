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
	SortedList list2(12);
	ItemType item1(1, "1st");
	ItemType item2(2, "2nd");
	ItemType item3(3, "3rd");
	ItemType item4(4, "4th");
	ItemType item5(5, "5th");
	ItemType item6(6, "6th");
	ItemType item7(7, "7th");
	ItemType item8(8, "8th");
	ItemType item9(9, "9th");
	ItemType item10(10, "10th");
	ItemType item11(11, "11th");
	ItemType item12(12, "12th");
	ItemType item13(13, "13th");
	
	//adds items out of order into the right order
	cout << "ORDER CHECK:\n";
	list1.PutItem(item1);
	list1.PutItem(item3);
	list1.PutItem(item2);
	list1.PrintList();

	//adds item already in list
	cout << "\nALREADY IN LIST:\n";
	list1.PutItem(item1);

	//checks bounds of array
	cout << "\nCHECK MAX ITEMS:\n";
	list1.PutItem(item4);
	list1.PutItem(item5);
	list1.PutItem(item6);
	list1.PutItem(item7);
	list1.PutItem(item8);
	list1.PutItem(item9);
	list1.PutItem(item10);
	list1.PutItem(item11);

	list1.PrintList();

	//copy constructor tests
	/*cout << "\nCOPY CONSTRUCTOR TESTS: \n";
	list2 = list1;
	cout << "list1:";
	list1.MakeEmpty();
	list1.PrintList();
	cout << "list2:";
	list2.PrintList();*/
	
	//tests with different max items for list
	cout << "\nCUSTOM MAX ITEMS CHECK(12 MAX ITEMS)\n";
	list2.PutItem(item1);
	list2.PutItem(item3);
	list2.PutItem(item2);
	list2.PutItem(item4);
	list2.PutItem(item5);
	list2.PutItem(item6);
	list2.PutItem(item7);
	list2.PutItem(item8);
	list2.PutItem(item9);
	list2.PutItem(item10);
	list2.PutItem(item11);
	list2.PutItem(item12);
	list2.PutItem(item13);

	list2.PrintList();



	//cout << "\nRESET LIST CHECKS\n" << list2.ResetList().GetData();

	list1.MakeEmpty();
	list1.PutItem(item1);
	list1.PutItem(item3);
	list1.PutItem(item2);
	list1.PrintList();
	cout << "\n";
	list1.DeleteItem(item1);
	list1.DeleteItem(item1);
	list1.PrintList();
	//list2.PrintList();

}
