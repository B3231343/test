#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>
using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    int year;
    string type;

public:
    Vehicle();
    Vehicle(string b, string m, int y, string t);

    string getBrand() const;
    string getModel() const;
    int getYear() const;
    string getType() const;

    void setBrand(const string& b);
    void setModel(const string& m);
    void setYear(int y);
    void setType(const string& t);

    void displayInfo() const;

    static Vehicle inputFromUser();

    static void deleteSingleMatch(vector<Vehicle>& vehicles,const string& brand,const string& model,int year,
    const string& type);
};

#endif
