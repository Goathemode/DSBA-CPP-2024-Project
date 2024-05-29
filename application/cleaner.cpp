#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <set>
#include "csv.h" // Include the CSV parser library


// Function to handle missing values (replace with mean)
void handleMissingValues(std::vector<std::vector<double>>& data) {
    for (auto& row : data) {
        for (auto& value : row) {
            if (std::isnan(value)) {
                // Replace NaN with the column mean
                double mean = 0.0;
                int count = 0;
                for (const auto& r : data) {
                    if (!std::isnan(r[&value - &row[0]])) {
                        mean += r[&value - &row[0]];
                        count++;
                    }
                }
                value = (count > 0) ? mean / count : 0.0;
            }
        }
    }
}

// Function to remove duplicates
void removeDuplicates(std::vector<std::vector<double>>& data) {
    std::set<std::vector<double>> uniqueData(data.begin(), data.end());
    data.assign(uniqueData.begin(), uniqueData.end());
}

// Function to normalize data (zero mean, unit variance)
void normalizeData(std::vector<std::vector<double>>& data) {
    size_t numRows = data.size();
    size_t numCols = data[0].size();

    std::vector<double> mean(numCols, 0.0);
    std::vector<double> stdDev(numCols, 0.0);

    // Calculate mean
    for (const auto& row : data) {
        for (size_t i = 0; i < numCols; ++i) {
            mean[i] += row[i];
        }
    }
    for (size_t i = 0; i < numCols; ++i) {
        mean[i] /= numRows;
    }

    // Calculate standard deviation
    for (const auto& row : data) {
        for (size_t i = 0; i < numCols; ++i) {
            stdDev[i] += std::pow(row[i] - mean[i], 2);
        }
    }
    for (size_t i = 0; i < numCols; ++i) {
        stdDev[i] = std::sqrt(stdDev[i] / numRows);
    }

    // Normalize data
    for (auto& row : data) {
        for (size_t i = 0; i < numCols; ++i) {
            if (stdDev[i] != 0) {
                row[i] = (row[i] - mean[i]) / stdDev[i];
            }
        }
    }
}

// Function to scale data to [0, 1]
void scaleData(std::vector<std::vector<double>>& data) {
    size_t numRows = data.size();
    size_t numCols = data[0].size();

    std::vector<double> minValues(numCols, std::numeric_limits<double>::max());
    std::vector<double> maxValues(numCols, std::numeric_limits<double>::lowest());

    // Find min and max values
    for (const auto& row : data) {
        for (size_t i = 0; i < numCols; ++i) {
            if (row[i] < minValues[i]) minValues[i] = row[i];
            if (row[i] > maxValues[i]) maxValues[i] = row[i];
        }
    }

    // Scale data
    for (auto& row : data) {
        for (size_t i = 0; i < numCols; ++i) {
            if (maxValues[i] != minValues[i]) {
                row[i] = (row[i] - minValues[i]) / (maxValues[i] - minValues[i]);
            }
        }
    }
}

// Function to read data from a CSV file and determine the number of columns dynamically
std::vector<std::vector<double>> readCSV(const std::string& filename) {
    std::vector<std::vector<double>> data;
    std::ifstream inFile(filename);
    std::string line;

    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    while (std::getline(inFile, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            try {
                row.push_back(std::stod(value));
            } catch (const std::invalid_argument&) {
                row.push_back(std::numeric_limits<double>::quiet_NaN());
            }
        }

        if (!row.empty()) {
            data.push_back(row);
        }
    }

    return data;
}

// Function to write data to a CSV file
void writeCSV(const std::string& filename, const std::vector<std::vector<double>>& data) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outFile << row[i];
            if (i != row.size() - 1) outFile << ",";
        }
        outFile << "\n";
    }
}

void clean(std::string fileLocation) {
    // Read data from CSV file
    std::vector<std::vector<double>> data = readCSV(fileLocation);

    // Check if data is empty
    if (data.empty()) {
        std::cerr << "No data read from CSV file." << std::endl;
        return;
    }

    // Handle missing values
    handleMissingValues(data);

    // Remove duplicates
    removeDuplicates(data);

    // Normalize data
    normalizeData(data);

    // Scale data
    scaleData(data);

    // Write cleaned data to a new CSV file
    writeCSV("cleaned_output.csv", data);

    std::cout << "Data cleaning complete. Cleaned data saved to 'cleaned_output.csv'." << std::endl;
    return;
}
