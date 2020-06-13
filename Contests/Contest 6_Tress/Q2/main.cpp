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
    if(i<n)
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

vector<int> maxVal(Node* root)
{
    vector<int> res;
    if(root==NULL)
        return res;
    queue<Node*> q;
    q.push(root);
    Node* temp=NULL;

    while(q.size())
    {
        int n=q.size();
        int currMax=INT_MIN;
        while(n--)
        {
            temp=q.front();
            q.pop();
            currMax=max(currMax,temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        res.push_back(currMax);
    }
    return res;
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

    vector<int> answer;
    answer=maxVal(root);
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<" ";
    return 0;
}
