//Roniki04@gmail.com
#pragma once
#include <queue>

#include "node.hpp"

template <typename T>

class bfs{
    private:
        Node<T> *rootTree; // Root of the tree
        std::queue<Node<T>*> myQueue; // Queue to store the nodes

    public:
        bfs(Node<T>* root): rootTree(root){ // Constructor
            myQueue.push(rootTree); // Push the root to the queue
        }

    Node<T> *get_root(){
        return rootTree;
    }

    bfs& operator++() {
        if (!myQueue.empty()) { // While the queue is not empty
            rootTree = myQueue.front(); // Get the front of the queue
            myQueue.pop(); // Pop the front of the queue

            for (auto child : rootTree->get_children()) { // For each child of the root
                myQueue.push(child); // Push the child to the queue
            }
            if(!myQueue.empty()){ // If the queue is not empty
                rootTree = myQueue.front(); // Get the front of the queue
            }
            else{ // If the queue is empty
                rootTree = nullptr; // Set the root to null
            }
        }
         else { // If the queue is empty
            rootTree = nullptr; // Set the root to null
        }
        return *this; // Return the object
    }

    Node<T> &operator*(){
        return *rootTree; // Return the root
    }

    bool operator!=(const bfs &other){
        return rootTree != other.rootTree; // Return true if the roots are not equal
    }

    bool operator==(const bfs &other){
        return rootTree == other.rootTree; // Return true if the roots are equal
    }

    Node<T>* operator->(){
        return rootTree; // Return the root
    }

};