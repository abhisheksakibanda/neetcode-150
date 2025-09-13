#include <vector>
#include <queue>
#include <string>
#include "TreeNode.h"

TreeNode* CreateBinaryTree(const std::vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

std::string PrintBinaryTree(const TreeNode* head) {
    if (!head) return "[]";
    std::vector<std::string> result;
    std::queue<const TreeNode*> q;
    q.push(head);

    while (!q.empty()) {
        const TreeNode* node = q.front();
        q.pop();
        if (node) {
            result.push_back(std::to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("-1");
        }
    }

    // Remove trailing "-1"s
    while (!result.empty() && result.back() == "-1") {
        result.pop_back();
    }

    std::string out = "[";
    for (size_t i = 0; i < result.size(); ++i) {
        out += result[i];
        if (i + 1 < result.size()) out += ",";
    }
    out += "]";
    return out;
}
