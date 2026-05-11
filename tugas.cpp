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

class Member : public User {
private:
    bool status;

public:
    Member(string pNama, string pEmail, bool pStatus)
        : User(pNama, pEmail) {
        status = pStatus;
    }

    void showProfile() {
        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : ";

        if(status == true) {
            cout << "Aktif" << endl;
        } else {
            cout << "Nonaktif" << endl;
        }
    }
};

int main() {

    Admin admin1("Budi", "admin@gmail.com");

    Member member1("Rina", "rina@gmail.com", true);
    Member member2("Dewi", "dewi@gmail.com", false);

    admin1.showAllMember();
    admin1.toggleActivationMember();

    cout << endl;

    member1.showProfile();

    cout << endl;

    member2.showProfile();

    return 0;
}