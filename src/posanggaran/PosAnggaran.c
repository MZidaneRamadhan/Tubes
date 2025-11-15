#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// #include "../../include/posanggaran.h"

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

void MenuPos();
void InputPosAnggaran(PosAnggaran **pos, int *length, int jumlahInput);
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama);
bool ValidasiNominalPos(int batasNominal);
void TampilPosAnggaran(PosAnggaran pos[], int length);
void PrintPosAnggaran(PosAnggaran pos[], int length);
void LoadPosAnggaran(PosAnggaran **pos, int *count);

int count = 0;

// void MenuPos();

int main()
{
    PosAnggaran *Pos = NULL;
    LoadPosAnggaran(&Pos, &count);

    int select;

    do
    {
        MenuPos();
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            int jumlahInput;
            printf("Masukkan berapa data baru: ");
            scanf("%d", &jumlahInput);

            InputPosAnggaran(&Pos, &count, jumlahInput);
            break;
        case 2:
            TampilPosAnggaran(Pos, count);
            break;
        case 0:
            break;

        default:
            printf("Pilih menu yang benar!");
            break;
        }
    } while (select);

    return 0;
}

// Procedure LoadPosAnggaran
/*	Melakukan read data dari file ke pos anggaran
    Input	: -
    Output	: Menampilkan menu dari Pos Anggaran
*/
void MenuPos()
{
    printf("========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
    printf("1. Masukan data Pos Anggaran baru\n");
    printf("2. Tampilkan semua data\n");
    printf("0. Kembali ke menu utama\n");
    printf("Masukan pilihan menu (0-2): ");
}

// Procedure LoadPosAnggaran
/*	Melakukan read data dari file ke pos anggaran
    Input	: PosAnggaran pos[]
    Output	: Mendapatkan nilai dari file
*/
void LoadPosAnggaran(PosAnggaran **pos, int *count)
{
    FILE *file = fopen("../../data/DataPosAnggaran.txt", "r");
    if (file == NULL)
    {
        printf("File tidak ditemukan, mulai dari data kosong.\n");
        return;
    }

    char nama[MAX_STRING];
    int batas;

    while (fscanf(file, " |%[^|]|%d|", nama, &batas) == 2)
    {
        // Tambahkan 1 slot ke array dinamis
        *pos = realloc(*pos, (*count + 1) * sizeof(PosAnggaran));

        // Masukkan data ke array
        strcpy((*pos)[*count].NamaAnggaran, nama);
        (*pos)[*count].BatasNominal = batas;

        (*count)++; // naikkan jumlah data
    }
    fclose(file);
}

// Procedure ValidasiNamaPos
/*	Menginput data pos anggaran ke dalam array struct
    Input	: PosAnggaran pos[], length
    Output	: Nama pos anggaran
              Batas nominal pos anggaran
*/
void InputPosAnggaran(PosAnggaran **pos, int *length, int jumlahInput)
{
    int oldLength = *length;
    int newLength = *length + jumlahInput;

    *pos = realloc(*pos, newLength * sizeof(PosAnggaran));

    for (int i = oldLength; i < newLength; i++)
    {
        printf("\nData ke-%d\n", i + 1);

        bool isNameValid;
        do
        {
            printf("Masukkan nama anggaran: ");
            scanf("%s", (*pos)[i].NamaAnggaran);

            isNameValid = ValidasiNamaPos(*pos, i, (*pos)[i].NamaAnggaran);

        } while (isNameValid);

        bool isNominalValid;
        do
        {
            printf("Masukan batas nominal: ");
            scanf("%d", &(*pos)[i].BatasNominal);

            isNominalValid = ValidasiNominalPos((*pos)[i].BatasNominal);

        } while (isNominalValid);
    }
    *length = newLength;
}

// Fungsi ValidasiNamaPos
/*	Memeriksa apakah ada nama pos anggaran yang sama
    Input	: PosAnggaran pos[], count, *nama
    Output	: True  -> duplikat
              False -> tidak duplikat
*/
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(pos[i].NamaAnggaran, nama) == 0)
        {
            printf("Nama anggaran '%s' sudah ada! Masukkan nama lain!\n", pos[i].NamaAnggaran);
            return true; // duplikat ditemukan
        }
    }
    return false;
}

// Fungsi ValidasiNominalPos
/*	Memeriksa apakah ada nama pos anggaran yang sama
    Input	: PosAnggaran pos[], count, *nama
    Output	: True  -> batas nominal <= 0
              False -> batas nominal tidak <= 0
*/
bool ValidasiNominalPos(int batasNominal)
{
    if (batasNominal <= 0)
    {
        printf("Batas nominal tidak boleh negatif dan 0! Ulangin input batas nominal!\n");
        return true; // batas <= 0
    }
    return false;
}

// Procedure TampilPosAnggaran
/*	Menampilkan data pos anggaran ke terminal
    Input	: PosAnggaran pos[], length
    Output	: Daftar data Pos Anggaran
*/
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

// Procedure TampilPosAnggaran
/*	Melakukan write data pos anggaran ke dalam file DataPosAnggaran.txt di folder /data
    Input	: PosAnggaran pos[], length
    Output	: Daftar data Pos Anggaran
*/
void PrintPosAnggaran(PosAnggaran pos[], int length)
{
    FILE *file;

    file = fopen("../../data/DataPosAnggaran.txt", "w");

    for (int i = 0; i < length; i++)
    {
        // fprintf(file, "|  %-15s |  %-14d |\n", pos[i].NamaAnggaran, pos[i].BatasNominal);
        fprintf(file, "|%s|%d|\n", pos[i].NamaAnggaran, pos[i].BatasNominal);
    }
    fclose(file);
}
