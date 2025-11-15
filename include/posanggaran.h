#ifndef POSANGGARAN
#define POSANGGARAN

#include <stdbool.h>

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

void LoadPosAnggaran(PosAnggaran pos[]);
void InputPosAnggaran(PosAnggaran pos[], int length);
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama);
void TampilPosAnggaran(PosAnggaran pos[], int length);
void PrintPosAnggaran(PosAnggaran pos[], int length);
void LoadPosAnggaran(PosAnggaran pos[]);

#endif