//Roniki04@gmail.com
#pragma once

#include <stack>
#include "node.hpp"

template <typename T>
class inOrder {
private:
    Node<T>* rootTree; // Root of the tree
    std::stack<Node<T>*> myStack; // Stack to store the nodes

    void pushLeft(Node<T>* node) {
        while (node) { // While the node is not null
            myStack.push(node); // Push the node to the stack
            if (!node->get_childrenNodes().empty()) { // If the node has children
                node = node->get_childrenNodes().front(); // Get the first child
            } else { // If the node does not have children
                break; // Break the loop
            }
        }
    }

public:
    inOrder(Node<T>* root) : rootTree(root) { // Constructor
        pushLeft(rootTree); // Push the leftmost nodes of the tree
        if (!myStack.empty()) { // If the stack is not empty
            rootTree = myStack.top(); // Get the top of the stack
        }
    }

    Node<T>* get_root() {
        return rootTree;
    }

    inOrder& operator++() {
        if (myStack.empty()) { // If the stack is empty
            rootTree = nullptr; // Set the root to null
            return *this; // Return the object
        }

        Node<T>* node = myStack.top(); // Get the top of the stack
        myStack.pop(); // Pop the top of the stack

        if (node) { // If the node is not null
            auto& children = node->get_childrenNodes(); // Get the children of the node
            if (children.size() > 1) { // If the node has more than one child
                pushLeft(children[1]); // Push the leftmost nodes of the right subtree
            }
        }

        if (!myStack.empty()) { // If the stack is not empty
            rootTree = myStack.top(); // Get the top of the stack
        } else {
            rootTree = nullptr; // Set the root to null
        }

        return *this; // Return the object
    }

    Node<T>& operator*() {
        return *rootTree; // Return the current node
    }

    bool operator!=(const inOrder& other) {
        return rootTree != other.rootTree; // Return true if the current nodes are not equal
    }

    bool operator==(const inOrder& other) {
        return rootTree == other.rootTree; // Return true if the current nodes are equal
    }

    Node<T>* operator->() {
        return rootTree;
    }
};
