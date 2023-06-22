#include <iostream>
#include <limits>

// This code is not finished and is an idea. This is not as functional and stable. 

class TrueBank {
private:
    std::string name;
    int bal;
public:
    void openingBalance();
    void deposit();
    void withdraw();
    void display();
};

int menu();

int main() {
    TrueBank bank;
    int choice;

    while (true) {
        choice = menu();
        switch (choice) {
            case 1:
                bank.openingBalance();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.display();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Choose 1 - 5 Only!" << std::endl;
        }
    }
}

int menu() {
    int choice;
    
    system("cls");

    std::cout << "WELCOME TO TRUE BANK" << std::endl << std::endl;
    std::cout << "(1) Setup Your Opening Balance" << std::endl;
    std::cout << "(2) Deposit Money" << std::endl;
    std::cout << "(3) Withdraw Money" << std::endl;
    std::cout << "(4) Account Details" << std::endl;
    std::cout << "(5) Cancel Transaction" << std::endl;
    std::cout << std::endl;
    std::cout << "Input Choice Here: ";
    std::cin >> choice;

    return choice;
}

void TrueBank::openingBalance() {
    system("cls");
    std::cout << "Enter Account Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Enter Opening Balance: ";
    std::cin >> bal;
    std::cout << "Your New Balance is: " << bal << std::endl;
    system("pause");
}

void TrueBank::deposit() {
    int deposit = 0;
    system("cls");

    std::cout << "Enter the Amount You Want to Deposit: ";
    std::cin >> deposit;
    bal += deposit;
    std::cout << "Your New balance is: " << bal << std::endl;
    system("pause");
}

void TrueBank::withdraw() {
    int withdraw;

    system("cls");

    std::cout << "Your Current Balance is: " << bal << std::endl;
    std::cout << "Enter the Amount You Want to Withdraw: ";
    std::cin >> withdraw;
    if (bal >= withdraw) {
        bal -= withdraw;
        std::cout << "Your New Balance is: " << bal << std::endl;
    }
    else {
        std::cout << "You Don't Have Enough Balance." << std::endl;
    }
    system("pause");
}

void TrueBank::display() {
    system("cls");

    std::cout << "BANK ACCOUNT DETAILS" << std::endl << std::endl;
    std::cout << "Account Name: " << name << std::endl;
    std::cout << "Your Balance: " << bal << std::endl;
    std::cout << std::endl;
    system("pause");
}
