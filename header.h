#ifndef _HEADER_H
#define _HEADER_H
#include <bits/stdc++.h>
using namespace std;
class BankAccount{
    protected:
        string type;
        static int accountID;
        double balance;
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
        Client(string, string, int);
        Client(string, string, string, string, char);
        string getName();
        string getAddress();
        int getPhoneNum();
};
class BankingApplication{
    private:
        fstream BankData;
        map<int, Client> client;
        void addClient();
        void readData();
        void depositMoney();
        void withdrawMoney();
        void listClients();
        int getClientID(int);
        int getClientIndex();
    public:
        BankingApplication();
        ~BankingApplication();
};

#endif
