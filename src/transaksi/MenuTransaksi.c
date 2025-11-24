#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"

Transaksi *transaksi = NULL;
int jumlahTransaksi = 0;

/*	Prosedur InputTransaksi
    I.S.	: Data transaksi dari user belum diketahui
    F.S.	: Data transaksi dari user sudah tersimpan ke array record
*/
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
            // jumlahTransaksi = jumlahInputTransaksi;
            InputTransaksi(&transaksi, &jumlahTransaksi, jumlahInputTransaksi);
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            PrintTransaksi(transaksi, jumlahTransaksi);
            break;

        case 2:
            ShowTransaksi(transaksi, jumlahTransaksi, 0);
            break;
        case 0:

            break;

        default:
            printf("Pilih menu yang benar!");
            break;
        }
    } while (select != 0);
}
