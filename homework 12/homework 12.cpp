//creator: Robert Ward
//homework 12
/*Purpose: the purpose for this program is to create a bank database where you can
add new clients to a text file within the same folder.
*/

#include <iostream>
#include <random>
#include <array>
#include <fstream>
#include <iostream>
#include <fstream>


using namespace std;


struct Data {
    //array :-)
    string name[2];
    int idNumber;
    string dateJoined;
    int cash;
    int creditScore;
};

void inputAccountInfo(Data& account) {
    cout << "   First Name: ";
    cin >> account.name[0];
    cout << "   Last Name: ";
    cin >> account.name[1];
    cout << "   ID Number: ";
    cin >> account.idNumber;
    cout << "   Date Joined: ";
    cin >> account.dateJoined;
    cout << "   Cash: ";
    cin >> account.cash;
    cout << "   Credit Score: ";
    cin >> account.creditScore;
}

int main () {
    
    Data* accountArray = nullptr;
    const char* username = getenv("USER");

    ///Users/robertward/Desktop/homework 12/tasks.txt
    string filePath = "/Users/" + string(username) + "/Desktop/homework 12/tasks.txt";


    ofstream outputFile(filePath, ios::app);


    cout << "please enter the amount of people you want to add" << endl << ": ";
    int numToAdd;

    cin >> numToAdd;


    accountArray = new Data[numToAdd];

    //input loop
    for (int i = 0; i < numToAdd; i++) {
        cout << "Account" << i+1 << ": \n";
        inputAccountInfo(accountArray[i]);
    }

    //output loop cause for some reason it needs this.
    for (int i = 0; i < numToAdd; i++) {
        outputFile << "Account" << i+1 << ": " << endl;
        outputFile << "     Name: " << accountArray[i].name[1] << ", " << accountArray[i].name[0] << endl;
        outputFile << "     ID Number: " << accountArray[i].idNumber << endl;
        outputFile << "     Date Joined: " << accountArray[i].dateJoined << endl;
        outputFile << "     Balance: $" << accountArray[i].cash << endl;
        outputFile << "     Credit Score: " << accountArray[i].creditScore << endl;
    }

    delete[] accountArray;

    return 0;
}