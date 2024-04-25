# DSBA-CPP-2024-Project

## The team
+ Буш Илья 234-2
+ Нефедов Георгий 234-2
+ Гурьева Полина 234-2
+ Безруков Севастьян 234-2
## Topic
Implementing K-Means Clustering Algorithm in QT Creator for Dataset Analysis
## Requirements
+ The application should be created with QT Creator IDE.
+ The app must use the K Means clustering algorithm to divide the dataset into the chosen number of clusters.
+ Error handling features are necessary in case of inputs or unexpected situations.
+ Implement the K-Means clustering algorithm in a separate function. The algorithm typically involves initializing cluster centroids, assigning data points to clusters based on proximity to centroids, updating centroids, and iterating until convergence.
+ For user guidance, instructions on using and interpreting results should be included in the documented app.
## Interface of the project
+ The application should have a user interface that allows users to easily upload and view datasets, specify the number of clusters they want the K Means algorithm to find, and customize K Means algorithm parameters such as the number of iterations and convergence threshold.
+ The algorithm-generated clusters should be shown on a scatter plot with colors for each cluster, information about each cluster such as centroid and size should be available in the app, and users should be able to save results and analysis reports
+ Implement a function to read and load the dataset from a file. You can use libraries like Qt's QFile for file handling.
+ Create a function to visualize the dataset and clustering results using a scatter plot. You can use Qt's QGraphicsView for plotting data points and clusters.
+ Develop a user interface that allows users to input parameters such as the number of clusters, maximum iterations, and convergence threshold.
+ Connect the user interface elements to the corresponding functions for dataset loading, K-Means clustering, and visualization.
+ Implement a widget to add error handling mechanisms that validate user inputs and handle exceptions during dataset loading or clustering.
+ Implement functionality to save the clustering results and analysis reports to files for future reference.
+ Test the application with sample datasets to ensure that the K-Means algorithm works correctly and the visualization accurately represents the clustering results.
+ Document the code with comments and provide instructions on how to use the application for dataset analysis using K-Means clustering.
