#ifndef TREE_H
#define TREE_H

using namespace std;

struct TreeNode{
    string name, surname;
    int ID;
    struct TreeNode *left, *right;
};

TreeNode *newNode(string name, string surname, int ID) {
    struct TreeNode* temp = new TreeNode;
    temp->name = name;
    temp->surname = surname;
    temp->ID = ID;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert(TreeNode *root, string name, string surname, int ID){
    if(root == NULL) return newNode(name, surname, ID);

    if(ID < root->ID)
        root->left = insert(root->left, name, surname, ID);
    else
        root->right = insert(root->right, name, surname, ID);

    return root;
}

TreeNode *findByID(TreeNode *root, int ID){
    if(root->ID == ID)
        return root;

    if(root == NULL)
        return NULL;

    if(ID > root->ID)
        return findByID(root->right, ID);
    else if(ID < root->ID)
        return findByID(root->left, ID);
}

TreeNode *minValueNode(TreeNode *node) {
    TreeNode *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

TreeNode *deleteNode(TreeNode *root, int ID){
    if(root == NULL) return root;

    if(ID < root->ID)
        root->left = deleteNode(root->left, ID);
    else if (ID > root->ID)
        root->right = deleteNode(root->right, ID);
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct TreeNode *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->ID = temp->ID;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->ID);
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->ID << "->";
        inorder(root->right);
    }
}

void preorder(TreeNode *root) {
    if (root != NULL) {
        cout<<root->ID<<"->";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->ID<<"->";
    }
}
//The following function are here to balance an unbalanced BST

TreeNode* buildTreeUtil(vector<TreeNode*> &nodes, int start, int end){
    if (start > end)
        return NULL;

    int mid = (start + end)/2;
    TreeNode *root = nodes[mid];

    root->left  = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);

    return root;
}

void storeBSTNodes(TreeNode* root, vector<TreeNode *> &nodes)
{
    // Base case
    if (root==NULL)
        return;

    // Store nodes in Inorder (which is sorted
    // order for BST)
    storeBSTNodes(root->left, nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right, nodes);
}

TreeNode* buildTree(TreeNode* root)
{
    // Store nodes of given BST in sorted order
    vector<TreeNode *> nodes;
    storeBSTNodes(root, nodes);

    // Constructs BST from nodes[]
    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}


#endif //TREE_H
