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


void showProgressBar(double progress) {
    int barWidth = 70;
    cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "]" << int(progress * 100.0) << " %\r";
    cout.flush();
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
    cout << "Clustering started...\n";
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

vector<int> assignClusters(const vector<string>& fieldNames, const vector<DynamicClass>& data, const vector<DynamicClass>& centroids) {
    vector<int> clusters(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        double minDist = numeric_limits<double>::max();
        int closestCentroid = -1;
        for (size_t j = 0; j < centroids.size(); ++j) {
            double dist = euclideanDistance(fieldNames, data[i], centroids[j]);
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
    vector<string> fieldNames;
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("Error opening file: " + filepath + '\n');
    } else {
        cout << "File " + filepath + " opened succesfully\n";
    }
    string line;
    bool isHeader = true;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
        if (lineCount > 2000) {
            throw runtime_error("File has more than 2000 lines\n");
        }
        stringstream ss(line);
        string cell;
        DynamicClass obj;
        int fieldCount = 0;
        while (getline(ss, cell, ',')) {
            if (isHeader) {
                fieldNames.push_back(cell);
            } else {
                if (cell.empty() || !isNumber(cell)) {
                    continue;
                }
                obj.addField(fieldNames[fieldCount], stod(cell));
            }
            fieldCount++;
            if (fieldNames.size() > 35) {
                throw runtime_error("File has more than 35 fields\n");
            }
        }
        if (!isHeader) {
            data.push_back(obj);
        }
        isHeader = false;
        if (fieldCount == 0) {
            throw runtime_error("Error opening file: no valid data for computation.\n");
        }
    }
    file.close();
    cout << "Data is ready for clustering.\n";
    return make_pair(data, fieldNames);
}


pair<vector<DynamicClass>, vector<int>> kMeans(const vector<DynamicClass>& data, const vector<string>& fieldNames, int k, int maxIterations) {
    vector<DynamicClass> centroids = initializeCentroids(data, k);
    vector<int> clusters(data.size());
    bool converged = false;
    int iter;
    for (iter = 0; iter < maxIterations && !converged; ++iter) {
        clusters = assignClusters(fieldNames, data, centroids);
        vector<DynamicClass> newCentroids = updateCentroids(data, clusters, k);
        converged = true;
        for (int i = 0; i < k; ++i) {
            if (euclideanDistance(fieldNames, centroids[i], newCentroids[i]) > 1e-4) {
                converged = false;
                break;
            }
        }
        centroids = newCentroids;
    }
    if (iter == maxIterations) {
        cout << "Algorithm terminated after exceeding the maximum amount of iterations.\n";
    } else if (iter % 10 == 1 && iter != 11) {
        cout << "Algorithm terminated after centroids converged on " + to_string(iter) + "st iteration.\n";
    } else if (iter % 10 == 2 && iter != 12) {
        cout << "Algorithm terminated after centroids converged on " + to_string(iter) + "nd iteration.\n";
    } else if (iter % 10 == 3 && iter != 13) {
        cout << "Algorithm terminated after centroids converged on " + to_string(iter) + "rd iteration.\n";
    } else {
        cout << "Algorithm terminated after centroids converged on " + to_string(iter) + "th iteration.\n";
    }
    return make_pair(centroids, clusters);
}


double silhouetteScore(const vector<string>& fieldNames, const vector<DynamicClass>& data, const vector<int>& clusters, const vector<DynamicClass>& centroids) {
    vector<double> a(data.size()); // measures cohesion
    vector<double> b(data.size()); // measures separation
    vector<double> s(data.size()); // computes silhouette score for a particular data point
    cout << "Computing the silhouette...\n";

    // compute a
    for (size_t i = 0; i < data.size(); ++i) {
        int cluster = clusters[i];
        double sum = 0.0;
        int count = 0;
        for (size_t j = 0; j < data.size(); ++j) {
            if (clusters[j] == cluster && i != j) {
                sum += euclideanDistance(fieldNames, data[i], data[j]);
                ++count;
            }
        }
        a[i] = sum / count;
        showProgressBar(static_cast<float>((i + 1) / (3.0 * data.size())));
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
                        dist += euclideanDistance(fieldNames, data[i], data[k]);
                        ++count;
                    }
                }
                if (count > 0) {
                    minDist = min(minDist, dist / count);
                }
            }
        }
        b[i] = minDist;
        showProgressBar(static_cast<float>((data.size() + i + 1) / (3.0 * data.size())));
    }

    // compute s
    for (size_t i = 0; i < data.size(); ++i) {
        s[i] = (b[i] - a[i]) / max(a[i], b[i]);
        if (isnan(s[i])) s[i] = 0.0;
        showProgressBar(static_cast<float>((2 * data.size() + i + 1) / (3.0 * data.size())));
    }
    showProgressBar(1.0);
    cout << '\n';
    double overallSilhouetteScore = accumulate(s.begin(), s.end(), 0.0) / s.size();
    return overallSilhouetteScore;
}


void cluster(std::string fileLocation, int k, int maxIterations, function<void(const std::string&)> output) {
    auto [data, fieldNames] = readData(fileLocation);
    auto [centroids, clusters] = kMeans(data, fieldNames, k, maxIterations);
    for (int i = 0; i < k; ++i) {
        output("Cluster: " + to_string(i) + " centroid: ");
        for (const auto& field : centroids[i].fields) {
            output(field.first + ": " + to_string(field.second) + " ");
        }
    }
    double silhouette = silhouetteScore(fieldNames, data, clusters, centroids);
    output("Silhouette score: " + to_string(silhouette) + '\n');
    return;
}
