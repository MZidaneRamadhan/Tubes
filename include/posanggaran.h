#ifndef POSANGGARAN
#define POSANGGARAN

#include <stdbool.h>

#define MAX_STRING 100

typedef struct
{
    char namaAnggaran[MAX_STRING];
    int batasNominal;
} PosAnggaran;

extern PosAnggaran *Pos;
extern int jumlahPos;

void InputPosAnggaran(PosAnggaran **pos, int *length, int jumlahInput);
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama);
bool ValidasiNominalPos(int batasNominal);
void ShowPosAnggaran(PosAnggaran pos[], int length);
void SavePosAnggaran(PosAnggaran pos[], int length);
void LoadPosAnggaran(PosAnggaran **pos, int *count);

#endif