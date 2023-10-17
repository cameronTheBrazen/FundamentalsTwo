#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

#include "book.h"
#include "bookbag.h"

void  printBookBag( BookBag& bag) {
	for (int i = 0; i < bag.getUniqueBookCount(); i++) {
		cout << bag[i];
	}
	
}

int main() {
	const string fileName = "book_list.txt";
	BookBag myBag("John Doe", "10/16/2023");
	
	//Open file
	ifstream file(fileName);
	if (!file) {
		cout << "No file you dummy!" << endl;
		exit(EXIT_FAILURE);
	}

	/*string title, desc;
	int quantity;
	double price;*/

	Book book;
	while (file >> book) {
		/*getline(file, desc);
		file >> price;
		file >> quantity;	//leaves new line in the stream */

		file.ignore(); //burn the witch... I mean the next character (whitespace in this case)
		//Create a book object to pass to push_back
		myBag.addBook(book);
	}

	
	// Output each book
	printBookBag(myBag);
	cout << "------------------------------------------------------" << endl;
	cout << myBag << endl;
	// Sort the books in alphabetical order
	// But I can't  - "sort" depends on less than operator
	
	printBookBag(myBag);

	return 0;
}