#include "bansos.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;




int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

  
        if (data[mid].nama == targetNama) {
            return mid; 
        } 

        else if (data[mid].nama < targetNama) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama, int low, int high) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (data[mid].nama == targetNama) {
        return mid;
    } else if (data[mid].nama < targetNama) {
        return binarySearchRecursive(data, targetNama, mid + 1, high);
    } else {
        return binarySearchRecursive(data, targetNama, low, mid - 1);
    }
}


vector<PenerimaBansos> getRealData() {
    return {
        {3201001, "Agus Salim"},      
        {3201005, "Budi Santoso"},    
        {3201012, "Cahya Kamila"},    
        {3201020, "Dedi Corbuzier"},  
        {3201015, "Eka Gustiwana"},  
        {3201030, "Fadil Jaidi"},     
        {3201099, "Gading Marten"},   
        {3201055, "Hesti Purwadinata"},
        {3201040, "Indro Warkop"},   
        {3201060, "Joko Anwar"},      
        {3201077, "Kaesang Pangarep"},
        {3201088, "Luna Maya"},       
        {3201002, "Maudy Ayunda"},    
        {3201023, "Nadim Makarim"},   
        {3201100, "Zaskia Gotik"}    
    };
}

vector<PenerimaBansos> generateData(int jumlah) {
    vector<PenerimaBansos> data;
    data.reserve(jumlah); 
    for (int i = 0; i < jumlah; i++) {

        string namaDummy = "Warga-" + to_string(1000000 + i); 
        data.push_back({(long long)i, namaDummy});
    }
    return data;
}



void menuPencarian() {
    vector<PenerimaBansos> data = getRealData();
    
  cout << "\n=== DATABASE PENERIMA BANSOS (URUT NAMA) ===\n"; 
  cout << left << setw(5) << "No" << setw(20) << "Nama Lengkap" << "NIK" << endl; 
  cout << "----------------------------------------------\n"; 
  for(size_t i = 0; i < data.size(); i++) { 
    cout << left << setw(5) << i+1 << setw(20) << data[i].nama << data[i].nik << endl; } 
  cout << "----------------------------------------------\n"; string namaCari; 
  cout << "\nMasukkan NAMA yang ingin dicari (Case Sensitive/Huruf Besar Kecil harus sama): "; cin.ignore(); getline(cin, namaCari); 
  cout << "\n--- Hasil Pencarian ---" << endl;



    int idx1 = binarySearchIterative(data, namaCari);
    cout << "[Metode Iteratif] "; 
    if(idx1 != -1) 
        cout << "DITEMUKAN! NIK: " << data[idx1].nik << endl;
    else 
        cout << "Nama tidak ada di database." << endl;


    int idx2 = binarySearchRecursive(data, namaCari, 0, data.size() - 1);
    cout << "[Metode Rekursif] ";
    if(idx2 != -1) 
        cout << "DITEMUKAN! NIK: " << data[idx2].nik << endl;
    else 
        cout << "Nama tidak ada di database." << endl;
}

void jalankanAnalisis() {
    vector<int> ukuranInput = {10, 100, 1000, 10000, 100000, 1000000};
    const int ITERASI = 100000; // jumlah pengulangan benchmark

    cout << "\n=== BENCHMARK PENCARIAN STRING (Nanoseconds) ===\n";
    cout << left << setw(15) << "Jumlah Data"
         << setw(20) << "Iteratif (ns)"
         << setw(20) << "Rekursif (ns)"
         << "Status" << endl;
    cout << string(65, '-') << endl;

    for (int n : ukuranInput) {
        vector<PenerimaBansos> data = generateData(n);
        string target = data.back().nama;

        volatile int hasil = 0; // cegah optimasi compiler

        // ===== Iteratif =====
        auto startIter = high_resolution_clock::now();
        for (int i = 0; i < ITERASI; i++) {
            hasil = binarySearchIterative(data, target);
        }
        auto stopIter = high_resolution_clock::now();

        // ===== Rekursif =====
        auto startRec = high_resolution_clock::now();
        for (int i = 0; i < ITERASI; i++) {
            hasil = binarySearchRecursive(data, target, 0, n - 1);
        }
        auto stopRec = high_resolution_clock::now();

        auto iterTime = duration_cast<nanoseconds>(stopIter - startIter).count();
        auto recTime  = duration_cast<nanoseconds>(stopRec - startRec).count();

        cout << left << setw(15) << n
             << setw(20) << iterTime
             << setw(20) << recTime
             << "Selesai" << endl;
    }
}