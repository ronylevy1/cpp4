#pragma once
#include "node.hpp"

template <typename T>

class myHeap{
    private:
        Node<T> *_root; // Root of the tree 
    
    public:
        myHeap(Node<T>* root): _root(root){} // Constructor

    Node<T> *get_root(){
        return _root;
    }

    myHeap &operator++(){
        if(_root->get_children().empty()){
            _root = nullptr;
        } else {
            _root = _root->get_children().front();
        }
        return *this;
    }

    Node<T> &operator*(){
        return *_root; // Return the root
    }

    bool operator!=(const myHeap &other){
        return _root != other._root; // Return true if the roots are not equal
    }

    bool operator==(const myHeap &other){
        return _root == other._root; // Return true if the roots are equal
    }

    Node<T>* operator->(){
        return _root;
    }
};