#include <iostream>
#include <string>
#include "mixcolumns.h"
#include "shiftrows.h"
#include "subbytes.h"

using namespace std;

struct CommandLineException
{
    CommandLineException(int m,int a)
    {
        cout << "\nToo many arguments on the command line.\n";
        cout << m << " argument(s) are permitted on the command line.\n";
        cout << a << " argument(s) appeared on the command line.\n";
    }
};

int main(int argc, char* argv[]){
    /*
    manage command line arguments as:
    "a.exe -[encrypt/decrypt] [message] [key]"
    if 3 are not presented, ask user for each 
    */
    try{
        bool decryptFlag = false;
        char flagString[255];
        string c;
        bool validInput = true;
        string message;
        string key;
        switch(argc){
            case 1:
                //get flag for Encrypt vs Decrypt
                do{
                    cout << "Enter '-decrypt' or '-encrypt'" << endl;                
                    cin >> flagString;
                    //FIX THIS ->
                    //c = tolower(flagString);
                    if(flagString == "-encrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else if (flagString == "-decrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                        validInput = false;
                    }
                } while (!validInput);

                cout << "Enter message to " << c << ":" << endl;
                cin >> message;

                cout << "Enter key:" <<endl;
                cin >> key;
                break;
            case 2:
                cout << "Enter message to " << c << ":" << endl;
                cin >> message;

                cout << "Enter key:" <<endl;
                cin >> key;
                break;
            case 3:
                cout << "Enter key:" <<endl;
                cin >> key;
                break;
            default:
                throw CommandLineException(3,argc-1);
                break;
        }
        /*
        i didnt think this far ahead when I started writing this...
        I guess this is where we would pass all our info into a mode
        of operation to break the message into the appropriate size
        */
    }
    catch(...){
        cout<<"Program Terminated!"<<endl;
        exit(EXIT_FAILURE);
    }


    return 0;
}