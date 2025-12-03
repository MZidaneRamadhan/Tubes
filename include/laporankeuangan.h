#ifndef LAPORANKEUANGAN
#define LAPORANKEUANGAN
#include "transaksi.h"
#include "posanggaran.h"

/*
 * Fungsi JumlahTransPemasukan
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan jumlah transaksi yang berjenis
 *         "Pemasukan".
 */
int JumlahTransPemasukan(Transaksi transaksi[], int jumlahTransaksi);

/*
 * Fungsi JumlahTransPengeluaran
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan jumlah transaksi yang berjenis
 *         "Pengeluaran".
 */
int JumlahTransPengeluaran(Transaksi transaksi[], int jumlahTransaksi);

/*
 * Fungsi TotalPemasukan
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dengan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan total nominal transaksi yang
 *         berjenis "Pemasukan".
 */
int TotalPemasukan(Transaksi transaksi[], int jumlahTransaksi);

/*
 * Fungsi TotalPengeluaran
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dengan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan total nominal transaksi yang
 *         berjenis "Pengeluaran".
 */
int TotalPengeluaran(Transaksi transaksi[], int jumlahTransaksi);

/*
 * Fungsi Saldo
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi valid.
 * F.S.  : Mengembalikan selisih antara total pemasukan dan
 *         total pengeluaran.
 */
int Saldo(int totalPemasukan, int totalPengeluaran);

/*
 * Fungsi RataRata
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi valid.
 * F.S.  : Mengembalikan nilai rata-rata pengeluaran.
 *         Jika jumlahTransaksi = 0, fungsi mengembalikan 0.
 */
int RataRata(Transaksi transaksi[], int jumlahTransaksi);

/*
 * Fungsi PersentaseSisa
 * ---------------------------------------------------------
 * I.S.  : Nilai saldo dan total pemasukan terdefinisi.
 * F.S.  : Mengembalikan persentase sisa saldo dari total pemasukan
 *         dalam bentuk float. Jika total pemasukan = 0,
 *         hasil adalah 0.0 untuk menghindari pembagian nol.
 */
float PersentaseSisa(int saldo, int totalPemasukan);

/*
 * Fungsi KondisiKeuangan
 * ---------------------------------------------------------
 * I.S.  : Nilai saldo terdefinisi.
 * F.S.  : Mengembalikan string kondisi keuangan berupa: "DEFISIT" atau "SEIMBANG" atau "SURPLUS"
 */
char *KondisiKeuangan(int saldo);

/*
 * Fungsi KesimpulanKondisiKeuangan
 * ---------------------------------------------------------
 * I.S.  : Persentase sisa saldo terdefinisi.
 * F.S.  : Mengembalikan string berisi kesimpulan kondisi keuangan:
 *         - >25%  : "Anda termasuk mahasiswa hemat dan produktif."
 *         - >0%   : "Keuangan Anda seimbang..."
 *         - <0%   : "Anda mulai boros..."
 *         - ==0% : "Kondisi keuangan kurang sehat..."
 */
char *KesimpulanKondisiKeuangan(int persentase);

/*  Fungsi RealisasiPos
   ---------------------------------------------------------
    Menghitung total nominal transaksi pengekuaran per satu pos anggaran
    I.S.	: Data yang tersimpan di dalam array transaksi
    F.S.	: Mengembalikan total nominal transaksi pengeluaran per pos anggaran
*/
int RealisasiPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);

/*	Fungsi JumlahTransPerPos
 * ---------------------------------------------------------
    I.S.	: Jumlah Transaksi per pos anggaran belum diketahuui
    F.S.	: Mengembalikan jumlah transaksi per pos anggaran
*/
int JumlahTransPerPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[]);

/*	Fungsi StatusPos
 * ---------------------------------------------------------
    I.S.	: Status pos belum diketaui
    F.S.	: Status pos sudah diketaui dan dikembalikan nilai nya
*/
char *StatusPos(int sisa);

/* Prosedur AnalisisLaporanKeuangan
 * ---------------------------------------------------------
    I.S.	: Hasil analisis keuangan belum di manipulasi dari hasil transaksi mahasiswa
              dan belum dimasukan ke dalam struct
    F.S.	: Hasil analisis keuangan sudah di manipulasi
*/
void AnalisisLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi);

/**
 * Prosedur ShowLaporanKeuangan
 * ---------------------------------------------------------
 * I.S.	: Hasil laporan keuangan mahassiswa belum muncul ke layar
 * F.S.	: Hasil laporan keuangan mahassiswa sudah muncul ke layar
 */
void ShowLaporanKeuangan();
void ShowLaporanPerBulan(int bulanCari, int tahunCari);

#endif