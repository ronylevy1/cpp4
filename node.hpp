//Roniki04@gmail.com
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

template <typename T>

class Node{
    private:
        T data;
        std::vector<Node<T>*> children; // Vector to store children nodes

    public:
        Node(const T& data): data(data){} // Constructor
    
        void set_data(T data){ // Set data
            this->data = data;        
        } 
         T get_data() const{
            return data; // Get data
        }  

        void add_child(Node<T>* child) {
            children.push_back(child);
        }

        T& get_value(){
            return data; // Return the current object
        }

        std::vector<Node<T>*>& get_children(){
            return children; // Return the children
        }

};