#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

class PasswordManager {

public:
    PasswordManager();

    void start();

private:
    std::string masterFileName = "master.dat";
    std::string vaultFileName = "vault.dat";
    std::string storePassword = {};
    
    void initialize();
    bool masterFileExists();
    void createMasterFile();
    bool verifyMasterPassword();
    bool createMasterPassword();
    void createMenu();
    void addPassword();
    void viewAllPassword();
    void searchPassword();
    void deletePassword();
    void exitRun();
};

#endif