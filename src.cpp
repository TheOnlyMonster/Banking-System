#include "header.h"
BankAccount::BankAccount(double b){
    while(b<=0){
        cout << "Please Enter a Valid Balance =========> ";
        cin >> balance;
    }
    this->balance = b;
    this->accountID++;
    this->type = "Basic";
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
    return balance;
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
    return type;
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
    int n;
    double balance;
    this->address = address;
    this->name = name;
    this->phoneNumber = phonenumber;
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
Client::Client(string address,string name,string phonenumber,string balance, char type){
    this->address = address;
    this->name = name;
    this->phoneNumber = stoi(phonenumber);
    if(type=='B'){
        bankAccount = new BankAccount(stod(balance));
    }
    else if(type=='S'){
        bankAccount = new SavingsBankAccount(stod(balance));
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
    readData();
    while(true){
        int n;
        cout << "Welcome to FCAI Banking Application" << '\n';
        cout << "1. Create a New Account" << '\n';
        cout << "2. List Clients and Accounts" << '\n';
        cout << "3. Withdraw Money" << '\n';
        cout << "4. Deposit Money" << '\n';
        cout << "0. Exit And Save" << '\n';
        cout << "Please Enter Choice =========> ";
        cin >> n;
        if(n==1){
            addClient();
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
        else if(n==0){
            break;
        }
        cout << "-------------------------------------------------------------------" << '\n';
    }
}
void BankingApplication::depositMoney(){
        double amount;
        int client_index = getClientIndex();
        cout << "Please Enter The Amount to Deposit =========> ";
        cin >> amount;
        while(client.at(client_index).getBankAccount()->deposit(amount)==-1){
            cout << "Sorry. This is less than what you can Deposit. " << '\n';
            cout << "Please Enter The Amount to Deposit =========> ";
            cin >> amount;
        }
        cout << "Thank you. " << '\n';
        cout << "Account ID: " << client.at(client_index).getBankAccount()->getID() << '\n';
        cout << "New Balance: " << client.at(client_index).getBankAccount()->getBalance() << '\n';
}
void BankingApplication::withdrawMoney(){
        double amount;
        int client_index = getClientIndex();
        cout << "Please Enter The Amount to Withdraw =========> ";
        cin >> amount;
        while(client.at(client_index).getBankAccount()->withdraw(amount)==-1){
            cout << "Sorry. This is more than what you can withdraw. " << '\n';
            cout << "Please Enter The Amount to Withdraw =========> ";
            cin >> amount;
        }
        cout << "Thank you. " << '\n';
        cout << "Account ID: " << client.at(client_index).getBankAccount()->getID() << '\n';
        cout << "New Balance: " << client.at(client_index).getBankAccount()->getBalance() << '\n';
}
int BankingApplication::getClientID(int id){
    for (auto it = client.begin(); it != client.end(); it++)
    {
        if(it->first==id){
            cout << "Account ID: " << it->first << '\n';
            cout << "Acocunt Type: " << it->second.getBankAccount()->getType() << '\n';
            cout << "Balance: " << it->second.getBankAccount()->getBalance() << '\n';
            return it->first;
        }
    }
    return -1;
}
int BankingApplication::getClientIndex(){
    int id, client_index;
    cout << "Please Enter Account ID =========> ";
    cin >> id;
    while((client_index=getClientID(id))==-1){
        cout << "Account ID Was Not Found " << '\n';
        cout << "Please Enter Account ID =========> ";
        cin >> id;
    }
    return client_index;
}
void BankingApplication::addClient(){
    string name, address;
    int phone;
    cout << "Please Enter Client First Name =========> ";
    cin >> name;
    cout << "Please Enter Client Address (Replace White Spaces with ,) =======> ";
    cin >> address;
    cout << "Please Enter Client Phone =======> ";
    cin >> phone;
    Client new_client(address, name, phone);
    client.insert({new_client.getBankAccount()->getID(),new_client});
    cout << "An account was created with ID " << client.rbegin()->second.getBankAccount()->getID() << " and Starting Balance " << client.rbegin()->second.getBankAccount()->getBalance() << " L.E." << '\n';
}
void BankingApplication::listClients(){
    for (auto it = client.begin(); it != client.end(); it++)
    {
        cout << "-------------------------- " << it->second.getName() << " --------------------------" << '\n';
        cout << "Address: " << it->second.getAddress() << ", Phone: " << it->second.getPhoneNum() << '\n';
        cout << "Account ID: " << it->first << " (" << it->second.getBankAccount()->getType() << ")" << '\n';
        cout << "Balance: " << it->second.getBankAccount()->getBalance() << '\n';
    }
}
void BankingApplication::readData(){
    BankData.open("C:/Users/abdel/OneDrive/Desktop/My-Github-Projects/Banking-System/BankingSystemData.txt",ios::in);
    string id;
    while(BankData >> id){
        string name, address, balance, type, phonenumber;
        BankData >> name;
        BankData >> balance;
        BankData >> type;
        BankData >> address;
        BankData >> phonenumber;
        Client existing_client(address, name, phonenumber, balance, type[0]);
        client.insert(pair<int, Client>(stoi(id),existing_client));
    }
    BankData.close();
}
BankingApplication::~BankingApplication(){
    BankData.open("C:/Users/abdel/OneDrive/Desktop/My-Github-Projects/Banking-System/BankingSystemData.txt",ios::out);
    for (auto it = client.begin(); it != client.end(); it++)
    {
        BankData << it->first << '\n';
        BankData << it->second.getName() << '\n';
        BankData << it->second.getBankAccount()->getBalance() << '\n';
        BankData << it->second.getBankAccount()->getType() << '\n';
        BankData << it->second.getAddress() << '\n';
        BankData << it->second.getPhoneNum() << '\n';
    }
    BankData.close();
}