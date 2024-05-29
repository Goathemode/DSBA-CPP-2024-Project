#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <vector>
#include <map>

class DynamicClass;

bool isNumber(const std::string& str1);

double euclideanDistance(const std::vector<std::string>& field_names1, const DynamicClass& obj1, const DynamicClass& obj2);

std::vector<DynamicClass> initializeCentroids(std::vector<DynamicClass>& data2, int k);

std::vector<int> assignClusters(const std::vector<std::string>& field_names1, const std::vector<DynamicClass>& data, const std::vector<DynamicClass>& centroids1);

std::vector<DynamicClass> updateCentroids(const std::vector<DynamicClass>& data, const std::vector<int>& clusters, int k);

std::pair<std::vector<DynamicClass>, std::vector<std::string>> readData(const std::string& filepath);

std::pair<std::vector<DynamicClass>, std::vector<int>> k_means(const std::vector<DynamicClass>& data1, const std::vector<std::string>& field_names, int k, int maxIterations);

void clean(std::string fileLocation);

#endif // CLEANER_H
