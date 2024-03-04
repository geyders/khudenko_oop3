//
// Created by user on 03.03.2024.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Конструктор за замовчуванням
    Person() : Person("Unknown", 0) {}

    // Основний конструктор
    Person(string basicString, int i) : name(basicString), age(i) {}

    // Перевантаження унарного оператора +
    Person operator+() {
        // Змінюємо дані об'єкта, наприклад, збільшуємо вік на 1
        ++age;
        return *this; // Повертаємо змінений об'єкт
    }

    // Перевантаження бінарного оператора +
    Person operator+(const Person& other) const {
        // Повертаємо новий об'єкт, що містить комбінацію даних обох об'єктів
        return Person(name + " & " + other.name, age + other.age);
    }

    // Перевантаження оператора << для виводу інформації про особу
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << endl;
        os << "Age: " << person.age << " years old" << endl;
        return os;
    }

    // Перевантаження оператора >> для введення інформації про особу
    friend istream& operator>>(istream& is, Person& person) {
        cout << "Enter name: ";
        is >> person.name;
        cout << "Enter age: ";
        is >> person.age;
        return is;
    }
};



#endif //UNTITLED_PERSON_H
