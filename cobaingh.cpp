#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Fungsi untuk memulai game tebak kata
void mulaiGame(const string& kataRahasia) {
    string tebakan;
    vector<char> hurufTebakan;
    int kesempatan = 6;  // Jumlah kesempatan

    cout << "Selamat datang di game Tebak Kata!" << endl;
    cout << "Kamu memiliki " << kesempatan << " kesempatan untuk menebak kata." << endl;

    while (kesempatan > 0) {
        // Menampilkan kemajuan tebakan
        cout << "Kata: ";
        for (char huruf : kataRahasia) {
            if (find(hurufTebakan.begin(), hurufTebakan.end(), huruf) != hurufTebakan.end()) {
                cout << huruf << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;

        // Meminta input dari pengguna
        cout << "Tebak huruf: ";
        cin >> tebakan;

        // Memeriksa apakah tebakan sudah dimasukkan
        if (tebakan.length() != 1) {
            cout << "Tebakan harus berupa satu huruf." << endl;
            continue;
        }

        char hurufTebak = tebakan[0];

        // Memeriksa jika huruf sudah ditebak sebelumnya
        if (find(hurufTebakan.begin(), hurufTebakan.end(), hurufTebak) != hurufTebakan.end()) {
            cout << "Kamu sudah menebak huruf ini sebelumnya." << endl;
            continue;
        }

        // Menambahkan huruf tebakan ke dalam vector
        hurufTebakan.push_back(hurufTebak);

        // Memeriksa apakah huruf tebakan ada dalam kata rahasia
        if (kataRahasia.find(hurufTebak) != string::npos) {
            cout << "Bagus! Huruf " << hurufTebak << " ada dalam kata." << endl;
        } else {
            kesempatan--;
            cout << "Sayang sekali, huruf " << hurufTebak << " tidak ada dalam kata. Kesempatan tersisa: " << kesempatan << endl;
        }

        // Memeriksa apakah semua huruf telah ditebak
        bool semuaTebakBenar = true;
        for (char huruf : kataRahasia) {
            if (find(hurufTebakan.begin(), hurufTebakan.end(), huruf) == hurufTebakan.end()) {
                semuaTebakBenar = false;
                break;
            }
        }

        // Jika semua huruf sudah ditebak
        if (semuaTebakBenar) {
            cout << "Selamat! Kamu telah menebak kata: " << kataRahasia << endl;
            return;  // Keluar dari fungsi karena tebakan benar
        }
    }

    // Jika pengguna kehabisan kesempatan
    cout << "Sayang sekali, kamu kehabisan kesempatan. Kata yang benar adalah: " << kataRahasia << endl;
}

int main() {
    string kataRahasia = "program";  // Kata yang harus ditebak

    mulaiGame(kataRahasia);  // Memanggil fungsi untuk memulai game

    return 0;
}
