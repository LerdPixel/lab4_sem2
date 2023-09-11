#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <gtest/gtest.h>
#include <string>
#include "../DynamicArray.h"
#include "../LinkedList.h"
#include "../binarytree.hpp"

struct BinaryTreeTests : public testing::Test {
    BinaryTree<int> ab;
    BinaryTree<int> ab2;
    BinaryTree<int> bb;
    BinaryTree<int> cb;
    BinaryTree<int> oo;
    BinaryTree<int> a213;
    void SetUp() {
        int e [] {2,1,3};
        a213 = BinaryTree(LinkedList(e, 3));
        int b[] {8,3,10,1,6,14,4,7,13};
        ab = BinaryTree(LinkedList(b, 9));
        ab2 = BinaryTree(LinkedList(b, 9));
        int a[] {3, 1, 6, 8, 4};
        bb = BinaryTree(LinkedList(a, 5));
        cb.insert(5);
        double c[] {5};
        double d[] {1, 2, 3, 5, 4, 6};
    }
    void TearDown() {
    }
};


TEST_F(BinaryTreeTests, Tests_equal_construct_1) {
    ASSERT_TRUE(ab.equal(ab2));
}
TEST_F(BinaryTreeTests, Tests_delete) {
    bb.insert(5);
    bb.removeNode(3);
    bb.removeNode(1);
    bb.removeNode(6);
    bb.removeNode(8);
    bb.removeNode(4);

    ASSERT_TRUE(bb.equal(cb));
}
TEST_F(BinaryTreeTests, Tests_delete1) {
    cb.removeNode(5);
    ASSERT_TRUE(BinaryTree<int>().equal(cb));
}
TEST_F(BinaryTreeTests, Tests_delete2) {
    cb.removeNode(6);
    ASSERT_TRUE(!BinaryTree<int>().equal(cb));
}
TEST_F(BinaryTreeTests, Tests_delete3) {
    cb.removeNode(5);
    cb.removeNode(5);
    ASSERT_TRUE(BinaryTree<int>().equal(cb));
}
TEST_F(BinaryTreeTests, Tests_equal2) {
    BinaryTree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    ASSERT_TRUE(tree.equal(ab));
}
TEST_F(BinaryTreeTests, Tests_treverse1) {
    BinaryTree<int> neo = BinaryTree(ab.straightLeft());
    ASSERT_TRUE(neo.equal(ab));
}
TEST_F(BinaryTreeTests, Tests_treverse2) {
    BinaryTree<int> neo = BinaryTree(ab.straightRight());
    ASSERT_TRUE(neo.equal(ab));
}
TEST_F(BinaryTreeTests, Tests_treverse3) {
    BinaryTree<int> neo = BinaryTree(bb.straightRight());
    ASSERT_TRUE(neo.equal(bb));
}
TEST_F(BinaryTreeTests, Tests_treverse4) {
    BinaryTree<int> neo = BinaryTree(bb.reverseLeft());
    ASSERT_TRUE(!neo.equal(bb));
}
TEST_F(BinaryTreeTests, Tests_find_1) {
    ASSERT_TRUE(bb.find(6));
}
TEST_F(BinaryTreeTests, Tests_find_2) {
    ASSERT_TRUE(!bb.find(0));
}
TEST_F(BinaryTreeTests, Tests_find_3) {
    ASSERT_TRUE(ab.find(14));
}TEST_F(BinaryTreeTests, Tests_find_4) {
    ASSERT_TRUE(!BinaryTree<int>().find(0));
}
TEST_F(BinaryTreeTests, Tests_find_5) {
    ab.removeNode(1);
    ASSERT_TRUE(!ab.find(1));
}
TEST_F(BinaryTreeTests, Tests_findSubTree_1) {
    ASSERT_TRUE(ab.findSubtree(oo));
}
TEST_F(BinaryTreeTests, Tests_findSubTree_2) {
    ASSERT_TRUE(!ab.findSubtree(cb));
}
TEST_F(BinaryTreeTests, Tests_findSubTree_3) {
    ASSERT_TRUE(!ab.findSubtree(cb));
}
TEST_F(BinaryTreeTests, Tests_findSubTree_4) {
    bb.removeNode(8);
    ASSERT_TRUE(ab.findSubtree(bb));
}
TEST_F(BinaryTreeTests, Tests_findSubTree_5) {
    ASSERT_TRUE(!ab.findSubtree(bb));
}
TEST_F(BinaryTreeTests, Tests_MakeSubTree_1) {
    bb = ab.subtree(6);
    ASSERT_TRUE(ab.findSubtree(bb));
}
TEST_F(BinaryTreeTests, Tests_MakeSubTree_2) {
    ASSERT_TRUE(ab.findSubtree(ab));
}
TEST_F(BinaryTreeTests, Tests_MakeSubTree_13) {
    bb = ab.subtree(1);
    ASSERT_TRUE(ab.findSubtree(bb));
}
float f1(int x) {
    return (float)x / 2;
}
int f2(int x) {
    return x * x;
}
TEST_F(BinaryTreeTests, Tests_map_1) {
    float t [] {2.5};
    BinaryTree<float> gh1 = BinaryTree(LinkedList(t, 1));
    BinaryTree<float> gh = cb.map(&f1);
    ASSERT_TRUE(gh.equal(gh1));
}
TEST_F(BinaryTreeTests, Tests_map_2) {
    int t [] {4, 1, 9};
    BinaryTree<int> gh1 = BinaryTree(LinkedList(t, 3));
    BinaryTree<int> gh = a213.map(&f2);
    ASSERT_TRUE(gh.equal(gh1));
}
TEST_F(BinaryTreeTests, Tests_trevers_central) {
    int t [] {1, 3, 4, 6, 8};
    LinkedList<int> gh1 = bb.central();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_centralRight) {
    int t [] {8, 6, 4, 3, 1};
    LinkedList<int> gh1 = bb.centralRight();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_straightLeft) {
    int t [] {3, 1, 6, 4, 8};
    LinkedList<int> gh1 = bb.straightLeft();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_straightRight) {
    int t [] {3, 6, 8, 4, 1};
    LinkedList<int> gh1 = bb.straightRight();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_reverseRight) {
    int t [] {8, 4, 6, 1, 3};
    LinkedList<int> gh1 = bb.reverseRight();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_reverseLeft) {
    int t [] {1, 4, 8, 6, 3};
    LinkedList<int> gh1 = bb.reverseLeft();
    ASSERT_TRUE(gh1 == LinkedList(t , 5));
}
TEST_F(BinaryTreeTests, Tests_trevers_copyTree) {
    BinaryTree<int> gh = bb.copyTree();
    ASSERT_TRUE(gh.equal(bb));
}
TEST_F(BinaryTreeTests, Tests_trevers_copyTree_1) {
    BinaryTree<int> gh = oo.copyTree();
    ASSERT_TRUE(gh.equal(oo));
}
TEST_F(BinaryTreeTests, Tests_trevers_copyTree_2) {
    BinaryTree<int> gh = ab.copyTree();
    ASSERT_TRUE(gh.equal(ab2));
}
bool f3(int x) {
    return (x % 2 == 0);
}
TEST_F(BinaryTreeTests, Tests_trevers_where_1) {
    int b[] {4,6,8};
    BinaryTree<int> gh = BinaryTree(LinkedList(b, 3));
    BinaryTree<int> gh2 = bb.where(&f3);
    ASSERT_TRUE(gh.equal(gh2));
}
TEST_F(BinaryTreeTests, Tests_trevers_where_2) {
    int b[] {4,6,8};
    BinaryTree<int> gh = BinaryTree(LinkedList(b, 3));
    BinaryTree<int> gh2 = bb.where(&f3);
    ASSERT_TRUE(gh.equal(gh2));
}
#endif
