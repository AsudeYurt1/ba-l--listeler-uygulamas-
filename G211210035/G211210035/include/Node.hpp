#ifndef NODE_HPP
#define NODE_HPP

#include "Digit.hpp"

struct Node {

    Digit* digit;
    Node* next;

    Node(int vvalue);
    ~Node();
};

#endif