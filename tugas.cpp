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

int User::globalId = 0;

class Admin : public User {
public:
    Admin(string pNama, string pEmail)
        : User(pNama, pEmail) {}

    void showAllMember() {
        cout << "Admin menampilkan semua member" << endl;
    }

    void toggleActivationMember() {
        cout << "Status member berhasil diubah" << endl;
    }
};
