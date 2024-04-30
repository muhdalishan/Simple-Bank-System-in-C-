#include <iostream>
#include <string>
#include"bank.h"//check bank.h 
using namespace std;

int main() {
    cout << "Welcome to the Ali Banking System!\n";

    int choice, accountNumber;
    string userName;
    double balance, amount;

    BankAccount* currentAccount = nullptr;

    do {
        cout<<"_____________________________________"<<endl;
		menu();
        cin >> choice;
		system("cls");
		
        switch (choice) {
            case 1:
                cout << "Enter owner's Name: ";
                cin >> userName;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial balance: ";
                cin >> balance;
                currentAccount = BankAccount::createAccount(userName, accountNumber, balance);
                if (currentAccount != nullptr) {
                    cout << "Account created successfully!" << endl;
                }
                break;
            case 2:
                cout << "Enter your account number: ";
                cin >> accountNumber;
                currentAccount = BankAccount::getAccount(accountNumber);
                if (currentAccount != nullptr) {
                    cout << "Account selected successfully!" << endl;
                }
                break;
            case 3:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    *currentAccount + amount;
                    cout << " " << amount << " deposited successfully." << endl;
                break;
			case 4:
			        cout << "Enter amount to withdraw: ";
			        cin >> amount;
			        if (*currentAccount - amount) {
			            cout  << amount << " withdrawn successfully." << endl;
			        } else {
			            cout << "Withdrawal failed" << endl;
			        }
			    break;
            case 5:
                    cout << "Balance:  " << currentAccount->getbalance() << endl;
                break;
            case 6:
                    cout << *currentAccount << endl;
                break;
            case 8:
                cout << "Average Balance across all accounts:  " << BankAccount::getAverageBalance() << endl;
                break;
            case 7:
                cout << "Transaction History:" << endl;
				for (int i = 0; i < currentAccount->getTransactionCount(); ++i) {
				    double transactionAmount = currentAccount->getTransactions()[i];
				    string transactionType;
				    if (transactionAmount > 0) {
				        transactionType = "Deposit: ";
				    } else {
				        transactionType = "Withdrawal: ";
				        transactionAmount = transactionAmount; 
				    }
				    cout << transactionType << transactionAmount << endl;
				}
                break;
            case 9:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 9);

    return 0;
}
