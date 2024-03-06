#ifndef NUMBERSLIST_HPP
#define NUMBERSLIST_HPP

#include "Number.hpp"

class NumbersList {
public:
    No* first;  // Bağlı liste başlangıcını temsil eden pointer
    No* currentNo; // Güncel düğümü  temsil eden pointer

    NumbersList();
    ~NumbersList();
	void printAllNumberAddresses();
    void printNodeAddresses();
    int getNumber() const;
    void addNo(No* no);
    void TakeOddNumbers();
    void TakeReserve();
    int  TakeLargestNo();
};


#endif
