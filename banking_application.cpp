#include<iostream>
using namespace std;
double account_amount = 50000;
bool balance(double amount){
    bool decision;
    if (amount <=10000) {
        cout<<"Your amount is less to perform withdrawl, please deposit sufficient amount"<<'\n';
        decision = false;
    }
    else{
        decision = true;
    }
    return decision;

}
double deposit(double amount,double deposit_amount){
    amount += deposit_amount;
    return amount;
}
double withdrawl(double amount,double withdrawl_amount){
    if (withdrawl_amount > amount) {
        cout<<"The withdrawl amount specified exceeds the balance amount, please enter valid amount"<<'\n';
    }
    else {
        amount -= withdrawl_amount;
    }
    return amount;
}

int main () {
    bool required_balance =  balance(account_amount);
    string deposit_decision;
    string withdrawl_decision;
    cout<<required_balance<<'\n';
    if (required_balance == 0) {
       cout<<"as your deposit is less, do your want to deposit any amount"<<'\n';
       cin>>deposit_decision;
    }
    else{
        cout<<"Do you want to withdraw the amount,then please provide your decision: ";
        cin>>withdrawl_decision;
        if (withdrawl_decision == "yes") {
            double withdraw_amount_again = 10000;
            ::account_amount =  withdrawl(account_amount,withdraw_amount_again);
            cout<<"Amount left : "<<account_amount<<'\n';
            while (account_amount >= withdraw_amount_again) {
                cout<<"Do you want to withdraw the amount,then please provide your decision: ";
                cin>>withdrawl_decision;
                account_amount =  withdrawl(account_amount,withdraw_amount_again);
                cout<<"Amount left : "<<account_amount<<'\n';
            }
            if (account_amount < 10000) {
                bool any_more_deposits;
                cout<<"Any deposit brother: ";
                cin>>any_more_deposits;
                while (any_more_deposits)
                {
                    account_amount += deposit(account_amount,25000);
                    cout<<"The amount added to account is :"<<account_amount<<'\n';
                    if (account_amount >= 50000) {
                        any_more_deposits = false;
                    }
                }
                
            }
            
        }
        else {
            cout<<"take care, bye"<<'\n';
        }
        //account_amount =  withdrawl(account_amount,10000);
    }
    if (deposit_decision == "yes") {
        account_amount += (account_amount,25000);
    }
    cout<<account_amount<<'\n';
    return 0;
}