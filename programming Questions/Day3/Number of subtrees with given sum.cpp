Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int tell(Node* root,int x,int &count)
{
if(root==NULL) return 0;

int s1 = tell(root->left,x,count);
int s2 = tell(root->right,x,count);
int sum = s1 + s2 + root->data ;
if(s1 + s2 + root->data == x)
{ count++;
return sum;
}

}
int countSubtreesWithSumX(Node* root, int x )
{
if (!root)return 0;
// Code here
int count=0;
tell(root,x,count);
return count;
}