#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }

    int left_depth = maxDepth(root -> left);
    int right_depth = maxDepth(root -> right);

    return 1 + max(left_depth,right_depth);
}

void deleteTree(TreeNode* node){
    if (node == nullptr){
        return ;
    }
    deleteTree(node -> left);
    deleteTree(node -> right);
    delete node;
}

int main(){
    
    TreeNode* root = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    root -> left = node9;
    root -> right = node20;
    root -> right -> right = node7;
    root -> right -> left = node15; 

    deleteTree(root);

}
