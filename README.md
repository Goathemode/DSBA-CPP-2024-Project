# DSBA-CPP-2024-Project

## The team
+ Буш Илья 234-2 (Qt application and logic and embedding all the code)
+ Нефедов Георгий 234-2 (Application design and documentation)
+ Гурьева Полина 234-2 (Finding and testing datasets, assisted in business logic)
+ Безруков Севастьян 234-2 (Head of business logic)
## Topic
Implementing K-Means Clustering Algorithm in QT Creator for Dataset Analysis
## Requirements
+ The application should be developed using C++ and QT Creator IDE.
+ Error handling features are necessary in case of inputs or unexpected situations.
+ The app must use the K Means clustering algorithm to divide the dataset into the chosen number of clusters. Implement this algorithm in a separate function. It typically involves initializing cluster centroids, assigning data points to clusters based on proximity to centroids, updating centroids, and iterating until convergence.
+ Implement functionality to save the clustering results and analysis reports to .txt files for future reference.
+ Test the application with sample datasets (.csv files) to ensure that the K-Means algorithm works correctly and the visualization accurately represents the clustering results.
+ For user guidance, instructions on using and interpreting results should be included in the documented app.
## Interface of the project
+ Develop a widget to specify the number of clusters they want the K-Means algorithm to find, and customize K-Means algorithm parameters such as the number of iterations and convergence threshold.
+ The algorithm-generated clusters should be shown (visualised) on a scatter plot with colors for each cluster, information about each cluster such as its centroid and size should be available in the app, and users should be able to save results and analysis reports in .txt files.
+ The interface has a block for reading dataset from .csv file (with restriction: maximum 2000 rows and 35 columns).
+ Connect the user interface elements to the corresponding functions for dataset loading, K-Means clustering, and visualization.
+ Implement a widget to add error handling mechanisms that validate user inputs and handle exceptions during dataset loading or clustering.
+ Provide a documentation with comments and instructions on how to use the application.
# Documentation
## Overview
The purpose of this application is to provide a user-friendly interface for performing data clustering using the k-means algorithm. The application allows users to input datasets and configure clustering parameters. It is designed to facilitate the analysis and understanding of complex data by grouping similar data points together. Key functionalities include data import, parameter tuning, and export of clustered data.
## Getting Started
Before using the application, ensure that you have the following requirements in place:
+ **Data File**: A dataset in CSV format that you want to cluster.
+ **Permissions**: Ensure you have read and write permissions for the directory where the application and data files are located.
+ **Qt Creator**: A working version of Qt creator
## Installation
1. **Clone the Repository**:
   - Open your terminal or command prompt.
   - Clone the repository from GitHub (or any other source) using the following command:
  ```
git clone https://github.com/Goathemode/DSBA-CPP-2024-Project
```
2. **Import the folder into Qt creator**
3. **Build and enjpy the experience**
## Application features
The k-means clustering application offers a range of features designed to simplify the process of clustering data and visualizing the results. The main features include:

- Data Loading: Import datasets in CSV format.
- Data Preprocessing: Handle missing values, normalize data, and select features for clustering.
- Cluster Configuration: Set the number of clusters and other k-means parameters.
- Cluster Execution: Run the k-means algorithm on the dataset.
## Cluster Configuration

- What it does: Allows you to set the number of clusters and other parameters for the k-means algorithm.
- How to use it:
  1. Go to the "Cluster Configuration" widgets.
  2. Enter the number of clusters (k) you want to create.
  3. Optionally adjust other parameters like maximum iterations.
- Important notes or tips:
  - Experiment with different values of k to find the optimal number of clusters.
  - Review algorithm settings for better performance.
## Cluster Execution
- What it does: Runs the k-means algorithm on your preprocessed dataset.
- How to use it:
  1. After configuring your clusters, click the "Cluster" button.
  2. Wait for the algorithm to process the data.
  3. The application will display results once clustering is complete.
- Important notes or tips:
  - The time taken depends on dataset size and complexity.
  - Check logs or console output for any errors during execution.
