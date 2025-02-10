#include <iostream>
#include <vector>
#include <string>
#include <limits> // Untuk cin.ignore()

using namespace std;

// Struktur data untuk sepatu
struct Sepatu {
    string nama;
    int harga;
    vector<int> ukuran;
};

// Struktur data untuk menyimpan pilihan pembelian
struct Pembelian {
    string nama_sepatu;
    int ukuran;
    int harga;
};

void tampilkanFrame(const string& teks) {
    int panjang = teks.length();
    cout << string(panjang + 9, '*') << endl;
    cout << " * & " << teks << " & *" << endl;
    cout << string(panjang + 9, '*') << endl;
}

void tampilkanPembelian(const vector<Pembelian>& daftar_pembelian) {
    if (daftar_pembelian.empty()) {
        cout << "\nBelum ada sepatu yang dibeli.\n";
        return;
    }

    cout << "\n--- Daftar Pembelian Saat Ini ---\n";
    for (size_t i = 0; i < daftar_pembelian.size(); ++i) {
        const auto& pembelian = daftar_pembelian[i];
        cout << i + 1 << ". Sepatu: " << pembelian.nama_sepatu
             << " | Ukuran: " << pembelian.ukuran
             << " | Harga: Rp " << pembelian.harga << endl;
    }
    cout << endl;
}

void hapusPembelian(vector<Pembelian>& daftar_pembelian) {
    if (daftar_pembelian.empty()) {
        cout << "\nTidak ada sepatu dalam keranjang untuk dihapus.\n";
        return;
    }

    tampilkanPembelian(daftar_pembelian);

    // tampilan hapus produk di keranjang
    int index_hapus;
    cout << "Masukkan nomor sepatu yang ingin dihapus dari keranjang: ";
    cin >> index_hapus;

    // validasi input dari hapus
    if (cin.fail() || index_hapus < 1 || index_hapus > daftar_pembelian.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pilihan tidak valid. Kembali ke menu.\n";
        return;
    }

    // Hapus item dari daftar pembelian
    daftar_pembelian.erase(daftar_pembelian.begin() + index_hapus - 1);
    cout << "Sepatu berhasil dihapus dari keranjang.\n";
}

int main() {
    string pesan = "Selamat datang, Selamat berbelanja!";
    tampilkanFrame(pesan);
    cout << endl;

    // Meminta input nama kasir
    string nama_kasir;
    cout << "Masukkan nama kasir: ";
    getline(cin, nama_kasir);

    // Daftar sepatu
    vector<Sepatu> daftar_sepatu = {
        {"Nike", 13000, {40, 41, 42}},
        {"Adidas", 3000, {39, 40, 43}},
        {"Puma", 13000, {38, 40, 44}}
    };

    vector<Pembelian> daftar_pembelian; // Menyimpan semua pilihan pengguna
    char lanjut;                        // Untuk mengulang pembelian

    do {
        // Menampilkan data sepatu
        cout << "\nDaftar Sepatu:\n";
        for (size_t i = 0; i < daftar_sepatu.size(); ++i) {
            cout << i + 1 << ". " << daftar_sepatu[i].nama << " - Harga: Rp " << daftar_sepatu[i].harga << endl;
        }

        // Meminta input dari user untuk memilih sepatu
        int pilihan;
        cout << "\nPilih sepatu berdasarkan nomor (1-" << daftar_sepatu.size() << "): ";
        cin >> pilihan;

        // Validasi input
        if (cin.fail() || pilihan < 1 || pilihan > daftar_sepatu.size()) {
            cin.clear(); // Menghapus flag error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
            cout << "Pilihan tidak valid. Coba lagi.\n";
            continue; // Kembali ke awal loop
        }

        // Pastikan buffer bersih
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        const Sepatu& sepatu_terpilih = daftar_sepatu[pilihan - 1];
        cout << "\nAnda memilih sepatu: " << sepatu_terpilih.nama << endl;

        // Menampilkan ukuran yang tersedia
        cout << "Ukuran yang tersedia: ";
        for (int u : sepatu_terpilih.ukuran) {
            cout << u << " ";
        }
        cout << "\n";

        // Meminta input ukuran
        int ukuran_pilihan;
        cout << "\nMasukkan ukuran yang Anda inginkan: ";
        cin >> ukuran_pilihan;

        // Validasi ukuran
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input ukuran tidak valid. Coba lagi.\n";
            continue; // Kembali ke awal loop
        }

        bool ukuran_valid = false;
        for (int u : sepatu_terpilih.ukuran) {
            if (u == ukuran_pilihan) {
                ukuran_valid = true;
                break;
            }
        }

        if (!ukuran_valid) {
            cout << "Ukuran tidak tersedia. Coba lagi.\n";
            continue; // Kembali ke awal loop
        }

        // Simpan pembelian ke daftar
        daftar_pembelian.push_back({sepatu_terpilih.nama, ukuran_pilihan, sepatu_terpilih.harga});

        // Tampilkan daftar pembelian saat ini
        tampilkanPembelian(daftar_pembelian);

        // opsi untuk menghapus sepatu dari keranjang atau melanjutkan pembelian
        cout << "\nApakah Anda ingin menghapus sepatu dari keranjang? (y/n): ";
        char opsi_hapus;
        cin >> opsi_hapus;
        if (opsi_hapus == 'y' || opsi_hapus == 'Y') {
            hapusPembelian(daftar_pembelian);
        }

        cout << "\nIngin membeli sepatu lagi? (y/n): ";
        cin >> lanjut;

        // Pastikan buffer bersih
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (lanjut == 'y' || lanjut == 'Y');

    // Menampilkan skema pembayaran
    cout << "\n--- Skema Pembayaran ---\n";
    int total_harga = 0;
    for (const auto& pembelian : daftar_pembelian) {
        cout << "Sepatu: " << pembelian.nama_sepatu
             << " | Ukuran: " << pembelian.ukuran
             << " | Harga: Rp " << pembelian.harga << endl;
        total_harga += pembelian.harga;
    }

    // Perhitungan diskon
    double diskon = 0.0;
    if (total_harga > 20000) {
        diskon = total_harga * 0.2; // 20% diskon
        cout << "Anda mendapatkan diskon 20%: Rp " << static_cast<int>(diskon) << endl;
    }

    int total_setelah_diskon = total_harga - static_cast<int>(diskon);
    cout << "Total yang harus dibayar: Rp " << total_setelah_diskon << "\n";

    // Meminta input nama pembeli
    string nama_pembeli;
    cout << "Masukkan nama Anda sebagai bukti pembayaran: ";
    getline(cin, nama_pembeli);

    // Meminta input uang pembayaran
    int uang_pembayaran;
    do {
        cout << "\nMasukkan jumlah uang pembayaran: ";
        cin >> uang_pembayaran;

        // Validasi uang pembayaran
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Coba lagi.\n";
            continue; // Kembali ke awal loop
        }

        if (uang_pembayaran < total_setelah_diskon) {
            int sisa_bayar = total_setelah_diskon - uang_pembayaran;
            cout << "Uang yang diberikan tidak mencukupi. Anda masih perlu membayar: Rp " 
                 << sisa_bayar << endl;

            // Meminta sisa uang yang harus dibayar
            int sisa_uang;
            cout << "Masukkan sisa uang yang harus dibayar: ";
            cin >> sisa_uang;

            // Validasi sisa uang
            if (cin.fail() || sisa_uang < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Coba lagi.\n";
                continue; // Kembali ke awal loop
            }

            uang_pembayaran += sisa_uang; // Tambahkan sisa uang ke total uang yang dibayarkan

            // Jika setelah menambahkan sisa uang, total sudah mencukupi
            if (uang_pembayaran >= total_setelah_diskon) {
                // Hitung kembalian
                int kembalian = uang_pembayaran - total_setelah_diskon;
                cout << "Kembalian Anda: Rp " << kembalian << "\n";
                break; // Keluar dari loop jika pembayaran cukup
            } else {
                cout << "Uang yang diberikan masih tidak mencukupi. Coba lagi.\n";
            }
        } else {
            // Hitung kembalian
            int kembalian = uang_pembayaran - total_setelah_diskon;
            cout << "Kembalian Anda: Rp " << kembalian << "\n";
            break; // Keluar dari loop jika pembayaran cukup
        }
    } while (true);

    // Menampilkan bukti pembayaran
    cout << "\n--- Bukti Pembayaran ---\n";
    cout << "Kasir: " << nama_kasir << endl;
    cout << "Pembeli: " << nama_pembeli << endl;

    cout << "\n--- Rincian Pembelian ---\n";
    for (const auto& pembelian : daftar_pembelian) {
        cout << "Sepatu: " << pembelian.nama_sepatu
             << " | Ukuran: " << pembelian.ukuran
             << " | Harga: Rp " << pembelian.harga << endl;
    }
    cout << "Total Harga: Rp " << total_setelah_diskon << endl;
    cout << "Kembalian: Rp " << (uang_pembayaran - total_setelah_diskon) << endl;
    cout << "\nTerima kasih atas kunjungan Anda!" << endl;
    cout << "Salam, semoga hari Anda menyenangkan!" << endl;
	cin.get();
    cin.get();
    return 0;
}
