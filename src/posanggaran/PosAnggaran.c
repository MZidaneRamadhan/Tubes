#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../../include/posanggaran.h"

/*
    Author : Muhammad Zidane Ramadhan Oktaviantoro (251524058)
*/

/**
 *  Procedure LoadPosAnggaran
 *  I.S.    : Array pos mungkin kosong dan file DataPosAnggaran.txt mungkin ada atau tidak.
 *  F.S.    : Array pos terisi dengan data pos anggaran hasil pembacaan file.
 **/
void LoadPosAnggaran(PosAnggaran **pos, int *count)
{
    FILE *file = fopen("../data/DataPosAnggaran.txt", "r");
    if (file == NULL)
    {
        printf("File tidak ditemukan, mulai dari data kosong.\n");
        return;
    }
    char buffer[256];
    char nama[MAX_STRING];
    int batas;

    fgets(buffer, sizeof(buffer), file);
    while (fscanf(file, " |%[^|]|%d|", nama, &batas) == 2)
    {
        // Tambahkan 1 slot ke array dinamis
        *pos = realloc(*pos, (*count + 1) * sizeof(PosAnggaran));

        // Masukkan data ke array
        strcpy((*pos)[*count].namaAnggaran, nama);
        (*pos)[*count].batasNominal = batas;

        (*count)++; // naikkan jumlah data
    }
    fclose(file);
}

/**
 *  Procedure InputPosAnggaran
 *  I.S.    : Array pos terdefinisi dengan length lama, user belum memasukkan data baru.
 *  F.S.    : Array pos bertambah sejumlah jumlahInput dan setiap data sudah tervalidasi.
 **/
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
            getchar();
            printf("Masukkan nama anggaran: ");
            scanf("%[^\n]", (*pos)[i].namaAnggaran);

            isNameValid = ValidasiNamaPos(*pos, i, (*pos)[i].namaAnggaran);

        } while (isNameValid);

        bool isNominalValid;
        do
        {
            printf("Masukan batas nominal: ");
            scanf("%d", &(*pos)[i].batasNominal);

            isNominalValid = ValidasiNominalPos((*pos)[i].batasNominal);

        } while (isNominalValid);
    }
    *length = newLength;
}

/**
 *  Fungsi ValidasiNominalPos
 *  I.S.    : batasNominal diberikan oleh user.
 *  F.S.    : Menghasilkan true jika batas nominal tidak valid (<= 0),
 *            atau false jika batas nominal valid.
 **/
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(pos[i].namaAnggaran, nama) == 0)
        {
            printf("Nama anggaran '%s' sudah ada! Masukkan nama lain!\n", pos[i].namaAnggaran);
            return true; // duplikat ditemukan
        }
    }
    return false;
}

/**
 *  Fungsi ValidasiNominalPos
 *  I.S.    : batasNominal diberikan oleh user.
 *  F.S.    : Menghasilkan true jika batas nominal tidak valid (<= 0),
 *            atau false jika batas nominal valid.
 **/
bool ValidasiNominalPos(int batasNominal)
{
    if (batasNominal <= 0)
    {
        printf("Batas nominal tidak boleh negatif dan 0! Ulangin input batas nominal!\n");
        return true; // batas <= 0
    }
    return false;
}

/**
 *  Procedure ShowPosAnggaran
 *  I.S.    : Array pos terdefinisi dan memiliki length data.
 *  F.S.    : Menampilkan seluruh data pos anggaran ke layar dalam format tabel.
 **/
void ShowPosAnggaran(PosAnggaran pos[], int length)
{
    printf("_____________________________________________\n");

    printf("|  No  |  %-15s |  %-14s |\n", "Nama Anggaran", "Batas Nominal");

    printf("|______|__________________|_________________|\n");

    for (int i = 0; i < length; i++)
    {
        printf("|  %-3d |  %-15s |  %-14d |\n", i + 1, pos[i].namaAnggaran, pos[i].batasNominal);
    }
    printf("|______|__________________|_________________|\n");
}

/**
 *  Procedure PrintPosAnggaran
 *  I.S.    : Array pos terisi sejumlah length data.
 *  F.S.    : Seluruh data pos anggaran ditulis ke file DataPosAnggaran.txt dalam folder /data.
 **/
void SavePosAnggaran(PosAnggaran pos[], int length)
{
    FILE *file;

    file = fopen("../data/DataPosAnggaran.txt", "w");

    fprintf(file, "|NamaPosAnggaran|Nominal|\n");
    for (int i = 0; i < length; i++)
    {
        fprintf(file, "|%s|%d|\n", pos[i].namaAnggaran, pos[i].batasNominal);
    }
    fclose(file);
}
