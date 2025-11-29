#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"
#include "../../include/laporankeuangan.h"

int jumlahPengeluaran = 0;
int totalPengeluaran = 0;
int jumlahPenmasukan = 0;
int totalPenmasukan = 0;
float saldo = 0;
float rataRata = 0;
float persentaseSisa = 0;
char kesimpulanKondisiKeuangan[100];

/*	Fungsi JumlahTransPemasukan

    Menghitung jumlah transaksi berjenis pemasukan
    Input	: Data jumlah transaksi dari user
    Output	: Jumlah transaksi yang berjenis pemasukan saja
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

// Fungsi JumlahTransPengeluaran
/*	Menghitung jumlah transaksi berjenis pengeluaran
    Input	: Data jumlah transaksi dari user
    Output	: Jumlah transaksi yang berjenis pengeluaran saja
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

// Fungsi Total Pemasukan
int TotalPemasukan(Transaksi transaksi[], int jumlahTransaksi)
{
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        {
            if (strcasecmp(transaksi[i].jenis, "Pemasukan") == 0)
                total += transaksi[i].nominal;
        }
    }
    return total;
}

// Fungsi Total Pengeluaran
int TotalPengeluaran(Transaksi transaksi[], int jumlahTransaksi)
{
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        {
            if (strcasecmp(transaksi[i].jenis, "Pengeluaran") == 0)
                total += transaksi[i].nominal;
        }
    }
    return total;
}

// Fungsi Saldo
int Saldo(Transaksi transaksi[], int jumlahTransaksi)
{
    int saldo = TotalPemasukan(transaksi, jumlahTransaksi) - TotalPengeluaran(transaksi, jumlahTransaksi);
    return saldo;
}

// Fungsi Rata-rata pengeluaran
int RataRata(Transaksi transaksi[], int jumlahTransaksi)
{
    int ratarata;
    if (jumlahTransaksi == 0)
    { // Jika tidak ada transaksi, rata-rata dianggap = 0
        ratarata = 0;
    }
    else if (jumlahTransaksi > 0)
    {
        ratarata = TotalPengeluaran(transaksi, jumlahTransaksi) / jumlahTransaksi;
    }
    return ratarata;
}

float PersentaseSisa(int saldo, int totalPemasukan)
{
    if (totalPemasukan == 0)
    {
        return 0.0; // Menghindari pembagian dengan nol
    }
    return ((float)saldo / totalPemasukan) * 100;
}

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

char *KesimpulanKondisiKeuangan(int pesentase)
{
    if (pesentase > 25.0)
    {
        return "Anda termasuk mahasiswa hemat dan produktif.";
    }
    else if (pesentase > 0.0)
    {
        return "Keuangan Anda seimbang, tetap waspada terhadap pengeluaran tidak perlu.";
    }
    else
    {
        return "Anda mulai boros, perhatikan pengeluaran harian.";
    }
}

float PersentaseSD(int saldo, int totalPemasukan)
{
    if (saldo >= 200000)
    {
        return 0.0; // Surplus Besar
    }
    else if (saldo >= 100000 && saldo < 200000)
    {
        return 0.0; // Surplus Sedang
    }
    else if (saldo > 0 && saldo < 100000)
    {
        return 0.0; // Surplus Kecil
    }
    else if (saldo == 0)
    {
        return 0.0; // Seimbang
    }
    else if (saldo < 0)
    {
        return 0.0; // Defisit Kecil
    }
    else if (saldo < -100000)
    {
        return 0.0; // Defisit Sedang
    }
    else if (saldo < -200000)
    {
        return 0.0; // Defisit Besar
    }
    return ((float)saldo / totalPemasukan) * 100;
}

/*	Prosedur ShowRekapitulasi
    I.S.	: Data transaksi dari user tersimpat di array record Transaksi
    F.S.	: Data transaksi dari user muncul di layar
*/
void ShowRekapitulasi(Transaksi transaksi[], int jumlahTransaksi)
{
    int jumlahKeluar = JumlahTransPemasukan(transaksi, jumlahTransaksi);
    int jumlahMasuk = JumlahTransPengeluaran(transaksi, jumlahTransaksi);
    int totalMasuk = TotalPemasukan(transaksi, jumlahTransaksi);
    int totalKeluar = TotalPengeluaran(transaksi, jumlahTransaksi);
    int saldoAkhir = Saldo(transaksi, jumlahTransaksi);
    int rataKeluar = RataRata(transaksi, jumlahTransaksi);

    printf("\nLaporan Rekapitulasi Pemasukan & Pengeluaran:\n");
    printf("______________________________________________________________\n");
    printf("| %-20s  | %-17s | %-15s |\n", "Jenis", "Jumlah Transaksi", "Total (Rp)");
    printf("|_______________________|___________________|_________________|\n");
    printf("| %-20s  | %-17d | %-15d |\n", "Pemasukan", jumlahMasuk, totalMasuk);
    printf("|_______________________|___________________|_________________|\n");
    printf("| %-20s  | %-17d | %-15d |\n", "Pengeluaran", jumlahKeluar, totalKeluar);
    printf("|_______________________|___________________|_________________|\n");
    printf("| %-20s  | %-17s | %-15d |\n", "Saldo Akhir", "-", saldoAkhir);
    printf("|_______________________|___________________|_________________|\n");
    printf("| %-20s | %-17s | %-15d |\n", "Rata-rata Pengeluaran", "-", rataKeluar);
    printf("|_______________________|___________________|_________________|\n");
}

/*  Fungsi RealisasiPos
    Menghitung total nominal transaksi pengekuaran per satu pos anggaran
    Input	: Data yang tersimpan di dalam array transaksi
    Output	: Totak nominal transaksi pengeluaran per pos anggaran
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
    Input	: Data yang tersimpan di dalam array transaksi
    Output	: Jumlah transaksi per pos anggaran
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

// Fungsi StatusPos
/*	Menentukan status satu pos anggaran berdasarkan sisa anggaran yang tersedia
    Input	: Nilai sisa
    Output	: Aman           -> jika sisa anggaran 0 atau lebih
              Melebihi batas -> jika sisa anggaran negatif alias melebihi batas nominal
*/
char *StatusPos(int sisa)
{
    if (sisa >= 0)
    {
        return "Aman";
    }
    return "Melebihi batas";
}

/* Prosedur ShowTransaksi
    I.S.	: Kondisi Transaksi dari setiap transaksi user belum muncul  ke layar
    F.S.	: Kondisi Transaksi dari setiap transaksi user sudah muncul ke layar
*/
void ShowKondisiKeuangan(Transaksi transaksi[], int jumlahTransaksi)
{
    printf("\nLaporan Keuangan:\n\n");

    printf("Laporan Kondisi Keuangan:\n");
    printf("___________________________________________________________________\n");
    printf("| %-35s | %-25s |\n", "Komponen", "Nilai (Rp)");
    printf("|_____________________________________|___________________________|\n");
    printf("| %-35s | %-25d |\n", "Total Pemasukan", TotalPemasukan(transaksi, jumlahTransaksi));
    printf("| %-35s | %-25d |\n", "Total Pengeluaran", TotalPengeluaran(transaksi, jumlahTransaksi));
    printf("| %-35s | %-25d |\n", "Total Pengeluaran Keseluruhan", TotalPengeluaran(transaksi, jumlahTransaksi));
    printf("| %-35s | %-25d |\n", "Saldo Akhir (Sisa Uang)", Saldo(transaksi, jumlahTransaksi));
    printf("| %-35s | %-25d |\n", "Rata-rata Pengeluaran per Transaksi", RataRata(transaksi, jumlahTransaksi));
    printf("| %-35s | %-24.2f%% |\n", "Persentase Sisa terhadap Pemasukan",
           PersentaseSisa(Saldo(transaksi, jumlahTransaksi), TotalPemasukan(transaksi, jumlahTransaksi)));
    printf("|_____________________________________|___________________________|\n");
}

/* Prosedur ShowLaporanKeuangan
    I.S.	: Laporan Pos Anggaran belum muncul ke layar
    F.S.	: Laporan Pos Anggaran sudah muncul ke layar
*/
void ShowLaporanKeuangan(PosAnggaran pos[], int jumlahPos, Transaksi transaksi[], int jumlahTransaksi)
{
    printf("\n============================ LAPORAN KEUANGAN BULANAN ============================\n");
    printf("Total Pemasukan   (%d Transaksi)  : Rp. %d\n",
           JumlahTransPemasukan(transaksi, jumlahTransaksi), TotalPemasukan(transaksi, jumlahTransaksi));
    printf("Total Pengeluaran (%d Transaksi)  : Rp. %d\n",
           JumlahTransPengeluaran(transaksi, jumlahTransaksi), TotalPengeluaran(transaksi, jumlahTransaksi));
    printf("Saldo Akhir                      : Rp. %d\n", Saldo(transaksi, jumlahTransaksi));
    printf("Rata-rata Pengeluaran            : Rp. %d\n", RataRata(transaksi, jumlahTransaksi));
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
    float saldo = Saldo(transaksi, jumlahTransaksi);
    float totalPemasukan = TotalPemasukan(transaksi, jumlahTransaksi);
    float persentaseSisa = PersentaseSisa(saldo, totalPemasukan);
    printf("Kondisi Keuangan  : %s (Sisa %.2f (persen) dari total pemasukan)\n", KondisiKeuangan(saldo), persentaseSisa);
    printf("Kesimpulan        : %s\n", KesimpulanKondisiKeuangan(persentaseSisa));
}
