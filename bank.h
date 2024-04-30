#include<iostream>
#include<string>
using namespace std;

class BankAccount {
private:
    string userName;
    int accountNumber;
    double balance;

    static int totalAccounts;
    static const int Max = 10;//suppose max 10 accounts for a bank
    static BankAccount accounts[Max];
    
    double* transactions;
    int transactionCount;

public:
	//constructor
    BankAccount(string name = "", int num = 0, double bal = 0) {
        userName = name;
        accountNumber = num;
        balance = bal;
		transactionCount=0;
        transactions=new double[Max];
		transactions[transactionCount++] = bal; 
    }
	//for deposit	
    void deposit(double amount) {
        balance += amount;
        transactions[transactionCount++] = amount;
    }
	//for withdraw
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions[transactionCount++] = -amount;
            return true;
        } else {
            cout << "Insufficient balance" << endl;
            return false;
        }
    }
	//balance return
    double getbalance() {
        return balance;
    }
   //display transitions
    double* getTransactions() const {
        return transactions;
    }
	//return total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
	//return transaction counts	
	int getTransactionCount() const {
        return transactionCount;
    }
    //creating new accounts or signup
    static BankAccount* createAccount(string userName, int accountNumber, double balance) {
        if (totalAccounts < Max) {
            accounts[totalAccounts++] = BankAccount(userName, accountNumber, balance);
            return &accounts[totalAccounts - 1];
        } else {
            cout << "Maximum number of accounts reached" << endl;
            return nullptr;
        }
    }
	//account slection or login
    static BankAccount* getAccount(int accountNumber) {
        for (int i = 0; i < totalAccounts; ++i) {
            if (accounts[i].accountNumber == accountNumber) {
                return &accounts[i];
            }
        }
        cout << "Account not found" << endl;
        return nullptr;
    }
	//average balance over all accounts
    static double getAverageBalance() {
        double totalBalance = 0.0;
        for (int i = 0; i < totalAccounts; ++i) {
            totalBalance += accounts[i].balance;
        }
        return totalBalance / totalAccounts;
    }
	//operator overloading to display account
    friend ostream& operator<<(ostream& out, const BankAccount& acc) {
        out << "Owner's userName: " << acc.userName << endl;
        out << "Account Number: " << acc.accountNumber << endl;
        out << "Balance:  " << acc.balance << endl;
        return out;
    }
	//operator overloading for deposit
	BankAccount& operator+(double amount) {
	    deposit(amount);
	    return *this;
	}
	//operator overloading for withdraw
    bool operator-(double amount) {
    if (withdraw(amount)) {
        return true;
    } else {
        return false;
    }
}

};
	//definitions
	BankAccount BankAccount::accounts[BankAccount::Max];
	int BankAccount::totalAccounts = 0;
	//display menu
	void menu() {
    cout << "\n1. Create Account\n2. Login Account\n\n3. Deposit Funds\n4. Withdraw Funds\n5. Check Balance\n\n6. Display Account Details\n7. Transactions History\n\n8. Average Balance \n9. Exit\n\nEnter your choice: ";
	}
	
	//end of header file