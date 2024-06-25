
#pragma once

#include <stack>
#include "node.hpp"

template <typename T>
class postOrder {
private:
    Node<T>* _root;               // Current node in the traversal
    std::stack<Node<T>*> stack;  // Vector to store the nodes

    void init(Node<T>* node) {
        if (node) {
            stack.push(node);
            for (auto it = node->get_children().rbegin(); it != node->get_children().rend(); ++it) {
                init(*it);
            }
        }
    }

public:
    postOrder(Node<T>* root) : _root(nullptr) {
        if (root) {
            init(root);
            _root = stack.top();
        }
    }

    Node<T>* get_root() const {
        return _root;
    }

    postOrder& operator++() {
    if (!stack.empty()) {
        stack.pop();
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


    Node<T>& operator*() {
        return *_root;
    }

    bool operator!=(const postOrder& other) const {
        return _root != other._root;
    }

    bool operator==(const postOrder& other) const {
        return _root == other._root;
    }

    Node<T>* operator->() {
        return _root;
    }
    
};
