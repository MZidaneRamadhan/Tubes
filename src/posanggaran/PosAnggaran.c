#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include "TampilPosAnggaran.c"
// #include "printposanggaran.h"

#define MAX_STRING 100

typedef struct
{
    char NamaAnggaran[MAX_STRING];
    int BatasNominal;
    int realisasi;
    int jumlahTransaksi;
    int SisaAnggaran;
    char Status[20];
} PosAnggaran;

void InputPosAnggaran(PosAnggaran pos[], int length);
void TampilPosAnggaran(PosAnggaran pos[], int length);
void PrintPosAnggaran(PosAnggaran pos[], int length);
int LoadPosAnggaran();

int main()
{
    PosAnggaran Pos[2]; // typedef

    // LoadPosAnggaran(Pos);

    // int JumlahData;
    // scanf("%d", &JumlahData);

    int length = sizeof(Pos) / sizeof(Pos[0]); // panjang array

    printf("========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
    printf("1. Masukan Pos Anggaran Baru\n");
    printf("2. Lihat Pos Anggaran\n");

    int select;
    do
    {
        switch (select)
        {
        case 1:
            InputPosAnggaran(Pos, length);
            break;
        case 2:

            TampilPosAnggaran(Pos, length);
            break;

        default:
            break;
        }
    } while (select = 0);

    InputPosAnggaran(Pos, length);
    TampilPosAnggaran(Pos, length);
    PrintPosAnggaran(Pos, length);

    return 0;
}
void menu()
{
    printf("1. Masukan data baru");
    printf("2. Tampilkan semua data");
    printf("0. ");
}
int LoadPosAnggaran()
{
    PosAnggaran datapos[100];
    FILE *file;

    file = fopen("../../data/DataPosAnggaran.txt", "r");

    for (int i = 0; i < 100; i++)
    {
        fscanf(file, "|  %[^|]|  %d", datapos[i].NamaAnggaran, &datapos[i].BatasNominal);

        // fprintf(file, "|  %-15s |  %-14d |\n", pos[i].NamaAnggaran, pos[i].BatasNominal);
    }
    fclose(file);

    return datapos;
}
void InputPosAnggaran(PosAnggaran pos[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Masukan nama anggaran : ");
        scanf("%s", &pos[i].NamaAnggaran);

        do
        {
            printf("Masukan batas nominal : ");
            scanf("%d", &pos[i].BatasNominal);
            if (pos[i].BatasNominal <= 0)
            {
                printf("Batas nominal tidak boleh negatif dan 0! ulangin input batas nominal!\n");
            }

        } while (pos[i].BatasNominal <= 0);
    }
}

void TampilPosAnggaran(PosAnggaran pos[], int length)
{
    printf("_____________________________________________\n");

    printf("|  No  |  %-15s |  %-14s |\n", "Nama Anggaran", "Batas Nominal");

    printf("|______|__________________|_________________|\n");

    for (int i = 0; i < length; i++)
    {
        printf("|  %-3d |  %-15s |  %-14d |\n", i + 1, pos[i].NamaAnggaran, pos[i].BatasNominal);
    }
    printf("|______|__________________|_________________|\n");
}

void PrintPosAnggaran(PosAnggaran pos[], int length)
{
    FILE *file;

    file = fopen("../../data/DataPosAnggaran.txt", "w");

    for (int i = 0; i < length; i++)
    {
        fprintf(file, "|  %-15s |  %-14d |\n", pos[i].NamaAnggaran, pos[i].BatasNominal);
    }
    fclose(file);
}

// ValidasiTransaksi(char jenis[], int nominal, char tanggal[],
//                   char NamaPos[], PosAnggaran pos[], int JumlahPos)
// {
//     int valid = 1;

//     // Validasi jenis transaksi
//     if (strcasecmp(jenis, "Pemasukan") != 0 && strcasecmp(jenis, "Pengeluaran") != 0)
//     {
//         printf("Jenis transaksi harus 'Pemasukan' atau 'Pengeluaran'\n");
//         valid = 0;
//     }

//     // Validasi nominal
//     if (nominal <= 0)
//     {
//         printf("Nominal harus lebih dari 0\n");
//         valid = 0;
//     }

//     // Validasi tanggal
//     if (strlen(tanggal) == 0)
//     {
//         printf("Tanggal tidak boleh kosong\n");
//         valid = 0;
//     }

//     // Validasi pos anggaran
//     int ditemukan = 0;
//     int i;
//     for (i = 0; i < JumlahPos; i++)
//     {
//         if (strcasecmp(NamaPos, pos[i].NamaAnggaran) == 0)
//         {
//             ditemukan = 1;
//             break;
//         }
//     }
//     if (ditemukan != 0)
//     {
//         printf("Pos anggaran '%s' tidak ditemukan\n", NamaPos);
//         valid = 0;
//     }
//     return valid;
// }