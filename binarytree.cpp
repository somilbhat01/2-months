#include <iostream>
#include <queue>
using namespace std;

// ==================== TREENODE STRUCT ====================
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ==================== BINARY TREE CLASS ====================
class BinaryTree {
private:
    TreeNode* root;
    
    // ========== DESTRUCTOR HELPER (Post-order deletion) ==========
    void destroyTree(TreeNode* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    
    // ========== TRAVERSAL HELPERS ==========
    
    // Inorder: Left → Root → Right
    void inorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    // Preorder: Root → Left → Right
    void preorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    // Postorder: Left → Right → Root
    void postorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    
    // ========== PROPERTY HELPERS ==========
    
    // Height: Longest path from node to leaf
    int heightHelper(TreeNode* node) {
        if (node == nullptr) return -1;  // -1 for empty tree
        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);
        return 1 + max(leftHeight, rightHeight);
    }
    
    // Count total nodes
    int countNodesHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    
    // Count leaf nodes (nodes with no children)
    int countLeavesHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return countLeavesHelper(node->left) + countLeavesHelper(node->right);
    }
    
public:
    // ========== CONSTRUCTOR ==========
    BinaryTree() : root(nullptr) {}
    
    // ========== DESTRUCTOR ==========
    ~BinaryTree() {
        destroyTree(root);
    }
    
    // ========== INSERT (Level order) ==========
    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }
            
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }
    
    // ========== SEARCH (BFS) ==========
    bool search(int value) {
        if (root == nullptr) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->data == value) return true;
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        return false;
    }
    
    // ========== TRAVERSALS (Public Wrappers) ==========
    
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
    
    void preorder() {
        preorderHelper(root);
        cout << endl;
    }
    
    void postorder() {
        postorderHelper(root);
        cout << endl;
    }
    
    void levelOrder() {
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
    
    // ========== PROPERTIES (Public Wrappers) ==========
    
    int height() {
        return heightHelper(root);
    }
    
    int countNodes() {
        return countNodesHelper(root);
    }
    
    int countLeaves() {
        return countLeavesHelper(root);
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    cout << "=== BINARY TREE TEST ===\n\n";
    
    BinaryTree tree;
    
    // Insert 7 nodes
    cout << "Inserting: 10, 20, 30, 40, 50, 60, 70\n\n";
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    
    // All traversals
    cout << "Inorder (Left → Root → Right): ";
    tree.inorder();     // 40 20 50 10 60 30 70
    
    cout << "Preorder (Root → Left → Right): ";
    tree.preorder();    // 10 20 40 50 30 60 70
    
    cout << "Postorder (Left → Right → Root): ";
    tree.postorder();   // 40 50 20 60 70 30 10
    
    cout << "Level Order (BFS): ";
    tree.levelOrder();  // 10 20 30 40 50 60 70
    
    // Properties
    cout << "\n=== PROPERTIES ===\n";
    cout << "Height of tree: " << tree.height() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Leaf nodes: " << tree.countLeaves() << endl;
    cout << "Is tree empty? " << (tree.isEmpty() ? "Yes" : "No") << endl;
    
    // Search tests
    cout << "\n=== SEARCH TESTS ===\n";
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not found") << endl;
    
    return 0;
}