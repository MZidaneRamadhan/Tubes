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
int saldo = 0;
float rataRata = 0;
float persentaseSisa = 0;
char statusKondisiKeuangan[20];
char kesimpulanKondisiKeuangan[100];

typedef struct
{
    char namaAnggaran[50];
    int batasNominal;
    int realisasi;
    int sisaNominal;
    int jumlah;
    char statusSisa[20];
} LaporanPosAnggaran;

LaporanPosAnggaran *laporanPosAnggaran = NULL;
;
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
    printf("Total Pemasukan: %d\n", total);

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
    printf("Total Pengeluaran: %d\n", total);
    return total;
}

/*
 * Fungsi Saldo
 * ---------------------------------------------------------
 * I.S.  : Array transaksi terdefinisi dan jumlahTransaksi valid.
 * F.S.  : Mengembalikan selisih antara total pemasukan dan
 *         total pengeluaran.
 */
int Saldo(int totalPemasukan, int totalPengeluaran)
{
    int saldo = totalPemasukan - totalPengeluaran;
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
    if (saldo < -10)
    {
        return "DEFISIT BESAR";
    }
    else if (saldo < 0)
    {
        return "DEFISIT RINGAN";
    }
    else if (saldo > 25)
    {
        return "SURPLUS";
    }
    else if (saldo > 0)
    {
        return "SURPLUS KECIL";
    }

    return "SEIMBANG";
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
    if (persentase < -10.0)
    {
        return "Kondisi keuangan kurang sehat. Kurangi pengeluaran dan cari tambahan pemasukan.";
    }
    else if (persentase < 0.0)
    {
        return "Anda mulai boros, perhatikan pengeluaran harian.";
    }
    else if (persentase > 25.0)
    {
        return "Anda termasuk mahasiswa hemat dan produktif.";
    }
    else if (persentase > 0.0)
    {
        return "Keuangan Anda seimbang, tetap waspada terhadap pengeluaran tidak perlu.";
    }
    else
    {
        return "Keuangan Anda berada pada titik netral.";
    }
}

/*  Fungsi RealisasiPos
   ---------------------------------------------------------
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

/*	Fungsi JumlahTransPerPos
 * ---------------------------------------------------------
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
 * ---------------------------------------------------------
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
 * ---------------------------------------------------------
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
    saldo = Saldo(totalPemasukan, totalPengeluaran);
    printf("Saldo: %d\n", saldo);
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
 * ---------------------------------------------------------
 * I.S.	: Hasil laporan keuangan mahassiswa belum muncul ke layar
 * F.S.	: Hasil laporan keuangan mahassiswa sudah muncul ke layar
 */
void ShowLaporanKeuangan()
{
    // const char *namaBulan[12] = {
    //     "Januari", "Februari", "Maret", "April", "Mei", "Juni",
    //     "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    printf("\n======================================= LAPORAN KEUANGAN BULANAN ========================================\n");
    printf("----------------------------------------------------------------------------------------------------------\n");

    printf("Total Pemasukan   (%d Transaksi)  : Rp. %d\n",
           jumlahPemasukan, totalPemasukan);
    printf("Total Pengeluaran (%d Transaksi)  : Rp. %d\n",
           jumlahPengeluaran, totalPengeluaran);
    printf("Saldo Akhir                      : Rp. %d\n", saldo);
    printf("Rata-rata Pengeluaran            : Rp. %.2f\n", rataRata);
    printf("----------------------------------------------------------------------------------\n");

    printf("\nLaporan Pos Anggaran:\n");
    printf("____________________________________________________________________________________________________________________\n");
    printf("| %-15s | %-15s | %-15s | %-15s | %-17s | %-20s |\n",
           "Pos", "Batas Nominal", "Realisasi", "Sisa", "Jumlah Transaksi", "Status");
    printf("|_________________|_________________|_________________|_________________|___________________|______________________|\n");

    for (int i = 0; i < jumlahPos; i++)
    {
        printf("| %-15s | %-15d | %-15d | %-15d | %-17d | %-20s |\n",
               laporanPosAnggaran[i].namaAnggaran,
               laporanPosAnggaran[i].batasNominal,
               laporanPosAnggaran[i].realisasi,
               laporanPosAnggaran[i].sisaNominal,
               laporanPosAnggaran[i].jumlah,
               laporanPosAnggaran[i].statusSisa);
    }

    printf("|_________________|_________________|_________________|_________________|___________________|______________________|\n");

    printf("\n----------------------------------------------------------------------------------\n");
    printf("Kondisi Keuangan  : %s (Sisa %.2f (persen) dari total pemasukan)\n", statusKondisiKeuangan, persentaseSisa);
    printf("Kesimpulan        : %s\n", kesimpulanKondisiKeuangan);
}

/**
 * Prosedur ShowLaporanPerBulan
 * ---------------------------------------------------------
 * I.S.	: Hasil laporan keuangan mahassiswa per bulan dipilih belum muncul ke layar
 * F.S.	: Hasil laporan keuangan mahassiswa per bulan dipilih sudah muncul ke layar
 */
void ShowLaporanPerBulan(int bulanCari, int tahunCari)
{
    const char *namaBulan[12] = {
        "JANUARI", "FEBRUARI", "MARET", "APRIL", "MEI", "JUNI",
        "JULI", "AGUSTUS", "SEPTEMBER", "OKTOBER", "NOVEMBER", "DESEMBER"};

    printf("\n======================================= LAPORAN KEUANGAN %s ========================================\n", namaBulan[bulanCari - 1]);
    printf("Periode Laporan   : %s %d\n", namaBulan[bulanCari - 1], tahunCari);
    printf("----------------------------------------------------------------------------------------------------------\n");

    printf("Total Pemasukan   (%d Transaksi)  : Rp. %d\n",
           jumlahPemasukan, totalPemasukan);
    printf("Total Pengeluaran (%d Transaksi)  : Rp. %d\n",
           jumlahPengeluaran, totalPengeluaran);
    printf("Saldo Akhir                      : Rp. %d\n", saldo);
    printf("Rata-rata Pengeluaran            : Rp. %.2f\n", rataRata);
    printf("----------------------------------------------------------------------------------\n");

    printf("\nLaporan Pos Anggaran:\n");
    printf("____________________________________________________________________________________________________________________\n");
    printf("| %-15s | %-15s | %-15s | %-15s | %-17s | %-20s |\n",
           "Pos", "Batas Nominal", "Realisasi", "Sisa", "Jumlah Transaksi", "Status");
    printf("|_________________|_________________|_________________|_________________|___________________|______________________|\n");

    for (int i = 0; i < jumlahPos; i++)
    {
        printf("| %-15s | %-15d | %-15d | %-15d | %-17d | %-20s |\n",
               laporanPosAnggaran[i].namaAnggaran,
               laporanPosAnggaran[i].batasNominal,
               laporanPosAnggaran[i].realisasi,
               laporanPosAnggaran[i].sisaNominal,
               laporanPosAnggaran[i].jumlah,
               laporanPosAnggaran[i].statusSisa);
    }

    printf("|_________________|_________________|_________________|_________________|___________________|______________________|\n");

    printf("\n----------------------------------------------------------------------------------\n");
    printf("Kondisi Keuangan  : %s (Sisa %.2f (persen) dari total pemasukan)\n", statusKondisiKeuangan, persentaseSisa);
    printf("Kesimpulan        : %s\n", kesimpulanKondisiKeuangan);
}
