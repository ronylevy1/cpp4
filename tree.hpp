// #pragma once

// #include <iostream>

// #include "preOrder.hpp"
// #include "postOrder.hpp"
// #include "inOrder.hpp"
// #include "bfs.hpp"
// #include "dfs.hpp"
// #include "myHeap.hpp"

// template <typename T>

// class Tree{
//     private:
//         Node<T> *_root; // Root of the tree
//         size_t _k; // Degree of the tree

//     public:
//     Tree(size_t k = 2): _root(nullptr), _k(k) {} // Constructor

//     // Constructor and Destructor
//     // ~Tree(){
//     //     if(_root){
//     //         for(auto child : _root->get_children()){
//     //             delete (child);
//     //         }
//     //         delete _root;
//     //     }
//     // }

//     void add_root(Node<T>* root){ // Add root to the tree
//         _root = root; // Set the root of the tree
//     }

//     void add_sub_node(Node<T>* parent, Node<T>* child){
//         if(parent->get_children().size() < _k){ // If the parent has less than k children
//             parent->add_child(child); // Add child to the parent
//         }
//         else{ // print error message if the parent has k children
//             std::cout << "The parent has " << _k << " children" << std::endl;
//         }
//     }

//     preOrder<T> end_pre_order(){
//         return preOrder<T>(nullptr); // End pre-order traversal
//     }
//     preOrder<T> begin_pre_order(){
//         return preOrder<T>(_root); // Begin pre-order traversal
//     }

//     postOrder<T> end_post_order(){
//         return postOrder<T>(nullptr); // End post-order traversal
//     }
//     postOrder<T> begin_post_order(){
//         return postOrder<T>(_root); // Begin post-order traversal
//     }

//     inOrder<T> end_in_order(){
//         return inOrder<T>(nullptr); // End in-order traversal
//     }
//     inOrder<T> begin_in_order(){
//         return inOrder<T>(_root); // Begin in-order traversal
//     }

//     bfs<T> end_bfs_scan(){
//         return bfs<T>(nullptr); // End BFS scan
//     }

//     bfs<T> begin_bfs_scan(){
//         return bfs<T>(_root); // Begin BFS scan
//     }

//     dfs<T> end_dfs_scan(){
//         return dfs<T>(nullptr); // End DFS scan
//     }
//     dfs<T> begin_dfs_scan(){
//         return dfs<T>(_root); // Begin DFS scan
//     }

//     myHeap<T> creatMyHeap(){
//         return myHeap<T>(_root); // Return the heap
//     }

// };


#include <SFML/Graphics.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "bfs.hpp"
#include "dfs.hpp"
#include "inOrder.hpp"
#include "myHeap.hpp"
#include "node.hpp"
#include "postOrder.hpp"
#include "preOrder.hpp"


template <typename T>
class Tree {
private:
    Node<T>* _root;  // Root of the tree
    size_t _k;       // Degree of the tree
    sf::Font _font;  // Font object for SFML

     void loadFont() {
        // Using a known good font path for Linux systems
        std::string fontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";  

        if (!_font.loadFromFile(fontPath)) {
            std::cout << "Failed to load font from path: " << fontPath << std::endl;
        }
    }

    void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float offsetX, float offsetY) {
        if (node == nullptr) return;

        // Draw the node circle
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::Red);  // Set circle color to red
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw the node value using loaded font inside the circle
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(1) << node->get_data();  // Format the data with 1 decimal place
        sf::Text text(ss.str(), _font, 15);                            // Create text with loaded font
        text.setFillColor(sf::Color::White);                           // Set text color to white

        // Center text inside the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());

        window.draw(text);

        // Draw the children
        auto children = node->get_children();
        for (size_t i = 0; i < children.size(); ++i) {
            float newX = x + (i - children.size() / 2.0) * offsetX;
            float newY = y + offsetY;

            // Draw line to child
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Green),  // Set line color to green
                sf::Vertex(sf::Vector2f(newX + 20, newY + 20), sf::Color::Green)
            };
            window.draw(line, 2, sf::Lines);

            // Recursively draw child nodes
            drawNode(window, children[i], newX, newY, offsetX / 2, offsetY);
        }
    }

public:
    Tree(size_t k = 2) : _root(nullptr), _k(k) {
        loadFont();  // Load the font when creating the object
    }

    void add_root(Node<T>* root) {
        _root = root;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_children().size() < _k) {
            parent->add_child(child);
        } else {
            std::cout << "The parent has " << _k << " children" << std::endl;
        }
    }

    preOrder<T> end_pre_order() {
        return preOrder<T>(nullptr);
    }

    preOrder<T> begin_pre_order() {
        return preOrder<T>(_root);
    }

    postOrder<T> end_post_order() {
        return postOrder<T>(nullptr);
    }

    postOrder<T> begin_post_order() {
        return postOrder<T>(_root);
    }

    inOrder<T> end_in_order() {
        return inOrder<T>(nullptr);
    }

    inOrder<T> begin_in_order() {
        return inOrder<T>(_root);
    }

    bfs<T> end_bfs_scan() {
        return bfs<T>(nullptr);
    }

    bfs<T> begin_bfs_scan() {
        return bfs<T>(_root);
    }

    dfs<T> end_dfs_scan() {
        return dfs<T>(nullptr);
    }

    dfs<T> begin_dfs_scan() {
        return dfs<T>(_root);
    }

    myHeap<T> creatMyHeap() {
        return myHeap<T>(_root);
    }

    void display() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::Black);
            if (_root) {
                drawNode(window, _root, 400, 50, 200, 100);
            }
            window.display();
        }
    }
};
