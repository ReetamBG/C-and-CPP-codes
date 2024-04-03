#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class account{
    protected:
    string name;
    int acc_no;
    float balance = 0;
    public:
    string acc_type;
    void initialise();
    void deposit();
    void display();
};

class curr_acc : public account{
    public:
    void chequeBook();
    void penalty();
};

class sav_acc : public account{
    public:
    void interest();
    void withdraw();
};

int main(){

    int choice, no;
    vector <account> acc;
    vector <curr_acc> curr_acc;
    vector <sav_acc> sav_acc;

    do{
        cout << "Choose Operation :" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Select Account and Choose Action" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice){
            case 1:
            cout << "Choose Account Type : " << endl;
            cout << "1. Current Account" << endl;
            cout << "2. Savings Account" << endl;
            cin >> choice;
            if(choice == 1){
                acc.resize(acc.size() + 1);
                acc[acc.size() - 1].acc_type = "Current";
                curr_acc.resize(acc.size() + 1);
                curr_acc[acc.size() - 1].initialise();
            }
            else if(choice == 2){
                acc.resize(acc.size() + 1);
                acc[acc.size() - 1].acc_type = "Savings";
                sav_acc.resize(acc.size() + 1);
                sav_acc[acc.size() - 1].initialise();
            }
            else{
                cout << "Invalid Option" << endl;
            }
            break;

            case 2:
            cout << "Choose account number : ";
            cin >> choice;
            if(acc[choice -1].acc_type == "Current"){
                do{
                    if(curr_acc.size() < choice){
                        curr_acc[choice - 1].acc_type = "Current";
                    }
                    else{
                        curr_acc[choice - 1].acc_type = "Current";
                        cout << "Account type : " << acc[choice - 1].acc_type << endl;
                        cout << "Choose Option : " << endl;
                        cout << "1. Deposit Money" << endl;
                        cout << "2. Write Cheque" << endl;
                        cout << "3. Display Info" << endl;
                        cout << "4. Check Penalty" << endl;
                        cout << "5. Back" << endl;
                        cin >> no;
                        switch(no){
                            case 1:
                            curr_acc[choice - 1].deposit();
                            break;
                            case 2:
                            curr_acc[choice - 1].chequeBook();
                            break;
                            case 3:
                            curr_acc[choice - 1].display();
                            break;
                            case 4:
                            curr_acc[choice - 1].penalty();
                            break;
                            case 5:
                            break;
                            default:
                            cout << "Invalid option" << endl;
                        }
                    }
                }
                while(no != 5);
            }
            if(acc[choice -1].acc_type == "Savings"){
                do{
                    if(sav_acc.size() < choice){
                        sav_acc[choice - 1].acc_type = "Savings";
                    }
                    else{
                        sav_acc[choice - 1].acc_type = "Savings";
                        cout << "Account type : " << acc[choice - 1].acc_type << endl;
                        cout << "Choose Option : " << endl;
                        cout << "1. Deposit Money" << endl;
                        cout << "2. Withdraw Money" << endl;
                        cout << "3. Check Interest" << endl;
                        cout << "4. Display Info" << endl;
                        cout << "5. Back" << endl;
                        cin >> no;
                        switch(no){
                            case 1:
                            sav_acc[choice - 1].deposit();
                            break;
                            case 2:
                            sav_acc[choice - 1].withdraw();
                            break;
                            case 3:
                            sav_acc[choice - 1].interest();
                            break;
                            case 4:
                            sav_acc[choice - 1].display();
                            case 5:
                            break;
                            default:
                            cout << "Invalid Option" << endl;
                        }
                    } 
                }
                while(no != 5);   
            }                   
        }
    }
    while(choice != 3);

    return 0;
}

//Function Definitions

void account :: initialise(){
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Account Number : ";
    cin >> acc_no;
}

void account :: deposit(){
    float amount;
    cout << "Enter deposit amount : ";
    cin >> amount;
    balance += amount;
}

void account :: display(){
    cout << "Account Holder Name : " << name << endl;
    cout << "Account Type : " << acc_type << endl;
    cout << "Account Number : " << acc_no << endl;
    cout << "The current balance is : " << balance << endl;
    cout << endl;
}

void curr_acc :: chequeBook(){
    float amount;
    do{
        cout << "Enter the amount to write on cheque ( Current Balance : " << balance << " ) : ";
        cin >> amount;
        if(amount > balance){
            cout << "Insufficient balance" << endl;
        }
    }
    while(amount > balance);
    balance -= amount;
}

void curr_acc :: penalty(){
    float penalty;
    if(balance < 500){
        balance -= ((2/100) * balance); 
        cout << "Penalty Imposed : " << ((2/100) * balance) << endl;       
    }
    else{
        cout << "No Penalty Imposed" << endl;
    }
}

void sav_acc :: interest(){
    int time;
    float interest;
    cout << "Enter the time period for interest ( In Years ) : ";
    cin >> time;
    interest = balance * pow((1 + (3/100)), time) - balance;
    balance = balance * pow((1 + (3/100)), time);
    cout << "Interest over " << time << " years : " << interest << endl;
}

void sav_acc :: withdraw(){
    float amount;
    do{
        cout << "Enter the amount to withdraw ( Current Balance : " << balance << " ) : ";
        cin >> amount;
        if(amount > balance){
            cout << "Insufficient balance" << endl;
        }
    }
    while(amount > balance);
    balance -= amount;
}

