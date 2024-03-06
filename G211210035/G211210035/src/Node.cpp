/**
* @file        Node.cpp
* @description  Bağlı liste üzerinde istenilen işlemleri yapar.
* @course      2.Öğretim A Grubu 
* @assignment  1. ödev
* @date        23.11.2023
* @author      asudeyurt.@ogr.sakarya.edu.tr*/
#include "Node.hpp"

Node::Node(int vvalue) : next(nullptr) {
    digit = new Digit(vvalue);
}

Node::~Node() { // Node sınıfının yıkıcı fonksiyonu 
    delete digit;
}