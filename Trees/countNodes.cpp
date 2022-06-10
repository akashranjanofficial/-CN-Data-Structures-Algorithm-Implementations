// count no. of nodes in the tree;
// no. of nodes= child ke jtne nodes +1;
#include <bits/stdc++.h>
using namespace std;
#include <queue>
template <typename t>
class TreeNode
{
public:
    t data;
    vector<TreeNode<t> *> children;
    // constructor
    TreeNode(t data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
// take input from user
TreeNode<int> *takeinput()
{
    int rootData;
    cout << "enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter num of children of" << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeinput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    // in case of the null tree to handle this situation
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    // no need of the base case in generic trees;
}
// takeinput level wise
TreeNode<int> *takeinputlevelwise()
{
    int rootData;
    cout << "enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childdata;
            cout << "enter" << i << "th child of" << front->data << endl;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void levelorderprint(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : " << endl;
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout << " " << endl;
    }
}
int countnodes(TreeNode<int> *root)
{
    int ans = 1;
    if (root == NULL)
    {
        return 0;
    }
    // base case
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countnodes(root->children[i]);
    }
    return ans;
}
// how to find the height of a tree;
/*  ====================================
 so  NULL = ZERO HEIGHT
 SO  */
int calh(TreeNode<int> *root)
{
    int ans = 0;
    if (root == NULL)
    {
        return 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(calh(root->children[i]), ans);
    }
    return ans + 1;
}
// DEPTH OF THE GENERIC TREE;
//  ROOT SE LAST ROOT KA VERTICAL LENGTH IS DEPTH;
// FUNCTION TO PRINT ALL NODES AT DEPTH K;
void printatlevelk(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printatlevelk(root->children[i], k - 1);
    }
}
int countleaf(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countleaf(root->children[i]);
    }
    return ans;
}
// tree traversal
/*-------------------------------- PREORDER ------------------ PHELE ROOT bole ga pheele hmko print kro mere children ko baad me kre lenge
postorder traversal
root bole ga first print child then print root;

 */
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {

        postorder(root->children[i]);
    }
    cout << root->data << " ";
}
// destructor
/* tree dynamically banaya ha so delete to krna hoga na/*/
void deletetree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
}
// function to find next larger element in the tree
int nextlarger(TreeNode<int> *root, int x)
{
    int ans = NULL;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > x)
    {
        ans = x;
        return ans;
    }
    int temp = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        temp = nextlarger(root->children[i], x);
        if(temp>x&&ans==NULL)
        {
            ans=temp;
        }
        if (temp < ans)
        {
            ans = temp;
        }
        
    }
    if(ans>temp)
    {
        return temp;
    }else return ans;
    
}

int main()
{
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = takeinputlevelwise();
    // printTree(root);
    // int k=countnodes(root);
    // cout<<"total no. of nodes are"<<" "<<k<<endl;
    // levelorderprint(root);
    // cout<<"height"<<calh(root)<<endl;

    // printatlevelk(root,2);
    //  cout<<"leaf"<<countleaf(root)<<endl;
   // postorder(root);
   int k;
   cin>>k;
   cout<<nextlarger(root,k)<<endl;
 //   delete (root);
    // another way to delete the tree;
    // here comes the concept of destructor;
}
