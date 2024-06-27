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
        while (node) {
            myStack.push(node);
            if (!node->get_children().empty()) {
                node = node->get_children().front();
            } else {
                break;
            }
        }
    }

public:
    inOrder(Node<T>* root) : rootTree(root) {
        pushLeft(rootTree);
        if (!myStack.empty()) {
            rootTree = myStack.top();
        }
    }

    Node<T>* get_root() {
        return rootTree;
    }

    inOrder& operator++() {
        if (myStack.empty()) {
            rootTree = nullptr;
            return *this;
        }

        Node<T>* node = myStack.top();
        myStack.pop();

        if (node) {
            auto& children = node->get_children();
            if (children.size() > 1) {
                pushLeft(children[1]); // Push the leftmost nodes of the right subtree
            }
        }

        if (!myStack.empty()) {
            rootTree = myStack.top();
        } else {
            rootTree = nullptr;
        }

        return *this;
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
