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
    "$a.exe [encrypt/decrypt]~ [key]~"
    if 2 are not presented, ask user for each 
    */
    try{
        bool decryptFlag = false;
        string flagString;
        bool validInput = true;
        string message;
        string key;
        switch(argc){
            case 1:
                //get flag for Encrypt vs Decrypt
                do{
                    cout << "Enter 'decrypt' or 'encrypt'" << endl;                
                    cin >> flagString;
                    //FIX THIS ->
                    for(int i=0; flagString[i]; i++){
                        flagString[i] = tolower(flagString[i]);
                    }
                    if(flagString == "encrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else if (flagString == "decrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                        validInput = false;
                    }
                } while (!validInput);

                cout << "Enter key followed by \"~\":" <<endl;
                getline(cin, key, '~');

                cout << "Enter message followed by \"~\" to " << flagString << ":" << endl;
                getline(cin, message, '~');

                break;
            case 2:
                flagString = argv[1];
                do{
                    for(int i=0; flagString[i]; i++){
                        flagString[i] = tolower(flagString[i]);
                    }
                    if(flagString == "encrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else if (flagString == "decrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                        validInput = false;
                        cout << "Enter 'decrypt' or 'encrypt'" << endl;                
                        cin >> flagString;
                    }
                } while (!validInput);
                cout << "Enter key followed by \"~\":" <<endl;
                getline(cin, key, '~');
                cout << "Enter message followed by \"~\" to " << flagString << ":" << endl;
                getline(cin, message, '~');
                break;
            case 3:
                flagString = argv[1];
                do{
                    for(int i=0; flagString[i]; i++){
                        flagString[i] = tolower(flagString[i]);
                    }
                    if(flagString == "encrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else if (flagString == "decrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                        validInput = false;
                        cout << "Enter 'decrypt' or 'encrypt'" << endl;                
                        cin >> flagString;
                    }
                } while (!validInput);
                key = argv[2];
                cout << "Enter message followed by \"~\":" <<endl;
                getline(cin, message, '~');
                break;
            case 4:
                flagString = argv[1];
                do{
                    for(int i=0; flagString[i]; i++){
                        flagString[i] = tolower(flagString[i]);
                    }
                    if(flagString == "-encrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else if (flagString == "decrypt"){
                        decryptFlag = false;
                        validInput = true;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                        validInput = false;
                        cout << "Enter 'decrypt' or 'encrypt'" << endl;                
                        cin >> flagString;
                    }
                } while (!validInput);
                key = argv[2];
                message = argv[3];
                break;
            default:
                throw CommandLineException(4,argc-1);
                break;
        }
        /*
        i didnt think this far ahead when I started writing this...
        I guess this is where we would pass all our info into a mode
        of operation to break the message into the appropriate size
        */
        cout<<flagString<<" "<<key<< " "<<message<<endl;
    }
    catch(...){
        cout<<"Program Terminated!"<<endl;
        exit(EXIT_FAILURE);
    }


    return 0;
}