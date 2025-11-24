#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"

/*	Prosedur PrintTransaksi
    I.S.	: Data transaksi dari user belum tersimpan di file eksternal
    F.S.	: Data transaksi dari user sudah tersimpan di file eksternal
*/
void PrintTransaksi(Transaksi transaksi[], int JumlahTransaksi)
{
    FILE *file = fopen("../data/DataTransaksi.txt", "w");

    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    for (int i = 0; i < JumlahTransaksi; i++)
    {
        fprintf(file, "%s|%s|%s|%s|%d|%s\n",
                transaksi[i].id,
                transaksi[i].tanggal,
                transaksi[i].jenis,
                transaksi[i].namaPos,
                transaksi[i].nominal,
                transaksi[i].deskripsi);
    }

    fclose(file);
}
