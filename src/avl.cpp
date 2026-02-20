#include "avl.h"

Node* AVL::rotateLeft(Node* node) {
    Node* grandchild = node->right->left;
    Node* new_parent = node->right;
    new_parent->left = node;
    node->right = grandchild;
    return new_parent;
}

Node* AVL::rotateRight(Node* node) {
    Node* grandchild = node->left->right;
    Node* new_parent = node->left;
    new_parent->right = node;
    node->left = grandchild;
    return new_parent;
}

bool AVL::insert(std::string name, std::string id) {
    if (id.size() != 8)
        return false;

    std::regex names = std::regex("^[A-Za-z ]*$");
    std::regex ids = std::regex("^[0-9]+$");
    
    if (!std::regex_search(name, names) || !std::regex_search(id, ids))
        return false;

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


bool AVL::remove(std::string id, Node* node, Node* parent, bool left) {
    if (node == NULL)
        node = root;
    if (node == NULL)
        return false;

    if (std::stoi(id) < std::stoi(node -> idNum)) {
        if (node -> left == NULL) 
            return false;
        bool state = remove(id,node -> left, node, true); 
        if (state)
            (node -> balance)--;
        return state;
    } else if (std::stoi(id) > std::stoi(node -> idNum)) {
        if (node -> right == NULL)
            return false;
        bool state = remove(id,node -> right, node, false); 
        if (state)
            (node -> balance)++;
        return state;
    } else {
        if (node -> left == NULL && node -> right == NULL) {
            if (parent == NULL) {
                delete node;
                node = NULL;
                root = NULL;
                return true;
            }
            if (left)
                parent -> left = NULL;
            else 
                parent -> right = NULL;
            delete node;
            size--;
            return true;
        }
        if (node -> left != NULL && node -> right == NULL) {
            if (parent == NULL) {
                node -> student = node -> left -> student;
                node -> idNum = node -> left -> idNum;
                Node* temp = node -> left -> left;
                node -> right = node -> left -> right;
                delete node -> left;
                node -> left = temp;
                size--;
                return true;
            }
            if (left)
                parent -> left = node -> left;
            else 
                parent -> right = node -> left;
            delete node;
            size--;
            return true;
        }
        if (node -> right != NULL && node -> left == NULL) {
            if (parent == NULL) {
                node -> student = node -> right -> student;
                node -> idNum = node -> right -> idNum;
                Node* temp = node -> right -> right;
                node -> left = node -> right -> left;
                delete node -> right;
                node -> right = temp;
                size--;
                return true;
            }
            if (left)
                parent -> left = node -> right;
            else 
                parent -> right = node -> right;
            delete node;
            size--;
            return true;
        }
        if (node -> right != NULL && node -> left != NULL) {
            if (parent == NULL) {
                Node* successor = node -> right;
                while(successor -> left != NULL) {
                successor = successor -> left;
                }
                node -> student = successor -> student;
                node -> idNum = successor -> idNum;
                node -> right = successor -> right;
                delete successor;
                size--;
                return true;
            }
            Node* successor = node -> right;
            Node* successor_parent = NULL;
            while(successor -> left != NULL) {
                successor_parent = successor;
                successor = successor -> left;
            }
            node -> student = successor -> student;
            node -> idNum = successor -> idNum;
            delete successor;
            if (successor_parent == NULL)
                if (successor -> right != NULL)
                    node -> right = successor -> right;
                else 
                    node -> right = NULL;
            else {
                if (successor -> right != NULL)
                    successor_parent -> left = successor -> right;
                else 
                    successor_parent -> left = NULL;
            }
            (node -> balance)++;
            size--;
            return true;
        }
    }
    return false;
}

bool AVL::removeInorder(int n) {
    if (n >= size)
        return false;
    Node* node = root;
    if (node == NULL)
        return false;
    
    int counter = 0;
    return removeHelper(root, n ,counter);
}

bool AVL::removeHelper(Node* node, int n, int& counter, Node* parent, bool left) {
    bool state = false;
    if (node -> left != NULL)
        state = removeHelper(node -> left, n, counter, node, true);

    if (counter++ == n) 
        return remove(node->idNum,node,parent,left);

    if (node -> right != NULL)
        state = removeHelper(node -> right, n, counter, node, false);
    return state;
}

std::string AVL::searchByID(std::string id, Node* node) {
    if (node == NULL)
        node = root;
    if (node == NULL)
        return "unsuccessful";
    
    if (std::stoi(id) < std::stoi(node -> idNum)) {
        if (node -> left == NULL)
            return "unsuccessful";
        return searchByID(id,node -> left); 
    } else if (std::stoi(id) > std::stoi(node -> idNum)) {
        if (node -> right == NULL)
            return "unsuccessful";
        return searchByID(id,node -> right);
    } else
        return node -> student;
}

std::vector<std::string> AVL::searchByName(std::string Name, Node* node) {
    std::vector<std::string> ids;
    if (node == NULL)
        node = root;
    if (node == NULL)
        return std::vector<std::string> {};

    if (node -> student == Name)
        ids.push_back(node -> idNum);

    if (node -> left != NULL) {
        std::vector<std::string> temp = searchByName(Name, node -> left);;
        ids.insert(ids.end(),temp.begin(),temp.end());
    }

    if (node -> right != NULL) {
        std::vector<std::string> temp = searchByName(Name, node -> right);;
        ids.insert(ids.end(),temp.begin(),temp.end());
    }
    return ids;
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