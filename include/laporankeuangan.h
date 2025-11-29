#ifndef LAPORANKEUANGAN
#define LAPORANKEUANGAN
#include "transaksi.h"

extern int jumlahPengeluaran;
extern int totalPengeluaran;
extern int jumlahPenmasukan;
extern int totalPenmasukan;
extern float saldo;
extern float rataRata;
extern float persentaseSisa;
extern char kesimpulanKondisiKeuangan[100];

int JumlahTransPemasukan(Transaksi transaksi[], int jumlahTransaksi);
int JumlahTransPengeluaran(Transaksi transaksi[], int jumlahTransaksi);
int TotalPemasukan(Transaksi transaksi[], int jumlahTransaksi);
int TotalPengeluaran(Transaksi transaksi[], int jumlahTransaksi);
int Saldo(Transaksi transaksi[], int jumlahTransaksi);
int RataRata(Transaksi transaksi[], int jumlahTransaksi);
float PersentaseSisa(int saldo, int totalPemasukan);
void ShowRekapitulasi(Transaksi transaksi[], int jumlahTransaksi);
void ShowKondisiKeuangan(Transaksi transaksi[], int jumlahTransaksi);

// Deklarasi Modul Laporan Keuangan
int RealisasiPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);
int JumlahTransPerPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);
char *StatusPos(int sisa);
// void ShowTransaksi(Transaksi transaksi[], int jumlahTransaksi, int pilihanUser);
void ShowLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi);

#endif