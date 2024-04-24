# DSBA-CPP-2024-Project

## The team
+ Буш Илья 234-2
+ Нефедов Георгий 234-2
+ Гурьева Полина 234-2
+ Безруков Севастьян 234-2
## Topic
Implementing K-Means Clustering Algorithm in QT Creator for Dataset Analysis
## Requirements
1. The application should be created with QT Creator IDE.
2. The application should have a user interface so that users can easily upload and view datasets.
3. Users should have the option to specify how many clusters they want the K Means algorithm to find.
4. The app should allow users to customize K Means algorithm parameters such as the number of iterations and convergence threshold.
5. The app must use the K Means clustering algorithm to divide the dataset into the chosen number of clusters.
6. The algorithm generated clusters should be shown on a scatter plot, with colors for each cluster.
7. Information about each cluster, such as centroid and size should be available in the app.
8. Users should be able to save results and analysis reports.
9. Error handling features are necessary in case of inputs or unexpected situations.
10. For user guidance, instructions on using and interpreting results should be included in the documented app.
## Interface of the project
1. Create a new QT Creator project and set up the necessary project structure.
2. Implement a function to read and load the dataset from a file. You can use libraries like Qt's QFile for file handling.
3. Implement the K-Means clustering algorithm in a separate function. The algorithm typically involves initializing cluster centroids, assigning data points to clusters based on proximity to centroids, updating centroids, and iterating until convergence.
4. Create a function to visualize the dataset and clustering results using a scatter plot. You can use Qt's QGraphicsView for plotting data points and clusters.
5. Develop a user interface that allows users to input parameters such as the number of clusters, maximum iterations, and convergence threshold.
6. Connect the user interface elements to the corresponding functions for dataset loading, K-Means clustering, and visualization.
7. Add error handling mechanisms to validate user inputs and handle exceptions during dataset loading or clustering.
8. Implement functionality to save the clustering results and analysis reports to files for future reference.
9. Test the application with sample datasets to ensure that the K-Means algorithm works correctly and the visualization accurately represents the clustering results.
10. Document the code with comments and provide instructions on how to use the application for dataset analysis using K-Means clustering.
