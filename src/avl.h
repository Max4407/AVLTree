#pragma once

#include <vector>
#include <regex>
#include "node.h"

class AVL {
private:
    Node* root;

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);

    int height(Node* node);
    bool insertHelper(Node* newNode, Node* node, Node* parent = NULL, bool left = 0);
    bool removeHelper(Node* node, int n , int& counter, Node* parent = NULL, bool left = 0);
    int balance(Node* node);

public:

    int size;

    AVL();
    ~AVL();

    bool insert(std::string name, std::string id);
    bool remove(std::string id, Node* node = NULL, Node* parent = NULL, bool left = 0);
    bool removeInorder(int n);

    std::string searchByID(std::string id, Node* node = NULL);
    std::vector<std::string> searchByName(std::string Name, Node* node = NULL);

    std::vector<std::string> preOrderNames(Node* node = NULL);
    std::vector<std::string> inOrderNames(Node* node = NULL);
    std::vector<std::string> postOrderNames(Node* node = NULL);

    std::vector<std::string> inOrderIDs(Node* node = NULL);

    int levelCount();
};