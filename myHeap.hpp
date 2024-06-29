//Roniki04@gmail.com
#pragma once
#include "node.hpp"
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

template <typename T>
class myHeap {
private:
    std::vector<Node<T>*> heap; // The heap
    size_t index; // Index of the heap

public:
    myHeap(Node<T>* root) : index(0) {
        if (root) { // If the root is not null
            std::queue<Node<T>*> q; // Queue to store the nodes
            q.push(root); // Push the root to the queue
            while (!q.empty()) { // While the queue is not empty
                Node<T>* node = q.front(); // Get the front of the queue
                q.pop(); // Pop the front of the queue
                heap.push_back(node); // Push the node to the heap
                for (auto child : node->get_childrenNodes()) { // For each child of the node
                    q.push(child); // Push the child to the queue
                }
            }
            std::make_heap(heap.begin(), heap.end(), [](Node<T>* a, Node<T>* b) { // Make the heap
                return a->get_value() > b->get_value();
            });
        }
    }

    myHeap& operator++() {
        if (index < heap.size()) { // If the index is less than the size of the heap
            ++index; // Add to the index
        }
        return *this;
    }

    Node<T>& operator*() {
        return *heap[index]; // Access the data of the current node
    }

    Node<T>* operator->() {
        return heap[index]; // Return the current node
    }

    bool operator!=(const myHeap& other) const {
        return index != other.index || heap != other.heap;
    }

    bool operator==(const myHeap& other) const {
        return index == other.index && heap == other.heap;
    }

    myHeap begin() { // Return the beginning of the heap
        return *this;
    }

    myHeap end() { // Return the end of the heap
        myHeap endHeap = *this;
        endHeap.index = heap.size();
        return endHeap;
    }
};

