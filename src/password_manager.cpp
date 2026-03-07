#include <iostream>
#include <fstream>

#include "password_manager.h"

void PasswordManager::
start() {
    initialize();
}

void PasswordManager::
initialize() {
    if ( !masterFileExists()) {
        createMasterFile();
    } else {
        verifyMasterPassword();
    }
    
    std::cout << "Access Granted\n";
}

void PasswordManager::
createMasterFile() {
    
    // Create file
    std::ofstream mFile;

    mFile.open( masterFileName );

    if ( !mFile.is_open()) {
        std::cout << "Error: in creating file\n";
        return;
    }
    std::cout << "File created successfully" << std::endl;
    
    std::cout << "CREATE AND ENTER MASTER PASSWORD :" << std::endl;
    std::cin >> storePassword;

    mFile << storePassword;

    mFile.close();
}

bool PasswordManager::
masterFileExists() {

    std::ifstream file( masterFileName );

    if ( file.is_open()) {
        file.close();
        return true;
    } else {
        return false;
    }
}

bool PasswordManager::
verifyMasterPassword() {

    std::string vPassword;
    std::string myText;

    std::ifstream file( masterFileName );
    
    if ( file.is_open()) {
        std::getline( file, storePassword );
    }

    std::cout << "ENTER PASSWORD FOR VERIFY" << std::endl;
    std::cin >> vPassword;

    if ( storePassword == vPassword ) {
        file.close();
        return true;
    } else {
        return false;
    }
}