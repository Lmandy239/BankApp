//Armando Laguardia

#include "Bank.h"

// Formatting function
string Bank::nCharString(size_t n, char c) {
    return string(n, c);
}
//display menu that uses parameters to later pass in input
void Bank::displayDataMenu(double investment, double deposit, double interest, double years) {
    cout << string(34, '*') << endl;    
    cout << string(10, '*') << " Data Input " << string(12, '*') << endl;
    cout << "Initial investment: " << investment << endl;
    cout << "Monthly Deposit: " << deposit << endl;
    cout << "Annual interest: " << interest << endl;
    cout << "Number of Years: " << years << endl;
    cout << "Press 1 to continue...: " << endl;
    cout << string(34, '*') << endl;    
    cout.flush();
}

//first display table that takes into account the monthly deposit
void Bank::reportTableDisplay1(double investment, double deposit, double interest, double years) {
  //just changed variable names to avoid confusio, but im assigning variables to the paramaters 
   double openingAmount = investment;
    double depositedAmount, total, interestAmount, closingBalance;
    //I originally had it for years, but decided to stick with months to show the math in depth 
    int months = years * 12;
    cout << "\n";
    cout << "Table One: Balance and Interest With Additional Monthly Deposits (Monthly)" << endl;

    cout << string(117, '_') << endl;    
    //Below we are using the setW method to create "columns"
    cout << fixed << setprecision(2);
    cout << "||" 
         << setw(10) << "Month" 
         << setw(20) << "Opening Amount" 
         << setw(20) << "Deposited Amount" 
         << setw(20) << "Total" 
         << setw(20) << "Interest" 
         << setw(20) << "Closing Balance"
         << setw(5) << "||"
         << endl;
    
    //for loop that iterates new rows as long as the yearly input is less than or equal to the passed total years
    for (int month = 1; month <= months; ++month) {
        //all the math as per the rubric
        depositedAmount = deposit;
        total = openingAmount + depositedAmount;
        interestAmount = total * ((interest / 100) / 12);
        closingBalance = total + interestAmount;
        //using setw method again to put the outputs in their corresponding columns (Must match the one above)
        cout << "||" << setw(10) << month 
             << setw(20) << openingAmount 
             << setw(20) << depositedAmount 
             << setw(20) << total 
             << setw(20) << interestAmount 
             << setw(20) << closingBalance 
             << setw(5) << "||"
             << endl;
        //setting the opening amount to the closing amount so that the next row starts with it
        openingAmount = closingBalance;
        
    }    
    cout << string(117, '_') << endl;    
    cout << "\n";
    cout << "Table Two: Balance and Interest Without Additional Monthly Deposits (Yearly)" << endl;
    cout << "\n";
}

//second desplay table without the added deposits
void Bank::reportTableDisplay2(double investment, double deposit, double interest, double years) {
   double openingAmount = investment;
    double depositedAmount, total, interestAmount, closingBalance;


    cout << string(117, '_') << endl;    
    //Below we are using the setW method to create "columns"
    cout << fixed << setprecision(2);
    cout << "||" 
         << setw(10) << "Year" 
         << setw(20) << "Opening Amount" 
         << setw(20) << "Deposited Amount" 
         << setw(20) << "Total" 
         << setw(20) << "Interest" 
         << setw(20) << "Closing Balance" 
         << setw(5) << "||"

         << endl;
    
       

    //for loop that iterates new rows as long as the yearly input is less than or equal to the passed total years
    for (int year = 1; year <= years; ++year) {
       
        //all the math as per the rubric
        depositedAmount = 0;
        total = openingAmount + depositedAmount;
        interestAmount = total * ((interest / 100));
        closingBalance = total + interestAmount;

        
        cout << "||" 
             << setw(10) << year 
             << setw(20) << openingAmount 
             << setw(20) << depositedAmount 
             << setw(20) << total 
             << setw(20) << interestAmount 
             << setw(20) << closingBalance
             << setw(5) << "||"
             << endl;
        
        //setting the opening amount to the closing amount so that the next row starts with it
        openingAmount = closingBalance;
        
    }
    cout << string(117, '_') << endl;
    cout << "\n";
   
}

//interactive menu for inputs
void Bank::interactiveMenu() {
    int choice;
    //simple trigger to enter initial data
    do {
        cout << "Please choose from the following:\n"
             << " 1. Enter data into bank app\n"
             << " 2. Quit" << endl;
        cin >> choice;
        double inv, dep, intRate, year;

        switch (choice) {
            case 1:
                cout << "Enter your initial investment: " << endl;
                cin >> inv;
                cout << "Enter your monthly deposit: " << endl;
                cin >> dep;
                cout << "Enter annual interest rate: " << endl;
                cin >> intRate;
                cout << "Enter the amount of years: " << endl;
                cin >> year;
                //passing down inputs to the display data table
                displayDataMenu(inv, dep, intRate, year);

                // Input key to continue
                cin >> choice;
                if (choice == 1) {
                    //calling the tables and passing the inputs
                    reportTableDisplay1(inv, dep, intRate, year);
                    reportTableDisplay2(inv, dep, intRate, year);
                } else {
                    cout << "Wrong input, goodbye!" << endl;
                }
                break;
            case 2:
                cout << "GoodBye!" << endl;
                break;
            default:
                cout << "Try again" << endl;
                break;
        }
        //to loop that default condition
    } while (choice != 2);
}
