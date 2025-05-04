#include "Vehicle.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Vehicle::Vehicle() {
    brand = "Unknown";
    model = "Unknown";
    year = 0;
    type = "Unknown";
}

Vehicle::Vehicle(string b, string m, int y, string t) {
    brand = b;
    model = m;
    year = y;
    type = t;
}

string Vehicle::getBrand() const {
    return brand;
}

string Vehicle::getModel() const {
    return model;
}

int Vehicle::getYear() const {
    return year;
}

string Vehicle::getType() const {
    return type;
}

void Vehicle::setBrand(const string& b) {
    brand = b;
}

void Vehicle::setModel(const string& m) {
    model = m;
}

void Vehicle::setYear(int y) {
    year = y;
}

void Vehicle::setType(const string& t) {
    type = t;
}

void Vehicle::displayInfo() const {
    cout << "品牌: " << brand << ", 型號: " << model << ", 年份: " << year << ", 類型: " << type << endl;
}

Vehicle Vehicle::inputFromUser() {
    string b, m, t;
    int y;
    cout << "請輸入品牌：";
    cin >> b;
    cout << "請輸入型號：";
    cin >> m;
    cout << "請輸入年份：";
    cin >> y;
    cout << "請輸入類型：";
    cin >> t;
    return Vehicle(b, m, y, t);
}

void Vehicle::deleteSingleMatch(vector<Vehicle>& vehicles, const string& brand, const string& model, int year, const string& type) {
    auto new_end = remove_if(vehicles.begin(), vehicles.end(), [=](const Vehicle& v) {
        return v.getBrand() == brand &&
               v.getModel() == model &&
               v.getYear() == year &&
               v.getType() == type;
    });
    vehicles.erase(new_end, vehicles.end());
}
