//Roniki04@gmail.com
#pragma once

#include <stack>

#include "node.hpp"

template <typename T>

class preOrder {
   private:
    Node<T>* _root;              // Root of the tree
    std::stack<Node<T>*> stack;  // Stack to store the nodes

   public:
    preOrder(Node<T>* root) : _root(root) {  // Constructor
        if (_root) {
            stack.push(_root);
        }
    }

    Node<T>* get_root() const {
        return _root;
    }

    preOrder& operator++() {
        if (!stack.empty()) {
            _root = stack.top();
            stack.pop();
            for (auto it = _root->get_children().rbegin(); it != _root->get_children().rend(); ++it) {
                stack.push(*it);
            }
            if (!stack.empty()) {
                _root = stack.top();
            } else {
                _root = nullptr;
            }
        } else {
            _root = nullptr;
        }
        return *this;
    }

    T& operator*() {
        return _root->get_data();  // Access data of current node
    }

    bool operator!=(const preOrder& other) const {
        return _root != other._root;  // Return true if the roots are not equal
    }

    bool operator==(const preOrder& other) const {
        return _root == other._root;  // Return true if the roots are equal
    }

    Node<T>* operator->() {
        return _root;
    }
};
