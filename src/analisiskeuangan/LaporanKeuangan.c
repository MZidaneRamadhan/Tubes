#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"
#include "../../include/laporankeuangan.h"

int jumlahPengeluaran = 0;
int totalPengeluaran = 0;
int jumlahPemasukan = 0;
int totalPemasukan = 0;
float saldo = 0;
float rataRata = 0;
float persentaseSisa = 0;
char statusKondisiKeuangan[20];
char kesimpulanKondisiKeuangan[100];

LaporanPosAnggaran *laporanPosAnggaran;
/*
 * Fungsi JumlahTransPemasukan
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan jumlah transaksi yang berjenis
 *         "Pemasukan".
 */
int JumlahTransPemasukan(Transaksi transaksi[], int jumlahTransaksi)
{
    int hitung = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].jenis, "Pemasukan") == 0)
        {
            hitung++;
        }
    }
    return hitung;
}

/*
 * Fungsi JumlahTransPengeluaran
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan jumlah transaksi yang berjenis
 *         "Pengeluaran".
 */
int JumlahTransPengeluaran(Transaksi transaksi[], int jumlahTransaksi)
{
    int hitung = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].jenis, "Pengeluaran") == 0)
        {
            hitung++;
        }
    }
    return hitung;
}

/*
 * Fungsi TotalPemasukan
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dengan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan total nominal transaksi yang
 *         berjenis "Pemasukan".
 */
int TotalPemasukan(Transaksi transaksi[], int jumlahTransaksi)
{
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].jenis, "Pemasukan") == 0)
            total += transaksi[i].nominal;
    }
    return total;
}

/*
 * Fungsi TotalPengeluaran
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dengan jumlahTransaksi
 *         menyatakan banyaknya elemen valid dalam array.
 * F.S.  : Mengembalikan total nominal transaksi yang
 *         berjenis "Pengeluaran".
 */
int TotalPengeluaran(Transaksi transaksi[], int jumlahTransaksi)
{
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].jenis, "Pengeluaran") == 0)
            total += transaksi[i].nominal;
    }
    return total;
}

/*
 * Fungsi Saldo
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi valid.
 * F.S.  : Mengembalikan selisih antara total pemasukan dan
 *         total pengeluaran.
 */
int Saldo(Transaksi transaksi[], int jumlahTransaksi)
{
    int saldo = TotalPemasukan(transaksi, jumlahTransaksi) -
                TotalPengeluaran(transaksi, jumlahTransaksi);
    return saldo;
}

/*
 * Fungsi RataRata
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi valid.
 * F.S.  : Mengembalikan nilai rata-rata pengeluaran.
 *         Jika jumlahTransaksi = 0, fungsi mengembalikan 0.
 */
int RataRata(Transaksi transaksi[], int jumlahTransaksi)
{
    int ratarata;
    if (jumlahTransaksi == 0)
    {
        ratarata = 0;
    }
    else
    {
        ratarata = TotalPengeluaran(transaksi, jumlahTransaksi) / jumlahTransaksi;
    }
    return ratarata;
}

/*
 * Fungsi PersentaseSisa
 * ---------------------------------------------------------
 * I.S.  : Nilai saldo dan total pemasukan terdefinisi.
 * F.S.  : Mengembalikan persentase sisa saldo dari total pemasukan
 *         dalam bentuk float. Jika total pemasukan = 0,
 *         hasil adalah 0.0 untuk menghindari pembagian nol.
 */
float PersentaseSisa(int saldo, int totalPemasukan)
{
    if (totalPemasukan == 0)
    {
        return 0.0;
    }
    return ((float)saldo / totalPemasukan) * 100;
}

/*
 * Fungsi KondisiKeuangan
 * ---------------------------------------------------------
 * I.S.  : Nilai saldo terdefinisi.
 * F.S.  : Mengembalikan string kondisi keuangan berupa: "DEFISIT" atau "SEIMBANG" atau "SURPLUS"
 */
char *KondisiKeuangan(int saldo)
{
    if (saldo < 0)
    {
        return "DEFISIT";
    }
    else if (saldo == 0)
    {
        return "SEIMBANG";
    }
    else
    {
        return "SURPLUS";
    }
}

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
char *KesimpulanKondisiKeuangan(int persentase)
{
    if (persentase > 25.0)
    {
        return "Anda termasuk mahasiswa hemat dan produktif.";
    }
    else if (persentase > 0.0)
    {
        return "Keuangan Anda seimbang, tetap waspada terhadap pengeluaran tidak perlu.";
    }
    else if (persentase < 0.0)
    {
        return "Anda mulai boros, perhatikan pengeluaran harian.";
    }
    else
    {
        return "Kondisi keuangan kurang sehat. Kurangi pengeluaran dan cari tambahan pemasukan.";
    }
}

/*  Fungsi RealisasiPos
    Menghitung total nominal transaksi pengekuaran per satu pos anggaran
    I.S.	: Data yang tersimpan di dalam array transaksi
    F.S.	: Mengembalikan total nominal transaksi pengeluaran per pos anggaran
*/
int RealisasiPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[])
{
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].namaPos, namaPos) == 0 &&
            strcasecmp(transaksi[i].jenis, "Pengeluaran") == 0)
        {
            total += transaksi[i].nominal;
        }
    }
    return total;
}

// Fungsi JumlahTransPerPos
/*	Menghitung jumlah transaksi per satu pos anggaran
    I.S.	: Jumlah Transaksi per pos anggaran belum diketahuui
    F.S.	: Mengembalikan jumlah transaksi per pos anggaran
*/
int JumlahTransPerPos(Transaksi transaksi[], int jumlahTransaksi, char namaPos[])
{
    int jumlah = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        if (strcasecmp(transaksi[i].namaPos, namaPos) == 0)
        {
            jumlah++;
        }
    }
    return jumlah;
}

/*	Fungsi StatusPos
    I.S.	: Status pos belum diketaui
    F.S.	: Status pos sudah diketaui dan dikembalikan nilai nya
*/
char *StatusPos(int sisa)
{
    if (sisa >= 0)
    {
        return "Aman";
    }
    return "Melebihi batas";
}

/* Prosedur AnalisisLaporanKeuangan
    I.S.	: Hasil analisis keuangan belum di manipulasi dari hasil transaksi mahasiswa
              dan belum dimasukan ke dalam struct
    F.S.	: Hasil analisis keuangan sudah di manipulasi
*/
void AnalisisLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi)
{
    totalPemasukan = TotalPemasukan(transaksi, jumlahTransaksi);
    jumlahPemasukan = JumlahTransPemasukan(transaksi, jumlahTransaksi);
    totalPengeluaran = TotalPengeluaran(transaksi, jumlahTransaksi);
    jumlahPengeluaran = JumlahTransPengeluaran(transaksi, jumlahTransaksi);
    saldo = totalPemasukan - totalPengeluaran;
    rataRata = RataRata(transaksi, jumlahTransaksi);
    persentaseSisa = PersentaseSisa(saldo, totalPemasukan);

    strcpy(statusKondisiKeuangan, KondisiKeuangan(saldo));
    strcpy(kesimpulanKondisiKeuangan, KesimpulanKondisiKeuangan(persentaseSisa));

    laporanPosAnggaran = realloc(laporanPosAnggaran, jumlahPos * sizeof(LaporanPosAnggaran));

    for (int i = 0; i < jumlahPos; i++)
    {
        strcpy(laporanPosAnggaran[i].namaAnggaran, pos[i].namaAnggaran);
        laporanPosAnggaran[i].batasNominal = pos[i].batasNominal;
        laporanPosAnggaran[i].realisasi = RealisasiPos(transaksi, jumlahTransaksi, pos[i].namaAnggaran);
        laporanPosAnggaran[i].sisaNominal = pos[i].batasNominal - laporanPosAnggaran[i].realisasi;
        laporanPosAnggaran[i].jumlah = JumlahTransPerPos(transaksi, jumlahTransaksi, pos[i].namaAnggaran);
        strcpy(laporanPosAnggaran[i].statusSisa, StatusPos(laporanPosAnggaran[i].sisaNominal));
    }
}

/**
 * Prosedur ShowLaporanKeuangan
 * I.S.	: Hasil laporan keuangan mahassiswa belum muncul ke layar
 * F.S.	: Hasil laporan keuangan mahassiswa sudah muncul ke layar
 */
void ShowLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi)
{
    printf("\n============================ LAPORAN KEUANGAN BULANAN ============================\n");
    printf("Total Pemasukan   (%d Transaksi)  : Rp. %d\n",
           jumlahPemasukan, totalPemasukan);
    printf("Total Pengeluaran (%d Transaksi)  : Rp. %d\n",
           jumlahPengeluaran, totalPengeluaran);
    printf("Saldo Akhir                      : Rp. %d\n", saldo);
    printf("Rata-rata Pengeluaran            : Rp. %d\n", rataRata);
    printf("----------------------------------------------------------------------------------\n");

    printf("\nLaporan Pos Anggaran:\n");
    printf("__________________________________________________________________________________________________________\n");
    printf("| %-15s | %-15s | %-15s | %-15s | %-17s | %-10s |\n",
           "Pos", "Batas Nominal", "Realisasi", "Sisa", "Jumlah Transaksi", "Status");
    printf("|_________________|_________________|_________________|_________________|___________________|____________|\n");

    for (int i = 0; i < jumlahPos; i++)
    {

        int realisasi = RealisasiPos(transaksi, jumlahTransaksi, pos[i].namaAnggaran);
        int sisa = pos[i].batasNominal - realisasi;
        int jumlah = JumlahTransPerPos(transaksi, jumlahTransaksi, pos[i].namaAnggaran);

        printf("| %-15s | %-15d | %-15d | %-15d | %-17d | %-10s |\n",
               pos[i].namaAnggaran,
               pos[i].batasNominal,
               realisasi,
               sisa,
               jumlah,
               StatusPos(sisa));
    }

    printf("|_________________|_________________|_________________|_________________|___________________|____________|\n");

    printf("\n----------------------------------------------------------------------------------\n");
    printf("Kondisi Keuangan  : %s (Sisa %.2f (persen) dari total pemasukan)\n", statusKondisiKeuangan, persentaseSisa);
    printf("Kesimpulan        : %s\n", kesimpulanKondisiKeuangan);
}
