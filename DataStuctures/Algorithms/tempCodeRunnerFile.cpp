// Question 1: (b) Find the predecessor and Successor of a given node

#include <iostream>
using namespace std;
 
struct BstNode
{
    int key;
    struct BstNode *left, *right;
};
void PredandSuccessor(BstNode* root, BstNode*& pre, BstNode*& suc, int key)
{
    if (root == NULL)  return ;
 
    if (root->key == key)
    {
        if (root->left != NULL)
        {
            BstNode* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        if (root->right != NULL)
        {
            BstNode* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
    if (root->key > key)
    {
        suc = root ;
        PredandSuccessor(root->left, pre, suc, key) ;
    }
    else 
    {
        pre = root ;
        PredandSuccessor(root->right, pre, suc, key) ;
    }
}
 BstNode *createNode(int item)
{
    BstNode *temp =  new BstNode;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
BstNode* insert(BstNode* node, int key)
{
    if (node == NULL) return createNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
 
int main()
{
    int key;
    cout<< "enter Key: "<<endl;
    cin>> key;

 

    BstNode *root = NULL;
    root = insert(root, 50);
    insert(root, 35);
    insert(root, 24);
    insert(root, 43);
    insert(root, 69);
    insert(root, 62);
    insert(root, 78);
 
 
    BstNode* pre = NULL, *suc = NULL;
 
    PredandSuccessor(root, pre, suc, key);
    if (pre != NULL)
      cout << "The Predecessor is :" << pre->key << endl;
    else
      cout << "No Predecessor found:";
 
    if (suc != NULL)
      cout << "The Successor is: " << suc->key;
    else
      cout << "No Successor found";
    return 0;
}