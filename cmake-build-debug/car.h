//
// Created by user on 03.03.2024.
//

#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

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
    Car(Car&& other) noexcept : brand(move(other.brand)), model(move(other.model)), year(other.year) {
        cout << "Moved car " << brand << " " << model << endl;
    }

    // Деструктор
    ~Car() {
        cout << "Destroyed car " << brand << " " << model << endl;
    }

    // Функція для виведення інформації про автомобіль
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

#endif //UNTITLED_CAR_H
