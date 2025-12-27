#ifndef BANSOS_H
#define BANSOS_H

#include <vector>
#include <string>

using namespace std;

// Struktur data utama
struct PenerimaBansos {
    long long nik;
    string nama;
};

// --- Prototipe Fungsi Pencarian ---
int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama);
int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama, int low, int high);

// --- Prototipe Fungsi Data & Utility ---
vector<PenerimaBansos> generateData(int jumlah);
vector<PenerimaBansos> getRealData();

// --- Prototipe Fungsi Antarmuka (UI) ---
void jalankanAnalisis();
void menuPencarian();

#endif