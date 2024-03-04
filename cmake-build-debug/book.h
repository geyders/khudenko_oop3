//
// Created by user on 03.03.2024.
//

#ifndef UNTITLED_BOOK_H
#define UNTITLED_BOOK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    // Конструктор за замовчуванням
    Book() : Book("Unknown", "Unknown author", 0) {}

    // Основний конструктор
    Book(string t, string a, int y) : title{ t }, author{ a }, year{ y } {
        cout << "Created book '" << title << "' by " << author << endl;
    }

    // Конструктор копіювання
    Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
        cout << "Copied book '" << title << "' by " << author << endl;
    }

    // Конструктор переміщення
    Book(Book&& other) noexcept : title(move(other.title)), author(move(other.author)), year(other.year) {
        cout << "Moved book '" << title << "' by " << author << endl;
    }

    // Деструктор
    ~Book() {
        cout << "Destroyed book '" << title << "' by " << author << endl;
    }

    // Функція для виведення інформації про книгу
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year of publication: " << year << endl;
    }
};


#endif //UNTITLED_BOOK_H
