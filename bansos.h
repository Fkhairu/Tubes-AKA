#ifndef BANSOS_H
#define BANSOS_H

#include <vector>
#include <string>

using namespace std;

struct PenerimaBansos {
    long long nik;
    string nama;
};


int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama);
int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama,int low, int high);


vector<PenerimaBansos> generateData(int jumlah); 
vector<PenerimaBansos> getRealData();


int binarySearchIterative(const vector<PenerimaBansos>& data, string targetNama);
int binarySearchRecursive(const vector<PenerimaBansos>& data, string targetNama, int low, int high);


vector<PenerimaBansos> generateData(int jumlah); 
vector<PenerimaBansos> getRealData();            

void jalankanAnalisis();
void menuPencarian();

#endif