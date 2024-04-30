# Simple-Bank-System-in-Cpp

⚠ Download Both main and header file always

---------------------------------------------


Breif Problem Statement 👇

Instructions:
You are tasked with developing a simple banking system program in C++ that allows users to create bank accounts, deposit and withdraw funds, check balances, and perform other operations. Your program should incorporate the following features:

BankAccount Class:
The BankAccount class represents individual bank accounts and should have private member variables for account number, balance, and owner's name.
Implement constructors to initialize the account with default values and with user-defined values. Ensure proper initialization of member variables using constructor initializer lists.
Implement a destructor to release any dynamically allocated memory.
Use appropriate access specifiers to encapsulate data and methods effectively.

Transactions:
Implement methods to deposit and withdraw funds from the account. Ensure that withdrawal is only allowed if the balance is sufficient.
Use pointer(s) to manage transactions history (e.g., an array of transaction objects). Implement appropriate memory management techniques to handle dynamic memory allocation.

Static Attribute and Methods:
Introduce a static attribute to keep track of the total number of accounts created.
Implement a static method to calculate and return the average balance across all accounts.

Operator Overloading:
Overload the + operator to allow adding funds to an account.
Overload the - operator to allow withdrawing funds from an account.
Overload the << operator to allow displaying account information.

Friend Function:
Implement a friend function to display detailed account information, including owner's name, account number, and balance.

Input:
The user will interact with the program via a simple command-line interface.
Users can choose from various operations such as creating an account, depositing funds, withdrawing funds, checking balance, and displaying account details.
The user will provide necessary inputs as prompted by the program.

Output:
The program should provide appropriate messages to inform the user about the outcome of each operation (e.g., success or failure).
Display account information, transaction history, and average balance as requested by the user.


Example:
Welcome to the Simple Banking System!

1. Create Account
2. Deposit Funds
3. Withdraw Funds
4. Check Balance
5. Display Account Details
6. Exit

Enter your choice: 1
Enter owner's name: John Doe
Enter initial balance: 1000
Account created successfully!

Enter your choice: 2
Enter account number: 1001
Enter amount to deposit: 500
500 deposited successfully.

Enter your choice: 3
Enter account number: 1001
Enter amount to withdraw: 700
Insufficient balance!

Enter your choice: 4
Enter account number: 1001
Balance: $500

Enter your choice: 5
Enter account number: 1001

Account Details:
Owner's Name: John Doe
Account Number: 1001
Balance: $500
Transaction History:
1. Deposit: +$500
Total Transactions: 1

Enter your choice: 6
Exiting the program. Thank you!
