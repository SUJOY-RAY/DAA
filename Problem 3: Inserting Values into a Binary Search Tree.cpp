#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=nullptr;
    }
};


Node* insert(Node* root, int data){
    if (root==nullptr)
    {
        return new Node(data);
    }
    if (data<root->data)
    {
        root->left=insert(root->left,data);
    }else
    {
        root->right=insert(root->right,data);
    }
    return root;      
}

void inOrder(Node* root){
    if (root==nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}

int main(){
    Node* root=nullptr;
    int values[]={1,2,3,4,5,6,7,8};
    for(int a: values){
        root=insert(root,a);
    }
    inOrder(root);
}