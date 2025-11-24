#include <stdio.h>
#include "../include/posanggaran.h"
#include "../include/transaksi.h"
#include "../include/laporankeuangan.h"

void menu();

/**
 * Fungsi main
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
        printf("Masukan pilihan menu (0-2): ");
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