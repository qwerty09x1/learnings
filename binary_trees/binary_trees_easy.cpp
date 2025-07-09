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

// Build tree from level-order string input like: 3 9 20 null null 15 7
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Convert tree to level-order string vector (with "null")
vector<string> treeToVector(TreeNode* root) {
    vector<string> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            result.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back("null");
        }
    }

    // Trim trailing "null"s
    while (!result.empty() && result.back() == "null")
        result.pop_back();

    return result;
}

// Your tree logic here
TreeNode* solveTree(TreeNode* root) {
    // Example: return tree as is
    return root;
}
//Maximum depth of binary tree
int maxheight(TreeNode* root){
    if (root == nullptr) return 0;
    if(root->left==NULL && root->right==NULL){
       return 1; 
    }
    else if(root->left == NULL){
        return 1+maxheight(root->right);
    }
    else if(root->right == NULL){
        return 1+maxheight(root->left);
    }
    else {
        return 1+max(maxheight(root->left),maxheight(root->right));
    }
}

// Same Tree


// kth smallest element in a BST

// Validate Binary Search Tree

void solve() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<string> tokens;
    string temp;
    while (ss >> temp) {
        tokens.push_back(temp);
    }

    TreeNode* root = buildTree(tokens);
    TreeNode* newRoot = solveTree(root);
    vector<string> output = treeToVector(newRoot);

    // // Print like [3,9,20,null,null,15,7]
    // cout << "[";
     cout << maxheight(root);
    // for (int i = 0; i < output.size(); i++) {
    //     cout << output[i];
    //     if (i < output.size() - 1) cout << ",";
    // }
    // cout << "]" << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
