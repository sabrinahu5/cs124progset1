#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

// Node structure (for each vertex)
struct Node {
  int ID;
  bool visited;
  float value;
  float coords[4];
};

// Construct MinHeap class
class MinHeap {

    private:

        vector<Node> heap;

        int parent(int i) {
            return (i-1)/2;
        }

        int left(int i) {
            return 2*i + 1;
        }

        int right(int i) {
            return 2*i + 2;
        }

        void swap(Node& x, Node& y) {
            Node temp = x;
            x = y;
            y = temp;
        }

        void minHeapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < heap.size() && heap[l].value < heap[smallest].value) {
                smallest = l;
            }

            if (r < heap.size() && heap[r].value < heap[smallest].value) {
                smallest = r;
            }

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                minHeapify(smallest);
            }
        }

    public:

        int size() {
            return heap.size();
        }

        void insert(Node n) {
            heap.push_back(n);

            int i = heap.size() - 1;
            while (i != 0 && heap[parent(i)].value > heap[i].value) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        Node getMin() {
            if (heap.empty()) {
                return {0, false, 0, {0,0,0,0}};
            }

            Node minNode = heap[0];

            heap[0] = heap.back();
            heap.pop_back();

            minHeapify(0);

            return minNode;
        }

};
