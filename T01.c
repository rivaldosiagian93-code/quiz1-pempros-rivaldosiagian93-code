#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data pesanan
typedef struct {
    char kode[10];
    char nama[50];
    long harga;
    int porsi;
    long subtotal;
} Pesanan;

int main() {
    Pesanan daftar_pesanan[100];
    int jumlah_pesanan = 0;
    long total_harga = 0;
    char input_kode[10];
    
    
    while (1) {
        // Menerima input kode menu
        scanf("%s", input_kode);
        
        // Berhenti jika input adalah END
        if (strcmp(input_kode, "END") == 0) {
            break;
        }
        
        // Menerima input porsi
        int input_porsi;
        scanf("%d", &input_porsi);
        
        // Menyimpan data ke dalam struct
        strcpy(daftar_pesanan[jumlah_pesanan].kode, input_kode);
        daftar_pesanan[jumlah_pesanan].porsi = input_porsi;
        
        // Daftar menu disesuaikan dengan contoh di gambar
        // Silakan sesuaikan kode input (NP, RD, AG) dengan ketentuan soal aslinya
        if (strcmp(input_kode, "NGS") == 0) {
            strcpy(daftar_pesanan[jumlah_pesanan].nama, "Nasi Padang");
            daftar_pesanan[jumlah_pesanan].harga = 25000;
        } else if (strcmp(input_kode, "AP") == 0) {
            strcpy(daftar_pesanan[jumlah_pesanan].nama, "Rendang");
            daftar_pesanan[jumlah_pesanan].harga = 30000;
        } else if (strcmp(input_kode, "GG") == 0) {
            strcpy(daftar_pesanan[jumlah_pesanan].nama, "Ayam Goreng");
            daftar_pesanan[jumlah_pesanan].harga = 22000;
        } else {
            strcpy(daftar_pesanan[jumlah_pesanan].nama, "Menu Lain");
            daftar_pesanan[jumlah_pesanan].harga = 10000; // Harga default
        }
        
        // Menghitung subtotal
        daftar_pesanan[jumlah_pesanan].subtotal = daftar_pesanan[jumlah_pesanan].porsi * daftar_pesanan[jumlah_pesanan].harga;
        
        total_harga += daftar_pesanan[jumlah_pesanan].subtotal;
        jumlah_pesanan++;
    }
    
    // ==========================================================
    // BAGIAN OUTPUT STRUK (Disamakan persis dengan gambar)
    // ==========================================================
    printf("\n%-19s %-9s %-9s %s\n", "Menu", "Porsi", "Harga", "Total");
    printf("==============================================================\n");
    
    for (int i = 0; i < jumlah_pesanan; i++) {
        // %-19s berarti string rata kiri dengan lebar 19 karakter
        // %-9d berarti integer rata kiri dengan lebar 9 karakter
        printf("%-19s %-9d %-9ld %ld\n", 
               daftar_pesanan[i].nama, 
               daftar_pesanan[i].porsi, 
               daftar_pesanan[i].harga, 
               daftar_pesanan[i].subtotal);
    }
    
    printf("==============================================================\n");
    
    // %-37s untuk mendorong angka Total Pembayaran agar lurus dengan kolom Total
    printf("%-37s %ld\n", "Total Pembayaran", total_harga);
    
    return 0;
}