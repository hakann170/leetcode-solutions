#include <iostream>
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

bool isSameTree(TreeNode* p, TreeNode* q){
    if (p == nullptr && q == nullptr){
        return true;
    }
    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)){
        return false;
    }
    if (p->val != q->val){
        return false;
    }

    bool result_for_left = isSameTree(p->left, q->left);
    bool result_for_right = isSameTree(p->right, q->right);

    if (result_for_left && result_for_right){
        return true;
    }
        return false;

}
int main(){
    TreeNode* root1 = new TreeNode(1);
    TreeNode* node2_1 = new TreeNode(2);
    TreeNode* node3_1 = new TreeNode(3);
    root1 -> left = node2_1;
    root1 -> right = node3_1;

    TreeNode* root2 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    root2 -> left = node2;
    root2 -> right = node3;

    bool result = isSameTree(root1, root2);
    if (result){
        cout << "Verilen dugumler birbirine es.";
    }else{
        cout << "Dugumler birbirine esit degil.";
    }

    return 0;
}
