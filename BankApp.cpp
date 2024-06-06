#include <iostream>
#include <iomanip>
// #include "ClockClass.cpp"
using namespace std;

//formating function
string nCharString(size_t n, char c) {
return string(n, c);
}


void displayDataMenu(double investment, double deposit, double interest, double years){
cout << string(34, '*') << endl;    
cout << string(10, '*') << " Data Input " << string(12, '*') << endl;
cout << "Initial investment: "<< investment << endl;
cout << "Monthly Deposit: " << deposit << endl;
cout << "Annual interest: " << interest << endl;
cout << "Number of Years: " << years << endl;
cout << "Press any key to continue...: " << endl;
cout.flush();
}

void interactiveMenu(int choice) {
    cout << "Hello, please choose from the following:\n"
         << " 1. Enter data into bank app\n"
         << " 2. Quit" << endl;

    double inv, dep, intRate, year;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter your initial investment: "<< endl;
        cin >> inv;
        cout << "Enter your monthly deposit: "<< endl;
        cin >> dep;
        cout << "Enter annual interest rate: "<< endl;
        cin >> intRate;
        cout << "Enter the amount of years: "<< endl;
        cin >> year;

        displayDataMenu(inv, dep, intRate, year);

        break;
    case 2:
        cout << "GoodBye!" << endl;
        break;
    default:
        cout << "Try again" << endl;
        interactiveMenu(choice);
        break;
    }
    
}


int main(){
    int choice;
    
    interactiveMenu(choice);

    return 0;
}

