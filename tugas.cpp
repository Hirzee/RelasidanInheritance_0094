#include <iostream>
#include <string>
using namespace std;


class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    
    User(string pNama, string pEmail) {
        id = generateId();
        nama = pNama;
        email = pEmail;
    }

    int generateId() {
        return ++globalId;
    }
};

