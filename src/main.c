#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/posanggaran.h"

void menu();

int main()
{
    int select;
    menu();
    do
    {
        switch (select)
        {
        case 1:

            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        default:
            break;
        }
        /* code */
    } while (select);

    return 0;
}

void menu()
{
    printf("========================================= Aplikasi Keuangan Mahasiswa =========================================\n");
    printf("Pilihan menu\n");
    printf("1. Pos Anggaran\n");
    printf("2. Tampilkan \n");
    printf("0. Kembali ke menu utama\n");
    printf("Masukan pilihan menu (0-2): ");
}