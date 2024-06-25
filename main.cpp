// #include <iostream>
// #include <string>
// #include <SFML/Graphics.hpp>
// #include "node.hpp"
// #include "tree.hpp"

// using namespace std;

// int main() {
//     Node<double> root_node = Node<double>(1.1);
//     Tree<double> tree; // Binary tree that contains doubles.
//     tree.add_root(&root_node);
//     Node<double> n1 = Node<double>(1.2);
//     Node<double> n2 = Node<double>(1.3);
//     Node<double> n3 = Node<double>(1.4);
//     Node<double> n4 = Node<double>(1.5);
//     Node<double> n5 = Node<double>(1.6);

//     tree.add_sub_node(&root_node, &n1);
//     tree.add_sub_node(&root_node, &n2);
//     tree.add_sub_node(&n1, &n3);
//     tree.add_sub_node(&n1, &n4);
//     tree.add_sub_node(&n2, &n5);

//     // Print tree nodes in different orders
//     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

//     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

//     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

//     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     // Display the tree using GUI
//     tree.display();

//     return 0;
// }


#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

#include "myComplex.hpp"


int main() {
    // Create tree nodes
    // Node<double> root_node(1.1);
    // Tree<double> tree;

    // // Set root node
    // tree.add_root(&root_node);

    // // Create additional nodes
    // Node<double> n1(1.2);
    // Node<double> n2(1.3);
    // Node<double> n3(1.4);
    // Node<double> n4(1.5);
    // Node<double> n5(1.6);

    // // Add nodes to the tree
    // tree.add_sub_node(&root_node, &n1);
    // tree.add_sub_node(&root_node, &n2);
    // tree.add_sub_node(&n1, &n3);
    // tree.add_sub_node(&n1, &n4);
    // tree.add_sub_node(&n2, &n5);


    // Node<int> root_node(1);
    // Tree<int> tree(3);

    // // Set root node
    // tree.add_root(&root_node);

    // // Create additional nodes
    // Node<int> n1(2);
    // Node<int> n2(3);
    // Node<int> n3(4);
    // Node<int> n4(5);
    // Node<int> n5(6);
    // Node<int> n6(7);
    // Node<int> n7(8);

    // // Add nodes to the tree
    // tree.add_sub_node(&root_node, &n1);
    // tree.add_sub_node(&root_node, &n2);
    // tree.add_sub_node(&root_node, &n7); 
    // tree.add_sub_node(&n1, &n3);
    // tree.add_sub_node(&n1, &n4);
    // tree.add_sub_node(&n2, &n5);
    // tree.add_sub_node(&n2, &n6);


    // Node<std::string> root_node("root");
    // Tree<std::string> tree;

    // // Set root node
    // tree.add_root(&root_node);

    // // Create additional nodes
    // Node<std::string> n1("rony");
    // Node<std::string> n2("liat");
    // Node<std::string> n3("micahel");
    // Node<std::string> n4("david");
    // Node<std::string> n5("shir");

    // // Add nodes to the tree
    // tree.add_sub_node(&root_node, &n1);
    // tree.add_sub_node(&root_node, &n2);
    // tree.add_sub_node(&n1, &n3);
    // tree.add_sub_node(&n1, &n4);
    // tree.add_sub_node(&n2, &n5);


    Node<MyComplex> root_node(MyComplex(1.3,3));
    Tree<MyComplex> tree;

    // Set root node
    tree.add_root(&root_node);

    // Create additional nodes
    Node<MyComplex> n1(MyComplex(1,2));
    Node<MyComplex> n2(MyComplex(1,6));
    Node<MyComplex> n3(MyComplex(1,4));
    Node<MyComplex> n4(MyComplex(1,5));
    Node<MyComplex> n5(MyComplex(1,3));

    // Add nodes to the tree
    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);


    

    //tree.display();

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
    for (auto node = tree.creatMyHeap(); node != tree.creatMyHeap(); ++node) {
        std::cout << node->get_value() << std::endl;
    } // 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    // Display the tree using GUI
    tree.display();

    return 0;
}
