#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Build a binary tree from level-order input (-1 for NULL)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Convert binary tree to vector in level-order (nulls as -1)
vector<int> treeToVector(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1); // NULL marker
        }
    }

    // Trim trailing -1s
    while (!result.empty() && result.back() == -1)
        result.pop_back();

    return result;
}

// Example: Your custom logic here
TreeNode* solveTree(TreeNode* root) {
    // For example: return same root (no change)
    return root;
}

void solve() {
    vector<int> values;
    int x;
    while (cin >> x) {
        values.push_back(x);
    }

    TreeNode* root = buildTree(values);
    TreeNode* newRoot = solveTree(root);
    vector<int> output = treeToVector(newRoot);

    // Print in [1,2,3,-1,4,...] format
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i < output.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
