#pragma once

#include <vector>
#include "node.h"

class AVL {
private:
    Node* root;

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);

    int height(Node* node);
    bool insertHelper(Node* newNode, Node* node, Node* parent = NULL, bool left = 0);

public:
    AVL();
    ~AVL();

    int size;

    bool insert(std::string name, std::string id);
    Node* remove(std::string id);

    std::string searchByID(std::string id);
    std::vector<std::string> searchByName(std::string Name);

    std::vector<std::string> preOrderNames(Node* node = NULL);
    std::vector<std::string> inOrderNames(Node* node = NULL);
    std::vector<std::string> postOrderNames(Node* node = NULL);

    int levelCount();
};