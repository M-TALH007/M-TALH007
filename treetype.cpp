#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        right=NULL;
        left=NULL;
    }
};

void preorder(struct node* root);
void inorder(struct node* root);
void postorder(struct node* root);

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" " ;
    inorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int depth(node *root) {
    int d = 0;
    while (root != NULL) {
        d++;
        root = root->left;
    }
    return d;
}

bool isPerfectR(struct node *root, int d, int level = 0) {
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return isPerfectR(root->left, d, level + 1) &&
           isPerfectR(root->right, d, level + 1);
}
int countNumNodes(struct node *root) {
    if (root == NULL)
        return (0);
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}
bool checkHeightBalance(node *root, int *height) {

    int leftHeight = 0, rightHeight = 0;

    int l = 0, r = 0;

    if (root == NULL) {
        *height = 0;
        return 1;
    }

    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if (std::abs(leftHeight - rightHeight >= 2))
        return 0;

    else
        return l && r;
}
bool checkComplete(struct node *root, int index, int numberNodes) {


    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) &&
            checkComplete(root->right, 2 * index + 2, numberNodes));
}

bool isPerfect(node *root) {
    int d = depth(root);
    return isPerfectR(root, d);
}
int main()
{
    struct node* root = new node(5);
    root->left=new node(1);
    root->right=new node(2);
    root->right->right= new node(3);
    root->right->left= new node(12);
    root->left->right= new node(4);
    root->left->left= new node(4);

    cout<<"the preorder traversal of a tree : ";
    preorder(root);
    cout<<endl;

    cout<<"the post order traversal of a tree : ";
    postorder(root);
    cout<<endl;

    cout<<"the inorder traversal : ";
    inorder(root);
    cout<<endl;
    if (isPerfect(root))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";

    int node_count = countNumNodes(root);
    int index = 0;
    if (checkComplete(root, index, node_count))
        cout << "The tree is a complete binary tree\n";
    else
        cout << "The tree is not a complete binary tree\n";
    int height = 0;
    if (checkHeightBalance(root, &height))
        cout << "The tree is balanced";
    else
        cout << "The tree is not balanced";
    return 0;
}

