#include <stdio.h>
#include <string.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"
#include "../../include/laporankeuangan.h"

/*	Prosedur ShowTransaksi
    I.S.	: Data transaksi dari user tersimpat di array record Transaksi
    F.S.	: Data transaksi dari user muncul di layar
*/

void ShowTransaksi(Transaksi transaksi[], int JumlahTransaksi, int pilihanUser)
{
    printf("\n================ DAFTAR TRANSAKSI ================\n");
    printf("_____________________________________________________________________________________________\n");
    printf("| %-6s | %-12s | %-12s | %-12s | %-12s | %-20s |\n",
           "ID", "Tanggal", "Jenis", "Pos", "Nominal", "Deskripsi");
    printf("|________|______________|______________|______________|______________|______________________|\n");

    for (int i = 0; i < jumlahTransaksi; i++)
    {
        bool tampil = false;

        if (pilihanUser == 0)
        {
            tampil = true;
        }
        else if (pilihanUser == 1 && strcasecmp(transaksi[i].jenis, "Pemasukan") == 0)
        {
            tampil = true;
        }
        else if (pilihanUser == 2 && strcasecmp(transaksi[i].jenis, "Pengeluaran") == 0)
        {
            tampil = true;
        }

        if (tampil)
        {
            printf("| %-6s | %-12s | %-12s | %-12s | %-12d | %-20s |\n",
                   transaksi[i].id,
                   transaksi[i].tanggal,
                   transaksi[i].jenis,
                   transaksi[i].namaPos,
                   transaksi[i].nominal,
                   transaksi[i].deskripsi);
        }
    }
    printf("|________|______________|______________|______________|______________|______________________|\n");
}