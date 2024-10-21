#include<iostream>
#include<unordered_map>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node* left;
    Node* right;
    
    Node(char val, int frequency){
        data=val;
        freq=frequency;
        left=right=nullptr;
    }
};
void decode_huff(Node* root, const string& s){
    Node* current=root;
    string decodedString="";

    for (auto &&c : s)
    {
        current=(c=='0')?current->left:current->right;
        if (current->left==nullptr&& current->right==nullptr)
        {
            decodedString+=current->data;
            current=root;
        }
    }
    cout<<decodedString<<endl;
}

int main() {
    Node* root = new Node('\0', 0);
    root->left = new Node('A', 5);
    root->right = new Node('\0', 2);
    root->right->left = new Node('B', 2);
    root->right->right = new Node('\0', 1);
    root->right->right->left = new Node('C', 1);
    root->right->right->right = new Node('D', 1);
    root->right->right->left = new Node('R', 2);

    string encodedString = "01111001100011010111100";
    decode_huff(root, encodedString);

    return 0;
}





