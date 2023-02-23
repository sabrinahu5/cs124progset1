#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// produces random double within a range
double random_double(double min, double max) {
    ((double)rand() / (double)RAND_MAX) * (max - min) + min;
}

// function to generate random numbers on [0,1], where n is the number of vertices
int findMST1(int n) {

    // create nodes beforehand
    // Prim's start w/ random point
    // store all nodes in list (node: ID, type, coordinates, "value")
    // add each node to visited
    // check every vertex directly connected to tree, calculate distance from each 
    // edges calculate as you go (either generate random, or find distance) - at node, check all n-1 other nodes
    // iterate - give each node a value, cheapest way to get to that node
    // priority queue sorts node by value (priority queue is all nodes around the node with distance, pop top of priority queue)
    // if weight is less than value than node possesses
    // binary heap
    // structure for each node, flexible
    // 1.2



    // made node structure to store ID (0 to n), type, and coordinates (array of length 4, initialize as much as needed)
    // different types of nodes
    // visited or not (true or false)
    // choose random number for each edge
    // estimate bigger n 
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
