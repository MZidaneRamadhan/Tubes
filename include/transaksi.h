#ifndef TRANSAKSI
#define TRANSAKSI

#include <stdbool.h>
#include "posanggaran.h"

#define MAX_STRING 100

typedef struct
{
    char id[10];
    char tanggal[20];
    char jenis[20];
    char namaPos[20];
    int nominal;
    char deskripsi[100];
} Transaksi;

extern Transaksi *transaksi;

extern int jumlahTransaksi;

/*Procedure yang melakukan write data transaksi ke dalam file .txt*/
void LoadTransaksi(Transaksi **transaksi, int *jumlahTransaksi);

/*Procedure yang melakukan proses input data transaksi kedalam Array of scruct Transaksi*/
void InputTransaksi(Transaksi **transaksi, int *jumlahTransaksi, int jumlahInputTransaksi);

/*Function yang mengembalikan nilai bool. Memvalidasi format tanggal transaksi, tanggal String tanggal dalam format "DD-MM-YYYY".*/
bool ValidasiTanggal(char tanggal[]);

/*Function yang mengembalikan nilai bool. Memvalidasi jenis transaksi pemasukan atau pengeluaran .*/
bool ValidasiJenis(char jenis[]);

/*Function yang mengembalikan nilai bool. Memvalidasi nama pos anggaran apakah sesuai dengan data yang ada*/
bool ValidasiPos(PosAnggaran daftarPos[], int JumlahPos, char namapos[]);

/*Function yang mengembalikan nilai bool. Memvalidasi nominal yang di input apakah nominal tersebut kurang dari 0.*/
bool ValidasiNominal(int nominal);

/*Procedure yang menampilkan tabel data transaksi*/
void ShowTransaksi(Transaksi transaksi[], int JumlahTransaksi, int pilihanUser);

/*Procedure yang melakukan write data transaksi ke dalam file .txt*/
void SaveTransaksi(Transaksi transaksi[], int JumlahTransaksi);

#endif