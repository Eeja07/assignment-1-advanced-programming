# Laporan Programming Assignment 1: Basic C++

## Tugas Utama

Pada programming assignment 1 ini Anda diminta untuk menyelesaikan program yang diperuntukan untuk menghitung umur seseorang dalam tahun dan bulan serta hari dalam minggu untuk tanggal tersebut. Dalam penyelesaiannya Anda akan diberikan templete C++ yang tersedia dan Anda diminta untuk mengubah 3 fungsi utama yang digunakan untuk menghitung umur dalam tahun, umur dalam bulan, dan hari pada tanggal tersebut.

Jawab :

Source code :

![Screen Shot 2023-03-05 at 01 10 50](https://user-images.githubusercontent.com/115524218/222924196-38b52d58-8927-4277-b57b-779dbe28066a.png)
![Screen Shot 2023-03-05 at 01 11 22](https://user-images.githubusercontent.com/115524218/222924191-20a0b0c2-39bc-4e86-827c-3ca372779d27.png)

Dengan Hasil Output :

![Screen Shot 2023-03-04 at 16 31 28](https://user-images.githubusercontent.com/115524218/222924209-0d9ed449-8e2f-4cc3-9609-550d709dc820.png)

Penjelasan :

3 Fungsi yang diminta untuk diubah merupakan 3 fungsi utama yaitu fungsi yearsOld(tm* inputTgl, tm* currentTgl), monthsOld(tm* inputTgl, tm* currentTgl), dan dayOfDate(tm\* inputTgl).

A. Pada fungsi yearsOld() yang memiliki 2 parameter ini berfungsi untuk menghitung umur dalam tahun

1. Pada line 76 merupakan cara menghitungnya yaitu mengurangi tahun sekarang dengan tahun dari tanggal lahir yang diinput.
2. Pada line 77-81 merupakan syaratnya yaitu jika Jika bulan sekarang lebih kecil dari bulan lahir, atau bulan lahir sama dengan bulan sekarang tetapi tanggal sekarang lebih kecil dari tanggal lahir, maka usia dikurangi 1. Hal ini karena seseorang belum bertambah usianya sampai hari ulang tahun mereka tiba.

B. Pada fungsi monthsOld() yang memiliki 2 parameter ini berfungsi untuk menghitung umur dalam bulan

1. Pada line 88 merupakan cara menghitungnya yaitu mengurangi tahun sekarang dengan tahun dari tanggal lahir yang diinput kemudian dikali 12. Setelah itu ditambah dengan hasil dari bulan sekarang dikurang bulan dari tanggal lahir yang diinput.
2. Pada line 89-92 merupakan syaratnya yaitu Jika tanggal lahir sekarang lebih kecil dari tanggal lahir yang diinput , maka usia dikurangi 1. Hal ini karena seseorang belum bertambah bulan umurnya sampai hari ulang tahun mereka tiba.

C. Pada fungsi dayOfDate() yang memiliki 1 parameter ini berfungsi untuk mengetahui nama hari dari tanggal lahir yang kita input

1. Pada line 99 merupakan deklarasi array dari string dayNames yang berisi nama-nama hari, dimulai dari minggu karena mengacu pada tm_wday.
2. Pada line 100 mktime berfungsi untuk mengonversi tanggal yang diinputkan dalam struktur 'tm' menjadi nilai waktu dalam format 'time_t'.
3. Pada line 101 tm_wday merupakan anggota struktur tm yang menyimpan hari dalam seminggu dalam format angka, mulai dari 0 (Minggu) hingga 6 (Sabtu). Nilai tm_wday pada struktur tm diakses untuk mendapatkan indeks hari dalam seminggu. Kemudian nilai indeks ini digunakan untuk mengakses elemen yang sesuai dari array dayNames dan mengembalikan nama hari.
