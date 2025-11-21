#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <string>

class Node {
    public:
    // ============= attributes =============
    size_t accessNum; // numero de veces que aparece una ip
    std::vector<std::string> ips; // ips que aparecen accessNum veces en los logs 
    Node* left;
    Node* right;

    // ============= methods =============
    Node(size_t accessNum, std::vector<std::string> ips) // constructor
        : accessNum(accessNum), ips(ips), left(nullptr), right(nullptr) {}
    
    Node(size_t accessNum, std::string ip)
        : accessNum(accessNum), ips{ip}, left(nullptr), right(nullptr) {}

};

#endif 