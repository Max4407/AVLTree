#include "node.h"

Node::Node() {
    idNum = "";
    student = "";

    left = NULL;
    right = NULL;

    balance = 0;
}

Node::Node(std::string name, std::string id) {
    idNum = id;
    student = name;

    left = NULL;
    right = NULL;   

    balance = 0;
}

Node::Node(Node& other) {
    idNum = other.idNum;
    student = other.student;
    balance = other.balance;

    if (other.left != NULL)
        left = new Node(*other.left);
    else 
        left = NULL;
    if (other.right != NULL)
        right = new Node(*other.right);
    else   
        right = NULL;
}

Node::Node(Node&& other) {
    idNum = other.idNum;
    student = other.student;
    balance = other.balance;

    if (other.left != NULL)
        left = new Node(*other.left);
    else 
        left = NULL;
    if (other.right != NULL)
        right = new Node(*other.right);
    else   
        right = NULL;
}

Node& Node::operator=(Node& other) {
    this -> idNum = other.idNum;
    this -> student = other.student;
    this -> balance = other.balance;

    if (other.left != NULL)
        this -> left = new Node(*other.left);
    else 
        this -> left = NULL;
    if (other.right != NULL)
        this -> right = new Node(*other.right);
    else   
        this -> right = NULL;
    
    return *this;
}

Node& Node::operator=(Node&& other) {
    this -> idNum = other.idNum;
    this -> student = other.student;
    this -> balance = other.balance;

    if (other.left != NULL)
        this -> left = new Node(*other.left);
    else 
        this -> left = NULL;
    if (other.right != NULL)
        this -> right = new Node(*other.right);
    else   
        this -> right = NULL;
    
    return *this;
}

Node::~Node() {
    idNum = "";
    student = "";
    balance = 0;

    left = nullptr;
    right = nullptr; //dont want to delete left and right because it will cause removing root to remove whole tree
}