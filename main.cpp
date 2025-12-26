#include <iostream>
#include "bansos.h" 

using namespace std;

int main() {
    int pilihan;
    do {
        cout << "\n============================================\n";
        cout << "   APLIKASI PENCARIAN DATA BANSOS (C++)   \n";
        cout << "============================================\n";
        cout << "1. Pencarian Data (Iteratif vs Rekursif)\n";
        cout << "2. Analisis Efisiensi (Benchmark Running Time)\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuPencarian();
                break;
            case 2:
                jalankanAnalisis();
                break;
            case 3:
                cout << "Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    return 0;
}