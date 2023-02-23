#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include "binary_heap.hpp"

using namespace std;

// Produces random edge
float random_float() {
    return ((float)rand() / (float) RAND_MAX);
}

// Gets distance between two points (for dim 2, 3, 4)
float get_dist(float c1[], float c2[], int dim) {
    float dist = 0;
    // Distance formula based on dimension
    for (int i = 0; i < dim; i++) {
        dist += (c1[i] - c2[i]) * (c1[i] - c2[i]);
    }
    return sqrt(dist);
}

// Function to find min weight with Prim's
float primMST(int n) {

    float min_dist = 0;
    Node nodes[n];
    float dist[n];
    bool visited[n];
    MinHeap minheap;


}


int main(int argc, char** argv) {

    
    return 0;

}