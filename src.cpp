#include "header.h"
BankAccount::BankAccount(double balance){
    while(balance<=0){
        cout << "Please Enter a Valid Balance =========> ";
        cin >> balance;
    }
    this->balance = balance;
    accountID++;
    type = "Basic";
}
BankAccount::BankAccount(){
    accountID++;
    this->balance = 0;
    this->type = "Basic";
}
int BankAccount::getID(){
    return this->accountID;
}
double BankAccount::getBalance(){
    return this->balance;
}
int BankAccount::withdraw(double amount){
    if (amount <= this->balance && amount >= 0)
    {
        this->balance -= amount;
        return this->balance;
    }
    return -1;
}
string BankAccount::getType(){
    return this->type;
}
int BankAccount::deposit(double amount){
    if (amount > 0){
        this->balance += amount;
        return this->balance;
    }
    return -1;
}
SavingsBankAccount::SavingsBankAccount(double balance):BankAccount(){
    while (balance < this->minimumBalance)
    {
        cout << "Please Deposit Amount of Money Larger Than " << this->minimumBalance << " L.E. =========> ";
        cin >> balance;
    }
    this->balance = balance;
    this->type = "Saving";
}
double SavingsBankAccount::getMinBalance(){
    return this->minimumBalance;
}
int SavingsBankAccount::withdraw(double amount){
    if ( ( (this->balance - amount) >= this->minimumBalance) && amount >= 0){
        this->balance -= amount;
        return this->balance;
    }
    return -1;
}
int SavingsBankAccount::deposit(double amount){
    if (amount >= 100 && amount > 0)
    {
        this->balance += amount;
        return this->balance;
    }
    return -1;
}
Client::Client(string address,string name,int phonenumber){
    this->address = address;
    this->name = name;
    this->phoneNumber = phonenumber;
    int n;
    double balance;
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving || Type 1 or 2 =========> ";
    cin >> n;
    cout << "Please Enter the Starting Balance =========> ";
    cin >> balance;
    if(n==1){
        bankAccount = new BankAccount(balance);
    }
    else if(n==2){
        bankAccount = new SavingsBankAccount(balance);
    }
}
string Client::getName(){
    return this->name;
}
string Client::getAddress(){
    return this->address;
}
int Client::getPhoneNum(){
    return this->phoneNumber;
}
BankAccount *Client::getBankAccount(){
    return bankAccount;
}
BankingApplication::BankingApplication(){
    while(true){
        int n;
        cout << "Welcome to FCAI Banking Application" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. List Clients and Accounts" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "Please Enter Choice =========> ";
        cin >> n;
        if(n==1){
            addClient();
            cout << "An account was created with ID " << clients.back().getBankAccount()->getID() << " and Starting Balance " << clients.back().getBankAccount()->getBalance() << " L.E." << endl;
        }
        else if(n==2){
            listClients();
        }
        else if(n==3){
            withdrawMoney();
        }
        else if(n==4){
            depositMoney();
        }
        cout << "-------------------------------------------------------------------" << endl;
    }
}
void BankingApplication::depositMoney(){
        double amount;
        int client_index = getClientIndex();
        cout << "Please Enter The Amount to Deposit =========> ";
        cin >> amount;
        while(clients[client_index].getBankAccount()->deposit(amount)==-1){
            cout << "Sorry. This is less than what you can Deposit. " << endl;
            cout << "Please Enter The Amount to Deposit =========> ";
            cin >> amount;
        }
        cout << "Thank you. " << endl;
        cout << "Account ID: " << clients[client_index].getBankAccount()->getID() << endl;
        cout << "New Balance: " << clients[client_index].getBankAccount()->getBalance() << endl;
}
void BankingApplication::withdrawMoney(){
        double amount;
        int client_index = getClientIndex();
        cout << "Please Enter The Amount to Withdraw =========> ";
        cin >> amount;
        while(clients[client_index].getBankAccount()->withdraw(amount)==-1){
            cout << "Sorry. This is more than what you can withdraw. " << endl;
            cout << "Please Enter The Amount to Withdraw =========> ";
            cin >> amount;
        }
        cout << "Thank you. " << endl;
        cout << "Account ID: " << clients[client_index].getBankAccount()->getID() << endl;
        cout << "New Balance: " << clients[client_index].getBankAccount()->getBalance() << endl;
}
int BankingApplication::getClientID(int id){
    for (int i = 0; i < clients.size(); i++)
    {
        if(id==clients[i].getBankAccount()->getID()){
            cout << "Account ID: " << clients[i].getBankAccount()->getID() << endl;
            cout << "Acocunt Type: " << clients[i].getBankAccount()->getType() << endl;
            cout << "Balance: " << clients[i].getBankAccount()->getBalance() << endl;
            return i;
        }
    }
    return -1;
}
int BankingApplication::getClientIndex(){
    int id,client_index;
    cout << "Please Enter Account ID =========> ";
    cin >> id;
    while((client_index=getClientID(id))==-1){
        cout << "Account ID Was Not Found " << endl;
        cout << "Please Enter Account ID =========> ";
        cin >> id;
    }
    return client_index;
}
void BankingApplication::addClient(){
    string name, address;
    int phone;
    cout << "Please Enter Client Name =========> ";
    cin.ignore();
    getline(cin, name);
    cin.ignore();
    cout << "Please Enter Client Address =======> ";
    getline(cin, address);
    cout << "Please Enter Client Phone =======> ";
    cin >> phone;
    clients.push_back(Client(address, name, phone));
}
void BankingApplication::listClients(){
    for (int i = 0; i < clients.size(); i++)
    {
        cout << "-------------------------- " << clients[i].getName() << " --------------------------" << endl;
        cout << "Address: " << clients[i].getAddress() << ", Phone: " << clients[i].getPhoneNum() << endl;
        cout << "Account ID: " << clients[i].getBankAccount()->getID() << " (" << clients[i].getBankAccount()->getType() << ")" << endl;
        cout << "Balance: " << clients[i].getBankAccount()->getBalance() << endl;
    }
}