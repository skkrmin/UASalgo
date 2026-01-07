#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Siswa {
    string nama;
    int id;
    float tugas, uts, uas, nilaiAkhir;
    char grade;
};

void hitungNilai(Siswa &s) {
    s.nilaiAkhir = (0.4 *s.tugas) + (0.3 * s.uts) + (0.3 * s.uas);
    if (s.nilaiAkhir >= 90) s.grade = 'A';
    else if (s.nilaiAkhir >= 80) s.grade = 'B';
    else if (s.nilaiAkhir >= 70) s.grade = 'C';
    else if (s.nilaiAkhir >= 60) s.grade = 'D';
    else s.grade = 'E';
}

void tambahSiswa(vector<Siswa> &data) {
    Siswa s;
    cout << "\nID siswa: ";
    cin >> s.id;
    cout << "Nama siswa: ";
    cin.ignore();
    getline(cin, s.nama);
    cout << "Nilai tugas: ";
    cin >> s.tugas;
    cout << "Nilai UTS: ";
    cin >> s.uts;
    cout << "Nilai UAS: ";
    cin >> s.uas;

    hitungNilai(s);
    data.push_back(s);
    cout << "Data siswa berhasil ditambahkan.\n";
}

void tampilSiswa(const vector<Siswa> &data) {
    if (data.empty()) {
        cout << "\nData siswa kosong.";
        return;
    }

    cout << "\n=== Data nilai siswa ===\n";
    cout << left << setw(16) << "ID"
         << left << setw(24) << "Nama"
         << left << setw(8) << "Tugas"
         << left << setw(8) << "UTS"
         << left << setw(8) << "UAS"
         << left << setw(8) << "Akhir"
         << left << setw(10) << "Grade" << endl;
    
    for (const auto &s : data) {
        cout << left << setw(16) << s.id
             << left << setw(24) << s.nama
             << left << setw(8) << s.tugas
             << left << setw(8) << s.uts
             << left << setw(8) << s.uas
             << left << setw(8) << fixed << setprecision(2) s.nilaiAkhir
             << left << setw(10) << s.grade << endl;
    }
}

void ubahSiswa(vector <Siswa> &data) {
    int id;
    cout << "Masukkan Id siswa yang ingin diubah: ";
    cin >> id;

    for(auto &s : data) {
        if(s.id == id) {
        cout << "Nilai tugas baru: ";
        cin >> s.tugas;
        cout << "Nilai UTS baru: ";
        cin >> s.uts;
        cout << "Nilai UAS baru: ";
        cin >> s.uas;
        hitungNilai(s);
        cout << "Data siswa berhasil diubah.\n";
        }
    }
} 

void hapusSiswa(vector <Siswa> &data) {
    int id;
    cout << "Masukkan id siswa yang akan dihapus: ";
    cin >> id;
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i].id == id) {
            data.erase(data.begin() + i);
            cout << "Data siswa berhasil dihapus.\n";
            return;
        }
    }
}

int main() {
    vector<Siswa> Data; 
    int pilihan;

    do {
        cout << "\n=== Menu Manajemen Nilai Siswa ===\n";
        cout << "1. Tambah data siswa\n";
        cout << "2. Tampilkan data siswa\n";
        cout << "3. Ubah data siswa\n";
        cout << "4. Hapus data siswa\n";
        cout << "0. keluar\n";
        cout << "Masukkan Pilihan\n";
        cin >> pilihan;

    switch (pilihan) {
        case 1:
            tambahSiswa(Data);
            break;
        case 2:
            tampilSiswa(Data);
            break;
        case 3:
            ubahSiswa(Data);
            break;
        case 4:
            hapusSiswa(Data);
            break;
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
    }

    } while (pilihan != 0);
    return 0;
}