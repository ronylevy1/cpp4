
#pragma once

#include <stack>
#include "node.hpp"

template <typename T>
class inOrder {
private:
    Node<T>* _root; // Root of the tree
    std::stack<Node<T>*> stack; // Stack to store the nodes
    //Node<T>* current;

    void pushLeft(Node<T>* node) {
        while (node) {
            stack.push(node);
            if (!node->get_children().empty()) {
                node = node->get_children().front();
            } else {
                break;
            }
        }
    }

public:
    inOrder(Node<T>* root) : _root(root) {
        pushLeft(_root);
        if (!stack.empty()) {
            _root = stack.top();
        }
    }

    Node<T>* get_root() {
        return _root;
    }

    inOrder& operator++() {
        if (stack.empty()) {
            _root = nullptr;
            return *this;
        }

        Node<T>* node = stack.top();
        stack.pop();

        if (node) {
            auto& children = node->get_children();
            if (children.size() > 1) {
                pushLeft(children[1]); // Push the leftmost nodes of the right subtree
            }
        }

        if (!stack.empty()) {
            _root = stack.top();
        } else {
            _root = nullptr;
        }

        return *this;
    }

    Node<T>& operator*() {
        return *_root; // Return the current node
    }

    bool operator!=(const inOrder& other) {
        return _root != other._root; // Return true if the current nodes are not equal
    }

    bool operator==(const inOrder& other) {
        return _root == other._root; // Return true if the current nodes are equal
    }

    Node<T>* operator->() {
        return _root;
    }
};
