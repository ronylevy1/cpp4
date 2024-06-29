//Roniki04@gmail.com
#include "bfs.hpp"
#include "dfs.hpp"
#include "inOrder.hpp"
#include "myComplex.hpp"
#include "myHeap.hpp"
#include "node.hpp"
#include "postOrder.hpp"
#include "preOrder.hpp"
#include "tree.hpp"
#include "doctest.h"

#include <iostream>
#include <sstream>

// Test for preOrder
TEST_CASE("Testing preOrder - int") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    std::vector<int> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
}

TEST_CASE("Testing preOrder - double"){
    Node<double> root_node(1.1);

    Node<double> n1(2.2);
    Node<double> n2(3.3);
    Node<double> n3(4.4);
    Node<double> n4(5.5);
    Node<double> n5(6.6);
    Node<double> n6(7.7);
    Node<double> n7(8.8);

    Tree<double,4> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&root_node, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);
    tree.add_sub_node(&n3, &n6);
    tree.add_sub_node(&n3, &n7);

    std::vector<double> expected = {1.1, 2.2, 5.5, 3.3, 6.6, 4.4, 7.7, 8.8};
    std::vector<double> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back(node->get_value());
    }
    CHECK(result == expected);
 
}

TEST_CASE("Testing preOrder - string"){
    Node<std::string> root_node("yuvi");

    Node<std::string> n1("rony");
    Node<std::string> n2("liat");
    Node<std::string> n3("michael");
    Node<std::string> n4("shai");
    Node<std::string> n5("chanan");

    Tree<std::string,5> tree; 
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<std::string> expected = {"yuvi", "rony", "michael", "shai", "liat", "chanan"};
    std::vector<std::string> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back(node->get_value());
    }
    CHECK(result == expected);
}

TEST_CASE("Testing preOrder - myComplex"){
    Node<MyComplex> root_node(MyComplex(1, 1));

    Node<MyComplex> n1(MyComplex(2, 2));
    Node<MyComplex> n2(MyComplex(3, 3));
    Node<MyComplex> n3(MyComplex(4, 4));
    Node<MyComplex> n4(MyComplex(5, 5));
    Node<MyComplex> n5(MyComplex(6, 6));

    Tree<MyComplex,3> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<MyComplex> expected = {MyComplex(1, 1), MyComplex(2, 2), MyComplex(4, 4), MyComplex(5, 5), MyComplex(3, 3), MyComplex(6, 6)};
    std::vector<MyComplex> result;

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
}


// Test for postOrder
TEST_CASE("Testing postOrder") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<int> expected = {4, 5, 2, 6, 3, 1};
    std::vector<int> result;

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
}



// Test for inOrder
TEST_CASE("Testing inOrder") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<int> expected = {4, 2, 5, 1, 6, 3};
    std::vector<int> result;

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
}


// Test for myHeap
TEST_CASE("Testing myHeap") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    myHeap<int> heap = tree.MyHeap();

    std::vector<int> expected = {1, 2, 3};
    std::vector<int> result;

    for (int i = 0; i < 3; ++i) {
        result.push_back(heap->get_value());
        ++heap;
    }

    CHECK(result == expected);
}

// Test for MyComplex
TEST_CASE("Testing MyComplex") {
    MyComplex c1(1, 2);
    MyComplex c2(3, 4);

    CHECK(c1.getReal() == 1);
    CHECK(c1.getImag() == 2);

    MyComplex c3 = c1 + c2;
    CHECK(c3.getReal() == 4);
    CHECK(c3.getImag() == 6);

    MyComplex c4 = c1 - c2;
    CHECK(c4.getReal() == -2);
    CHECK(c4.getImag() == -2);

    MyComplex c5 = c1 * c2;
    CHECK(c5.getReal() == -5);
    CHECK(c5.getImag() == 10);

    MyComplex c6 = c1 / c2;
    CHECK(c6.getReal() == doctest::Approx(0.44).epsilon(0.01));
    CHECK(c6.getImag() == doctest::Approx(0.08).epsilon(0.01));

    CHECK(c1 != c2);
    CHECK(c1 == MyComplex(1, 2));
}

// Test for Node
TEST_CASE("Testing Node") {
    Node<int> node(1);
    CHECK(node.get_data() == 1);

    node.set_data(2);
    CHECK(node.get_data() == 2);
}

// Test for Tree
TEST_CASE("Testing Tree") {
    Node<int> root_node(1);
    Tree<int,3> tree;

    tree.add_root(&root_node);
    CHECK(tree.get_root()->get_value() == 1);

    Node<int> n1(2);
    Node<int> n2(3);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);

    CHECK(tree.get_root()->get_childrenNodes().size() == 2);
}

// Test for dfs
TEST_CASE("Testing dfs") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    Tree<int,3> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<int> expected = {1, 2, 4, 5, 3, 6};
    std::vector<int> result;

    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
}

// Test for bfs
TEST_CASE("Testing bfs") {
    Node<int> root_node(1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    
    Tree<int,3> tree;
    tree.add_root(&root_node);

    tree.add_sub_node(&root_node, &n1);
    tree.add_sub_node(&root_node, &n2);
    tree.add_sub_node(&n1, &n3);
    tree.add_sub_node(&n1, &n4);
    tree.add_sub_node(&n2, &n5);

    std::vector<int> expected = {1, 2, 3, 4, 5, 6};
    std::vector<int> result;

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result.push_back(node->get_value());
    }

    CHECK(result == expected);
   // tree.display();
}
