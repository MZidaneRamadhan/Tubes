#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/transaksi.h"

void LoadTransaksi(Transaksi **transaksi, int *jumlahTransaksi)
{
    FILE *file = fopen("../data/DataTransaksi.txt", "r");
    if (!file)
    {
        perror("Gagal membuka file transaksi");
        return;
    }

    char id[10], tanggal[20], jenis[20], namaPos[20], deskripsi[100];
    int nominal;

    char header[200];
    fgets(header, sizeof(header), file); // skip header jika ada

    while (fscanf(file, " %[^|]|%[^|]|%[^|]|%[^|]|%d|%[^\n]",
                  id, tanggal, jenis, namaPos, &nominal, deskripsi) == 6)
    {
        *transaksi = realloc(*transaksi, (*jumlahTransaksi + 1) * sizeof(Transaksi));

        strcpy((*transaksi)[*jumlahTransaksi].id, id);
        strcpy((*transaksi)[*jumlahTransaksi].tanggal, tanggal);
        strcpy((*transaksi)[*jumlahTransaksi].jenis, jenis);
        strcpy((*transaksi)[*jumlahTransaksi].namaPos, namaPos);
        (*transaksi)[*jumlahTransaksi].nominal = nominal;
        strcpy((*transaksi)[*jumlahTransaksi].deskripsi, deskripsi);

        (*jumlahTransaksi)++;
    }
    fclose(file);
    int lenght = *jumlahTransaksi;
}