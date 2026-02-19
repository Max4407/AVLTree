#include "avl.h"
#include <iostream>

Node* AVL::rotateLeft(Node* node) {
    Node* grandchild = node->right->left;
    Node* new_parent = node->right;
    new_parent->left = node;
    node->right = grandchild;
    std::cout << new_parent -> student;
    std::cout << node -> student;
    return new_parent;
}

Node* AVL::rotateRight(Node* node) {
    Node* grandchild = node->left->right;
    Node* new_parent = node->left;
    new_parent->right = node;
    node->left = grandchild;
    std::cout << new_parent -> student;
    std::cout << node -> student;
    return new_parent;
}


bool AVL::insert(std::string name, std::string id) {
    if (root == NULL) {
        root = new Node(name,id);
        size = 1;
        return true;
    } 
    Node* newNode = new Node(name,id); 
    bool success = insertHelper(newNode,root);
    if (success)
        size++;      
    return success;
}

bool AVL::insertHelper(Node* newNode, Node* node, Node* parent, bool left) {  

    bool state = 0;

    if (std::stoi(newNode -> idNum) > std::stoi(node -> idNum)) {
        if (node -> right == NULL) {
            node -> right = newNode;
            (node -> balance)--;
            return true;
        }
        else {
            state = insertHelper(newNode, node -> right, node, false);
            if (state && (--(node -> balance) <= -2)) {
                if (node -> right -> balance == -1)
                    node = rotateLeft(node);
                if (node -> right -> balance == 1) {
                    node -> right = rotateRight(node -> right);
                    node = rotateLeft(node);
                }
            }
        }
    }
    else if (std::stoi(newNode -> idNum) < std::stoi(node -> idNum)) {
        if (node -> left == NULL) {
            node -> left = newNode;
            (node -> balance)++;
            return true;
        }
        else {
            state = insertHelper(newNode, node -> left, node, true);
            if (state && (++(node -> balance) >= 2)) {
                if (node -> left -> balance == -1) {
                    node -> left = rotateLeft(node -> left);
                    node = rotateRight(node);
                }
                if (node -> left -> balance == 1) 
                    node = rotateRight(node);
            }
        }
    } else 
        return false;
    if (parent == NULL)
        root = node;
    else {
        if (left)
            parent -> left = node;
        else 
            parent -> right = node;
    }
    return state;
}


Node* AVL::remove(std::string id) {
    return new Node();
}

std::string AVL::searchByID(std::string id) {
    return "";
}

std::vector<std::string> AVL::searchByName(std::string Name) {
    return std::vector<std::string>{};
}


std::vector<std::string> AVL::preOrderNames(Node* node) {
    if (node == NULL)
        node = root;
    if (node == NULL)
        return std::vector<std::string> {};
    std::vector<std::string> names;
    names.push_back(node -> student);
    if (node -> left != NULL) {
        std::vector<std::string> temp = preOrderNames(node -> left);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    if (node -> right != NULL) {
        std::vector<std::string> temp = preOrderNames(node -> right);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    return names;
}

std::vector<std::string> AVL::inOrderNames(Node* node) {
    if (node == NULL)
        node = root;
    if (node == NULL)
        return std::vector<std::string> {};
    std::vector<std::string> names;
    if (node -> left != NULL) {
        std::vector<std::string> temp = inOrderNames(node -> left);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    names.push_back(node -> student);
    if (node -> right != NULL) {
        std::vector<std::string> temp = inOrderNames(node -> right);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    return names;
}

std::vector<std::string> AVL::postOrderNames(Node* node) {
    if (node == NULL)
        node = root;
    if (node == NULL)
        return std::vector<std::string> {};
    std::vector<std::string> names;
    if (node -> left != NULL) {
        std::vector<std::string> temp = postOrderNames(node -> left);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    if (node -> right != NULL) {
        std::vector<std::string> temp = postOrderNames(node -> right);
        names.insert(names.end(),temp.begin(),temp.end());
    }
    names.push_back(node -> student);
    return names;
}

int AVL::levelCount() {
    if (root == NULL)
        return 0;
    return 1 + std::max(height(root -> left),height(root -> right));
}

int AVL::height(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + std::max(height(node -> left),height(node -> right));
}

AVL::AVL() {
    size = 0;
    root = NULL;
}

AVL::~AVL() {
    size = 0;
    delete root;
    root = nullptr;
}