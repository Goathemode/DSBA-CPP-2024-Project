# DSBA-CPP-2024-Project

## The team
+ Буш Илья 234-2
+ Нефедов Георгий 234-2
+ Гурьева Полина 234-2
+ Безруков Севастьян 234-2
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
