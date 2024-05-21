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
class DynamicClass
{
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
double euclideanDistance(vector<string> field_names1, DynamicClass obj1, DynamicClass obj2) {
    double sum1 = 0.0;
    for (size_t i = 0; i < field_names1.size(); i++) {
        double diff = obj1.getField(field_names1[i]) - obj2.getField(field_names1[i]);
        sum1 += diff * diff;
    }
    return sqrt(sum1);
}


vector<DynamicClass> initializeCentroids(vector<DynamicClass>& data2, int k) 
{
    vector<DynamicClass> centroids; 
    vector<DynamicClass> shuffledData = data2;
    random_device rd;
    
    //std::cout << __LINE__ << std::endl;
    
    default_random_engine rng(rd()); // бог знает как это работает

    //std::cout << __LINE__ << std::endl;
    
    shuffle(shuffledData.begin(), shuffledData.end(), rng);
    
    //std::cout << __LINE__ << std::endl;
    
    //std::cout << shuffledData.size() << std::endl;
    
    for (int i = 0; i < k; i++) 
    {
        centroids.push_back(shuffledData[i]);
    }

    //std::cout << __LINE__ << std::endl;
    

    return centroids; 
}

vector<int> assignClusters(vector<string> field_names1, vector<DynamicClass>& data, vector<DynamicClass> centroids1)
{
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

vector<DynamicClass> updateCentroids(vector<DynamicClass>& data, vector<int> clusters, int k)
{
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

int main()
{
    std::cout << __LINE__ << std::endl; // это для дебага

    vector<DynamicClass> data1;
    int line_count = 0;
    vector<string> field_names;
    ifstream file("data.csv");

    if (file.is_open() == false)
    {
        throw std::runtime_error("file is not found"); // !!! нужно тут это написать
    }

    std::cout << __LINE__ << std::endl; // это для дебага

    string line;
    DynamicClass Obj;
    std::cout << __LINE__ << std::endl; // это для дебага

    char delim = ' ';

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string cell;

        if (line.find(',') != std::string::npos) // !!! МОЖНО УЛУЧШИТЬ, сделать функцию, которая ищет delimiter по строке. 
            delim = ',';
        if (line.find('\t') != std::string::npos) // !!!
            delim = '\t'; 

        if (line_count == 0) { // этот блок собирает заголовки
        
            //cout << line << endl;
            //cout << "!!!" << delim << "!!!" << endl;

            while(getline(ss, cell, delim) ) 
            {
                //cout << cell << endl;
                field_names.push_back(cell);
            }
            //std::cout << field_names.size() << std::endl;

        }

        
        if (line_count == 1) { // этот блок удаляет из вектора заголовки, относящиеся не к скалярным полям
            int field_count = 0;
            DynamicClass Obj;
            while (getline(ss, cell, delim)) { // !!!
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
            while (getline(ss, cell, delim)) { // !!!
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
    
    std::cout << __LINE__ << std::endl;
    
    int k = 3;
    int maxIterations = 100;
    vector<DynamicClass> centroids = initializeCentroids(data1, k);
    
    std::cout << centroids.size() << std::endl;
    
    std::cout << __LINE__ << std::endl;
    
    for (int iter = 0; iter < maxIterations; iter++) {
        vector<int> clusters = assignClusters(field_names, data1, centroids);
        std::cout << __LINE__ << std::endl;
        vector<DynamicClass> newCentroids = updateCentroids(data1, clusters, k);
        // тут нужно добавить проверку на сходимость, т.е если эта итерация не принесла значительные изменения, мы заканчиваем
        //delete &centroids; // ??? вроде не нужно 
        centroids = newCentroids; // неа
    }

    //std::cout << __LINE__ << std::endl;
    for (int i = 0; i < k; i++) {
        cout << "Cluster: " << i << " centroid: ";
        for (auto field : centroids[i].fields) { // дебаг вывод
            cout << field.first << ": " << field.second << " ";
        }
        cout << '\n';
    }
    //std::cout << __LINE__ << std::endl;

    return 0;
}
