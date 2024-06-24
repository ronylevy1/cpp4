#pragma once

#include <vector>

#include "node.hpp"

template <typename T>

class inOrder{
    private:
        Node<T> *_root; // Root of the tree
        std::vector<Node<T>*> stack; // Stack to store the nodes
    
    public:
        inOrder(Node<T>* root): _root(root){} // Constructor

    Node<T> *get_root(){
        return _root;
    }

     inOrder& operator++() {
        if (!stack.empty()) {
            Node<T>* current = stack.back();
            stack.pop_back();
            
            // Move to the right child and push all left children onto the stack
            if (!current->get_children().empty()) {
                current = current->get_children().front();
                while (current) {
                    stack.push_back(current);
                    current = current->get_children().empty() ? nullptr : current->get_children().front();
                }
            }

            _root = stack.empty() ? nullptr : stack.back();
        } else {
            _root = nullptr;
        }
        return *this;
    }


    Node<T> &operator*(){
        return *_root; // Return the root
    }

    bool operator!=(const inOrder &other){
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const inOrder &other){
        return _root == other._root; // Return true if the roots are equal
    }

    Node<T>* operator->(){
        return _root;
    }

};