// CS 112 A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
struct Book {                                                                          //structure of book
	int ID = 0, price = 0, pages = 0, issuedby = 0;
	string bookname = "-", author = "-", ISBN = "-", issuedon = "-", returndate = "-";

	void printall()                                                                   //print a book
	{
		cout << "Book ID :- " << ID << endl;
		cout << "Book Name :- " << bookname << endl;
		cout << "Author :- " << author << endl;
		cout << "ISBN :- " << ISBN << endl;
		cout << "Price :- " << price << endl;
		cout << "No. of pages :- " << pages << endl;
		cout << "Issued By :- " << issuedby << endl;
		cout << "Issued on :- " << issuedon << endl;
		cout << "Return Date :- " << returndate << endl;
	}
	void addbook(int IDtobeadded)                                                     // adds new book
	{

		ID = IDtobeadded;
		cout << "Enter Book Name :- ";
		cin.ignore();
		getline(cin, bookname);
		cout << "Enter Author :- ";
		getline(cin, author);
		cout << "Enter ISBN :- ";
		getline(cin, ISBN);
		cout << "Enter Price :- ";
		cin >> price;
		cout << "Enter No. of pages :- ";
		cin >> pages;
		cout << "Enter ID of student Issued By :- ";
		cin.ignore();
		cin >> issuedby;
		cout << "Enter Issued on :- ";
		cin.ignore();
		getline(cin, issuedon);
		cout << "Enter Return Date :- ";
		getline(cin, returndate);
	}
	void deleteparticularbook()                                                        // deletes a particular book by setting all the variables either to blank or 0
	{
		ID = 0;
		bookname = "-";
		author = "-";
		ISBN = "-";
		price = 0;
		pages = 0;
		issuedby = 0;
		issuedon = "-";
		returndate = "-";
		cout << "Congratulations book deletion successful" << endl;
	}

};
struct Booklist {                            // booklist i.e. an array of books is created
	Book book[10];

	void printallbooklist()                  // prints the entire booklist
	{
		for (int count = 0;count < 10;count++)
		{
			book[count].printall();
		}
	}
	void addbook()                             //adds book to the book list
	{
		bool flag = false;
		int  index, IDtobeadded;
		for (int count = 0;count < 10;count++)     // finds the index on the array to which the new book will be placed. 
		{
			if (book[count].ID == 0)
			{
				index = count;
				break;
			}
		}
		cout << "Enter book ID :- ";
		cin >> IDtobeadded;
		for (int count = 0;count < 10; count++)             // checks if the book ID entered is not already in use
		{
			if (book[count].ID == IDtobeadded)
			{
				cout << "Sorry book ID already exists. Please change book ID." << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			book[index].addbook(IDtobeadded);
			cout << "Congratulations ! New book added" << endl;
		}

	}
	void sortbookdescending()                        //sorts book in descending order 
	{
		bool flag;
		Book tempbook;
		do
		{
			flag = false;
			for (int count = 0;count < 9;count++)
			{
				if (book[count].ID < book[count + 1].ID)
				{
					tempbook = book[count];
					book[count] = book[count + 1];
					book[count + 1] = tempbook;
					flag = true;
				}
			}
		} while (flag);
	}
	void sortbookascending()                                   // sorts books in the array in ascending order
	{
		bool flag;
		Book tempbook;
		do
		{
			flag = false;
			for (int count = 0;count < 9;count++)
			{
				if (book[count].ID > book[count + 1].ID)
				{
					tempbook = book[count];
					book[count] = book[count + 1];
					book[count + 1] = tempbook;
					flag = true;
				}
			}
		} while (flag);
	}
	void deleteselectedbook(int todeleteID) {                          //delete the passed ID from the array
		bool flag = true;                                              //if flag doesnot change in the loop it means that the id does not exist
		for (int count = 0;count < 10;count++)
		{
			if (book[count].ID == todeleteID)
			{
				book[count].deleteparticularbook();
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			cout << "Sorry but the desired book was not found. Please try again with the correct book ID." << endl;
		}
	}
	void deleteallbook()                   //deletes the entire array by setting it to either 0 or -
	{
		for (int count = 0;count < 10;count++)
		{
			book[count].deleteparticularbook();
		}
	}
	void printsomebook()                 //inputs an ID and prints it.
	{
		bool flag = true;                //if flag doesnot change in loop it means id does not exist in records
		int IDtobedisplayed;
		cout << "Enter ID of book to be displayed";
		cin >> IDtobedisplayed;
		for (int count = 0;count < 10;count++)
		{
			if (book[count].ID == IDtobedisplayed)
			{
				book[count].printall();
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			cout << "Sorry Desired Book not found. Please confirm the ID and try again." << endl;
		}
	}

	int swapbooklist()                         // this function outputs the index no. of the book where it is placed in array if it doesnot exist it ouputs 20.
	{

		int booktobeswapped;
		bool flag = true;
		cout << "Enter ID of book you wish to be swapped from its list. ";
		cin >> booktobeswapped;
		for (int count = 0;count < 10;count++)
		{
			if (book[count].ID == booktobeswapped)
			{
				flag = false;
				return count;

			}
		}
		if (flag == true)
		{
			return 20;

		}
	}
	bool checkbook(int a)                                  //function return type  in bool checking whether the input book exists or not. 
	{
		for (int count = 0;count < 10;count++)
		{
			if (book[count].ID == a)
			{
				return true;

			}

		}return false;
	}

};
struct Student {                                               //structure student with its variable
	int ID = 0, RollNo = 0, Booksissued = 0;
	string StdName = "-";
	void printstudent()                                   //prints an instance of student
	{
		cout << "Student ID :- " << ID << endl;
		cout << "Student Name :- " << StdName << endl;
		cout << "Student Roll No. :- " << RollNo << endl;
		cout << "Books Issued by the Student " << Booksissued << endl;
	}

};
struct studentlist {                           //structure student list which is an array of student
	Student studentlist[10];
	void printallstudentlist()                 //prints all students in an instance of studentlist
	{
		for (int count = 0; count < 10;count++)
		{
			studentlist[count].printstudent();
		}
	}
	void printsomestudent()                   //prints a specific student of an instance of student list
	{
		int IDtobedisplayed;
		cout << "Enter Id of student you want to print";
		cin >> IDtobedisplayed;
		for (int count = 0;count < 10;count++)
		{
			if (studentlist[count].ID == IDtobedisplayed)
			{
				studentlist[count].printstudent();
			}
		}
	}
	void deletestudent(int todeleteID)                         //deletes a specific student of a instance of student list 
	{
		bool flag = true;                                     //if flag doesnot change it means that the student to be deleted doesnot exist
		for (int count = 0;count < 10;count++)
		{
			if (studentlist[count].ID == todeleteID)
			{
				studentlist[count].RollNo = 0;
				studentlist[count].Booksissued = 0;
				studentlist[count].ID = 0;
				studentlist[count].StdName = "-";
				cout << "Congratulations student deletion successful" << endl;
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			cout << "Sorry student ID not found. Please try again with correct student ID" << endl;
		}

	}
	void addstudent()                        //adds student to the studentlist
	{
		int index, Idtobeadded;
		bool flag = false;
		for (int count = 0;count < 10;count++)         //works out the index free on which the student going to be input will be saved
		{
			if (studentlist[count].ID == 0)
			{
				index = count;
				break;
			}
		}		cout << "Enter Student ID" << endl;
		cin >> Idtobeadded;
		for (int count = 0;count < 10;count++)            //checks if the input id already exists
		{
			if (studentlist[count].ID == Idtobeadded)
			{
				cout << "Sorry Student ID already exists. Please change the student ID" << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)                              //if it does not exist then add further details
		{
			studentlist[index].ID = Idtobeadded;
			cout << "Enter Student Roll No." << endl;
			cin >> studentlist[index].RollNo;
			cout << "Enter Books issued on student" << endl;
			cin >> studentlist[index].Booksissued;
			cout << "Enter Student name " << endl;
			cin.ignore();
			getline(cin, studentlist[index].StdName);
			cout << "Student successfully added to record" << endl;
		}
	}


};
struct Library {                                         //structure library which contains variable booklib and stdlib in one instances 
	Booklist booklib;
	studentlist stdlib;
	void issuebook(int a, int b) {                   //saves the two parameters passed in appropriate variables 	
		for (int count = 0;count < 10;count++)
		{
			if (booklib.book[count].ID == 0)
			{
				booklib.book[count].ID = a;
				stdlib.studentlist[count].ID = b;
				return;
			}
		}
	}
	void returnbook() {                             //returns book by setting its issue records to 0
		int bookID;
		bool flag = true;
		cout << "Enter the book ID to be returned. ";
		cin >> bookID;
		for (int count = 0;count < 10;count++)
		{
			if (booklib.book[count].ID == bookID)
			{
				booklib.book[count].ID = 0;
				stdlib.studentlist[count].ID = 0;
				cout << "Book Return successful. " << endl;
				flag = false;
			};
		}
		if (flag == true) {
			cout << "The book was never issued. Please check records." << endl;
		}
	}

};

int main()
{
	bool flag = false, flag2 = false;
	int bookID, studentID;
	int choice;
	studentlist s1;
	Booklist b1, b2;
	Library Lib1;
	int input;
	do
	{
		cout << "MAIN MENU" << endl;
		cout << "\t 1. Student" << endl;
		cout << "\t 2. Book " << endl;
		cout << "\t 3. List " << endl;
		cout << "\t 4. Library " << endl;
		cout << "\t 5. Exit " << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "Student Sub-Menu";
			cout << "\t 1. Add new Student";
			cout << "\t 2. Delete existing Student";
			cout << "\t 3. Show all Students \t";
			cin >> choice;
			switch (choice)
			{
			case 1:
				s1.addstudent();
				break;
			case 2:
				int todeleteID;
				flag = false;
				cout << "Enter the Student ID of the student you want to delete" << endl;
				cin >> todeleteID;
				for (int count = 0; count < 10;count++)
				{
					if (Lib1.stdlib.studentlist[count].ID == todeleteID)             //cross checks if there are any books issued on the student
					{
						cout << "Can not delete student as book is issued on his ID" << endl;
						flag = true;
						break;
					}
				}
				if (flag == false)
				{
					s1.deletestudent(todeleteID);
				}
				break;
			case 3:
				s1.printallstudentlist();
				break;
			}
			break;
		case 2:

			cout << "Book Sub-Menu ";
			cout << "\t 1. Add New Book";
			cout << "\t 2. Delete Existing Book";
			cout << "\t 3. Show Particular Book" << endl;
			cout << "\t 4. Show All Books";
			cout << "\t 5. Sort Books in Ascending Order";
			cout << "\t 6. Sort Books in Descending Order" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				b1.addbook();

				break;
			case 2:
				int todeleteID;
				flag = false;
				cout << "Enter the Book ID of the Book you want to delete" << endl;
				cin >> todeleteID;
				for (int count = 0; count < 10;count++)
				{
					if (Lib1.booklib.book[count].ID == todeleteID)
					{
						cout << "Can not delete Book as book is issued." << endl;
						flag = true;
						break;
					}
				}
				if (flag == false)
				{
					b1.deleteselectedbook(todeleteID);
				}
				break;

				break;
			case 3:
				b1.printsomebook();
				break;
			case 4:
				b1.printallbooklist();
				break;
			case 5:
				b1.sortbookascending();
				cout << "Book Sorting successful" << endl;
				break;
			case 6:
				b1.sortbookdescending();
				cout << "Book Sorting Successful" << endl;
				break;
			}
			break;
		case 3:
			cout << "List Sub Menu ";
			cout << "\t 1. Add New List";
			cout << "\t 2. Delete Existing List";
			cout << "\t 3. Show Particular List";
			cout << "\t 4. Show All Books";
			cout << "\t 5. Delete book from list and assign book to another list " << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				cout << "New Booklist created" << endl;
				b2.addbook();
				break;
			case 2:
				cout << "Deleting Current Booklist" << endl;
				b1.deleteallbook();
				break;
			case 3:
				int pchoice;
				cout << "Record only has two lists. Press 1 to print the first list. Press 2 to print second list. ";
				cin >> pchoice;
				if (pchoice == 1)
				{
					b1.printallbooklist();
				}
				else if (pchoice == 2) {
					b2.printallbooklist();
				}
				else cout << "Invalid input. Please try again." << endl;
				break;
			case 4:
				b1.printallbooklist();
				b2.printallbooklist();
				break;
			case 5:
				int warning;
				cout << "WARNING : Books after being moved to the new list will not be able to get issued or deleted." << endl << "Press 0 if you wish to return to MAIN MENU. Press any number to proceed to the swap. ";
				cin >> warning;
				if (warning)
				{
					int freshlocation;

					for (int count = 0;count < 10;count++)            //finds the new index in the second list to which the book will be moved 
					{
						if (b2.book[count].ID == 0)
						{
							freshlocation = count;
							break;
						}
					}
					choice = b1.swapbooklist();
					if (choice != 20) {
						b2.book[freshlocation] = b1.book[choice];        //swap the book
						b1.book[choice].ID = 0;
						cout << "Book successfully swapped" << endl;
						break;
					}
					else {
						cout << "Sorry your desired book was not found in the current list" << endl;
						break;
					}
				}
			}
			break;
		case 4:
			cout << "Library Sub-Menu ";
			cout << "\t 1. Issue a book ";
			cout << "\t 2. Return a book ";
			cout << "\t 3. Print which books have been issued ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Please enter the Book ID you wish to be issued. " << endl;
				cin >> bookID;
				for (int count = 0;count < 10;count++)                  // cross checks if the book ID exists
				{
					if (b1.book[count].ID == bookID)
					{
						flag = true;
						cout << "Please enter the student ID you wish to issue the book to. " << endl;
						cin >> studentID;
						for (int count2 = 0;count < 10;count++)               //cross checks if the student ID exists
						{
							if (s1.studentlist[count].ID == studentID)
							{
								flag2 = true;
								Lib1.issuebook(bookID, studentID);
								cout << "The book has been issued successfully" << endl;
								break;
							}
						}
						if (flag2 == false)
						{
							cout << "Sorry the Student ID was not found in records. The book can not be issued " << endl;
						}
						break;

					}
				}
				if (flag == false)
				{
					cout << "Sorry the book you wished to issue was not found in the record" << endl;
					break;
				}
				break;
			case 2:
				Lib1.returnbook();
				break;
			case 3:
				for (int count = 0;count < 10;count++)
				{
					cout << "Book ID of issued book is :- " << Lib1.booklib.book[count].ID << endl;
				}
				break;

			}


		}

	} while (input != 5);
	cout << "Thank You for Using. Have a nice day....";
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
