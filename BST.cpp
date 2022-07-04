/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
 
class BSTNode
{
public:
    int Key;
    BSTNode * Left;
    BSTNode * Right;
    BSTNode * Parent;

// Function to create a new Node in heap
BSTNode * Insert(BSTNode * node, int key)
{
    if(node == NULL)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
    }
    // If the given key is greater than node's key then go to right subtree
    else if(node->Key < key){
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }
    // If the given key is smaller than node's key then go to left subtree
    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }
        return node;
}

void printPREOrder(BSTNode * node){
// Stop printing if no node found
    if (node == NULL) 
          return; 
  
     /* first print data of node */
     cout<< node->Key <<" ";   
  
     /* then recur on left subtree */
     printPREOrder(node->Left);   
  
     /* now recur on right subtree */
     printPREOrder(node->Right);
}

void printPOSTOrder(BSTNode * node){
// Stop printing if no node found
    if (node == NULL) 
          return; 
  
     /* then recur on left subtree */
     printPOSTOrder(node->Left);   
  
     /* now recur on right subtree */
     printPOSTOrder(node->Right);
     
     /* first print data of node */
     cout<< node->Key <<" ";  
}

void printInOrder(BSTNode * node){
// Stop printing if no node found
    if (node == NULL) 
          return; 
  
     /* then recur on left subtree */
     printInOrder(node->Left);  
     
     /* first print data of node */
     cout<< node->Key <<" ";  
  
     /* now recur on right subtree */
     printInOrder(node->Right);
}

BSTNode * Search(BSTNode * node, int key)
{
    
    if (node == NULL)
        return NULL;
    // The given key is found
    else if(node->Key == key)
    {
        cout<<endl<<key <<" found in BST.";
        return node;
    }
    
    else if(node->Key < key){
        return Search(node->Right, key);
        }
    // The given is smaller than
    // current node's key
    else
        return Search(node->Left, key);
}

int FindMin(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}
int FindMax(BSTNode * node)
{
    if(node == NULL)
        return -1;
    else if(node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

BSTNode * Remove(BSTNode * root,int key)
{
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->Key)
        root->Left = Remove(root->Left, key);
 
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->Key)
        root->Right = Remove(root->Right, key);
 
    // if key is same as root's key, then This is the node to be deleted
    else {
        // node has no child
        if (root->Left==NULL and root->Right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->Left == NULL) {
            BSTNode* temp = root->Right;
            delete(root);
            return temp;
        }
        else if (root->Right == NULL) {
            BSTNode* temp = root->Left;
            delete(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        BSTNode* temp = new BSTNode();
        temp->Key = FindMin(root->Right);
 
        // Copy the inorder successor's content to this node
        root->Key = temp->Key;
 
        // Delete the inorder successor
        root->Right = Remove(root->Right, temp->Key);
    }
    return root;
}
    
    int Successor(BSTNode * node)
    {
        // The successor is the minimum key value
        // of right subtree
        if (node->Right != NULL)
        {
            return FindMin(node->Right);
        }
    }

};
int main() {
	BSTNode* root = NULL;  
	
    root = root->Insert(root,15);	
    root = root->Insert(root,3);
    root = root->Insert(root,18);
    root = root->Insert(root,1);
    root = root->Insert(root,10);
    root = root->Insert(root,22);
    root = root->Insert(root,20);
    
    cout<<"PreOrder:";
    root->printPREOrder(root);
    cout<<"\nPostOrder:";
    root->printPOSTOrder(root);
    cout<<"\nInOrder:";
    root->printInOrder(root);
    
    root->Search(root,18);
    
    cout<<"\nMax in tree is "<<root->FindMax(root);
    cout<<"\nMin in tree is "<<root->FindMin(root);
    
    root = root->Remove(root,3);
    
    cout<<"\nPreOrder:";
    root->printPREOrder(root);
    cout<<"\nPostOrder:";
    root->printPOSTOrder(root);
    cout<<"\nInOrder:";
    root->printInOrder(root);
    return 0;
}