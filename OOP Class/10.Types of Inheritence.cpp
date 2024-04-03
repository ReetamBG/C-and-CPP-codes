#include<iostream>
using namespace std;

class accounts{
};
class currentAccounts : public accounts{
};
class savingAccounts : public accounts{
};
class fixedDeposit : public accounts{
};
class shortTerm : public fixedDeposit{
};
class longTerm : public fixedDeposit{
};
class midTerm : public fixedDeposit{
};


int main(){

    

    return 0;
}