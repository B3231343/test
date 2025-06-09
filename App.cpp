#include "Vehicle.h"
#include <iostream>
#include <vector>
using namespace std;

void runVehicleApp() {
    vector<Vehicle> vehicles;

    while (true) {
        cout << "\n=== 交通工具管理系統 ===" << endl;
        cout << "1. 新增車輛" << endl;
        cout << "2. 搜尋車輛" << endl;
        cout << "3. 刪除車輛" << endl;
        cout << "4. 顯示所有車輛" << endl;
        cout << "5. 離開" << endl;
        cout << "請輸入選項：";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Vehicle v = Vehicle::inputFromUser();
            vehicles.push_back(v);
        }
        else if (choice == 2) {
            string brand, model, type;
            int year = 0;
            cout << "請輸入欲搜尋的品牌 (無輸入直接按Enter跳過)：";
            getline(cin, brand);
            cout << "請輸入欲搜尋的型號 (無輸入直接按Enter跳過)：";
            getline(cin, model);
            cout << "請輸入欲搜尋的年份 (無輸入直接按Enter跳過，或輸入0代表忽略年份)：";
            cin >> year;
            cin.ignore();
            cout << "請輸入欲搜尋的類型 (無輸入直接按Enter跳過)：";
            getline(cin, type);

            cout << "\n=== 搜尋結果 ===" << endl;
            bool found = false;
            for (const auto& v : vehicles) {
                bool match = true;
                if (!brand.empty() && v.getBrand() != brand)
                    match = false;
                if (!model.empty() && v.getModel() != model)
                    match = false;
                if (year != 0 && v.getYear() != year)
                    match = false;
                if (!type.empty() && v.getType() != type)
                    match = false;

                if (match) {
                    v.displayInfo();
                    found = true;
                }
            }
            if (!found) {
                cout << "找不到符合條件的車輛。" << endl;
            }
        }
        else if (choice == 3) {
            string brand, model, type;
            int year;
            cout << "請輸入品牌：";
            getline(cin, brand);
            cout << "請輸入型號：";
            getline(cin, model);
            cout << "請輸入年份：";
            cin >> year;
            cin.ignore();
            cout << "請輸入類型：";
            getline(cin, type);

            Vehicle::deleteSingleMatch(vehicles, brand, model, year, type);
        }
        else if (choice == 4) {
            cout << "\n=== 所有車輛 ===" << endl;
            for (const auto& v : vehicles) {
                v.displayInfo();
            }
        }
        else if (choice == 5) {
            cout << "程式結束！" << endl;
            break;
        }
        else {
            cout << "選項無效，請重新輸入！" << endl;
        }
    }
}
