#include <iostream>
#include "bansos.h"

using namespace std;

int main() {
    int pilihan;
    do {
        cout << "\n==========================================\n";
        cout << "      APLIKASI PENCARIAN DATA BANSOS      \n";
        cout << "==========================================\n";
        cout << "1. Pencarian Data (Iteratif vs Rekursif)\n";
        cout << "2. Analisis Efisiensi (Running Time)\n";
        cout << "3. Keluar\n";
        cout << "------------------------------------------\n";
        cout << "Pilihan Anda: ";
        
        if (!(cin >> pilihan)) { // Validasi input jika user memasukkan huruf
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: menuPencarian(); break;
            case 2: jalankanAnalisis(); break;
            case 3: cout << "Terima kasih. Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);

    return 0;
}