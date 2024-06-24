#pragma once

#include <vector>

#include "node.hpp"

template <typename T>

class postOrder{
    private:
        Node<T> *_root; // Root of the tree
        std::vector<Node<T>*> stack; // Stack to store the nodes
    
    public:
        postOrder(Node<T>* root): _root(root){} // Constructor

    Node<T> *get_root(){
        return _root;
    }

    postOrder& operator++() {
        while (!stack.empty()) {
            _root = stack.back();
            stack.pop_back();
            for (auto child : _root->get_children()) {
                stack.push_back(child);
            }
            return *this;
        }
        _root = nullptr;
        return *this;
    }

    Node<T> &operator*(){
        return *_root; // Return the root
    }

    bool operator!=(const postOrder &other){
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const postOrder &other){
        return _root == other._root; // Return true if the roots are equal
    }

    Node<T>* operator->(){
        return _root;
    }

};
