#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Komik {
    string judul;
    int volume;
    string tanggalRilis;
    Komik* next;
};

Komik* head = nullptr;

struct KomikData {
    string judul;
    int volume;
    string tanggalRilis;
};

void tambahKomik(string judul, int volume, string tanggal) {
    Komik* baru = new Komik{judul, volume, tanggal, nullptr};

    if (!head) {
        head = baru;
    } else {
        Komik* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}

void inputKomik() {
    string judul, tanggal;
    int volume;

    cout << "Judul Komik: ";
    cin.ignore();
    getline(cin, judul);
    cout << "Volume: ";
    cin >> volume;
    cout << "Tanggal Rilis (dd-mm-yyyy): ";
    cin.ignore();
    getline(cin, tanggal);

    tambahKomik(judul, volume, tanggal);
    cout << "Komik berhasil ditambahkan!\n";
}

void tampilkanKomik() {
    if (!head) {
        cout << "Belum ada rilisan.\n";
        return;
    }

    Komik* temp = head;
    int i = 1;
    cout << "\nDaftar Rilisan Komik:\n";
    while (temp) {
        cout << i++ << ". " << temp->judul
             << " Vol. " << temp->volume
             << " - " << temp->tanggalRilis << endl;
        temp = temp->next;
    }
}

void cariKomik() {
    string keyword;
    cout << "Masukkan judul atau volume yang dicari: ";
    cin.ignore();
    getline(cin, keyword);

    Komik* temp = head;
    bool ditemukan = false;

    while (temp) {
        if (temp->judul.find(keyword) != string::npos ||
            to_string(temp->volume) == keyword) {
            cout << "Ditemukan: " << temp->judul << " Vol. "
                 << temp->volume << " - " << temp->tanggalRilis << endl;
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "Komik tidak ditemukan.\n";
    }
}

void hapusKomik() {
    string target;
    cout << "Masukkan judul komik yang ingin dihapus: ";
    cin.ignore();
    getline(cin, target);

    Komik* temp = head;
    Komik* prev = nullptr;

    while (temp) {
        if (temp->judul == target) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
            cout << "Komik berhasil dihapus.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Komik tidak ditemukan.\n";
}

void simpanKeFile(const string& namaFile) {
    ofstream file(namaFile);
    Komik* temp = head;

    while (temp) {
        file << temp->judul << ";" << temp->volume << ";" << temp->tanggalRilis << endl;
        temp = temp->next;
    }
    file.close();
    cout << "Data berhasil disimpan ke file.\n";
}

void muatDariFile(const string& namaFile) {
    ifstream file(namaFile);
    if (!file) {
        cout << "File tidak ditemukan, mulai dari data kosong.\n";
        return;
    }

    string baris;
    while (getline(file, baris)) {
        stringstream ss(baris);
        string judul, volumeStr, tanggal;
        getline(ss, judul, ';');
        getline(ss, volumeStr, ';');
        getline(ss, tanggal, ';');
        tambahKomik(judul, stoi(volumeStr), tanggal);
    }

    file.close();
    cout << "Data berhasil dimuat dari file.\n";
}

void hapusSemua() {
    while (head) {
        Komik* temp = head;
        head = head->next;
        delete temp;
    }
}

vector<KomikData> linkedListToVector() {
    vector<KomikData> data;
    Komik* temp = head;
    while (temp) {
        data.push_back({temp->judul, temp->volume, temp->tanggalRilis});
        temp = temp->next;
    }
    return data;
}

void urutTanggalRilis(Komik* head) {
    if (!head) {
        cout << "Belum ada rilisan.\n";
        return;
    }
    vector<KomikData> data = linkedListToVector();

    sort(data.begin(), data.end(), [](const KomikData& a, const KomikData& b) {
        return a.tanggalRilis < b.tanggalRilis;
    });

    cout << "\nUrutan Komik Berdasarkan Tanggal Rilis:\n";
    for (int i = 0; i < data.size(); ++i) {
        cout << i + 1 << ". " << data[i].judul << " Vol. " << data[i].volume
             << " - " << data[i].tanggalRilis << endl;
    }
}

int main() {
    muatDariFile("komik.txt");

    int pilihan;
    do {
        cout << "\n===== Sistem Manajemen Rilisan Komik =====\n";
        cout << "1. Tambah Komik\n";
        cout << "2. Tampilkan Semua\n";
        cout << "3. Cari Komik\n";
        cout << "4. Hapus Komik\n";
        cout << "5. Simpan ke File\n";
        cout << "6. Urutkan Berdasarkan Tanggal Rilis\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: inputKomik(); break;
            case 2: tampilkanKomik(); break;
            case 3: cariKomik(); break;
            case 4: hapusKomik(); break;
            case 5: simpanKeFile("komik.txt"); break;
            case 6: urutTanggalRilis(head); break;
            case 0:
                simpanKeFile("komik.txt");
                hapusSemua();
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
