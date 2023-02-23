#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// will have three diff functions, which will be called at different times depending on command line argument
// setup the graph for the problem (complete graph on n vertices, 
// where the weight of each edge is a real number chosen uniformly at random on [0,1])

// figure out most efficient MST algorithm
// implement it lol

// function to generate random numbers on [0,1], where n is the number of vertices
int findMST1(int n) {

    // initialize graph
    srand(time(NULL));

    double graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = i+1, j < n; j++) {
            double weight = (double) rand() / RAND_MAX;
            graph[i][j] = weight
            graph[j][i] = weight
        }
    }


}

int main(int argc, char** argv) {
    srand(time(NULL)); // Initialize the random number generator with the current time
    
    int n = 5; // Number of vertices
    double graph[n][n]; // Matrix to represent the graph
    
    // Initialize the graph with random weights
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double weight = ((double) rand() / RAND_MAX); // Generate a random weight between 0 and 1
            graph[i][j] = weight;
            graph[j][i] = weight; // Symmetric weights
        }
    }
    
    // Print the graph to verify
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", graph[i][j]);
        }
        printf("\n");
    }
    
    return 0;


}
