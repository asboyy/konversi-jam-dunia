#include <iostream>
using namespace std;

int main() {
    int pilihanMenu;
    do {
        cout << "\n=== Menu Utama ===" << endl;
        cout << "1. Konversi Waktu Dunia" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih menu (1-2): ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            int jam, menit, pilihanKota;
            cout << "\n=== Konversi Waktu Dunia ===" << endl;
            cout << "Masukkan jam (0-23) WIB: ";
            cin >> jam;
            cout << "Masukkan menit (0-59): ";
            cin >> menit;

            if (jam < 0 || jam > 23 || menit < 0 || menit > 59) {
                cout << "Input waktu tidak valid!" << endl;
                continue;
            }

            cout << "\nPilih kota tujuan:" << endl;
            cout << "1. Tokyo (UTC+9)" << endl;
            cout << "2. London (UTC+0 / +1 DST)" << endl;
            cout << "3. New York (UTC-5 / -4 DST)" << endl;
            cout << "4. Sydney (UTC+10)" << endl;
            cout << "Masukkan pilihan (1-4): ";
            cin >> pilihanKota;

            int offsetWIB = 7; // WIB = UTC+7
            int offsetKota = 0;
            string kota;

            switch (pilihanKota) {
                case 1: 
                    offsetKota = 9; 
                    kota = "Tokyo"; 
                    break;
                case 2: {
                    kota = "London";
                    char dst;
                    cout << "Apakah DST aktif? (y/n): ";
                    cin >> dst;
                    offsetKota = (dst == 'y' || dst == 'Y') ? 1 : 0;
                    break;
                }
                case 3: {
                    kota = "New York";
                    char dst;
                    cout << "Apakah DST aktif? (y/n): ";
                    cin >> dst;
                    offsetKota = (dst == 'y' || dst == 'Y') ? -4 : -5;
                    break;
                }
                case 4: 
                    offsetKota = 10; 
                    kota = "Sydney"; 
                    break;
                default:
                    cout << "Pilihan kota tidak valid!" << endl;
                    continue;
            }

            // 1) Konversi WIB -> UTC
            int jamUTC = jam - offsetWIB;
            if (jamUTC < 0) jamUTC += 24;
            if (jamUTC >= 24) jamUTC -= 24;

            // 2) Konversi UTC -> Kota tujuan
            int jamTujuan = jamUTC + offsetKota;
            if (jamTujuan < 0) jamTujuan += 24;
            if (jamTujuan >= 24) jamTujuan -= 24;

            cout << "\n=== Hasil Konversi ===" << endl;
            cout << "Waktu di " << kota << " = "
                 << (jamTujuan < 10 ? "0" : "") << jamTujuan << ":"
                 << (menit < 10 ? "0" : "") << menit << endl;
        }
        else if (pilihanMenu == 2) {
            cout << "Terima kasih! Program selesai." << endl;
        }
        else {
            cout << "Pilihan menu tidak valid!" << endl;
        }
    } while (pilihanMenu != 2);

    return 0;
}

