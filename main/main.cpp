#include <iostream>
#include <string>
#include <fstream>
#include "KeyGen.h"

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
    "$a.exe [encrypt/decrypt]~ [message]~"
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
                message = argv[2];
                break;
            default:
                throw CommandLineException(4,argc-1);
                break;
        }
        
        //Get or generate the key

        ifstream keyFile ("key.txt");
        if(keyFile){
            if(keyFile.is_open()){
                getline(keyFile, key);
            }
            keyFile.close();
        }
        else{
            ofstream newKeyFile ("key.txt");
            if(newKeyFile.is_open()){
                //generate key

                //these are both large blum primes
                int prime1 = 5651;
                int prime2 = 5623;
                //Need random seed
                unsigned long long int seed = 13;

                key = keyGen(prime1, prime2, seed);

                newKeyFile << key;
                newKeyFile.close();
            }
        }
        
        //TODO: break message up, break key up into 4*4, pass to AES and mop
        

        cout<<flagString<< " "<<key<<" "<<message<<endl;
    }
    catch(...){
        cout<<"Program Terminated!"<<endl;
        exit(EXIT_FAILURE);
    }


    return 0;
}