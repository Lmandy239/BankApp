//Armando Laguardia

#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <iomanip>
using namespace std;

//method delcarations to be implemented in the cpp file
class Bank {
    //all public methods
public:
    void displayDataMenu(double investment, double deposit, double interest, double years);
    void reportTableDisplay1(double investment, double deposit, double interest, double years);
    void reportTableDisplay2(double investment, double deposit, double interest, double years);
    void interactiveMenu();
    double calculateTotalAmount(double opening, double deposit);
    double calculateInterest(double opening, double deposit, double interest);
    //formatting method - private
private:
    string nCharString(size_t n, char c);
};

#endif
