# Banking-System
 This is a full banking system using OOP concepts and CPP
 
This projects was one of my college assignments that I enjoyed making it and I learned from it how to use OOP concepts in the real world.

The banking application allows the user, i.e., the bank employee to create a bank account for a specific client. It allows him to list all the available 
bank accounts. For each account, it allows him to display the account details, withdraw money and 
deposit money. 
There are two types of bank accounts. The first type is the basic BankAccount. It holds the 
following data: 
<br />
• <strong> account ID </strong> <br />
• <strong> balance </strong> <br />
The following methods apply to this class: 
<br />
• <strong> Constructor</strong>. There are 2 constructors. The first sets the balance to a given value. The second is 
a no-argument constructor and it sets the balance to 0. 
<br />
• <strong>Setters and getters</strong>. These methods allow accessing the private data fields. 
<br />
• <strong>withdraw</strong>. It withdraws an amount of money from the account if the balance is sufficient. 
<br />
• <strong>deposit</strong>. It deposits an amount of money in the account. 
<br />
The second type of accounts extends the basic Bank Account and may have some extra data fields 
and operations. It is called SavingsBankAccount. This account requires the user to keep a 
minimum amount of money in the account, which is called the minimum balance, as long as the 
account is open. It also requires him to make deposits that are not less than 100 a time. So, it has 
the following additional data field: 
<br />
• <strong>minimumBalance</strong> This minimum balance takes a default value of 1000 L.E. 
It has the following methods plus those inherited from the parent class: 
<br />
• <strong>Constructor</strong>. The constructor sets the value of the initial balance and the minimum balance. 
Initial balance should be >= min balance. 
<br />
• <strong>Setters and getters</strong>. These methods allow accessing the private data fields. 
<br />
• <strong>withdraw</strong>. It overrides the method withdraw to allow withdrawing money but not below the 
minimum balance. 
<br />
• <strong>deposit</strong>. It deposits an amount of money in the account but only if the amount is >= 100 LE. 

There is also a Client class which holds the basic information of a client like his name, address 
and phone number. It holds a pointer to his bank account. The main class that runs the application is BankingApplication. 
This class displays the main menu and accepts the user's choice. It maintains a list of accounts and clients. It allows the user to 
perform operations on a bank account. 

The following UML diagram describes the relationships between classes.

![image](https://user-images.githubusercontent.com/92688600/215230289-d29facd7-e382-4939-a4e4-c1df9fed8211.png)
