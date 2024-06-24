#pragma once

#include <vector>

#include "node.hpp"

template <typename T>

class preOrder {
   private:
    Node<T>* _root;               // Root of the tree
    std::vector<Node<T>*> stack;  // Stack to store the nodes

   public:
    // preOrder(Node<T>* root) : _root(root) {  // Constructor
    //     if (_root) {
    //         stack.push_back(_root);
    //     }
    // }

    // Node<T>* get_root() const {
    //     return _root;
    // }

    // preOrder& operator++() {
    //     if (!stack.empty()) {
    //         _root = stack.back();
    //         std::cout << "Current: " << _root->get_data() << std::endl;

    //         stack.pop_back();
    //         for (auto it = _root->get_children().rbegin(); it != _root->get_children().rend(); ++it) {
    //             stack.push_back(*it);
    //             std::cout << "Pushed: " << (*it)->get_data() << std::endl;
    //         }
    //     } else {
    //         _root = nullptr;
    //     }
    //     return *this;
    // }

    preOrder(Node<T>* root) : _root(root) {  // Constructor
        if (_root) {
            stack.push_back(_root);
        }
    }

    Node<T>* get_root() const {
        return _root;
    }

    preOrder& operator++() {
        if (!stack.empty()) {
            _root = stack.back();
            stack.pop_back();
            for (auto it = _root->get_children().rbegin(); it != _root->get_children().rend(); ++it) {
                if(*it)
                    stack.push_back(*it);
            }
            if (!stack.empty()) {
                _root = stack.back();
            }
            else
            {
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
