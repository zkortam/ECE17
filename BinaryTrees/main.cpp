#include <iostream>
#include "BinaryTree.h"

int main() {

    // Create a binary tree to hold integers.
    BinaryTree<int> tree;

    // Show the initial height, with no nodes.
    cout << "Height: " << tree.treeHeight() << endl;

    // Insert some nodes into the tree.
    cout << "Inserting nodes." << endl;
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);


    // Display the nodes.
    cout << "Here are the values in the tree:" << endl;
    tree.displayInOrder();

    // Print the number of nodes
    cout << "Initial number of nodes:  " << tree.numNodes() << endl;

    // Display the number of leaf nodes.
    cout << "Initial number of leaf nodes: " << tree.numLeafNodes() << endl;

    // Display the tree height.
    cout << "Initial height: " << tree.treeHeight() << endl;

    // Delete some nodes.
    cout << "Deleting node with value 8..." << endl;
    tree.remove(8);
    cout << "Deleting node with value 12..." << endl;
    tree.remove(12);

    // Display the nodes that are left.
    cout << "Now, here are the nodes:" << endl;
    tree.displayInOrder();

    // Display the updated number of nodes, leaf nodes, and tree height.
    cout << "Updated number of nodes:  " << tree.numNodes() << endl;
    cout << "Updated number of leaf nodes: " << tree.numLeafNodes() << endl;
    cout << "Updated Height: " << tree.treeHeight() << endl;

}
