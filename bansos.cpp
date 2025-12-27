#include "bansos.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Implementasi Binary Search Iteratif
int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama) {
    int low = 0;
    int high = data.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid].nama == targetNama) return mid;
        if (data[mid].nama < targetNama) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Implementasi Binary Search Rekursif
int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama, int low, int high) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (data[mid].nama == targetNama) return mid;
    
    if (data[mid].nama < targetNama)
        return binarySearchRecursive(data, targetNama, mid + 1, high);
    
    return binarySearchRecursive(data, targetNama, low, mid - 1);
}

// Data Dummy Terurut (Pastikan data ini selalu terurut berdasarkan Nama untuk Binary Search)
vector<PenerimaBansos> getRealData() {
    return {
        {3201001, "Agus Salim"}, {3201005, "Budi Santoso"}, {3201012, "Cahya Kamila"},
        {3201020, "Dedi Corbuzier"}, {3201015, "Eka Gustiwana"}, {3201030, "Fadil Jaidi"},
        {3201099, "Gading Marten"}, {3201055, "Hesti Purwadinata"}, {3201040, "Indro Warkop"},
        {3201060, "Joko Anwar"}, {3201077, "Kaesang Pangarep"}, {3201088, "Luna Maya"},
        {3201002, "Maudy Ayunda"}, {3201023, "Nadim Makarim"}, {3201100, "Zaskia Gotik"}
    };
}

vector<PenerimaBansos> generateData(int jumlah) {
    vector<PenerimaBansos> data;
    data.reserve(jumlah);
    for (int i = 0; i < jumlah; ++i) {
        data.push_back({(long long)i, "Warga-" + to_string(1000000 + i)});
    }
    return data;
}

void menuPencarian() {
    vector<PenerimaBansos> data = getRealData();
    // Opsional: Sort data jika belum yakin terurut
    // sort(data.begin(), data.end(), [](const PenerimaBansos& a, const PenerimaBansos& b) { return a.nama < b.nama; });

    cout << "\n=== DATABASE PENERIMA BANSOS (TERURUT) ===\n";
    cout << left << setw(5) << "No" << setw(25) << "Nama Lengkap" << "NIK" << endl;
    cout << string(45, '-') << endl;
    
    for (size_t i = 0; i < data.size(); ++i) {
        cout << left << setw(5) << i + 1 << setw(25) << data[i].nama << data[i].nik << endl;
    }

    string namaCari;
    cout << "\nMasukkan NAMA yang ingin dicari (Case Sensitive): ";
    cin.ignore();
    getline(cin, namaCari);

    int idx1 = binarySearchIterative(data, namaCari);
    cout << "\n[Metode Iteratif] Status: " << (idx1 != -1 ? "DITEMUKAN! NIK: " + to_string(data[idx1].nik) : "Tidak ditemukan") << endl;

    int idx2 = binarySearchRecursive(data, namaCari, 0, data.size() - 1);
    cout << "[Metode Rekursif] Status: " << (idx2 != -1 ? "DITEMUKAN! NIK: " + to_string(data[idx2].nik) : "Tidak ditemukan") << endl;
}

void jalankanAnalisis() {
    const int ITERASI = 100000;
    vector<int> ukuranInput = {10, 100, 1000, 10000, 100000, 1000000};

    cout << "\n=== BENCHMARK PENCARIAN (Nanoseconds) ===\n";
    cout << left << setw(15) << "Jumlah Data" << setw(20) << "Iteratif (ns)" << setw(20) << "Rekursif (ns)" << "Status" << endl;
    cout << string(65, '-') << endl;

    for (int n : ukuranInput) {
        vector<PenerimaBansos> data = generateData(n);
        string target = data.back().nama; // Cari elemen terakhir (Worst Case)
        volatile int hasil = 0;

        // Benchmark Iteratif
        auto startIter = high_resolution_clock::now();
        for (int i = 0; i < ITERASI; ++i) hasil = binarySearchIterative(data, target);
        auto stopIter = high_resolution_clock::now();

        // Benchmark Rekursif
        auto startRec = high_resolution_clock::now();
        for (int i = 0; i < ITERASI; ++i) hasil = binarySearchRecursive(data, target, 0, n - 1);
        auto stopRec = high_resolution_clock::now();

        auto iterTime = duration_cast<nanoseconds>(stopIter - startIter).count() / ITERASI;
        auto recTime = duration_cast<nanoseconds>(stopRec - startRec).count() / ITERASI;

        cout << left << setw(15) << n << setw(20) << iterTime << setw(20) << recTime << "Selesai" << endl;
    }
}