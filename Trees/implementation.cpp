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
        cout << front->data <<" : "<< endl;
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pendingNodes.push(front->children[i]);
        }
        cout<<" "<<endl;
    }
}
int main()
{
    /*
    theory->
    a simple esxample of tree is the files and its directries so a file can have many directries and so on
    so it will form a tree
    so generally we can take a example of a company like ceo so under ceo there will be cto and at the same leveal we have cbo and both of
    these people will be malik of workers
    so root node ke pass apne bache ka address and same wase hi jase maa baap apne bache ka adress rakhte ha;
    so iss structure ko hm tree structure kehte
    so ak node ke jtne bache hote ha usse hm child node kehte ha so concept is parent child
    siblings mtlbe they have same parents
    so a node which doesnot have any child is calle LEAF NODE;
                                    root
                                    |
                          -------     ----------
                         |                      |
                        A                       B
                                           ----------
                                           |          |
                                           C          D
 SO HERE ROOT IS A NODE WHICH HAVE CHILD A AND B FURTHER B HAVE CHILD C AND D AND FURTHER C AND D HAVE NO CHILD SO A AND B ARE SIBLINGS BECAUSE
 BOTH A AND B HAVE SAME PARENTS AND B HAVE TWO CHILDREND C AND D SO C AND D IS SIBLINGS
 ALSO C , D AND A IS LEAF NODE BECAUSE THEY DONT HAVE ANY CHILD
 */
    // TreeNode<int>*root=new TreeNode<int>(1);
    // TreeNode<int>*node1=new TreeNode<int>(2);
    // TreeNode<int>*node2=new TreeNode<int>(3);
    // TreeNode<int>*node3=new TreeNode<int>(4);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);
    TreeNode<int> *root = takeinputlevelwise();
   // printTree(root);
   levelorderprint(root);
}
