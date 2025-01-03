#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
private:
    struct TreeNode {
        T value;
        TreeNode *left;
        TreeNode *right;
    };

    int leafCount;

    TreeNode *root;
    void insert(TreeNode *&nodePtr, TreeNode *&newNode);
    void destroySubTree(TreeNode *nodePtr);
    void deleteNode(T num, TreeNode *&nodePtr);
    void makeDeletion(TreeNode *&nodePtr);
    void displayInOrder(TreeNode *nodePtr);
    void displayPreOrder(TreeNode *nodePtr);
    void displayPostOrder(TreeNode *nodePtr);
    int countNodes(TreeNode *&nodePtr);
    void countLeaves(TreeNode *nodePtr);
    int getTreeHeight(TreeNode *nodePtr);

public:
    BinaryTree()		// Constructor
    { root = nullptr; }
    ~BinaryTree()		// Destructor
    { destroySubTree(root); }
    void insertNode(T num);
    bool searchNode(T num);
    void remove(T num);
    void displayInOrder()
    {	displayInOrder(root); }
    void displayPreOrder()
    {	displayPreOrder(root); }
    void displayPostOrder()
    {	displayPostOrder(root); }

    int numNodes();
    int numLeafNodes();
    int treeHeight();
};


/* This function accepts a TreeNode pointer and a pointer to a node.
 * The function inserts the node into the tree pointed to by
 * the TreeNode pointer. This function is called recursively.
 *
 * Parameters:
 *     TreeNode *&nodePtr - pointer to tree (or subtree when called recursively)
 *     TreeNode *&newNode - node to insert
 *
 * Returns:
 *     void
 */
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == nullptr) {
        nodePtr = newNode;				// Insert the node.
    }
    else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode); // Search the left branch
    }
    else {
        insert(nodePtr->right, newNode);// Search the right branch
    }
}


/* This function creates a new node to hold num as its value,
 * and passes it to the insert function.
 *
 * Parameters:
 *     T num - value of new node
 *
 * Returns:
 *     void
*/
template <class T>
void BinaryTree<T>::insertNode(T num) {
    TreeNode *newNode = nullptr; // Pointer to a new node.

    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // Insert the node.
    insert(root, newNode);
}


/* This function is called by the destructor. It
 * deletes all nodes in the tree.
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to tree head
 *
 * Returns:
 *     void
*/
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
    if (nodePtr != nullptr) {
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }

        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }

        delete nodePtr;
    }
}


/* This function determines if a value is present in
 * the tree. If so, the function returns true.
 * Otherwise, it returns false.
 *
 * Parameters:
 *     T num - the value to search for
 *
 * Returns
 *     bool - true if value found, false otherwise
 */
template <class T>
bool BinaryTree<T>::searchNode(T num) {
    bool status = false;

    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == num) {
            status = true;
        }
        else if (num < nodePtr->value) {
            nodePtr = nodePtr->left;
        }
        else {
            nodePtr = nodePtr->right;
        }
    }

    return status;
}


/* This function calls deleteNode to delete the
 * node whose value member is the same as num.
 *
 * Parameters:
 *     T num - the value of the node to remove
 *
 * Returns
 *     void
 */
template <class T>
void BinaryTree<T>::remove(T num) {
    deleteNode(num, root);
}


/* This function deletes the node whose value
 * member is the same as num.
 *
 * Parameters:
 *     T num - value of node to delete
 *     TreeNode *&nodePtr - pointer to tree
 *
 * Returns:
 *     void
 */

template <class T>
void BinaryTree<T>::deleteNode(T num, TreeNode *&nodePtr) {
    if (num < nodePtr->value) {
        deleteNode(num, nodePtr->left);
    }
    else if (num > nodePtr->value) {
        deleteNode(num, nodePtr->right);
    }
    else {
        makeDeletion(nodePtr);
    }
}


/* This function takes a reference to a pointer to the node
 * that is to be deleted. The node is removed and the
 * branches of the tree below the node are reattached.
 *
 * Parameters:
 *     TreeNode *&nodePtr - reference to pointer of node being deleted
 *
 * Returns:
 *     void
 */
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr) {
    // Temporary pointer, used in reattaching the left subtree.
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr) {
        cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;   // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;  // Reattach the right child
        delete tempNodePtr;
    }
        // If the node has two children.
    else {
        // Move one node the right.
        tempNodePtr = nodePtr->right;

        // Go to the end left node.
        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}


/* The displayInOrder member function displays the values
 * in the subtree pointed to by nodePtr, via inorder traversal.
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to start of tree
 *
 * Returns:
 *     None
 */
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}


/* The displayPreOrder member function displays the values
 * in the subtree pointed to by nodePtr, via preorder traversal.
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to start of tree
 *
 * Returns:
 *     None
 */
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}


/* The displayPostOrder member function displays the values
 * in the subtree pointed to by nodePtr, via postorder traversal.
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to start of tree
 *
 * Returns:
 *     None
 */
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}


/* The numNodes function returns the number of nodes in the tree.
 *
 *  Parameters:
 *     None
 *
 * Returns:
 *     int - number of nodes
 */
template <class T>
int BinaryTree<T>::numNodes() {
    return countNodes(root);
}



/* The countNodes function uses recursion to count the nodes in
 * the tree. This function is called by the public member
 * function numNodes.
 *
 * Parameters:
 *     TreeNode *&nodePtr - pointer to start of tree
 *
 * Returns:
 *     int - the number of nodes in the tree
 */
template <class T>
int  BinaryTree<T>::countNodes(TreeNode *&nodePtr) {
    // implement this function
    if (nodePtr == nullptr) {
        return 0;
    }
    return 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
}



/* This function calls countLeaves() and displays number of leaf nodes in tree
 *
 * Parameters:
 *     None
 *
 * Returns:
 *     int - the number of leaf nodes in tree
 */
template <class T>
int BinaryTree<T>::numLeafNodes() {
    leafCount = 0;    // reset to 0 each time a count is made
    countLeaves(root);

    return leafCount;
}



/* This function performs postorder traversal and counts leaf nodes
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to start of tree
 *
 * Returns:
 *     void
 */
template <class T>
void BinaryTree<T>::countLeaves(TreeNode* nodePtr) {
    // implement this function
    if (nodePtr == nullptr) {
        return;
    }

    if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
        leafCount++;
    } else {
        countLeaves(nodePtr->left);
        countLeaves(nodePtr->right);
    }
}



/* This function uses recursion to count the height of
 * the tree.
 *
 * Parameters:
 *     TreeNode *nodePtr - pointer to start of tree
 *
 * Returns:
 *     int - height of tree
 */
template <class T>
int BinaryTree<T>::getTreeHeight(TreeNode* nodePtr) {
    // implement this function
    if (nodePtr == nullptr) {
        return 0;
    }

    int leftHeight = getTreeHeight(nodePtr->left);
    int rightHeight = getTreeHeight(nodePtr->right);

    return 1 + std::max(leftHeight, rightHeight);
}


/* This function calls getTreeHeight and displays height of tree.
 *
 * Parameters:
 *     None
 *
 * Returns:
 *     int - height of tree
 */
template <class T>
int BinaryTree<T>::treeHeight() {
    return getTreeHeight(root);
}

#endif // DO NOT ADD CODE BELOW THIS LINE
