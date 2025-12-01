#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"

/*	Prosedur SaveTransaksi
    I.S.	: Data transaksi dari user belum di ambil dari file eksternal
    F.S.	: Data transaksi dari user sudah di ambil dari file eksternal
*/
void LoadTransaksi(Transaksi **transaksi, int *jumlahTransaksi)
{
    FILE *file = fopen("../data/DataTransaksi.txt", "r");
    if (!file)
    {
        perror("Gagal membuka file transaksi");
        return;
    }

    char id[10], tanggal[20], jenis[20], namaPos[20], deskripsi[100], header[200];
    int nominal;

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

/**
 *  Prosedur InputTransaksi
 *  I.S.    : Array transaksi mungkin kosong atau memiliki beberapa data awal.
 *            User belum memasukkan data transaksi baru.
 *  F.S.    : Array transaksi bertambah sejumlah jumlahInputTransaksi.
 *            Setiap transaksi memiliki ID otomatis, tanggal valid, jenis valid,
 *            pos anggaran valid, nominal valid, dan deskripsi terisi.
 **/
void InputTransaksi(Transaksi **transaksi, int *jumlahTransaksi, int jumlahInputTransaksi)
{
    int oldLenght = *jumlahTransaksi;
    int newLength = *jumlahTransaksi + jumlahInputTransaksi;
    // Alokasi untuk menambah panjang array struct Transaksi
    *transaksi = realloc(*transaksi, newLength * sizeof(Transaksi));

    for (int i = oldLenght; i < newLength; i++)
    {
        printf("Input transaksi ke-%d\n", i + 1);

        // ID otomatis
        sprintf((*transaksi)[i].id, "T%03d", i + 1);

        // Tanggal
        do
        {
            printf("Tanggal (dd/mm/yyyy): ");
            scanf("%s", (*transaksi)[i].tanggal);

            if (!ValidasiTanggal((*transaksi)[i].tanggal))
            {
                printf("Tanggal tidak boleh kosong!\n");
            }

        } while (!ValidasiTanggal((*transaksi)[i].tanggal));

        // Jenis transaksi
        do
        {
            printf("Jenis (Pemasukan/Pengeluaran): ");
            scanf("%s", (*transaksi)[i].jenis);

            if (!ValidasiJenis((*transaksi)[i].jenis))
            {
                printf("Jenis (*transaksi) harus 'Pemasukan' atau 'Pengeluaran'\n");
            }
        } while (!ValidasiJenis((*transaksi)[i].jenis));

        // Pos Anggaran
        if (strcasecmp((*transaksi)[i].jenis, "Pemasukan") == 0)
        {
            strcpy((*transaksi)[i].namaPos, "Pemasukan");
        }
        else
        {
            do
            {
                printf("Pos Anggaran: ");
                scanf("%s", (*transaksi)[i].namaPos);

                if (!ValidasiPos(Pos, jumlahPos, (*transaksi)[i].namaPos))
                {
                    printf("Pos anggaran '%s' tidak ditemukan\n", (*transaksi)[i].namaPos);
                }

            } while (!ValidasiPos(Pos, jumlahPos, (*transaksi)[i].namaPos));
        }

        // Nominal
        do
        {
            printf("Nominal (Rp): ");
            scanf("%d", &(*transaksi)[i].nominal);

            if (!ValidasiNominal((*transaksi)[i].nominal))
            {
                printf("Nominal harus lebih dari 0\n");
            }

        } while (!ValidasiNominal((*transaksi)[i].nominal));
        getchar();

        // Deskripsi
        printf("Deskripsi: ");
        scanf(" %[^\n]", (*transaksi)[i].deskripsi);
    }
    *jumlahTransaksi = newLength;
}

/**
 *  Fungsi ValidasiJenis
 *  I.S.    : Variabel jenis berisi input dari user.
 *  F.S.    : Menghasilkan true jika jenis adalah "Pemasukan" atau "Pengeluaran",
 *            dan false jika selain itu.
 **/
bool ValidasiJenis(char jenis[])
{
    return (strcasecmp(jenis, "Pemasukan") == 0 ||
            strcasecmp(jenis, "Pengeluaran") == 0);
}

/**
 *  Fungsi ValidasiNominal
 *  I.S.    : User menginput nilai nominal.
 *  F.S.    : Menghasilkan true jika nominal > 0,
 *            dan false jika nominal <= 0.
 **/
bool ValidasiNominal(int nominal)
{
    return nominal > 0;
}

/**
 *  Fungsi ValidasiPos
 *  I.S.    : daftarPos terdefinisi berisi seluruh pos anggaran.
 *            namapos merupakan input user.
 *  F.S.    : Menghasilkan true jika namapos ditemukan di daftarPos,
 *            dan false jika tidak ditemukan.
 **/
bool ValidasiPos(PosAnggaran daftarPos[], int JumlahPos, char namapos[])
{
    for (int i = 0; i < JumlahPos; i++)
    {
        if (strcasecmp(namapos, daftarPos[i].namaAnggaran) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
 *  Fungsi ValidasiTanggal
 *  I.S.    : tanggal merupakan input user dalam bentuk string.
 *  F.S.    : Menghasilkan true jika string tanggal tidak kosong,
 *            dan false jika kosong.
 **/

bool ValidasiTanggal(char tanggal[])
{
    return strlen(tanggal) > 0;
}

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

/*	Prosedur SaveTransaksi
    I.S.	: Data transaksi dari user belum tersimpan di file eksternal
    F.S.	: Data transaksi dari user sudah tersimpan di file eksternal
*/
void SaveTransaksi(Transaksi transaksi[], int JumlahTransaksi)
{
    FILE *file = fopen("../data/DataTransaksi.txt", "w");

    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }
    fprintf(file, "No|Tanggal|JenisPengeluaran|NamaPos|Nominal|Deskripsi\n");

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
