#include <iostream>
#include <string>

using namespace std;

//class check definitions
class check {
private:
    static int number;
    int checknum;
    string checkmemo;
    float checkamount;

public://default constructor setting
    check():checknum(++number), checkmemo(""),checkamount(0.0){

    }
// it getting them
    int getchecknum() const {return checknum;}
    string getcheckmemo() const {return checkmemo;}
    float getcheckamount()const{return checkamount;}
// it setting them
    void setcheckmemo(const string& memo){checkmemo= memo;}
    void setcheckamount(float amount){checkamount= amount; }

};

int check::number= 0

//definitions for checkbook
class checkbook{
private:
    static int allchecks;
    static const int n= 5;
    int numofchecks;
    float balance;
    check checks[n];

public://consturc
    checkbook(float initialbalance): numofchecks(0), balance(initialbalance){

    }
//getting for allchecks
static int getallchecks(){return allchecks;}
//function to write a check
bool writecheck(float amount){
    if (numofchecks >= n||allchecks>=10||amount>balance){
        return false;
    }
// getting user input
    cout<<"please enter check memo: ";
    cin.ignore();
    string memo;
    getline(cin,memo);
    checks[numofchecks].setcheckmemo(memo);
    checks[numofchecks].setcheckamount(amount);
//updating balance and numofchecks
    balance-= amount;
    numofchecks++;
    allchecks++;

    return true;
}
// function to display check details
    void displaychecks() const{
        for (int i= numofchecks -1; i>= 0; i--){
            cout<< checks[i].getchecksamout()<<" " <<checks[i].getchecknum()<<" "<< checks[i].getcheckmemo()<<endl;

        }
    }

};

int checkbook:: allchecks= 0;

int main(){//test the checkbook class
    checkbook cb1(1000), cb2(500);

    for (int i= 0; i< 10; i++){//perform check writing operations
        cout<<"memo?" <<endl;
        cb1.writecheck(150);

        cout<< "memo? "<< endl;
        cb2.writecheck(130);

    }//displaying details for cb1 and 2
    cout << "cb1 check details"<< endl;
    cb1.displaychecks();

    cout<< "cb2 check details " <<endl;
    cb2.displaychecks();

    cout<< cb1.getallchecks()<<endl;//displaying the total number of checks for both
    cout<< cb2.getallchecks()<< endl;



    return 0;
}
