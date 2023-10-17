#include "bookbag.h"
#include <stdexcept>
BookBag::BookBag(std::string customerName, std::string currentDate)
    : customerName(customerName), currentDate(currentDate){}

std::string BookBag::getCustomerName() const{
    return customerName;
}

std::string BookBag::getDate() const{
    return currentDate;
}

void BookBag::addBook(Book book){
    for (Book& aBook : books) {
        if (aBook == book) {
            aBook.setQuantity(aBook.getQuantity() + book.getQuantity());
            return;
        }
    }
    books.push_back(book);
}

void BookBag::removeBook(std::string title, std::string description){
    //If we had used book instead of title we could have possibly done the above in reverse?
    for (int i = 0; i < books.size(); ++i) {
        if (
            books.at(i).getTitle() == title &&
            books.at(i).getDescription() == description) {
           
            books.erase(books.begin() + i);

            break;
            
        }
    }
}

void BookBag::removeBook(Book book) {
    removeBook(book.getTitle(), book.getDescription());

}

void BookBag::modifyBook(const Book& book)
{
    Book defaultBook;
    for (Book& aBook : books) {
        if (aBook == book) {
            if (book.getQuantity() != defaultBook.getQuantity()) {
                if (book.getQuantity() == 0){
                    removeBook(aBook);
                }
                
            }
            else {
                aBook.setQuantity(book.getQuantity());
            }

            if (book.getPrice() != defaultBook.getPrice()) {
                aBook.setPrice(book.getPrice());
            }
            break;
        }
    }


}

int BookBag::getNumBooksInBag() const
{
    int total = 0;
    for (const Book& book : books) {
        total += book.getQuantity();
        }
    return total;
}

double BookBag::getCostOfBag() const
{
    double totalCost = 0.0;
    for (const Book& book : books) {
        totalCost += book.getQuantity() * book.getPrice();
    }
    return totalCost;
}

int BookBag::getUniqueBookCount() const
{
    return books.size();
}

void BookBag::printTotal() const
{
    throw std::runtime_error("printTotal not implemented");
}

void BookBag::printDescriptions() const
{
    throw std::runtime_error("printDescriptions not implemented");
}

BookBag BookBag::operator+(BookBag rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books=this->books;
    for (const Book& book : rhs.books) {
        tempBag.addBook(book);

    }
    return tempBag;
}

BookBag BookBag::operator+(Book rhs)
{
    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.addBook(rhs);

    return tempBag;
}

BookBag BookBag::operator-(Book rhs)
{

    BookBag tempBag(this->customerName, this->currentDate);
    tempBag.books = this->books;
    tempBag.removeBook(rhs);

    return tempBag;
}

Book BookBag::operator[](int index)
{
    if (index < 0 || index >= books.size()) {
        throw std::runtime_error("index out of range");

    }

    return books[index];
}

std::ostream& operator<<(std::ostream& out, const BookBag& bag)
{

    if (bag.books.empty()) {
        out << " book bag is empty";
        return out;
    
    }
    out << bag.customerName << "'s Book Bag - " <<
        bag.currentDate << std::endl;
    out << "Number of books: " << bag.getNumBooksInBag() << "\n\n" << std::endl;
    for (const Book& book : bag.books) {
    
        out << book << std::endl;
    }
    out << "\n Total: $" << bag.getCostOfBag();

    return out;
}
