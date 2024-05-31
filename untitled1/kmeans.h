#ifndef KMEANS_H
#define KMEANS_H

#include <string>
#include <map>
#include <vector>
#include <functional>

class DynamicClass;

bool isNumber(const std::string& str1);

double euclideanDistance(const std::vector<std::string>& field_names1, const DynamicClass& obj1, const DynamicClass& obj2);

std::vector<DynamicClass> initializeCentroids(std::vector<DynamicClass>& data2, int k);

std::vector<int> assignClusters(const std::vector<std::string>& field_names1, const std::vector<DynamicClass>& data, const std::vector<DynamicClass>& centroids1);

std::vector<DynamicClass> updateCentroids(const std::vector<DynamicClass>& data, const std::vector<int>& clusters, int k);

std::pair<std::vector<DynamicClass>, std::vector<std::string>> readData(const std::string& filepath);

std::pair<std::vector<DynamicClass>, std::vector<int>> k_means(const std::vector<DynamicClass>& data1, const std::vector<std::string>& field_names, int k, int maxIterations);

void cluster(std::string fileLocation, int k, std::function<void(const std::string&)> output);

#endif // KMEANS_H
