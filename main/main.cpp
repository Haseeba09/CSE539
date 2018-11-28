#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "KeyGen.h"
#include "ofb.h"

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
        string iv;
        switch(argc){
            case 1:
                //get flag for Encrypt vs Decrypt
                do{
                    cout << "Enter 'decrypt' or 'encrypt'" << endl;
                    //SECURE CODING: STR50-CPP. Guarantee that storage for strings has sufficient space                 
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
                //SECURE CODING: STR50-CPP. Guarantee that storage for strings has sufficient space 
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
                        //SECURE CODING: STR50-CPP. Guarantee that storage for strings has sufficient space                 
                        cin >> flagString;
                    }
                } while (!validInput);
                cout << "Enter message followed by \"~\" to " << flagString << ":" << endl;
                //SECURE CODING: STR50-CPP. Guarantee that storage for strings has sufficient space 
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
                        //SECURE CODING: STR50-CPP. Guarantee that storage for strings has sufficient space                 
                        cin >> flagString;
                    }
                } while (!validInput);
                message = argv[2];
                break;
            default:
                //SECURE CODING: ERR50-CPP. Do not abruptly terminate the program
                throw CommandLineException(4,argc-1);
                break;
        }
        unsigned char output[message.length()];
        unsigned char messageArray[message.length()];
        unsigned char keyArray[16];
        unsigned char ivArray[16];
        
        //Get or generate the key

        ifstream keyFile ("key.txt");
        if(keyFile){
            if(keyFile.is_open()){
                getline(keyFile, key);
            }
            //SECURE CODING: FIO51-CPP. Close files when they are no longer needed
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
                //SECURE CODING: MSC51-CPP. Ensure your random number generator is properly seeded
                //Not followed! Attempted to use random_device, but did not get random seed
                key = keyGen(prime1, prime2, seed);

                newKeyFile << key;
                //SECURE CODING: FIO51-CPP. Close files when they are no longer needed
                newKeyFile.close();
            }
        }

        ifstream ivFile ("iv.txt");
        if(ivFile){
            if(ivFile.is_open()){
                getline(ivFile, iv);
            }
            //SECURE CODING: FIO51-CPP. Close files when they are no longer needed
            ivFile.close();
        }
        else{
            ofstream newIvFile ("iv.txt");
            if(newIvFile.is_open()){
                //generate key

                //these are both large blum primes
                int prime1 = 5651;
                int prime2 = 5623;
                //Need random seed
                unsigned long long int seed = 21;
                //SECURE CODING: MSC51-CPP. Ensure your random number generator is properly seeded
                //Not followed! Attempted to use random_device, but did not get random seed
                iv = keyGen(prime1, prime2, seed);

                newIvFile << iv;
                //SECURE CODING: FIO51-CPP. Close files when they are no longer needed
                newIvFile.close();
            }
        }

        
        for(int i =0; i<message.length(); i++){
            messageArray[i] = message[i];
        }
        for(int i=0; i<16; i++){
            keyArray[i] = key[i];
            ivArray[i] = iv[i];
        }

        ofb(keyArray, ivArray, messageArray, output, decryptFlag, message.length());        

        for(int i=0; i<message.length(); i++){
            //SECURE CODING:EXP53-CPP. Do not read uninitialized memory
            cout<<output[i];
        }

        
    }
    //SECURE CODING: ERR51-CPP. Handle all exceptions
    catch(...){
        cout<<"Program Terminated!"<<endl;
        exit(EXIT_FAILURE);
    }


    return 0;
}