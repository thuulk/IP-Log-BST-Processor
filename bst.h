#ifndef BST_H
#define BST_H
#include "node.h"
#include <unordered_map>
#include <fstream>
#include <sstream>


class BST {

    
    private:
    // ============= attributes =============
    Node* root;

    // ============= private methods =============
    Node* insertIp(Node* root, const size_t& key, const std::string& ip) { // Inserting recursively the new ip into its node by accessNum
        if (!root) return new Node(key, ip); 
        else if (key > root->accessNum) root->right = insertIp(root->right, key, ip); // buscando recursivamente al nodo que tenga una 
        else if (key < root->accessNum) root->left = insertIp(root->left, key, ip);
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

    void reverseInOrderTopTier(Node* root, std::unordered_map <std::string, size_t>& ipByAccess, size_t& topTier) const {
        /*
        let ipByAccess be a hash-map of pairs where IP spotted are storaged from greatest-to-less order
        let topTier represent the number of IP vectors to print in greatest-to-less order of accessNum
        */

        if (!root || topTier <= 0) return; // terminar las llamadas recursivas en caso de que el siguiente nodo a llamar sea nullptr o ya haya acabado el top tier
        reverseInOrderTopTier(root->right, ipByAccess, topTier); // llegar recursivamente al nodo que tenga las ips mas accesadas segun los logs
        for (const std::string& ip : root->ips) { // iterando sobre el vector de ips para almacenarlos en el hashmap
            if (topTier <= 0) break;
            ipByAccess[ip] = root->accessNum;
            topTier--;
        }

        reverseInOrderTopTier(root->left, ipByAccess, topTier); // recorriendo recursivamente desde el nodo con key mas grande hasta al nodo con menor key
    }

    void freeTree(Node* root) { // liberating memory from the BST
        if (!root) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }


    public:
    // ============= encapsulating methods =============
    BST() : root(nullptr) {} // constructor
    ~BST() { freeTree(root); } // liberating memory

    void insert(const size_t& key, const std::string& ip) { root = insertIp(root, key, ip); }

    std::unordered_map<std::string, size_t> topTier(size_t& remaining) {
        std::unordered_map<std::string, size_t> topT;
        reverseInOrderTopTier(root, topT, remaining);
        return topT;
    }

    void print() { reverseInOrder(root); }





};

#endif

