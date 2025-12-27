#ifndef BANSOS_H
#define BANSOS_H

#include <vector>
#include <string>

using namespace std;

// Struktur data untuk penerima bansos
struct PenerimaBansos {
    long long nik;
    string nama;
};

// Fungsi Algoritma Pencarian
int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama);
int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama, int low, int high);

// Fungsi Helper & Data
vector<PenerimaBansos> generateData(int jumlah);
vector<PenerimaBansos> getRealData();

// Fungsi Antarmuka
void jalankanAnalisis();
void menuPencarian();

#endif