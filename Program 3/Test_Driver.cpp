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
	ItemType item1(1, "1st");
	bool truth;
	//SortedList tests
	SortedList list1;
	SortedList list2(12);

	//empty lists tests
	cout << "\nEMPTY LISTS CHECKS: \n";

	cout << "PrintList: \n";
	list1.PrintList();

	cout << "resetList: " << list1.ResetList().GetData() << "\n";

	cout << "MakeEmpty: \n"; 
	list1.MakeEmpty();

	cout << "next: " << list1.GetNext().GetData() << "\n";

	cout << "Length: " << list1.GetLength() << "\n";

	cout << "GetItem: " << list1.GetItem(item1, truth).GetData();

	cout << "DeleteItem: " << list1.DeleteItem(item1);







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
	cout << "\nORDER CHECK:\n";
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
	list2.PutItem(item8);
	list2.PutItem(item7);
	list2.PutItem(item6);
	list2.PutItem(item9);
	list2.PutItem(item10);
	list2.PutItem(item11);
	list2.PutItem(item12);
	list2.PutItem(item13);

	list2.PrintList();

	//length checks
	cout << "\nLENGTH CHECKS\n";
	cout << "list1: " << list1.GetLength() << "\n";
	cout << "list2: " << list2.GetLength() << "\n";


	//next and resetlist
	cout << "\nNEXT ITEM AND RESET LIST CHECKS\n" << list1.ResetList().GetData() << "\t";
	cout << list1.GetNext().GetData() << "\t";
	cout << list1.GetNext().GetData() << "\t";
	cout << list1.GetNext().GetData() << "\t";
	cout << list1.GetNext().GetData() << "\t";
	cout << list1.ResetList().GetData() << "\t";

	cout << list1.DeleteItem(item1);
	cout << list1.DeleteItem(item5);
	cout << list1.DeleteItem(item10);

	list1.PrintList();
	list1.MakeEmpty();
	list1.PrintList();

	cout << list1.GetLength();
	



}
