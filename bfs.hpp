#pragma once
#include <queue>

#include "node.hpp"

template <typename T>

class bfs{
    private:
        Node<T> *_root; // Root of the tree
        std::queue<Node<T>*> myQueue; // Queue to store the nodes

    public:
        bfs(Node<T>* root): _root(root){ // Constructor
            myQueue.push(_root); // Push the root to the queue
        }

    Node<T> *get_root(){
        return _root;
    }

    bfs& operator++() {
        if (!myQueue.empty()) {
            _root = myQueue.front();
            myQueue.pop();

            // Enqueue all children of the current node
            for (auto child : _root->get_children()) {
                myQueue.push(child);
            }
            if(!myQueue.empty()){
                _root = myQueue.front();
            }
            else{
                _root = nullptr;
            }
        }
         else {
            _root = nullptr; // End condition: queue is empty
        }
        return *this;
    }

    Node<T> &operator*(){
        return *_root; // Return the root
    }

    bool operator!=(const bfs &other){
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const bfs &other){
        return _root == other._root; // Return true if the roots are equal
    }

    void print(){
        while(_root != nullptr){ // While the root is not null
            std::cout << _root->get_data() << " "; // Print the data
            ++(*this); // Increment the object
        }
        std::cout << std::endl; // Print a new line
    }

    Node<T>* operator->(){
        return _root;
    }

};