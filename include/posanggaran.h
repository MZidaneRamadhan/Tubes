#ifndef POSANGGARAN
#define POSANGGARAN

typedef struct
{
    char NamaAnggaran[100];
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

#endif