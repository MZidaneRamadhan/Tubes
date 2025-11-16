#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_STRING_LENGTH 100

//Struct Data (Sinkron dengann modul yang lain)

typedef struct {
    char NamaAnggaran[MAX_STRING_LENGTH];
    int BatasNominal;
}PosAnggaran;

typedef struct {
    char ID[10];
    char tanggal[15];
    char NamaPos[MAX_STRING_LENGTH];
    int nominal;
    char deskripsi[100];
    char jenis[20];
}Transaksi;

// Perhitungan keuangan

// Deklarsi Fungsi dan Procedure
void MenuLaporanKeuangan(Transaksi transaksi[], int jumlahtransaksi);
void TampilkanLaporanKeuangan(Transaksi transaksi[], int jumlahTransaksi);
int TotalPemasukan(Transaksi transaksi[],int jumlahTransaksi);
int TotalPengeluaran(Transaksi transaksi[],int jumlahTransaksi);
int Saldo(Transaksi transaksi[],int jumlahTransaksi);
int RataRata(Transaksi transaksi[],int jumlahTransaksi);
char* KondisiKeuangan(int saldo);
float PersentaseSisa(int saldo, int totalPemasukan);
float PersentaseSD(int saldo, int totalPemasukan);

// Procedure Input Laporan Keuangan
// Data yang ada disini hanya sebagai contoh untuk menguji fungsi dan prosedur apakah berjalan dengan baik atau tidak,
// untuk data yang sebenarnya, akan diambil dari modul input transaksi
void TampilkanLaporanKeuangan(Transaksi transaksi[], int jumlahTransaksi);
int main(){
    Transaksi transaksi[5] = {
        {"T001", "2024-01-01", "Gaji", 100000, "Gaji Bulanan", "Pemasukan"},
        {"T002", "2024-01-05", "Asu Kayang", 150000, "Proyek Desain", "Pemasukan"},
        {"T003", "2024-01-10", "Makan", 80000, "Makan Siang", "Pengeluaran"},
        {"T004", "2024-01-15", "Transportasi", 150000, "Ojek Online", "Pengeluaran"},
        {"T005", "2024-01-20", "Bonus", 1000000, "Bonus Proyek", "Pemasukan"}
    };
    MenuLaporanKeuangan(transaksi,5);
    int totalPemasukan = TotalPemasukan(transaksi, 5);
    int totalPengeluaran = TotalPengeluaran(transaksi,5);
    int saldo = Saldo (transaksi,5);
    TampilkanLaporanKeuangan(transaksi,5);
    return 0;
}

// Fungsi Total Pemasukan
int TotalPemasukan(Transaksi transaksi[],int jumlahTransaksi){
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++){
        if (strcmp(transaksi[i].jenis,"Pemasukan")==0){
            total += transaksi[i].nominal;
        }
    }
    return total;
}


// Fungsi Total Pengeluaran
int TotalPengeluaran(Transaksi transaksi[],int jumlahTransaksi){
    int total = 0;
    for (int i = 0; i < jumlahTransaksi; i++){
        if (strcmp(transaksi[i].jenis,"Pengeluaran")==0){
            total += transaksi[i].nominal;
        }
    }
    return total;
}


// Fungsi Saldo 
int Saldo(Transaksi transaksi[],int jumlahTransaksi){
    int saldo = TotalPemasukan(transaksi,jumlahTransaksi) - TotalPengeluaran (transaksi,jumlahTransaksi);
    return saldo;
}

// Fungsi Rata-rata pengeluaran
int RataRata(Transaksi transaksi[],int jumlahTransaksi){
    int ratarata;
    if (jumlahTransaksi == 0) {     // Jika tidak ada transaksi, rata-rata dianggap = 0
        ratarata = 0;
    } else if (jumlahTransaksi > 0){
        ratarata = TotalPengeluaran(transaksi,jumlahTransaksi) / jumlahTransaksi;
    }
    return ratarata;
}


// Fungsi Kondisi Keuangan
char* KondisiKeuangan(int saldo){
    if (saldo > 0){
        return "Surplus"; //Sehat
    } else if (saldo == 0){
        return "Seimbang"; //Cukup
    } else {
        return "Defisit"; //Buruk
    }
}


// Persentase Sisa
float PersentaseSisa(int saldo, int totalPemasukan){
    if (totalPemasukan == 0){
        return 0.0; // Menghindari pembagian dengan nol
    }
    return ((float)saldo / totalPemasukan) * 100;
}

// Persentase Surplus dan Defisit
float PersentaseSD(int saldo, int totalPemasukan){
    if (saldo >= 200000) {
        return 0.0; // Surplus Besar
    } else if (saldo >= 100000 && saldo < 200000) {
        return 0.0; // Surplus Sedang
    } else if (saldo > 0 && saldo < 100000) {
        return 0.0; // Surplus Kecil
    } else if (saldo == 0) {
        return 0.0; // Seimbang
    } else if (saldo < 0) {
        return 0.0; // Defisit Kecil
    } else if (saldo < -100000) {
        return 0.0; // Defisit Sedang
    } else if (saldo < -200000) {
        return 0.0; // Defisit Besar
    }
    return ((float)saldo/ totalPemasukan) * 100;
    }


// Procedure Menampilkan Laporan Keuangan
void TampilkanLaporanKeuangan(Transaksi transaksi[], int jumlahTransaksi){
    printf("Laporan Keuangan:\n");
    printf("______________________________________________________________________________________________________\n");
    printf("%-8s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "ID", "Tanggal", "Nama Pos", "Nominal", "Deskripsi", "Jenis");
    printf("_______________________________________________________________________________________________________\n");
    for (int i = 0; i < jumlahTransaksi; i++){
        printf("%-8s | %-15s | %-15s | %-15d | %-15s | %-15s |\n", 
        transaksi[i].ID, transaksi[i].tanggal, transaksi[i].NamaPos, transaksi[i].nominal, transaksi[i].deskripsi,
         transaksi[i].jenis);
    }
    printf("_______________________________________________________________________________________________________\n");
    printf("Laporan Kondisi Keuangan:\n");
    printf("_______________________________________________________________________________________________________________________________________\n");
    printf("%-25s | %-25s | %-25s | %-25s | %-25s | \n", "Total Pemasukan", "Total Pengeluaran",
         "Saldo Akhir", "Rata-rata Pengeluaran", "Kondisi Keuangan");
    printf("_________________________________________________________________________________________________________________________________________\n");
    printf(("%-25d | %-25d | %-25d | %-25d | %-25s | \n",TotalPemasukan(transaksi,jumlahTransaksi),TotalPengeluaran(transaksi,jumlahTransaksi),
    Saldo(transaksi,jumlahTransaksi),RataRata(transaksi,jumlahTransaksi),KondisiKeuangan(Saldo(transaksi,jumlahTransaksi))));
    printf("_________________________________________________________________________________________________________________________________________\n");
    printf("Persentase Sisa: %.2f%%\n", PersentaseSisa(Saldo(transaksi,jumlahTransaksi), TotalPemasukan(transaksi,jumlahTransaksi)));
    printf("Persentase Surplus/Defisit: %.2f%%\n", PersentaseSD(Saldo(transaksi,jumlahTransaksi), TotalPemasukan(transaksi,jumlahTransaksi)));}


// Menu Laporan Keuangan
void MenuLaporanKeuangan(Transaksi transaksi[], int jumlahtransaksi){
    int select;
    do{
        printf("Menu Laporan Keuangan:\n");
        printf("1. Tampilkan Laporan Keuangan\n");
        printf("2. Tampilkan Total Pemasukan\n");
        printf("3. Tampilkan Total Pengeluaran\n");
        printf("4. Tampilkan Saldo Akhir\n");
        printf("5. Tampilkan Rata-rata Pengeluaran\n");  
        printf("Pilih opsi (1-5): ");
        scanf("%d", &select);
        switch(select){
            case 1:
                TampilkanLaporanKeuangan(transaksi, jumlahtransaksi);
                break;
            case 2:
                printf("Total Pemasukan: %d\n", TotalPemasukan(transaksi, jumlahtransaksi));
                break;
            case 3:
                printf("Total Pengeluaran: %d\n", TotalPengeluaran(transaksi, jumlahtransaksi));
                break;
            case 4:
                printf("Saldo Akhir: %d\n", Saldo(transaksi, jumlahtransaksi));
                break;
            case 5:
                printf("Rata-rata Pengeluaran: %d\n", RataRata(transaksi, jumlahtransaksi));
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (select != 6);
}