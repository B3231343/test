#include "Vehicle.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Vehicle> vehicles;

    cout << "請手動新增一筆資料：" << endl;
    vehicles.push_back(Vehicle::inputFromUser());

    cout << "\n=== 所有交通工具資訊 ===" << endl;
    for (const auto& v : vehicles)
    {
        v.displayInfo();
    }

    string keyword;
    cout << "\n請輸入品牌進行搜尋：";
    cin >> keyword;
    for (const auto& v : vehicles)
    {
        if (v.getBrand() == keyword)
        {
            v.displayInfo();
        }
    }

    cout << "\n請輸入型號進行搜尋：";
    cin >> keyword;
    for (const auto& v : vehicles)
    {
        if (v.getModel() == keyword)
        {
            v.displayInfo();
        }
    }

    int year;
    cout << "\n請輸入年份進行搜尋：";
    cin >> year;
    for (const auto& v : vehicles)
    {
        if (v.getYear() == year)
        {
            v.displayInfo();
        }
    }

    cout << "\n請輸入類型進行搜尋：";
    cin >> keyword;
    for (const auto& v : vehicles)
    {
        if (v.getType() == keyword)
        {
            v.displayInfo();
        }
    }

    string brand, model, type;
    cout << "\n請輸入要刪除資料的品牌：";
    cin >> brand;
    cout << "請輸入型號：";
    cin >> model;
    cout << "請輸入年份：";
    cin >> year;
    cout << "請輸入類型：";
    cin >> type;
    Vehicle::deleteSingleMatch(vehicles, brand, model, year, type);

    cout << "\n=== 剩餘資料 ===" << endl;
    for (const auto& v : vehicles)
    {
        v.displayInfo();
    }

    return 0;
}
