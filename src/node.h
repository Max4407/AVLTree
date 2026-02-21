#pragma once

#include <string>

struct Node {
    std::string student;
    std::string idNum;

    Node* left;
    Node* right;

    Node();
    Node(std::string name, std::string id);
    ~Node();

    Node(Node& other);
    Node(Node&& other);
    Node& operator=(Node& other);
    Node& operator=(Node&& other);
};