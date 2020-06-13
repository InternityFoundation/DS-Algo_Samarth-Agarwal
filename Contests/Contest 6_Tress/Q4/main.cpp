#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node=new Node;
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

Node* insertLevelOrder(vector<string> V,Node* root,int i,int n)
{
    if(i<n && V[i]!="null")
    {
        int val=0;
        for(int j=0;j<V[i].size();j++)
            val=(val*10)+((int)(V[i][j])-48);
        //int val=stoi(V[i]);
        Node* temp=newNode(val);
        root=temp;

        root->left=insertLevelOrder(V,root->left,2*i+1,n);
        root->right=insertLevelOrder(V,root->right,2*i+2,n);
    }
    return root;
}

int ct=0;

void dfs(Node* root,int greatest)
{
    if(root==NULL)
        return;
    if(root->data>=greatest)
    {
        ct++;
        greatest=root->data;
    }
    dfs(root->left,greatest);
    dfs(root->right,greatest);
}

int goodNodes(Node* root)
{
    int greatest=root->data;
    dfs(root, greatest);
    return ct;
}

int main()
{
    int N;
    cout<<"Enter number of elements\n";
    cin>>N;
    vector<string> V;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        V.push_back(s);
    }
    Node* root=insertLevelOrder(V,root,0,N);
    cout<<goodNodes(root);
    return 0;
}
