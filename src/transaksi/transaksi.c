#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_STRING 100

// Kamus data variabel global
typedef struct
{
    char NamaAnggaran[MAX_STRING];
    int BatasNominal;
} PosAnggaran;
PosAnggaran pos[100];

typedef struct
{
    char id[10];
    char tanggal[20];
    char jenis[20];
    char namapos[20];
    int nominal;
    char deskripsi[100];
} Transaksi;

int JumlahTransaksi;
int JumlahPos;

// Deklarasi Modul Pos Anggaran
void InputPosAnggaran(PosAnggaran pos[], int JumlahPos);
void ShowPosAnggaran(PosAnggaran pos[], int JumlahPos);
void PrintPosAnggaran(PosAnggaran pos[], int JumlahPos);

// Deklarasi Modul Transaksi
void InputTransaksi(Transaksi t[], int JumlahTransaksi);
bool ValidasiTanggal(char tanggal[]);
bool ValidasiJenis(char jenis[]);
bool ValidasiPos(PosAnggaran pos[], int JumlahPos, char namapos[]);
bool ValidasiNominal(int nominal);
void ShowTransaksi(Transaksi t[], int JumlahTransaksi);
void PrintTransaksi(Transaksi t[], int JumlahTransaksi);

// Program Utama
int trans()
{
    // Pos Anggaran
    printf("Masukkan jumlah pos anggaran: ");
    scanf("%d", &JumlahPos);
    Transaksi trans[JumlahPos];
    getchar();

    printf("\n============= INPUT DATA POS ANGGARAN =============\n");
    InputPosAnggaran(pos, JumlahPos);

    printf("\n============= DAFTAR POS ANGGARAN =============\n");
    ShowPosAnggaran(pos, JumlahPos);

    PrintPosAnggaran(pos, JumlahPos);

    // Transaksi
    printf("Masukkan jumlah transaksi: ");
    scanf("%d", &JumlahTransaksi);
    getchar();

    printf("\n============= INPUT DATA TRANSAKSI =============\n");
    InputTransaksi(trans, JumlahTransaksi);

    printf("\n============= DAFTAR TRANSAKSI =============\n");
    ShowTransaksi(trans, JumlahTransaksi);

    PrintTransaksi(trans, JumlahTransaksi);

    return 0;
}

void InputPosAnggaran(PosAnggaran pos[], int JumlahPos)
{
    for (int i = 0; i < JumlahPos; i++)
    {
        printf("Masukan nama anggaran : ");
        scanf("%s", pos[i].NamaAnggaran);
        getchar();

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

void ShowPosAnggaran(PosAnggaran pos[], int JumlahPos)
{
    printf("\n");
    printf("| No |  %-15s |  %-14s |\n",
           "Nama Anggaran", "Batas Nominal");
    printf("|||_|\n");

    for (int i = 0; i < JumlahPos; i++)
    {
        printf("| %-3d|  %-15s |  %-14d |\n",
               i + 1,
               pos[i].NamaAnggaran,
               pos[i].BatasNominal);
    }
    printf("|||_|\n");
}

void PrintPosAnggaran(PosAnggaran pos[], int JumlahPos)
{
    FILE *file;

    file = fopen("DataPosAnggaran.txt", "w");

    for (int i = 0; i < JumlahPos; i++)
    {
        fprintf(file, "|  %-15s |  %-14d |\n", pos[i].NamaAnggaran, pos[i].BatasNominal);
    }
    fclose(file);
}

/*	Prosedur InputTransaksi
    I.S.	: Data transaksi dari user belum diketahui
    F.S.	: Data transaksi dari user sudah tersimpan ke array record
*/

void InputTransaksi(Transaksi t[], int JumlahTransaksi)
{
    for (int i = 0; i < JumlahTransaksi; i++)
    {
        printf("Input Transaksi ke-%d\n", i + 1);

        // ID otomatis
        sprintf(t[i].id, "T%03d", i + 1);

        // Tanggal
        do
        {
            printf("Tanggal (dd/mm/yyyy): ");
            scanf("%s", t[i].tanggal);

            if (!ValidasiTanggal(t[i].tanggal))
            {
                printf("Tanggal tidak boleh kosong!\n");
            }

        } while (!ValidasiTanggal(t[i].tanggal));

        // Jenis transaksi
        do
        {
            printf("Jenis (Pemasukan/Pengeluaran): ");
            scanf("%s", t[i].jenis);

            if (!ValidasiJenis(t[i].jenis))
            {
                printf("Jenis transaksi harus 'Pemasukan' atau 'Pengeluaran'\n");
            }
        } while (!ValidasiJenis(t[i].jenis));

        // Pos Anggaran
        do
        {
            printf("Pos Anggaran: ");
            scanf("%s", t[i].namapos);

            if (!ValidasiPos(pos, JumlahPos, t[i].namapos))
            {
                printf("Pos anggaran '%s' tidak ditemukan\n", t[i].namapos);
            }

        } while (!ValidasiPos(pos, JumlahPos, t[i].namapos));

        // Nominal
        do
        {
            printf("Nominal (Rp): ");
            scanf("%d", &t[i].nominal);

            if (!ValidasiNominal(t[i].nominal))
            {
                printf("Nominal harus lebih dari 0\n");
            }

        } while (!ValidasiNominal(t[i].nominal));
        getchar();

        // Deskripsi
        printf("Deskripsi: ");
        scanf(" %[^\n]", t[i].deskripsi);
    }
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
        if (strcasecmp(namapos, pos[i].NamaAnggaran) == 0)
        {
            return true;
        }
    }
    return false;
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

/*	Prosedur ShowTransaksi
    I.S.	: Data transaksi dari user tersimpat di array record Transaksi
    F.S.	: Data transaksi dari user muncul di layar
*/

void ShowTransaksi(Transaksi t[], int JumlahTransaksi)
{
    printf("___________________________________________________________________________________________\n");
    printf("| %-6s | %-12s | %-12s | %-12s | %-12s | %-20s |\n",
           "ID", "Tanggal", "Jenis", "Pos", "Nominal", "Deskripsi");
    printf("|________|______________|______________|______________|______________|____________________|\n");

    for (int i = 0; i < JumlahTransaksi; i++)
    {
        printf("| %-6s | %-12s | %-12s | %-12s | %-12d | %-20s |\n",
               t[i].id,
               t[i].tanggal,
               t[i].jenis,
               t[i].namapos,
               t[i].nominal,
               t[i].deskripsi);
    }

    printf("|________|______________|______________|______________|______________|____________________|\n");
}

/*	Prosedur PrintTransaksi
    I.S.	: Data transaksi dari user belum tersimpan di file eksternal
    F.S.	: Data transaksi dari user sudah tersimpan di file eksternal
*/

void PrintTransaksi(Transaksi t[], int JumlahTransaksi)
{
    FILE *file = fopen("DataTransaksi.txt", "a");

    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    for (int i = 0; i < JumlahTransaksi; i++)
    {
        fprintf(file, "%s | %s | %s | %s | %d | %s\n",
                t[i].id,
                t[i].tanggal,
                t[i].jenis,
                t[i].namapos,
                t[i].nominal,
                t[i].deskripsi);
    }

    fclose(file);
}