/*
 * @Author: your name
 * @Date: 2021-05-10 22:26:28
 * @LastEditTime: 2021-05-10 22:49:02
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /LeetCode/872.cpp
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "default_header.h"
class Solution {
public:
    
    void dfs(TreeNode* root,list<int> &leavesSeq)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            leavesSeq.push_back(root->val);
        }
        else
        {
            if(root->left != nullptr)
            {
                dfs(root->left, leavesSeq);
            }
            else if(root->right != nullptr)
            {
                dfs(root->right, leavesSeq);
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 叶子结点：左右子树都为null
        // 遍历一遍，把树的最底层节点按顺序找出来
        list<int> leaves_1;
        list<int> leaves_2;
        dfs(root1, leaves_1);
        dfs(root2, leaves_2);
        if(leaves_1.size() != leaves_2.size())
        {
            return false;
        }
        return leaves_1 == leaves_2;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root1 = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* root2 = stringToTreeNode(line);
        
        bool ret = Solution().leafSimilar(root1, root2);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}