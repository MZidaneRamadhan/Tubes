#ifndef LAPORANKEUANGAN
#define LAPORANKEUANGAN
#include "transaksi.h"
#include "posanggaran.h"

extern int jumlahPengeluaran;
extern int totalPengeluaran;
extern int jumlahPemasukan;
extern int totalPemasukan;
extern float saldo;
extern float rataRata;
extern float persentaseSisa;
extern char statusKondisiKeuangan[20];
extern char kesimpulanKondisiKeuangan[100];

typedef struct
{
    char namaAnggaran[50];
    int batasNominal;
    int realisasi;
    int sisaNominal;
    int jumlah;
    char statusSisa[10];
} LaporanPosAnggaran;

extern LaporanPosAnggaran *laporanPosAnggaran;
int JumlahTransPemasukan(Transaksi transaksi[], int jumlahTransaksi);
int JumlahTransPengeluaran(Transaksi transaksi[], int jumlahTransaksi);
int TotalPemasukan(Transaksi transaksi[], int jumlahTransaksi);
int TotalPengeluaran(Transaksi transaksi[], int jumlahTransaksi);
int Saldo(Transaksi transaksi[], int jumlahTransaksi);
int RataRata(Transaksi transaksi[], int jumlahTransaksi);
float PersentaseSisa(int saldo, int totalPemasukan);

int RealisasiPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);
int JumlahTransPerPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);
char *StatusPos(int sisa);

void AnalisisLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi);

void ShowLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi);

#endif