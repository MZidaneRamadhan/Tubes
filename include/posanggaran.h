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

/**
 *  Procedure LoadPosAnggaran
 *  I.S.    : Array pos mungkin kosong dan file DataPosAnggaran.txt mungkin ada atau tidak.
 *  F.S.    : Array pos terisi dengan data pos anggaran hasil pembacaan file.
 **/
void InputPosAnggaran(PosAnggaran **pos, int *length, int jumlahInput);

/**
 *  Procedure InputPosAnggaran
 *  I.S.    : Array pos terdefinisi dengan jumlahPos lama, user belum memasukkan data baru.
 *  F.S.    : Array pos bertambah sejumlah jumlahInput dan setiap data sudah tervalidasi.
 **/
bool ValidasiNamaPos(PosAnggaran pos[], int count, const char *nama);

/**
 *  Fungsi ValidasiNominalPos
 *  I.S.    : batasNominal diberikan oleh user.
 *  F.S.    : Menghasilkan true jika batas nominal tidak valid (<= 0),
 *            atau false jika batas nominal valid.
 **/
bool ValidasiNominalPos(int batasNominal);

/**
 *  Fungsi ValidasiNominalPos
 *  I.S.    : batasNominal diberikan oleh user.
 *  F.S.    : Menghasilkan true jika batas nominal tidak valid (<= 0),
 *            atau false jika batas nominal valid.
 **/
void ShowPosAnggaran(PosAnggaran pos[], int length);

/**
 *  Procedure ShowPosAnggaran
 *  I.S.    : Array pos terdefinisi dan memiliki jumlahPos data.
 *  F.S.    : Menampilkan seluruh data pos anggaran ke layar dalam format tabel.
 **/
void SavePosAnggaran(PosAnggaran pos[], int length);

/**
 *  Procedure SavePosAnggaran
 *  I.S.    : Array pos terisi sejumlah jumlahPos data.
 *  F.S.    : Seluruh data pos anggaran ditulis ke file DataPosAnggaran.txt dalam folder /data.
 **/
void LoadPosAnggaran(PosAnggaran **pos, int *count);

#endif