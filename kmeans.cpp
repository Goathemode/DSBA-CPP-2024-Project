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
#include <numeric>


using namespace std;

// Класс, отражающий data point в произвольном dataset
class DynamicClass {
    public:
        map<string, double> fields;
        
        void addField(string name, double value) {
            fields[name] = value;
        }

        double getField(string name) const {
            if (fields.find(name) != fields.end()) {
                return fields.at(name);
            } else {
                return 0.0;
            }
        }
};

// Отсеивает целые и дробные числа, затесавшиеся в string (т.к клетка файла .csv - string)
bool isNumber(const string& str1) {
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


double euclideanDistance(const vector<string>& field_names, const DynamicClass& obj1, const DynamicClass& obj2) {
    double sum = 0.0;
    for (const auto& field_name : field_names) {
        double diff = obj1.getField(field_name) - obj2.getField(field_name);
        sum += diff * diff;
    }
    return sqrt(sum);
}

vector<DynamicClass> initializeCentroids(const vector<DynamicClass>& data, int k) {
    vector<DynamicClass> centroids;
    vector<DynamicClass> shuffledData = data;
    random_device rd;
    default_random_engine rng(rd()); // бог знает как это работает
    shuffle(shuffledData.begin(), shuffledData.end(), rng);
    for (int i = 0; i < k; i++) {
        centroids.push_back(shuffledData[i]);
    }
    return centroids;
}

vector<int> assignClusters(const vector<string>& field_names, const vector<DynamicClass>& data, const vector<DynamicClass>& centroids) {
    vector<int> clusters(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        double minDist = numeric_limits<double>::max();
        int closestCentroid = -1;
        for (size_t j = 0; j < centroids.size(); ++j) {
            double dist = euclideanDistance(field_names, data[i], centroids[j]);
            if (dist < minDist) {
                minDist = dist;
                closestCentroid = j;
            }
        }
        clusters[i] = closestCentroid;
    }
    return clusters;
}

vector<DynamicClass> updateCentroids(const vector<DynamicClass>& data, const vector<int>& clusters, int k) {
    vector<DynamicClass> newCentroids(k);
    vector<int> clusterCounts(k, 0);
    for (size_t i = 0; i < data.size(); ++i) {
        int cluster = clusters[i];
        for (const auto& [name, value] : data[i].fields) {
            newCentroids[cluster].addField(name, newCentroids[cluster].getField(name) + value);
        }
        clusterCounts[cluster]++;
    }
    for (int i = 0; i < k; ++i) {
        if (clusterCounts[i] > 0) {
            for (const auto& [name, value] : newCentroids[i].fields) {
                newCentroids[i].fields[name] = value / clusterCounts[i];
            }
        }
    }
    return newCentroids;
}

pair<vector<DynamicClass>, vector<string>> readData(const string& filepath) {
    vector<DynamicClass> data;
    vector<string> field_names;
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("Error opening file: " + filepath + '\n');
    }
    string line;
    bool isHeader = true;
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        DynamicClass obj;
        int field_count = 0;
        while (getline(ss, cell, ',')) {
            if (isHeader) {
                field_names.push_back(cell);
            } else {
                if (cell.empty() || !isNumber(cell)) {
                    continue;
                }
                obj.addField(field_names[field_count], stod(cell));
            }
            field_count++;
        }
        if (!isHeader) {
            data.push_back(obj);
        }
        isHeader = false;
    }
    return make_pair(data, field_names);
}


pair<vector<DynamicClass>, vector<int>> k_means(const vector<DynamicClass>& data, const vector<string>& field_names, int k, int maxIterations) {
    vector<DynamicClass> centroids = initializeCentroids(data, k);
    vector<int> clusters(data.size());
    bool converged = false;
    for (int iter = 0; iter < maxIterations && !converged; ++iter) {
        clusters = assignClusters(field_names, data, centroids);
        vector<DynamicClass> newCentroids = updateCentroids(data, clusters, k);
        converged = true;
        for (int i = 0; i < k; ++i) {
            if (euclideanDistance(field_names, centroids[i], newCentroids[i]) > 1e-4) {
                converged = false;
                break;
            }
        }
        centroids = newCentroids;
    }
    return make_pair(centroids, clusters);
}


double silhouetteScore(const vector<string>& field_names, const vector<DynamicClass>& data, const vector<int>& clusters, const vector<DynamicClass>& centroids) {
    vector<double> a(data.size()); // computes cohesion
    vector<double> b(data.size()); // computes separation
    vector<double> s(data.size()); // computes silhouette score for a particular data point

    // compute a
    for (size_t i = 0; i < data.size(); ++i) {
        int cluster = clusters[i];
        double sum = 0.0;
        int count = 0;
        for (size_t j = 0; j < data.size(); ++j) {
            if (clusters[j] == cluster) {
                sum += euclideanDistance(field_names, data[i], data[j]);
                ++count;
            }
        }
        a[i] = sum / count;
    }

    // compute b
    for (size_t i = 0; i < data.size(); ++i) {
        int cluster = clusters[i];
        double minDist = numeric_limits<double>::max();
        for (size_t j = 0; j < centroids.size(); ++j) {
            if (j != cluster) {
                double dist = 0.0;
                int count = 0;
                for (size_t k = 0; k < data.size(); ++k) {
                    if (clusters[k] == j) {
                        dist += euclideanDistance(field_names, data[i], data[k]);
                        ++count;
                    }
                }
                if (count > 0) {
                    minDist = min(minDist, dist / count);
                }
            }
        }
        b[i] = minDist;
    }

    // compute s
    for (size_t i = 0; i < data.size(); ++i) {
        s[i] = (b[i] - a[i]) / max(a[i], b[i]);
    }
    double overallSilhouetteScore = accumulate(s.begin(), s.end(), 0.0) / s.size();
    return overallSilhouetteScore;
}


int main() {
    pair<vector<DynamicClass>, vector<string>> data = readData("basic1.csv");
    vector<DynamicClass> data1 = data.first;
    vector<string> field_names = data.second;
    int k = 4;
    int maxIterations = 100;
    pair<vector<DynamicClass>, vector<int>> result = k_means(data1, field_names, k, maxIterations);
    vector<DynamicClass> centroids = result.first;
    vector<int> clusters = result.second;
    for (int i = 0; i < k; ++i) {
        cout << "Cluster: " << i << " centroid: ";
        for (const auto& field : centroids[i].fields) {
            cout << field.first << ": " << field.second << " ";
        }
        cout << '\n';
    }
    double silhouette = silhouetteScore(field_names, data1, clusters, centroids);
    cout << "Silhouette score: " << silhouette << '\n';

    return 0;
}
