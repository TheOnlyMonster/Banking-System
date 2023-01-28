#ifndef _HEADER_H
#define _HEADER_H
#include <bits/stdc++.h>
using namespace std;
class BankAccount{
    protected:
        double balance;
        string type;
        static int accountID;
    public:
        string getType();
        BankAccount(double);
        BankAccount();
        int getID();
        double getBalance();
        virtual int withdraw(double);
        virtual int deposit(double);
};
class SavingsBankAccount:public BankAccount{
    private:
        double minimumBalance = 1000;
    public:
        SavingsBankAccount(double);
        double getMinBalance();
        int withdraw(double);
        int deposit(double);
};
class Client{
    private:
        string name;
        string address;
        int phoneNumber;
        BankAccount *bankAccount;
    public:
        BankAccount *getBankAccount();
        Client(string,string,int);
        string getName();
        string getAddress();
        int getPhoneNum();
};
class BankingApplication{
    private:
        vector<Client> clients;
        void addClient();
        void depositMoney();
        void withdrawMoney();
        void listClients();
        int getClientID(int);
        int getClientIndex();
    public:
        BankingApplication();
};

#endif
