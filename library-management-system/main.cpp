
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class LibraryItem {
protected:
    std::string title;
    std::string author;
    bool checkedOut;

public:
    LibraryItem(std::string title, std::string author)
        : title(std::move(title)), author(std::move(author)), checkedOut(false) {}

    virtual ~LibraryItem() = default;

    void checkOut() { checkedOut = true; }
    void returnItem() { checkedOut = false; }
    bool isCheckedOut() const { return checkedOut; }
    const std::string& getTitle() const { return title; }

    // Polymorphic display, overridden by derived classes
    virtual void display() const {
        std::cout << "\"" << title << "\" by " << author
                   << (checkedOut ? " [checked out]" : " [available]");
    }
};

class PrintedBook : public LibraryItem {
    int pageCount;

public:
    PrintedBook(std::string title, std::string author, int pageCount)
        : LibraryItem(std::move(title), std::move(author)), pageCount(pageCount) {}

    void display() const override {
        LibraryItem::display();
        std::cout << " - Printed, " << pageCount << " pages\n";
    }
};

class EBook : public LibraryItem {
    double fileSizeMB;

public:
    EBook(std::string title, std::string author, double fileSizeMB)
        : LibraryItem(std::move(title), std::move(author)), fileSizeMB(fileSizeMB) {}

    void display() const override {
        LibraryItem::display();
        std::cout << " - EBook, " << fileSizeMB << " MB\n";
    }
};

class Library {
    std::vector<std::unique_ptr<LibraryItem>> items;

public:
    void addItem(std::unique_ptr<LibraryItem> item) {
        items.push_back(std::move(item));
    }

    void listAll() const {
        std::cout << "\n--- Library Catalog (" << items.size() << " items) ---\n";
        for (const auto& item : items) {
            item->display();  // polymorphic call
        }
    }

    bool checkOutByTitle(const std::string& title) {
        for (auto& item : items) {
            if (item->getTitle() == title && !item->isCheckedOut()) {
                item->checkOut();
                return true;
            }
        }
        return false;
    }
};

int main() {
    Library library;

    library.addItem(std::make_unique<PrintedBook>("The Hobbit", "J.R.R. Tolkien", 310));
    library.addItem(std::make_unique<PrintedBook>("Clean Code", "Robert C. Martin", 464));
    library.addItem(std::make_unique<EBook>("Effective C++", "Scott Meyers", 4.2));

    library.listAll();

    std::cout << "\nChecking out \"The Hobbit\"...\n";
    library.checkOutByTitle("The Hobbit");

    library.listAll();

    return 0;
}
