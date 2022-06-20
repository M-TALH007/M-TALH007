/*
#include <iostream>
#include <queue>

using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    TreeNode *root;
    BinaryTree() : root(nullptr) {}

    void bfsTraversal()
    {
        if (root == nullptr)
            return;
        queue<TreeNode *> q;
        TreeNode *node = root;
        q.push(node);
        cout << endl;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }

    void dfsTraversal()
    {
        dfsTraversal(root);
    }
    void dfsTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        dfsTraversal(root->left);
        dfsTraversal(root->right);
    }

    // check complete with queue
    bool checkComplete()
    {
        if (root == nullptr)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        bool nonCompleteNode = false;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr)
            {
                if (nonCompleteNode == true)
                {
                    return false;
                }
                q.push(cur->left);
            }
            else
            {
                nonCompleteNode = true;
            }
            if (cur->right != nullptr)
            {
                if (nonCompleteNode == true)
                {
                    return false;
                }
                q.push(cur->right);
            }
            else
            {
                nonCompleteNode = true;
            }
        }
        return true;
    }

    bool checkFull()
    {
        return checkFull(root);
    }
    bool checkFull(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        if ((root->left) && (root->right))
            return (checkFull(root->left) && checkFull(root->right));
        return false;
    }

    // Function to check if the given tree is perfect
    bool checkPerfect()
    {
        queue<TreeNode *> q;

        // Push the root node
        q.push(root);

        // Flag to check if leaf nodes have been found
        bool flag = false;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            // If current node has both left and right child
            if (temp->left && temp->right)
            {
                // If a leaf node has already been found
                // then return false
                if (flag == true)
                {
                    return false;
                }

                // If a leaf node has not been discovered yet
                // push the left and right child in the queue
                else
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }

            // If a leaf node is found mark flag as one
            else if (!temp->left && !temp->right)
            {
                flag = true;
            }

            // If the current node has only one child
            // then return false
            else if (!temp->left || !temp->right)
                return false;
        }

        // the given tree is perfect return true
        return true;
    }
};

int main()
{
    // example 1
    // not a complete tree
    BinaryTree T1;
    T1.root = new TreeNode(7);
    T1.root->left = new TreeNode(3);
    T1.root->right = new TreeNode(9);
    T1.root->left->left = new TreeNode(1);
    T1.root->right->right = new TreeNode(4);
    cout << "BFS Traversal: ";
    T1.bfsTraversal();
    cout << endl;
    cout << "DFS Traversal: " << endl;
    T1.dfsTraversal();
    cout << endl;

    cout << endl
         << "Example 1: " << endl;
    cout << (T1.checkComplete() ? "is complete" : "is not complete") << endl;

    // example 2
    // is a complete tree
    cout << endl
         << "Example 2: " << endl;
    BinaryTree T2;
    T2.root = new TreeNode(7);
    T2.root->left = new TreeNode(3);
    T2.root->right = new TreeNode(9);
    T2.root->left->left = new TreeNode(1);
    T2.root->left->right = new TreeNode(4);
    cout << (T2.checkComplete() ? "is complete" : "is not complete") << endl;

    // example 3
    // is a full tree
    cout << endl
         << "Example 3: " << endl;
    BinaryTree T3;
    T3.root = new TreeNode(7);
    T3.root->left = new TreeNode(3);
    T3.root->right = new TreeNode(9);
    T3.root->left->left = new TreeNode(1);
    T3.root->left->right = new TreeNode(4);
    cout << (T3.checkFull() ? "is full" : "is not full") << endl;

    // example 4
    // is not a full tree
    cout << endl
         << "Example 4: " << endl;
    BinaryTree T4;
    T4.root = new TreeNode(7);
    T4.root->left = new TreeNode(3);
    T4.root->right = new TreeNode(9);
    T4.root->left->left = new TreeNode(1);
    cout << (T4.checkFull() ? "is full" : "is not full") << endl;

    // example 5
    // is a perfect tree
    cout << endl
         << "Example 5: " << endl;
    BinaryTree T5;
    T5.root = new TreeNode(7);
    T5.root->left = new TreeNode(3);
    T5.root->right = new TreeNode(9);
    T5.root->left->left = new TreeNode(1);
    T5.root->left->right = new TreeNode(2);
    T5.root->right->left = new TreeNode(11);
    T5.root->right->right = new TreeNode(14);
    cout << (T5.checkPerfect() ? "is perfect" : "is not perfect") << endl;

    // example 6
    // is not a perfect tree
    cout << endl
         << "Example 6: " << endl;
    BinaryTree T6;
    T6.root = new TreeNode(7);
    T6.root->left = new TreeNode(3);
    T6.root->right = new TreeNode(9);
    T6.root->left->left = new TreeNode(1);
    cout << (T6.checkPerfect() ? "is perfect" : "is not perfect") << endl;
    return 0;}
*/

#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;

class binary{
public:
    int data;
    binary *left ,  *right;
    // Valued Constructor
    binary(int value){
        data = value;
        right = NULL; left = NULL;
    }};

// insertion of Values in Tree.
binary *insert_To_Tree(binary *root , int value){  // root null
    if(root == NULL){
        return new binary(value); // Assigning Value to root if NULL. root value
    } // when root is assign before runing than below statment will work.
    if(value > root->data){
        root->right = insert_To_Tree(root->right , value);  //
    }else // add to root left.
    {root->left = insert_To_Tree(root->left , value);}
    return root;}

// Finding the minimum and maximum ib Binary Tree.

void min(binary *root){
    binary * curr = root ;
    while(curr ->left != NULL){
        curr = curr->left;
    }
    cout << "The Minimum Number in Tree is : " << curr->data << endl;
}

void max(binary *root){
    binary * curr = root ;
    while(curr ->right != NULL){
        curr = curr->right;
    }
    cout << "The Maximum Number in Tree is : " << curr->data << endl;
}

void BFS(binary *root){
    if(root == NULL){
        return;}
    queue<binary * > q;
    q.push(root);
    binary *node;  // temp node
    while(!q.empty()){
        node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left !=NULL){
            q.push(node->left);
        }
        if (node->right !=NULL){
            q.push(node->right);
        }
    }};

bool isFULL(binary* &root){
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->left != NULL && root->right != NULL){
        return (isFULL(root->left) && isFULL(root->right));
    }
    return false;
}

int Depth(binary* &node)
{
    int dep = 0;
    while (node != NULL)
    {
        dep++;
        node = node->left;
    }
    return dep;
}

bool Check(binary* &root, int dep, int level = 0)
{
    if (root == NULL) //node does not present
        return true;

    if (root->left == NULL && root->right == NULL)//finding node is present and level is one
        return (dep == level+1);

    if (root->left == NULL || root->right == NULL)
        return false;

    return Check(root->left, dep, level+1) && Check(root->right, dep, level+1);
}

bool isPerfect(binary* &root)
{
    int dep = Depth(root);
    return Check(root, dep);
}

int TotalNodes(binary* &root)
{
    if (root == NULL)
        return (0);
    return (1 + TotalNodes(root->left) +
            TotalNodes(root->right));
}

bool isComplete( binary* &root,int index, int number_nodes)
{

    if (root == NULL)
        return (true);

    if (index >= number_nodes)
        return (false);


    return (isComplete(root->left, 2*index + 1, number_nodes) &&
    isComplete(root->right, 2*index + 2, number_nodes));
}



void DFS_Pre(binary *root){
    if(root == NULL){
        return;}
    stack<binary *> s;
    s.push(root);
    binary *node;
    while(!s.empty()){
        node = s.top();
        cout << node->data << " ";
        s.pop();
        if (node->right !=NULL){
            s.push(node->right);
        }
        if (node->left !=NULL){
            s.push(node->left);
        }

    }};

// Checking either a tree is full or perfect or Complete.




int main(){
// binary b;
    binary *root = new binary(4);  // root

    /* binary b;
     binary *root = NULL;
     root = b.insert(root,5);*/ // need to understand
    //binary *root = insert_To_Tree(root , 4);  same work

    insert_To_Tree(root, 10);
    insert_To_Tree(root, 2);
    insert_To_Tree(root, 4);
    insert_To_Tree(root, 6);
    insert_To_Tree(root, 8);
    insert_To_Tree(root, 10);

    // Tree Traversal BFS AND DFS.
    BFS(root);
    cout << endl;
    DFS_Pre(root);
    cout << endl;

    // Minimum and maximum in Tree
    min(root);
    max(root);

    // Complete and full and Perfect

    if(isFULL(root)){
        cout<<"It is Full tree";
    }else{
        cout<<"Not a full tree";
    }

    cout<<endl;

    if(isPerfect(root)){
        cout<<"It is Perfect tree";
    }else{
        cout<<"Not a Perfect tree";
    }

    cout<<endl;

    int node_count = TotalNodes(root);
    int index = 0;

    if(isComplete(root,index,node_count)){
        cout<<"It is Complete tree";
    }else{
        cout<<"Not a Complete tree";
    }


    return 0;}


