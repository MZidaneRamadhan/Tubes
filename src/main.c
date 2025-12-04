#include <stdio.h>
#include "../include/posanggaran.h"
#include "../include/transaksi.h"
#include "../include/display.h"
#include "../include/laporankeuangan.h"
#include <windows.h>

Transaksi *transaksi = NULL;
int jumlahTransaksi = 0;

PosAnggaran *Pos = NULL;
int jumlahPos = 0;
void Loading();
/**
 * Fungsi main
 * Author : Muhammad Zidane Ramadhan Oktaviantoro (251524058)
 * ------------------------------------------
 * I.S.  : Program belum dijalankan.
 * F.S.  : Seluruh data Pos Anggaran dan Transaksi dimuat (load),
 *         kemudian program menampilkan menu utama.
 */
void menu();
/**
 * Procedure Display Menu
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenu();
/**
 *  Procedure MenuPosAnggaran
 *  Melakukan read data dari file ke pos anggaran
 *  I.S	: -
 *  F.S	: Menampilkan menu Pos Anggaran secara berulang
 **/
void MenuPosAnggaran();
/**
 * Procedure Display Menu
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenuTransaksi();
/**
 *  Prosedur MenuTransaksi
 *  Author : Firliana Febrina (251524044)
 *  I.S.	: Laporan Keuanngan pilihan user belum muncul ke layar
 *  F.S.	: Laporan Keuangan pilihan user sudah muncul ke layar
 **/
void MenuTransaksi();
/**
 * Procedure Display Laporan Keuangan
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenuLaporanKeuangan();
/**
 *  Prosedur MenuLaporanKeuangan
 *  Author : Abhidal Muhammad Gazza (251524032)
 *  I.S.	: Laporan Keuanngan pilihan user belum muncul ke layar
 *  F.S.	: Laporan Keuangan pilihan user sudah muncul ke layar
 **/
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
    AnalisisLaporanKeuangan(Pos, jumlahPos, transaksi, jumlahTransaksi);
    menu();
    return 0;
}

/**
 * Procedure Display Menu
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenu()
{
    printf("\n========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
    printf("=====================================\n");
    printf("             PILIHAN MENU            \n");
    printf("=====================================\n");
    printf("1. Pos Anggaran\n");
    printf("2. Transaksi \n");
    printf("3. Analisis Keuangan\n");
    printf("\033[31m0. Exit\033[0m \n");
    printf("=====================================\n");
    printf("Masukan pilihan menu (0-3): ");
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
        DisplayMenu();
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
            Alert();
            // printf("\n\033[93mPilihan tidak valid. Pilih menu yang benar!\033[0m\n");
        }
    } while (select != 0);
}

/**
 * Procedure Display Menu
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenuPosAnggaran()
{
    printf("\n=====================================\n");
    printf("           MENU POS ANGGARAN         \n");
    printf("=====================================\n");
    printf("\n1. Masukan data Pos Anggaran baru\n");
    printf("2. Tampilkan semua data Pos Anggaran\n");
    printf("\033[93m0. Kembali ke menu utama\033[0m\n");
    printf("=====================================\n");
    printf("Masukan pilihan menu (0-2): ");
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
        DisplayMenuPosAnggaran();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            int jumlahInput;
            printf("Masukkan berapa data baru: ");
            scanf("%d", &jumlahInput);

            InputPosAnggaran(&Pos, &jumlahPos, jumlahInput);
            Loading();
            ShowPosAnggaran(Pos, jumlahPos);
            SavePosAnggaran(Pos, jumlahPos);
            break;

        case 2:
            ShowPosAnggaran(Pos, jumlahPos);
            break;

        case 0:
            printf("\nKembali ke menu awal");
            break;

        default:
            Alert();
            // printf("\n\033[93mPilihan tidak valid. Pilih menu yang benar!\033[0m\n");
            break;
        }
    } while (select != 0);
}

/**
 * Procedure Display Menu
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenuTransaksi()
{
    // printf("\n========================================= APLIKASI KEUANGAN MAHASISWA =========================================\n");
    printf("\n=====================================\n");
    printf("           MENU TRANSAKSI            \n");
    printf("=====================================\n");
    printf("1. Masukan data Tramsaksi baru\n");
    printf("2. Tampilkan semua data Transaksi\n");
    printf("\033[93m0. Kembali ke menu utama\033[0m\n");
    printf("=====================================\n");
    printf("Masukan pilihan menu (0-2): ");
}

/**
 *  Prosedur MenuTransaksi
 *  Author : Firliana Febrina (251524044)
 *  I.S.	: Laporan Keuanngan pilihan user belum muncul ke layar
 *  F.S.	: Laporan Keuangan pilihan user sudah muncul ke layar
 **/
void MenuTransaksi()
{
    int select;
    do
    {
        DisplayMenuTransaksi();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            int jumlahInputTransaksi;
            printf("\nMasukkan berapa data baru: ");
            scanf("%d", &jumlahInputTransaksi);

            InputTransaksi(&transaksi, &jumlahTransaksi, jumlahInputTransaksi);
            Loading();
            AnalisisLaporanKeuangan(Pos, jumlahPos, transaksi, jumlahTransaksi);

            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            SaveTransaksi(transaksi, jumlahTransaksi);

            break;
        case 2:
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            break;
        case 0:
            printf("\nKembali ke menu awal");
            break;
        default:
            Alert();
            // printf("\n\033[93mPilihan tidak valid. Pilih menu yang benar!\033[0m\n");
            break;
        }
    } while (select != 0);
}

/**
 * Procedure Display Laporan Keuangan
 * ------------------------------------------
 * I.S.  : -.
 * F.S.  : Menampilkan daftar menu utama secara berulang hingga user memilih exit (0).
 */
void DisplayMenuLaporanKeuangan()
{
    printf("\n=====================================\n");
    printf("        MENU LAPORAN KEUANGAN        \n");
    printf("=====================================\n");
    printf(" 1. Tampilkan Laporan Keuangan\n");
    printf(" 2. Tampilkan Seluruh Transaksi\n");
    printf(" 3. Tampilkan Transaksi Pemasukan\n");
    printf(" 4. Tampilkan Transaksi Pengeluaran\n");
    printf(" 5. Laporan per Bulan\n");
    printf("\033[93m 0. Kembali ke menu utama\033[0m\n");
    printf("=====================================\n");
    printf(" Pilih opsi (0-4) : ");
}

/**
 *  Prosedur MenuLaporanKeuangan
 *  Author : Abhidal Muhammad Gazza (251524032)
 *  I.S.	: Laporan Keuanngan pilihan user belum muncul ke layar
 *  F.S.	: Laporan Keuangan pilihan user sudah muncul ke layar
 **/
void MenuLaporanKeuangan()
{
    int select;
    do
    {
        DisplayMenuLaporanKeuangan();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            ShowLaporanKeuangan();
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
        case 5:
            int bulan, tahun;
            printf("Masukkan bulan (1-12): ");
            scanf("%d", &bulan);
            printf("Masukkan tahun: ");
            scanf("%d", &tahun);
            ShowLaporanPerBulan(bulan, tahun);
            break;
        case 0:
            printf("\nKembali ke menu awal");
            break;
        default:
            Alert();
            // printf("\n\033[93mPilihan tidak valid. Pilih menu yang benar!\033[0m\n");
        }
    } while (select != 0);
}

void Loading()
{
    printf("Menambah data");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
        Sleep(200); // Windows
    }
    printf("\n");
}

void Alert()
{
    Sleep(200); // Windows
    printf("\n\033[93mPilihan tidak valid. Pilih menu yang benar!\033[0m\n");
    fflush(stdout);
    Sleep(1000); // Windows
    printf("\n");
}