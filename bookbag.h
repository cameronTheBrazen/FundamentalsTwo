#ifndef _BOOKBAG_H_ //if not defined
#define _BOOKBAG_H_

#include <string>
#include <vector>
#include <iostream>
#include "book.h"

class BookBag {
private:
	std::string customerName;
	std::string currentDate;
	std::vector<Book> books;

public:
	BookBag(std::string customerName, std::string currentDate);

	// getters
	std::string getCustomerName() const;
	std::string getDate() const;

	// Bookbag actions
	void addBook(Book book);
	void removeBook(std::string title, std::string description);
	void removeBook(Book book);
	void modifyBook(const Book& book);

	// Information about the bag itself
	int getNumBooksInBag() const;
	double getCostOfBag() const;
	int getUniqueBookCount()const;

	void printTotal() const;
	void printDescriptions() const;

	friend std::ostream& operator<<(std::ostream& out, const BookBag& bag);

	BookBag operator+(BookBag rhs);
	BookBag operator+(Book rhs);	//different parameters keeps this from being a problem (the op. on right is the param.)

	BookBag operator-(Book rhs);


	Book operator[](int index);
};





#endif // !_BOOKBAG_H_
