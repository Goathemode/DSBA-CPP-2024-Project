#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <random>
#include <limits>


using namespace std;

// Класс, отражающий data point в произвольном dataset
class DynamicClass {
    public:
        map<string, double> fields;

        void addField(string name, double value) {
            fields[name] = value;
        }

        double getField(string name) {
            if (fields.find(name) != fields.end()) {
                return fields.at(name);
            } else {
                return 0.0;
            }
        }
};


// Отсеивает целые и дробные числа, затесавшиеся в string (т.к клетка файла .csv - string)
bool isNumber(string str1) {
    bool decimalPointFound = false;
    bool negativeSignFound = false;
    int charCount = 0;
    for (char c : str1) {
        if (!isdigit(c)) {
            if (c == '.' && !decimalPointFound) {
                decimalPointFound = true;
            } else if (c == '-' && !negativeSignFound && charCount == 0) {
                negativeSignFound = true;
            } else {
                return false;
            }
        }
        charCount++;
    }
    return true;
}

// Эвклидово расстояние
double euclideanDistance(vector<string> field_names1, DynamicClass obj1, DynamicClass obj2) {
    double sum1 = 0.0;
    for (size_t i = 0; i < field_names1.size(); i++) {
        double diff = obj1.getField(field_names1[i]) - obj2.getField(field_names1[i]);
        sum1 += diff * diff;
    }
    return sqrt(sum1);
}

vector<DynamicClass> initializeCentroids(vector<DynamicClass>& data2, int k) {
    vector<DynamicClass> centroids;
    vector<DynamicClass> shuffledData = data2;
    random_device rd;
    default_random_engine rng(rd()); // бог знает как это работает
    shuffle(shuffledData.begin(), shuffledData.end(), rng);
    for (int i = 0; i < k; i++) {
        centroids.push_back(shuffledData[i]);
    }
    return centroids;
}

vector<int> assignClusters(vector<string> field_names1, vector<DynamicClass>& data, vector<DynamicClass> centroids1) {
    vector<int> clusters;
    for (DynamicClass point : data) {
        double minDist = numeric_limits<double>::max();
        int closestCentroid = -1;
        for (size_t i = 0; i < centroids1.size(); i++) {
            double dist = euclideanDistance(field_names1, point, centroids1[i]);
            if (dist < minDist) {
                minDist = dist;
                closestCentroid = i;
            }
        }
        clusters.push_back(closestCentroid);
    }
    return clusters;
}

vector<DynamicClass> updateCentroids(vector<DynamicClass>& data, vector<int> clusters, int k) {
    vector<DynamicClass> newCentroids(k);
    vector<int> clusterCounts(k, 0);
    for (int i = 0; i < k; i++) {
        newCentroids[i].fields.clear();
    }
    for (size_t i = 0; i < data.size(); i++) {
        int cluster = clusters[i];
        for (auto [name, value] : data[i].fields) {
            newCentroids[cluster].addField(name, value);
        }
        clusterCounts[cluster]++;
    }
    for (int i = 0; i < k; i++) {
        for (auto [name, value] : newCentroids[i].fields) {
            value /= clusterCounts[i];
        }
    }
    return newCentroids;
}

pair<vector<DynamicClass>, vector<string>> readData(string filepath) {
    vector<DynamicClass> data1;
    int line_count = 0;
    vector<string> field_names;
    ifstream file(filepath);
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
                if (!isNumber(cell) || cell == "") {
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
                if (cell == "") {
                    Obj.addField(field_names[field_count], 0.0);
                } else if (isNumber(cell)) {
                    Obj.addField(field_names[field_count], stod(cell));
                } else {
                    field_count--;
                }
                field_count++;
            }
            data1.push_back(Obj);
        }
        line_count++;
        if (line_count > 2000) {
            // throw runtime_error("This table has over 2000 lines");
        }
    }
    return make_pair(data1, field_names);
}

pair<vector<DynamicClass>, vector<int>> k_means(vector<DynamicClass> data1, vector<string> field_names, int k, int maxIterations) {
    vector<int> clusters;
    vector<DynamicClass> centroids = initializeCentroids(data1, k);
    for (int iter = 0; iter < maxIterations; iter++) {
        clusters = assignClusters(field_names, data1, centroids);
        vector<DynamicClass> newCentroids = updateCentroids(data1, clusters, k);
        // тут нужно добавить проверку на сходимость, т.е если эта итерация не принесла значительные изменения, мы заканчиваем
        centroids = newCentroids;
    }
    return make_pair(centroids, clusters);
}

int main2() {
    pair<vector<DynamicClass>, vector<string>> data = readData("data2.csv");
    vector<DynamicClass> data1 = data.first;
    vector<string> field_names = data.second;
    pair<vector<DynamicClass>, vector<int>> result = k_means(data1, field_names, 3, 100);
    vector<DynamicClass> centroids = result.first;
    vector<int> clusters = result.second;
    for (int i = 0; i < 3; i++) {
        cout << "Cluster: " << i << " centroid: ";
        for (auto field : centroids[i].fields) { // дебаг вывод
            cout << field.first << ": " << field.second << " ";
        }
        cout << '\n';
    }


    return 0;
}
