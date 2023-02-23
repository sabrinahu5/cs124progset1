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
    Node nodes[n];  // Initialize our nodes
    float dist[n];
    bool visited[n]; // Visited nodes
    MinHeap H;

    // Initialize stuff:
    for (int i = 0; i < n; i++) {
        nodes[i].value = __FLT_MAX__;
        nodes[i].visited = false;
    }

    // Starting node
    nodes[0].value = 0;
    H.insert(nodes[0]);

    // each node: ID (index in array?), type: dim, value: actual value
    // coords: coords if dim 2, 3, 4, visited: bool
    // array of n Nodes
    // initialize all as unvisited
    // start from the 0th node, mark value as 0
    // insert into minheap
    // while loop: take out min of minheap, set it as visited
    // go through all over n-1 nodes in array, pass by if visited
    // for each node, distance is random edge or distance between randomly generated coords
    // if the value of each node is less than the distance, set the value of each node as that distance
    // put the nodes in the minheap based on value
    // add mindistance to total mindistance
    // recur by extracting the min node in the heap and starting again
    while (H.size()) {
        Node v = H.getMin();
        v.visited = true;
        min_dist += v.value;
        for (int i = 0; i < n; i++) {
            if (nodes[i].visited == false) {
                float currdist = random_float();
                if (nodes[i].value > currdist) {
                    nodes[i].value = currdist;
                    H.insert(nodes[i]);
                }
            }
        }
    }

    return min_dist;

}


int main(int argc, char *argv[]) {

    srand(time(NULL));
    
    return 0;

}