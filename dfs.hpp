//Roniki04@gmail.com
#pragma once

#include <stack>

#include "node.hpp"

template <typename T>

class dfs {
   private:
    Node<T> *rootTree; // Root of the tree
    std::stack<Node<T> *> myStack; // Stack to store the nodes

   public:
    dfs(Node<T> *root) : rootTree(root) { // Constructor
        myStack.push(rootTree); // Push the root to the queue
    }

    Node<T> *get_root() {
        return rootTree;
    }

    dfs &operator++() {
        while (!myStack.empty()) { // While the stack is not empty
            rootTree = myStack.top(); // Get the top of the stack
            myStack.pop(); // Pop the top of the stack
            for (auto it = rootTree->get_childrenNodes().rbegin(); it != rootTree->get_childrenNodes().rend(); ++it) { // For each child of the root
                myStack.push(*it); // Push the child to the stack
            }
            if (!myStack.empty()) { // If the stack is not empty
                rootTree = myStack.top(); // Get the top of the stack
            } else { // If the stack is empty
                rootTree = nullptr; // Set the root to null
            }
            return *this; // Return the object
        }
        rootTree = nullptr; // Set the root to null
        return *this; // Return the object
    }

    Node<T> &operator*() {
        return *rootTree; // Return the root
    }

    bool operator!=(const dfs &other) {
        return rootTree != other.rootTree; // Return true if the roots are not equal
    }

    bool operator==(const dfs &other) {
        return rootTree == other.rootTree; // Return true if the roots are equal
    }

    Node<T> *operator->() {
        return rootTree; // Return the root
    }
};
