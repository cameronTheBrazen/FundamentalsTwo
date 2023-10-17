#include <stdexcept>
#include <iostream>
#include <string>
#include "book.h"

Book::Book() : Book("none", "none", -1.0, -1) {}  //see below to check what each corrolates to (DRY)

Book::Book(std::string bookTitle, std::string description, 
           double price, int quantity)
    : bookTitle(bookTitle), description(description),
      price(price), quantity(quantity) {}


void Book::setTitle(std::string bookTitle){
    if (bookTitle.empty()) {
        throw std::runtime_error("No empty book titles");
    }
    this->bookTitle = bookTitle;
}

std::string Book::getTitle() const{
    return bookTitle; //return std::string() is the same as return ""
}

void Book::setPrice(double price){
    if (price < 0) {
        throw std::runtime_error("No negative prices");
    }

    this->price = price;
}

double Book::getPrice() const{
    return price;
}

void Book::setQuantity(int quantity){
    if (quantity < 0) {
        throw std::runtime_error("No negative quantities");
    }

    this->quantity = quantity;
}

int Book::getQuantity() const{
    return quantity;
}

void Book::setDescription(std::string description){
    if (description.length() == 0) {
        throw std::runtime_error("No empty description");
    }

    this->description = description;
}

std::string Book::getDescription() const{
    return description;
}

void Book::printBookTitleAndConst() const{
    std::cout << bookTitle << " " << quantity
        << " @ $" << price << " = "
        << (quantity * price);

}

void Book::printBookDescription() const{
    std::cout << bookTitle << ": " << description;
}

std::ostream& operator<<(std::ostream& out, const Book& book){
    /*
    Book book (...);
    cout << book << 42; One on the left goes first.
    */

    out << "Title: " << book.bookTitle << std::endl;
    out << "Price: " << book.price << std::endl;
    out << "Quantity: " << book.quantity << std::endl;
    out << "Description: " << book.description;

    return out;
}

std::istream& operator>>(std::istream& in, Book& book){
    /*
        Book book;
        cin >> book;
    */

    getline(in, book.bookTitle);
    getline(in, book.description);
    in >> book.price;
    in >> book.quantity;

    return in;
}

bool operator==(const Book& lhs, const Book& rhs){
    return (lhs.bookTitle == rhs.bookTitle) &&
        (lhs.description == rhs.description);
}

bool operator!=(const Book& lhs, const Book& rhs){
    return !(lhs == rhs);
}

bool operator<(const Book& lhs, const Book& rhs){
    if (lhs.price < rhs.price) {
        return true;
    }
    else if (lhs.price == rhs.price) {
        if (lhs.bookTitle < rhs.bookTitle) {
            return true;
        }
    }

    return false;
}

bool operator>(const Book& lhs, const Book& rhs){
    if (lhs.price > rhs.price) {
        return true;
    }
    else if (lhs.price == rhs.price) {
        if (lhs.bookTitle > rhs.bookTitle) {
            return true;
        }
    }
    return false;
}
