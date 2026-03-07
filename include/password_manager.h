#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

class PasswordManager {

public:
    void start();

private:
    std::string masterFileName = "master.dat";
    std::string storePassword = {};
    
    void initialize();
    bool masterFileExists();
    void createMasterFile();
    bool verifyMasterPassword();
    bool createMasterPassword();
};

#endif