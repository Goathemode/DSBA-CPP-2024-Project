#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <vector>
#include <functional>

// Function to handle missing values (replace with mean)
void handleMissingValues(std::vector<std::vector<double>>& data);

// Function to remove duplicates
void removeDuplicates(std::vector<std::vector<double>>& data);

// Function to normalize data (zero mean, unit variance)
void normalizeData(std::vector<std::vector<double>>& data);

// Function to scale data to [0, 1]
void scaleData(std::vector<std::vector<double>>& data);

// Function to check if a string is a date
bool isDate(const std::string& str);

// Function to read data from a CSV file and determine the number of columns dynamically
std::vector<std::vector<double>> readCSV(const std::string& filename, std::function<void(const std::string&)> output);

// Function to write data to a CSV file
void writeCSV(const std::string& filename, const std::vector<std::vector<double>>& data, std::function<void(const std::string&)> output);

// Function to clean the data from a CSV file
void clean(std::string fileLocation, std::function<void(const std::string&)> output);

#endif // CLEANER_H
