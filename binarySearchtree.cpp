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

// ==================== BST CLASS ====================
class BST {
private:
    TreeNode* root;
    
    // ========== DESTRUCTOR HELPER ==========
    void destroyTree(TreeNode* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
    
    // ========== RECURSIVE INSERT HELPER ==========
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }
        // if equal: do nothing (no duplicates)
        
        return node;
    }
    
    // ========== RECURSIVE SEARCH HELPER ==========
    bool searchRecursive(TreeNode* node, int value) {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        
        if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }
    
    // ========== TRAVERSAL HELPERS ==========
    void inorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
    
    void preorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
    
    void postorderHelper(TreeNode* node) {
        if (node == nullptr) return;
        postorderHelper(node->left);
        postorderHelper(node->right);
        cout << node->data << " ";
    }
    
    // ========== PROPERTY HELPERS ==========
    int heightHelper(TreeNode* node) {
        if (node == nullptr) return -1;
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }
    
    int countNodesHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }
    
    int countLeavesHelper(TreeNode* node) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return 1;
        return countLeavesHelper(node->left) + countLeavesHelper(node->right);
    }
    
public:
    // ========== CONSTRUCTOR ==========
    BST() : root(nullptr) {}
    
    // ========== DESTRUCTOR ==========
    ~BST() {
        destroyTree(root);
    }
    
    // ========== INSERT (Recursive) ==========
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    // ========== INSERT (Iterative - No Recursion) ==========
    void insertIterative(int value) {
        TreeNode* newNode = new TreeNode(value);
        
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        TreeNode* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    return;
                }
                current = current->left;
            }
            else if (value > current->data) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return;
                }
                current = current->right;
            }
            else {
                // Duplicate - don't insert
                delete newNode;
                return;
            }
        }
    }
    
    // ========== SEARCH ==========
    bool search(int value) {
        return searchRecursive(root, value);
    }
    
    // ========== TRAVERSALS ==========
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
    
    // ========== PROPERTIES ==========
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
    cout << "=== BINARY SEARCH TREE TEST ===\n\n";
    
    BST tree;
    
    // Insert using recursive method
    cout << "Inserting (recursive): 50, 30, 70, 20, 40, 60, 80\n";
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "\n--- TRAVERSALS ---\n";
    cout << "Inorder (should be SORTED): ";
    tree.inorder();     // 20 30 40 50 60 70 80
    
    cout << "Preorder: ";
    tree.preorder();    // 50 30 20 40 70 60 80
    
    cout << "Postorder: ";
    tree.postorder();   // 20 40 30 60 80 70 50
    
    cout << "Level Order: ";
    tree.levelOrder();  // 50 30 70 20 40 60 80
    
    cout << "\n--- PROPERTIES ---\n";
    cout << "Height: " << tree.height() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Leaf nodes: " << tree.countLeaves() << endl;
    cout << "Is empty? " << (tree.isEmpty() ? "Yes" : "No") << endl;
    
    cout << "\n--- SEARCH TESTS ---\n";
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not found") << endl;
    
    cout << "\n--- TESTING INSERT ITERATIVE ---\n";
    BST tree2;
    tree2.insertIterative(50);
    tree2.insertIterative(30);
    tree2.insertIterative(70);
    tree2.insertIterative(20);
    tree2.insertIterative(40);
    tree2.insertIterative(60);
    tree2.insertIterative(80);
    
    cout << "Inorder from iterative insert: ";
    tree2.inorder();  // 20 30 40 50 60 70 80
    
    return 0;
}