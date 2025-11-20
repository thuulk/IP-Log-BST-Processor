#ifndef BST_H
#define BST_H
#include "node.h"

class BST {

    
    private:
    // ============= attributes =============
    Node* root;

    // ============= private methods =============
    Node* insertIp(Node* root, const size_t& key, const std::string& ip) { // Inserting recursively the new ip into its node by accessNum
        if (!root) return nullptr;
        else if (key > root->accessNum) insertIp(root->right, key, ip);
        else if (key < root->accessNum) insertIp(root->left, key, ip);
        else root->ips.push_back(ip);
        return root;
    }

    void reverseInOrder(Node* root) const { // Printing ips recursively in a greatest-to-less order
       if (!root) return;
       reverseInOrder(root->right);
       std::cout << "IPs spotted " << root->accessNum << " times:" << std::endl; 
       for (std::string& ip : root->ips) std::cout << ip << std::endl;
       std::cout << std::endl;
    }

    public:
    // ============= encapsulating methods =============
    BST() : root(nullptr) {}




};

#endif BST_H

