/**
* @file        NumbersList.cpp
* @description  Bağlı liste üzerinde istenilen işlemleri yapar.
* @course      2.Öğretim A Grubu 
* @assignment  1. ödev
* @date        23.11.2023
* @author      asudeyurt.@ogr.sakarya.edu.tr*/
#include <iostream>
#include "NumbersList.hpp"

NumbersList::NumbersList() : first(nullptr), currentNo(nullptr) {}

NumbersList::~NumbersList() {
     No* current = first;
    while (current != nullptr) {
        No* temp = current;
        current = current->next;
        delete temp;
    }
}

void NumbersList::addNo(No* no) {
    no->next = first;
    first = no;
    currentNo = no; // Yeni sayıyı güncel sayı olarak ayarlar
}


void NumbersList::TakeOddNumbers() {
    No* current = first;
    No* newFirst = nullptr; 
    No* temp;

    while (current != nullptr) {
        Node* nodeCurrent = current->first;
        No* newNo = new No();

        // Tek basamakları başa alır
        while (nodeCurrent != nullptr) {
            if (nodeCurrent->digit->value % 2 == 1) {
                newNo->addDigit(nodeCurrent->digit->value);
            }
            nodeCurrent = nodeCurrent->next;
        }

        // Çift basamakları ekle
        nodeCurrent = current->first;
        while (nodeCurrent != nullptr) {
            if (nodeCurrent->digit->value % 2 == 0) {
                newNo->addDigit(nodeCurrent->digit->value);
            }
            nodeCurrent = nodeCurrent->next;
        }

        // Yeni sayıyı ters çevir
        newNo->reserve();

        // Yeni sayıyı başa ekler
        newNo->next = newFirst;  // Bu satırı değiştirir
        newFirst = newNo;

        // Güncel sayıyı güncelle
        current = current->next;
    }

    // Listenin başını günceller 
    first = newFirst;  
}


void NumbersList::printNodeAddresses() {
    No* current = first;

    while (current != nullptr) {
        Node* nodeCurrent = current->first;

        // Sayıları yan yana yazdır
        while (nodeCurrent != nullptr) {
            std::cout << nodeCurrent->digit->value << "        ";
            nodeCurrent = nodeCurrent->next;
        }

        std::cout << std::endl;

        // Adresleri alt alta yazdır
        nodeCurrent = current->first;
        while (nodeCurrent != nullptr) {
            std::cout << nodeCurrent << " ";
            nodeCurrent = nodeCurrent->next;
        }

        std::cout << std::endl;  // Her düğüm seti arasında boş bir satır bırak

        current = current->next;
    }
}
 
 
 
 void NumbersList::TakeReserve() {
    No* current = first;

    while (current != nullptr) {
        current->reserve();
        current = current->next;
    } 
	
	
}
 

void NumbersList::printAllNumberAddresses() {// Bütün sayıların adreslerini yazar
    No* current = first;
    
	
    while (current != nullptr) {
       std:: cout << "Address for Number: " << current << std::endl;

        Node* nodeCurrent = current->first;

        std::cout << std::endl; 
        current = current->next;
    }
	
}
 int NumbersList::TakeLargestNo() {
    int largest = 0;
    No* largestNode = nullptr; // En büyük sayının bulunduğu düğümün adresi
    No* current = first;

    while (current != nullptr) {
        int currentNo = current->getNumber();
        int currentDigit = currentNo % 10; 

        if (currentNo > largest || (currentNo == largest && currentDigit > current->getNumber() % 10)) {
            largest = currentNo;
            largestNode = current;
        }

        current = current->next;
    }

    if (largestNode != nullptr) {
        
        std::cout << "Node Address: " << largestNode << std::endl;
    } else {
        std::cout << "List is empty." << std::endl;
    }

    return largest;
}