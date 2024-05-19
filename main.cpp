#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// Класс, отражающий data point в произвольном dataset
class DynamicClass {
    public:
        map<string, double> fields;
        
        void addField(string name, double value) {
            fields[name] = value;
        }

        double getField(string name) {
            return fields.at(name);
        }
};

// Отсеивает целые и дробные числа, затесавшиеся в string (т.к клетка файла .csv - string)
bool isNumber(string str1) {
    bool decimalPointFound = false;
    for (char c : str1) {
        if (!isdigit(c)) {
            if (c == '.' && !decimalPointFound) {
                decimalPointFound = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

// Эвклидово расстояние
double dist(vector<string> field_names1, DynamicClass obj1, DynamicClass obj2) {
    double sum1 = 0.0;
    for (size_t i = 0; i < field_names1.size(); i++) {
        double diff = obj1.getField(field_names1[i]) - obj2.getField(field_names1[i]);
    }
    return sqrt(sum1);
}

int main() {
    vector<DynamicClass> data1; 
    int line_count = 0;
    vector<string> field_names;
    ifstream file("data.csv");
    string line;
    DynamicClass Obj;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        if (line_count == 0) { // этот блок собирает заголовки
            while (getline(ss, cell, ',')) {
                field_names.push_back(cell);
            }
        }
        if (line_count == 1) { // этот блок удаляет из вектора заголовки, относящиеся не к скалярным полям
            int field_count = 0;
            DynamicClass Obj;
            while (getline(ss, cell, ',')) {
                if (!isNumber(cell)) {
                    field_names.erase(field_names.begin() + field_count);
                    field_count--;
                } else {
                    Obj.addField(field_names[field_count], stod(cell));
                }
                field_count++;
            }
            data1.push_back(Obj);
        }
        if (line_count >= 2) { // обычный ввод объектов типа DynamicClass в вектор data1
            int field_count = 0;
            DynamicClass Obj;
            while (getline(ss, cell, ',')) {
                if (isNumber(cell)) {
                    Obj.addField(field_names[field_count], stod(cell));
                } else {
                    field_count--;
                }
                field_count++;
            }
            data1.push_back(Obj);
        }
        line_count++;
    }
    for (DynamicClass object1 : data1) { // дебаг вывод
        for (string field_name : field_names) {
            cout << object1.getField(field_name) << " ";
        }
        cout << '\n';
    }
    return 0;
}