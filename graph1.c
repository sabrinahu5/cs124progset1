#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// produces random double within a range
double random_double(double min, double max) {
    ((double)rand() / (double)RAND_MAX) * (max - min) + min;
}

// function to generate random numbers on [0,1], where n is the number of vertices
int findMST1(int n) {

    // made node structure to store ID (0 to n), type, and coordinates (array of length 4, initialize as much as needed)
    // different types of nodes
    // visited or not (true or false)
    // choose random number for each edge
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
