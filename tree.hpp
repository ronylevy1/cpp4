// Roniki04@gmail.com
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

template <typename T, size_t k = 2>
class Tree {
   private:
    Node<T>* rootTree;  // Root of the tree
    sf::Font fontObj;   // Font object for SFML

    void loadFont() {
        // Using a known good font path for Linux systems
        std::string fontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

        if (!fontObj.loadFromFile(fontPath)) {
            std::cout << "Failed to load font from path: " << fontPath << std::endl;
        }
    }

    void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float offsetX, float offsetY) {
        if (node == nullptr) return;  // If the node is null, return

        // Draw the node circle
        sf::CircleShape circle(24);
        circle.setFillColor(sf::Color(255, 179, 71));  // Set circle color to oreng
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw the node value using loaded font inside the circle
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(1) << node->get_data();  // Format the data with 1 decimal place
        sf::Text text(ss.str(), fontObj, 14);                          // Create text with loaded font
        text.setFillColor(sf::Color::Black);                           // Set text color to black

        // Center text inside the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());

        window.draw(text);

        // Draw the children
        auto children = node->get_childrenNodes();
        for (size_t i = 0; i < children.size(); ++i) {
            float newX = x + (i - children.size() / 2.0) * offsetX;
            float newY = y + offsetY;

            // Draw line to child
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Green),  // Set line color to green
                    sf::Vertex(sf::Vector2f(newX + 20, newY + 20), sf::Color::Green)};
            window.draw(line, 2, sf::Lines);

            // Recursively draw child nodes
            drawNode(window, children[i], newX, newY, offsetX / 2, offsetY);
        }
    }

   public:
    Tree() : rootTree(nullptr) {
        std::cout << "k-ary tree" << std::endl;
        loadFont();  // Load the font when creating the object
    }

    void add_root(Node<T>* root) {
        rootTree = root;
    }
    Node<T>* get_root() {
        return rootTree;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_childrenNodes().size() < k) {  // If the parent has less than k children
            parent->add_child(child);                  // Add the child to the parent
        } else {
            std::cout << "The parent has " << k << " children" << std::endl;
        }
    }

    dfs<T> end_pre_order() {  // End of pre-order traversal
        return dfs<T>(nullptr);
    }

    dfs<T> begin_pre_order() {  // Begin of pre-order traversal
        return dfs<T>(rootTree);
    }

    dfs<T> end_post_order() {  // End of post-order traversal
        return dfs<T>(nullptr);
    }

    dfs<T> begin_post_order() {  // Begin of post-order traversal
        return dfs<T>(rootTree);
    }

    dfs<T> end_in_order() {  // End of in-order traversal
        return dfs<T>(nullptr);
    }

    dfs<T> begin_in_order() {  // Begin of in-order traversal
        return dfs<T>(rootTree);
    }

    bfs<T> end_bfs_scan() {  // End of breadth-first scan
        return bfs<T>(nullptr);
    }

    bfs<T> begin_bfs_scan() {  // Begin of breadth-first scan
        return bfs<T>(rootTree);
    }

    dfs<T> end_dfs_scan() {  // End of depth-first scan
        return dfs<T>(nullptr);
    }

    dfs<T> begin_dfs_scan() {  // Begin of depth-first scan
        return dfs<T>(rootTree);
    }

    myHeap<T> MyHeap() {  // Create a heap from the tree
        return myHeap<T>(rootTree);
    }

    void display() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::White);  // Set background color to white
            if (rootTree) {
                drawNode(window, rootTree, 400, 50, 200, 100);
            }
            window.display();
        }
    }

    ~Tree() {
        dfs<T> current = begin_dfs_scan();
        dfs<T> to_del = current;   
        dfs<T> last = end_dfs_scan();      
        while (current != last) {
            to_del = current;
            ++current;
            to_del->get_childrenNodes().clear();  
        }
        rootTree = nullptr;
    }
};

template <typename T>
class Tree<T, 2> {  // Specific for binary tree
   private:
    Node<T>* rootTree;  // Root of the tree
    sf::Font fontObj;   // Font object for SFML

    void loadFont() {
        // Using a known good font path for Linux systems
        std::string fontPath = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";

        if (!fontObj.loadFromFile(fontPath)) {
            std::cout << "Failed to load font from path: " << fontPath << std::endl;
        }
    }

    void drawNode(sf::RenderWindow& window, Node<T>* node, float x, float y, float offsetX, float offsetY) {
        if (node == nullptr) return;

        // Draw the node circle
        sf::CircleShape circle(24);
        circle.setFillColor(sf::Color(255, 179, 71));  // Set circle color to oreng
        circle.setPosition(x, y);
        window.draw(circle);

        // Draw the node value using loaded font inside the circle
        std::ostringstream ss;
        ss << std::fixed << std::setprecision(1) << node->get_data();  // Format the data with 1 decimal place
        sf::Text text(ss.str(), fontObj, 14);                          // Create text with loaded font
        text.setFillColor(sf::Color::Black);                           // Set text color to black

        // Center text inside the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(), circle.getPosition().y + circle.getRadius());

        window.draw(text);

        // Draw the children
        auto children = node->get_childrenNodes();
        for (size_t i = 0; i < children.size(); ++i) {
            float newX = x + (i - children.size() / 2.0) * offsetX;
            float newY = y + offsetY;

            // Draw line to child
            sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + 20, y + 20), sf::Color::Green),  // Set line color to green
                    sf::Vertex(sf::Vector2f(newX + 20, newY + 20), sf::Color::Green)};
            window.draw(line, 2, sf::Lines);

            // Recursively draw child nodes
            drawNode(window, children[i], newX, newY, offsetX / 2, offsetY);
        }
    }

   public:
    Tree() : rootTree(nullptr) {
        std::cout << "binary tree" << std::endl;
        loadFont();  // Load the font when creating the object
    }

    void add_root(Node<T>* root) {
        rootTree = root;
    }
    Node<T>* get_root() {
        return rootTree;
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        if (parent->get_childrenNodes().size() < 2) {  // If the parent has less than 2 children
            parent->add_child(child);                  // Add the child to the parent
        } else {
            std::cout << "The parent has 2 children" << std::endl;
        }
    }

    preOrder<T> end_pre_order() {  // End of pre-order traversal
        return preOrder<T>(nullptr);
    }

    preOrder<T> begin_pre_order() {  // Begin of pre-order traversal
        return preOrder<T>(rootTree);
    }

    postOrder<T> end_post_order() {  // End of post-order traversal
        return postOrder<T>(nullptr);
    }

    postOrder<T> begin_post_order() {  // Begin of post-order traversal
        return postOrder<T>(rootTree);
    }

    inOrder<T> end_in_order() {  // End of in-order traversal
        return inOrder<T>(nullptr);
    }

    inOrder<T> begin_in_order() {  // Begin of in-order traversal
        return inOrder<T>(rootTree);
    }

    bfs<T> end_bfs_scan() {  // End of breadth-first scan
        return bfs<T>(nullptr);
    }

    bfs<T> begin_bfs_scan() {  // Begin of breadth-first scan
        return bfs<T>(rootTree);
    }

    dfs<T> end_dfs_scan() {  // End of depth-first scan
        return dfs<T>(nullptr);
    }

    dfs<T> begin_dfs_scan() {  // Begin of depth-first scan
        return dfs<T>(rootTree);
    }

    myHeap<T> MyHeap() {  // Create a heap from the tree
        return myHeap<T>(rootTree);
    }

    void display() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color::White);  // Set background color to white
            if (rootTree) {
                drawNode(window, rootTree, 400, 50, 200, 100);
            }
            window.display();
        }
    }

    ~Tree() {
        dfs<T> current = begin_dfs_scan();  
        dfs<T> to_del = current;            
        dfs<T> last = end_dfs_scan();      
        while (current != last) {
            to_del = current;
            ++current;
            to_del->get_childrenNodes().clear();  
        }
        rootTree = nullptr;
    }
};
