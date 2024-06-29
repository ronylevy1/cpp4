//Roniki04@gmail.com
#pragma once

#include <stack>
#include "node.hpp"

template <typename T>
class postOrder {
private:
    Node<T>* rootTree; // Root of the tree
    std::stack<Node<T>*> myStack; // Stack to store the nodes

    void init(Node<T>* node) {
        if (node) { // If the node is not null
            myStack.push(node); // Push the node to the stack
            for (auto it = node->get_childrenNodes().rbegin(); it != node->get_childrenNodes().rend(); ++it) { // For each child of the node
                init(*it); // Initialize the child
            }
        }
    }

public:
    postOrder(Node<T>* root) : rootTree(nullptr) { // Constructor
        if (root) { // If the root is not null
            init(root); // Initialize the root
            rootTree = myStack.top(); // Get the top of the stack
        }
    }

    Node<T>* get_root() const {
        return rootTree; // Return the root
    }

    postOrder& operator++() {
    if (!myStack.empty()) { // If the stack is not empty
        myStack.pop(); // Pop the top of the stack
        if (!myStack.empty()) { // If the stack is not empty
            rootTree = myStack.top(); // Get the top of the stack
        } else { // If the stack is empty
            rootTree = nullptr; // Set the root to null
        }
    } else {
        rootTree = nullptr; // Set the root to null
    }
    return *this;
}


    Node<T>& operator*() {
        return *rootTree;
    }

    bool operator!=(const postOrder& other) const {
        return rootTree != other.rootTree;
    }

    bool operator==(const postOrder& other) const {
        return rootTree == other.rootTree;
    }

    Node<T>* operator->() {
        return rootTree;
    }
    
};
