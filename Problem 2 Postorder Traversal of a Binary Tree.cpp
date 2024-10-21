#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};

void postOrder(Node* root){
    if (root==nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
    
}



int main(int argc, char const *argv[])
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    postOrder(root);
    cout<<endl;

    return 0;
}
