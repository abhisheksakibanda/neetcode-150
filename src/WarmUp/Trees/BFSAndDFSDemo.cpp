#include <bits/stdc++.h>
#include "PrettyPrinter.h"
#include "BinaryTree/TreeNode.h"

using namespace std;

// Demonstration of DFS Traversal (Pre-order, In-order, Post-order)
void preOrderTraversal(TreeNode* root) {
    if (!root)
        return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (!root)
        return;
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

// Demonstration of BFS Traversal (Level-order)
void bfsTraversal(TreeNode* root) {
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        cout << (node ? to_string(node->val) : "null") << " ";
        if (node) {
            if (node->left) {
                nodeQueue.push(node->left);
            }
            if (node->right) {
                nodeQueue.push(node->right);
            }
        }
    }
}

int main() {
    auto root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    cout << "Pre-Order Traversal:" << endl;
    preOrderTraversal(root);
    cout << endl << endl << "In-Order Traversal:" << endl;
    inOrderTraversal(root);
    cout << endl << endl << "Post-Order Traversal:" << endl;
    postOrderTraversal(root);
    cout << endl << endl << "BFS Traversal (Level-Order):" << endl;
    bfsTraversal(root);
    cout << endl;
    delete root;
}
