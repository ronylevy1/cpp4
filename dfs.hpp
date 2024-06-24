#pragma once

#include <vector>

#include "node.hpp"

template <typename T>

class dfs{
    private:
        Node<T> *_root; // Root of the tree
        std::vector<Node<T>*> stack; // Stack to store the nodes

    public:
        dfs(Node<T>* root): _root(root){} // Constructor

    Node<T> *get_root(){
        return _root;
    }

    dfs& operator++() {
        while (!stack.empty()) {
            _root = stack.back();
            stack.pop_back();
            for (auto it = _root->get_children().rbegin(); it != _root->get_children().rend(); ++it) {
                stack.push_back(*it);
            }
            return *this;
        }
        _root = nullptr;
        return *this;
    }

    Node<T> &operator*(){
        return *_root; // Return the root
    }

    bool operator!=(const dfs &other){
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const dfs &other){
        return _root == other._root; // Return true if the roots are equal
    }

    Node<T>* operator->(){
        return _root;
    }

};

