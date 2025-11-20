#ifndef BST_H
#define BST_H
#include "node.h"

class BST {

    
    private:
    // ============= attributes =============
    Node* root;

    Node* insert(Node* root, const size_t& key, const std::string& ip) {
        if (!root) return nullptr;
        else if (key > root->accessNum) insert(root->right, key, ip);
        else if (key < root->accessNum) insert(root->left, key, ip);
        else root->ips.push_back(ip);
        return root;
    }

    public:
    // ============= public methods =============
    BST() : root(nullptr) {}




};

#endif BST_H

