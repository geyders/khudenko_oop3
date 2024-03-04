#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;

public:
    // Конструктор за замовчуванням
    Car() : Car("Unknown", "Unknown", 0) {}

    // Основний конструктор
    Car(string b, string m, int y) : brand(b), model(std::move(m)), year(y) {
        cout << "Created car " << brand << " " << model << endl;
    }

    // Конструктор копіювання
    Car(const Car& other) : brand(other.brand), model(other.model), year(other.year) {
        cout << "Copied car " << brand << " " << model << endl;
    }

    // Конструктор переміщення
    Car(Car&& other) noexcept : brand(std::move(other.brand)), model(std::move(other.model)), year(other.year) {
        cout << "Moved car " << brand << " " << model << endl;
    }

    // Деструктор
    ~Car() {
        cout << "Destroyed car " << brand << " " << model << endl;
    }

    // Функція для виведення інформації про автомобіль
    void displayInfo() {
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Book {
private:
    string title;
    inline static int number=0;
    string author;
    int year;

public:
    // Конструктор за замовчуванням
    Book() : Book("Unknown", "Unknown author", 0) {number++;}

    // Основний конструктор
    Book(string t, string a, int y) : title{ t }, author{ a }, year{ y } {
        number++;
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
        number--;
        cout << "Destroyed book '" << title << "' by " << author << endl;
    }

    static int getBookCount() {
        return number;
    }

    // Функція для виведення інформації про книгу
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year of publication: " << year << endl;
    }
};


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

int main() {
    Person person1("John", 30);
    Person person2("Alice", 25);

    // Перевантаження унарного оператора +
    cout << "Before unary operator +:" << endl;
    cout << person1;
    +person1; // Викликаємо унарний оператор +
    cout << "After unary operator +:" << endl;
    cout << person1;

    // Перевантаження бінарного оператора +
    cout << "Result of binary operator +:" << endl;
    cout << (person1 + person2);

    // Введення нових даних для об'єкта
    cout << "Enter information for a new person:" << endl;
    Person newPerson;
    cin >> newPerson;
    cout << "New person information:" << endl;
    cout << newPerson << endl--;
    cout << Book::getBookCount();

    return 0;
}



