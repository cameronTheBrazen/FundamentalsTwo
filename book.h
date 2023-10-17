//Header guard. It keeps bad things from happening
#ifndef _BOOK_VECTOR_H_ //if not defined
#define _BOOK_VECTOR_H_

#include <string>
#include <iostream>
//Don't include using namespace with programming .h files


class Book {
private:
	// member variables (instance variables)
	std::string bookTitle{};
	double price{};
	int quantity{};
	std::string description{};

public:
	//See contructor notes from BookStore_Inline
	Book();
	Book(std::string bookTitle, std::string description,
		 double price, int quantity);

	void setTitle(std::string bookTitle);	//remove this line to set booktitle as immutible (not expected to be changed)
	std::string getTitle() const;
	void setPrice(double price);
	double getPrice() const;
	void setQuantity(int quantity);
	int getQuantity() const;
	void setDescription(std::string description);
	std::string getDescription() const;

	void printBookTitleAndConst() const;
	void printBookDescription() const;

	//Overloads << and >> for cout and cin
	friend std::ostream& operator<< (std::ostream& out, const Book& book);
	friend std::istream& operator>> (std::istream& in, Book& book);

	// Overload some relational operators
	friend bool operator== (const Book& lhs, const Book& rhs); //left hand side, right hand side
	friend bool operator!= (const Book& lhs, const Book& rhs);
	friend bool operator< (const Book& lhs, const Book& rhs);
	friend bool operator> (const Book& lhs, const Book& rhs);
};


#endif //!_BOOK_VECTOR_H_ //Basically like an if statement