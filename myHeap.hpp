//Roniki04@gmail.com
#pragma once
#include "node.hpp"
#include <vector>
#include <queue>
#include <iostream>

template <typename T>
class myHeap {
private:
    Node<T>* _root; // Root of the tree
    std::queue<Node<T>*> nodes_queue; // Queue for level-order traversal

public:
    // Constructor
    myHeap(Node<T>* root) : _root(root) {
        if (_root) {
            nodes_queue.push(_root);
        }
    }

    Node<T>* get_root() const {
        return _root;
    }

    myHeap& operator++() {
        if (!nodes_queue.empty()) {
            Node<T>* current = nodes_queue.front();
            nodes_queue.pop();
            for (auto child : current->get_children()) {
                nodes_queue.push(child);
            }
            if (!nodes_queue.empty()) {
                _root = nodes_queue.front();
            } else {
                _root = nullptr;
            }
        } else {
            _root = nullptr;
        }
        return *this;
    }

    T& operator*() {
        return _root->get_data(); // Access data of current node
    }

    bool operator!=(const myHeap& other) const {
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const myHeap& other) const {
        return _root == other._root; // Return true if the roots are equal
    }

    Node<T>* operator->() {
        return _root;
    }

    static myHeap makeheap(const std::vector<T>& values) {
        if (values.empty()) {
            return myHeap(nullptr);
        }

        Node<T>* root = new Node<T>(values[0]);
        std::queue<Node<T>*> nodes;
        nodes.push(root);

        for (size_t i = 1; i < values.size(); ++i) {
            Node<T>* node = new Node<T>(values[i]);
            if (!nodes.empty()) {
                Node<T>* parent = nodes.front();
                parent->add_child(node);
                nodes.push(node);
                if (parent->get_children().size() == 2) {
                    nodes.pop();
                }
            }
        }

        return myHeap(root);
    }

    myHeap begin() {
        return myHeap(_root);
    }

    myHeap end() {
        return myHeap(nullptr);
    }
};
