#include <iostream>
#include <fstream>

#include "password_manager.h"

PasswordManager::
PasswordManager() {
    // Nothing to do yet
}

void PasswordManager::
start() {
    initialize();
}

void PasswordManager::
initialize() {
    bool verifyPassword = false;

    if ( !masterFileExists()) {
        createMasterFile();
    } else {
        verifyPassword = verifyMasterPassword();
        
        if ( verifyPassword ) {
            createMenu();
        } else {
            std::cout << "USER PASSWORD NOT MATCHED WITH MASTER PASSWORD" << std::endl;
        }
    }
    
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

void PasswordManager::
createMenu() {
    int selectMenu = 0;

    while ( true ) {
        std::cout << "1. Add Password\n";
        std::cout << "2. View all Password\n";
        std::cout << "3. Search Password\n";
        std::cout << "4. Delete Password\n";
        std::cout << "5. Exit\n";
    
        std::cin >> selectMenu;
        
        if ( selectMenu == 1 ) {
            addPassword();
        } else if ( selectMenu == 2 ) {
            viewAllPassword();
        } else if ( selectMenu == 3 ) {
            searchPassword();
        } else if ( selectMenu == 4 ) {
            deletePassword();
        } else if ( selectMenu == 5 ) {
            std::cout << "Exiting Password Manager...\n";
            break;
        } else {
            std::cout << "Invalid Option\n";
        }
    }
}

void PasswordManager::
addPassword() {

    std::ofstream vFile;

    std::string website;
    std::string userName;
    std::string password;

    // append mode ios::app
    vFile.open( vaultFileName, std::ios::app );

    if ( !vFile.is_open()) {
        std::cout << "Error: in creating vault file\n";
        return;
    }    

    std::cout << "Please...Enter your Website" << std::endl;
    std::cin >> website;

    std::cout << "Please...Enter your Username" << std::endl;
    std::cin >> userName;

    std::cout << "Please...Enter your Password" << std::endl;
    std::cin >> password;

    vFile << "|" << website << "|" << userName << "|" << password << std::endl;
    
    vFile.close();
}

void PasswordManager::
viewAllPassword() {}

void PasswordManager::
searchPassword() {}

void PasswordManager::
deletePassword() {}

void PasswordManager::
exitRun() {
    exit( 0 );
}