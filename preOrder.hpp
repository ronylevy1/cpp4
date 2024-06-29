//Roniki04@gmail.com
#pragma once

#include <stack>

#include "node.hpp"

template <typename T>

class preOrder {
   private:
    Node<T>* rootTree; // Root of the tree
    std::stack<Node<T>*> stack; // Stack to store the nodes

   public:
    preOrder(Node<T>* root) : rootTree(root) {  // Constructor
        if (rootTree) { // If the root is not null
            stack.push(rootTree); // Push the root to the stack
        }
    }

    Node<T>* get_root() const {
        return rootTree; // Return the root
    }

    preOrder& operator++() {
        if (!stack.empty()) { // If the stack is not empty
            rootTree = stack.top(); // Get the top of the stack
            stack.pop(); // Pop the top of the stack
            for (auto it = rootTree->get_childrenNodes().rbegin(); it != rootTree->get_childrenNodes().rend(); ++it) {
                stack.push(*it); // Push the child to the stack
            }
            if (!stack.empty()) { // If the stack is not empty
                rootTree = stack.top(); // Get the top of the stack
            } else {
                rootTree = nullptr; // Set the root to null
            }
        } else {
            rootTree = nullptr;
        }
        return *this;
    }

    T& operator*() {
        return rootTree->get_data(); // Access data of current node
    }

    bool operator!=(const preOrder& other) const {
        return rootTree != other.rootTree; // Return true if the roots are not equal
    }

    bool operator==(const preOrder& other) const {
        return rootTree == other.rootTree; // Return true if the roots are equal
    }

    Node<T>* operator->() {
        return rootTree;
    }
};
