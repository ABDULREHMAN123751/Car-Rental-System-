#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Car {
    string make, model, licensePlate, color;
    int year;
    double rentalPrice;
    bool available;
};

struct Customer {
    string name, contact, licenseNumber;
};

struct Rental {
    string customerName, carLicense;
    int rentalDays;
    double totalCost;
};

vector<Car> cars;
vector<Customer> customers;
vector<Rental> rentals;

void addCar() {
    Car car;
    cout << "Enter Car Make: "; cin >> car.make;
    cout << "Enter Car Model: "; cin >> car.model;
    cout << "Enter License Plate: "; cin >> car.licensePlate;
    cout << "Enter Car Color: "; cin >> car.color;
    cout << "Enter Manufacturing Year: "; cin >> car.year;
    cout << "Enter Rental Price per Day: "; cin >> car.rentalPrice;
    car.available = true;
    cars.push_back(car);
    cout << "Car Added Successfully!\n";
}

void viewCars() {
    for (const auto &car : cars) {
        cout << "Make: " << car.make << ", Model: " << car.model 
             << ", Year: " << car.year << ", License: " << car.licensePlate
             << ", Price per Day: $" << car.rentalPrice 
             << ", Available: " << (car.available ? "Yes" : "No") << "\n";
    }
}

void registerCustomer() {
    Customer cust;
    cout << "Enter Customer Name: "; cin >> cust.name;
    cout << "Enter Contact Number: "; cin >> cust.contact;
    cout << "Enter License Number: "; cin >> cust.licenseNumber;
    customers.push_back(cust);
    cout << "Customer Registered Successfully!\n";
}

void rentCar() {
    string customerName, licensePlate;
    int days;
    cout << "Enter Customer Name: "; cin >> customerName;
    cout << "Enter Car License Plate: "; cin >> licensePlate;
    cout << "Enter Rental Duration (Days): "; cin >> days;
    
    for (auto &car : cars) {
        if (car.licensePlate == licensePlate && car.available) {
            car.available = false;
            rentals.push_back({customerName, licensePlate, days, days * car.rentalPrice});
            cout << "Car Rented Successfully! Total Cost: $" << (days * car.rentalPrice) << "\n";
            return;
        }
    }
    cout << "Car Not Available!\n";
}

void returnCar() {
    string licensePlate;
    cout << "Enter Car License Plate to Return: "; cin >> licensePlate;
    
    for (auto it = rentals.begin(); it != rentals.end(); ++it) {
        if (it->carLicense == licensePlate) {
            for (auto &car : cars) {
                if (car.licensePlate == licensePlate) {
                    car.available = true;
                    break;
                }
            }
            rentals.erase(it);
            cout << "Car Returned Successfully!\n";
            return;
        }
    }
    cout << "Invalid Car License!\n";
}

int main() {
    int choice;
    do {
        cout << "\nCar Rental Management System\n";
        cout << "1. Add Car\n2. View Cars\n3. Register Customer\n4. Rent Car\n5. Return Car\n6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCar(); break;
            case 2: viewCars(); break;
            case 3: registerCustomer(); break;
            case 4: rentCar(); break;
            case 5: returnCar(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 6);
    
    return 0;
}