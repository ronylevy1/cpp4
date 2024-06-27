//Roniki04@gmail.com
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

#include "myComplex.hpp"


int main() {
    // Create root node
    Node<MyComplex> root_node(MyComplex(1,1));
    // Create additional nodes
    Node<MyComplex> n1(MyComplex(2,2));
    Node<MyComplex> n2(MyComplex(3,3));
    Node<MyComplex> n3(MyComplex(4,4));
    Node<MyComplex> n4(MyComplex(5,5));
    Node<MyComplex> n5(MyComplex(6,6));
    // Node<MyComplex> n6(MyComplex(7,7));
    // Node<MyComplex> n7(MyComplex(8,8));
    

    Tree<MyComplex> tree;

    // Set root node
    tree.add_root(&root_node);

    // Add nodes to the tree
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    // tree.add_sub_node(&root_node, &n3);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    // tree.add_sub_node(&n3, &n6);

    // Print tree nodes in different orders
    std::cout << "Pre-order traversal:" << std::endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    std::cout << "Post-order traversal:" << std::endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    std::cout << "In-order traversal:" << std::endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    std::cout << "Breadth-first traversal:" << std::endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    std::cout << "Depth-first traversal:" << std::endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        std::cout << node->get_value() << std::endl;
    } //1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    std::cout << "My-Heap traversal:" << std::endl;
    for (auto node = tree.MyHeap().begin(); node != tree.MyHeap().end(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.1, 1.2, 1.3, 1.4, 1.5, 1.6


    // Display the tree using GUI
    tree.display();

    return 0;
}
