#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/posanggaran.h"
#include "../../include/transaksi.h"

/*	Prosedur InputTransaksi
    I.S.	: Data transaksi dari user belum diketahui
    F.S.	: Data transaksi dari user sudah tersimpan ke array record
*/
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

// Fungsi ValidasiJenis
/*	Memeriksa keabsahan data jenis transaksi
    Input	: Data jenis transaksi dari user
    Output	: True  -> valid
              False -> tidak valid
*/
bool ValidasiJenis(char jenis[])
{
    return (strcasecmp(jenis, "Pemasukan") == 0 ||
            strcasecmp(jenis, "Pengeluaran") == 0);
}

// Fungsi ValidasiNominal
/*	Memeriksa keabsahan nominal transaksi
    Input	: Data nominal transaksi dari user
    Output	: True  -> valid
              False -> tidak valid
*/
bool ValidasiNominal(int nominal)
{
    return nominal > 0;
}

// Fungsi ValidasiPos
/*	Memeriksa keabsahan jenis pos anggaran
    Input	: Data jenis pos anggaran dari user
    Output	: True  -> valid
              False -> tidak valid
*/
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

// Fungsi ValidasiTanggal
/*	Memeriksa keabsahan data tanggal
    Input	: Data tanggal dari user
    Output	: True  -> valid
              False -> tidak valid
*/

bool ValidasiTanggal(char tanggal[])
{
    return strlen(tanggal) > 0;
}
