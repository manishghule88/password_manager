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
        if ( !verifyMasterPassword()) {
            std::cout << "Wrong Password\n";
            return;
        }
    }
    
    std::cout << "Access Granted\n";
}

void PasswordManager::
createMasterFile() {
    
    std::ofstream mFile;

    mFile.open( masterFileName );

    if ( !mFile.is_open()) {
        std::cout << "Error: in creating file\n";
        return;
    }

    std::cout << "File created successfully" << std::endl;
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
    std::ifstream file( masterFileName );

    if ( masterFileName.is_open()) {
        std::cout << "File is empty\n";
    } else {
        std::cout << "File is not empty\n";
    }
}