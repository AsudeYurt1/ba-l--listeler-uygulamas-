/**
* @file        Number.cpp
* @description  Bağlı liste üzerinde istenilen işlemleri yapar.
* @course      2.Öğretim A Grubu 
* @assignment  1. ödev
* @date        23.11.2023
* @author      asudeyurt.@ogr.sakarya.edu.tr*/
#include <iostream>
#include "Number.hpp"
using namespace std;

No::No() : first(nullptr), next(nullptr) {}

No::~No() {
    Node* current = first;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int No::getNumber() const {
    int number = 0;
    Node* current = first;

    while (current != nullptr) {
        number = number * 10 + current->digit->value;
        current = current->next;
    }

    return number;
}
void No::addDigit(int vvalue) {
    Node* newNode = new Node(vvalue);
    newNode->next = first;
    first = newNode;
}

 void No::reserve() {// Düğümleri ters sırayla bağlar
    
	Node* prev = nullptr;
    Node* current = first;
    Node* nnext = nullptr;

    while (current != nullptr) {
        nnext = current->next;
        current->next = prev;
        prev = current;
        current = nnext;
    }

    first = prev;
}
 
int No::TakeLargestDigit() {// En büyük basamağı bulur
    
	int large= 0;
    Node* current = first;
    while (current != nullptr) {
        int currentBig = current->digit->value;
        large = (currentBig> large) ? currentBig : large;
        current = current->next;
    }
    return large;
}

void No::TakeOddNumbers() {// Tek basamakları başa alır
    
	Node* prev = nullptr;
    Node* current = first;
    Node* nnext = nullptr;

    while (current != nullptr) {
        nnext = current->next;
        current->next = prev;
        prev = current;
        current = nnext;
    }

    first = prev;
}

