#ifndef BST_H
#define BST_H
#include "node.h"
#include <fstream>
#include <sstream>

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

    void reverseInOrderTopTier(Node* root, std::vector<std::pair<std::string, size_t>>& result, size_t& topTier) const {
        /*
        let result be a vector of pairs where IP spotted are storaged from greatest-to-less order
        let topTier represent the number of IP vectors to print in greatest-to-less order of accessNum
        */

    }

    void destructor(Node* root) {
        if (!root) return;
        destructor(root->left);
        destructor(root->right);
        delete root;
    }


    public:
    // ============= encapsulating methods =============
    BST() : root(nullptr) {} // constructor
    ~BST() { destructor(root); } // liberating memory




};

#endif BST_H

