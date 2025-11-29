#include <stdio.h>
#include "../include/posanggaran.h"
#include "../include/transaksi.h"
#include "../include/laporankeuangan.h"

Transaksi *transaksi = NULL;
int jumlahTransaksi = 0;

PosAnggaran *Pos = NULL;
int jumlahPos = 0;

void menu();
void MenuPosAnggaran();
/*Procedure yang akan menampilkan daftar menu transaksi.*/
void MenuTransaksi();
void MenuLaporanKeuangan();

/**
 * Fungsi main
 * Author : Muhammad Zidane Ramadhan Oktaviantoro (251524058)
 * ------------------------------------------
 * I.S.  : Program belum dijalankan.
 * F.S.  : Seluruh data Pos Anggaran dan Transaksi dimuat (load),
 *         kemudian program menampilkan menu utama.
 */
int main()
{
    LoadPosAnggaran(&Pos, &jumlahPos);
    LoadTransaksi(&transaksi, &jumlahTransaksi);
    menu();
    return 0;
}

/**
 * Procedure menu
 * ------------------------------------------
 * I.S.  : Data Pos Anggaran & Transaksi telah dimuat.
 * F.S.  : Menampilkan menu utama secara berulang hingga user memilih exit (0).
 */
void menu()
{
    int select;
    do
    {
        printf("\n========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
        printf("\nPilihan menu\n");
        printf("1. Pos Anggaran\n");
        printf("2. Transaksi \n");
        printf("3. Analisis Keuangan\n");
        printf("0. Exit\n");
        printf("Masukan pilihan menu (0-3): ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            MenuPosAnggaran();
            break;

        case 2:
            MenuTransaksi();
            break;

        case 3:
            MenuLaporanKeuangan();
            break;

        case 0:
            printf("Keluar program...\n");
            break;

        default:
            printf("Pilihan tidak valid\n");
        }
    } while (select != 0);
}

/**
 *  Procedure MenuPosAnggaran
 *  Melakukan read data dari file ke pos anggaran
 *  I.S	: -
 *  F.S	: Menampilkan menu Pos Anggaran secara berulang
 **/
void MenuPosAnggaran()
{
    int select;

    do
    {
        printf("\n========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
        printf("\nMenu Laporan Keuangan:\n");
        printf("\n1. Masukan data Pos Anggaran baru\n");
        printf("2. Tampilkan semua data Pos Anggaran\n");
        printf("0. Kembali ke menu utama\n");
        printf("Masukan pilihan menu (0-2): ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            int jumlahInput;
            printf("Masukkan berapa data baru: ");
            scanf("%d", &jumlahInput);

            InputPosAnggaran(&Pos, &jumlahPos, jumlahInput);
            SavePosAnggaran(Pos, jumlahPos);
            break;

        case 2:
            ShowPosAnggaran(Pos, jumlahPos);
            break;

        default:
            printf("Pilih menu yang benar!");
            break;
        }
    } while (select != 0);
}

void MenuTransaksi()
{
    int select;
    do
    {
        printf("\n========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
        printf("\nMenu Laporan Keuangan:\n");
        printf("\n1. Masukan data Tramsaksi baru\n");
        printf("2. Tampilkan semua data Transaksi\n");
        printf("0. Kembali ke menu utama\n");
        printf("Masukan pilihan menu (0-2): ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            int jumlahInputTransaksi;
            printf("\nMasukkan berapa data baru: ");
            scanf("%d", &jumlahInputTransaksi);
            InputTransaksi(&transaksi, &jumlahTransaksi, jumlahInputTransaksi);
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            PrintTransaksi(transaksi, jumlahTransaksi);
            break;

        case 2:
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            break;

        default:
            printf("Pilih menu yang benar!");
            break;
        }
    } while (select != 0);
}

/**
 *  Prosedur MenuLaporanKeuangan
 *  Author : Firliana Febrina (251524058)
 *  I.S.	: Laporan Keuanngan pilihan user belum muncul ke layar
 *  F.S.	: Laporan Keuangan pilihan user sudah muncul ke layar
 **/
void MenuLaporanKeuangan()
{
    int select;
    do
    {
        printf("\nMenu Laporan Keuangan:\n");
        printf("1. Tampilkan Laporan Keuangan\n");
        printf("2. Tampilkan Seluruh Transaksi\n");
        printf("3. Tampilkan Transaksi Pemasukan\n");
        printf("4. Tampilkan Transaksi Pengeluaran\n");
        // printf("5. Tampilkan Rekapitulasi\n");
        printf("0. Keluar\n");
        printf("Pilih opsi (0-5): ");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            ShowLaporanKeuangan(Pos, jumlahPos, transaksi, jumlahTransaksi);
            break;
        case 2:
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            break;
        case 3:
            ShowTransaksi(transaksi, jumlahTransaksi, 1);
            break;
        case 4:
            ShowTransaksi(transaksi, jumlahTransaksi, 2);
            break;
        // case 5:
        //     ShowRekapitulasi(transaksi, jumlahTransaksi);
        //     break;
        case 0:
            printf("Keluar...\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (select != 0);
}