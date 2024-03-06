#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "Node.hpp"

class No {
public:
    Node* first;
    No* next; 

    No();
    ~No();
    void addDigit(int vvalue);
	int getNumber() const;
     void reserve(); 
    int  TakeLargestDigit();
    void TakeOddNumbers(); 
};

#endif  