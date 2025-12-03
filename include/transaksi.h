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

/*	Prosedur SaveTransaksi
    I.S.	: Data transaksi dari user belum di ambil dari file eksternal
    F.S.	: Data transaksi dari user sudah di ambil dari file eksternal
*/
void LoadTransaksi(Transaksi **transaksi, int *jumlahTransaksi);

/**
 *  Prosedur InputTransaksi
 *  I.S.    : Array transaksi mungkin kosong atau memiliki beberapa data awal.
 *            User belum memasukkan data transaksi baru.
 *  F.S.    : Array transaksi bertambah sejumlah jumlahInputTransaksi.
 *            Setiap transaksi memiliki ID otomatis, tanggal valid, jenis valid,
 *            pos anggaran valid, nominal valid, dan deskripsi terisi.
 **/
void InputTransaksi(Transaksi **transaksi, int *jumlahTransaksi, int jumlahInputTransaksi);

/**
 *  Fungsi ValidasiJenis
 *  I.S.    : Variabel jenis berisi input dari user.
 *  F.S.    : Menghasilkan true jika jenis adalah "Pemasukan" atau "Pengeluaran",
 *            dan false jika selain itu.
 **/
bool ValidasiTanggal(const char *tanggal);

/**
 *  Fungsi ValidasiNominal
 *  I.S.    : User menginput nilai nominal.
 *  F.S.    : Menghasilkan true jika nominal > 0,
 *            dan false jika nominal <= 0.
 **/
bool ValidasiJenis(char jenis[]);

/**
 *  Fungsi ValidasiPos
 *  I.S.    : daftarPos terdefinisi berisi seluruh pos anggaran.
 *            namapos merupakan input user.
 *  F.S.    : Menghasilkan true jika namapos ditemukan di daftarPos,
 *            dan false jika tidak ditemukan.
 **/
bool ValidasiPos(PosAnggaran daftarPos[], int JumlahPos, char namapos[]);

/**
 *  Fungsi ValidasiTanggal
 *  I.S.    : tanggal merupakan input user dalam bentuk string.
 *  F.S.    : Menghasilkan true jika string tanggal tidak kosong,
 *            dan false jika kosong.
 **/
bool ValidasiNominal(int nominal);

/*	Prosedur ShowTransaksi
    I.S.	: Data transaksi dari user tersimpat di array record Transaksi
    F.S.	: Data transaksi dari user muncul di layar
*/
void ShowTransaksi(Transaksi transaksi[], int JumlahTransaksi, int pilihanUser);

/*	Prosedur SaveTransaksi
    I.S.	: Data transaksi dari user belum tersimpan di file eksternal
    F.S.	: Data transaksi dari user sudah tersimpan di file eksternal
*/
void SaveTransaksi(Transaksi transaksi[], int JumlahTransaksi);

#endif