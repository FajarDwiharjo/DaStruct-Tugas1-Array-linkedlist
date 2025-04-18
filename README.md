# 📚 Manajemen Rilisan Komik (C++)

Program terminal sederhana untuk mengelola rilisan komik menggunakan **Linked List** di C++.  
Cocok untuk tugas kuliah atau latihan struktur data. Data disimpan secara otomatis ke file `.txt`.

---

## ✨ Fitur

- ✅ Tambah rilisan komik (judul, volume, tanggal rilis)
- ✅ Tampilkan semua rilisan
- ✅ Cari rilisan berdasarkan judul atau volume
- ✅ Hapus rilisan berdasarkan judul
- ✅ Simpan & muat data dari file `komik.txt`
- ✅ Urutkan rilisan berdasarkan:
  - 📅 Tanggal rilis (lama ke baru)

---

## 🗃️ Struktur Folder

(Struktur folder bisa seperti ini:)

komik-manager/  
├── main.cpp          // Program utama  
├── komik.txt         // File penyimpanan data rilisan  
└── README.md         // Dokumentasi program  

---

## 🧑‍💻 Cara Menjalankan Program

### 💻 Di Windows (Command Prompt / PowerShell)

```bash
# 1. Pindah ke folder proyek
cd path\to\komik-manager

# 2. Kompilasi program
g++ main.cpp -o komik

# 3. Jalankan program
.\komik
```

### 🐧 Di Linux / WSL (Ubuntu)
```bash
# 1. Pindah ke direktori proyek
cd /mnt/c/Users/nama-kamu/path/to/komik-manager

# 2. Kompilasi program
g++ main.cpp -o komik

# 3. Jalankan program
./komik

## ⚠️ Pastikan g++ sudah terinstall. Jika belum, install dengan: sudo apt update && sudo apt install g++
```
## 💾 Catatan Penyimpanan

- Program membaca `komik.txt` secara otomatis saat dijalankan.
- Data akan disimpan otomatis saat keluar (menu `0`), atau manual lewat menu `5`.

---

## 🧪 Contoh Isi File `komik.txt`
```bash
Jujutsu Kaisen;1;01-01-2023 
Jujutsu Kaisen;2;01-02-2023 
One Piece;105;10-03-2024 
Chainsaw Man;14;15-04-2024

Format:  
**Judul;Volume;TanggalRilis**
```
---

## 🔧 Kompilator yang Direkomendasikan
```bash
- GCC (g++) – Linux / WSL
- MinGW – Windows
- VSCode + C++ Extension
```
---
