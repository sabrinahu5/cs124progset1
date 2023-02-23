#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// will have three diff functions, which will be called at different times depending on command line argument
// setup the graph for the problem (complete graph on n vertices, 
// where the weight of each edge is a real number chosen uniformly at random on [0,1])

// figure out most efficient MST algorithm
// implement it lol

// produces random double within a range
double random_double(double min, double max) {
    double range = max - min;
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


// function to generate random numbers on [0,1], where n is the number of vertices
int findMST1(int n) {

    // initialize graph
    srand(time(NULL));

    double graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            } else {
                double weight = random_double(0.0, 1.0);
                graph[i][j] = weight;
                graph[j][i] = weight; 
            }
        }
    }

    return 0;


}

int main(int argc, char** argv) {
    
    return 0;


}
