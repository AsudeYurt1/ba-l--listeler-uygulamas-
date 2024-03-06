/**
* @file        main.cpp
* @description  Bağlı liste üzerinde istenilen işlemleri yapar.
* @course      2.Öğretim A Grubu 
* @assignment  1. ödev
* @date        23.11.2023
* @author      asudeyurt.@ogr.sakarya.edu.tr*/

#include <iostream>
#include <fstream>
#include "NumbersList.hpp"
using namespace std;

 void read(NumbersList& numbersList){ // Dosyayı okuyan fonksiyon 
	 ifstream dosya("Numbers.txt");
    if (dosya.is_open()) {
        int no;
        while (dosya >> no) {
            No* newNo = new No();
            while (no > 0) {
                int digit = no % 10;
                newNo->addDigit(digit);
                no /= 10;
            }
            numbersList.addNo(newNo);
        }
        dosya.close();
    } else {
        cout << "txt file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    
 }
int main() {
    int choice;
	
   NumbersList numbersList;
   read(numbersList);
   

    do {
        
		
	cout <<"***************** MENU ******************"<<endl; /* Menü */ 
	cout << "1-> Bring the single digits to the beginning."<<endl;
    cout << "2-> Print digits in reverse"<<endl;
    cout << "3-> Print the largest number"<<endl;
    cout << "4-> To exit the program"<<endl;;
    cout << "Choice : ";
		
        cin >> choice;
		cout<<endl;

        switch (choice) {
            case 1:
                numbersList.TakeOddNumbers();
				numbersList.printNodeAddresses(); 
			    numbersList.printAllNumberAddresses();
				
                break;
            case 2:
                numbersList.TakeReserve();
				numbersList.printNodeAddresses();
				numbersList.printAllNumberAddresses();

                break;
            case 3:
                numbersList.TakeReserve();
				cout << "The largest number : " << numbersList.TakeLargestNo() << endl;
                break;
            case 4:
			cout <<"Exit"<<endl;
               
                break;
            default:
                cout << "Please try again"<<endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
