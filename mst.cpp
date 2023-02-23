#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include "binary_heap.hpp"
#include <chrono>

using namespace std;

// Produces random edge
float random_float() {
    return (float)rand() / RAND_MAX;
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
float primMST(int n, int dim) {

    float min_dist = 0;
    std::vector<Node> nodes(n);  // Initialize our nodes, maybe use vectors?
    MinHeap H;

    // Initialize stuff:
    for (int i = 0; i < n; i++) {
        nodes[i].value = __FLT_MAX__;
        nodes[i].visited = false;
        nodes[i].ID = i;
        if (dim > 0) {
            for (int j = 0; j < dim; j++) {
                nodes[i].coords[j] = random_float();
            }
        }
    }

    // Starting node
    nodes[0].value = 0;
    H.insert(nodes[0]);

    // Prim's!
    while (H.size()) {
        Node v = H.getMin();
        if (nodes[v.ID].visited) continue; // skip visited nodes
        nodes[v.ID].visited = true;
        min_dist += v.value;
        for (int i = 0; i < n; i++) {
            if (nodes[i].visited) {
                continue;
            }
            float currdist;
            if (dim == 0) {
                currdist = random_float();
            } else {
                currdist = get_dist(nodes[i].coords, nodes[v.ID].coords, dim);
            }
            if (nodes[i].value > currdist) {
                nodes[i].value = currdist;
                H.insert(nodes[i]); // add new node to heap
            }
        }
    }

    return min_dist;

}


int main(int argc, char *argv[]) {

    auto start_time = std::chrono::high_resolution_clock::now();

    srand(time(NULL));

    // command line argument should be in form "./randmst 0 numpoints numtrials dimension"
    if (argc != 5) {
        printf("Invalid arguments.");
        return 1;
    }

    int n = atoi(argv[2]); // Num of vertices in the graph
    int trials = atoi(argv[3]); // Num of trials
    int dim = atoi(argv[4]); // Num of dimensions (0, 2, 3, 4)

    float sum = 0;
    for (int i = 0; i < trials; i++) {
        sum += primMST(n, dim);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << sum / trials << " " << n << std::endl;
    std::cout << "Elapsed time: " << duration.count() << " milliseconds\n";

    return 0;

}