# Arduino MotoGP Racer Display

Proyek ini adalah sistem Arduino yang menggunakan remote infrared untuk menampilkan daftar pembalap MotoGP pada LCD I2C. Sistem ini memungkinkan navigasi maju dan mundur melalui daftar pembalap menggunakan tombol remote.

## Fitur

- Menampilkan daftar 5 pembalap MotoGP beserta timnya
- Navigasi menggunakan remote infrared (tombol 1 untuk next, tombol 2 untuk previous)
- Tampilan pada LCD 16x2 I2C
- Simulasi di Wokwi

## Persyaratan Hardware

- Arduino Uno
- IR Receiver (terhubung ke pin 2)
- LCD I2C 16x2 (alamat 0x27)
- Remote infrared standar (sesuai dengan kode Wokwi)

## Instalasi

1. Pastikan PlatformIO terinstal di sistem Anda.
2. Clone atau download proyek ini.
3. Buka proyek di PlatformIO.
4. Install dependencies dengan menjalankan `pio lib install` atau melalui PlatformIO IDE.

## Penggunaan

1. Upload kode ke Arduino Uno menggunakan PlatformIO.
2. Hubungkan hardware sesuai pin yang dikonfigurasi.
3. Nyalakan sistem. LCD akan menampilkan instruksi awal.
4. Gunakan tombol 1 pada remote untuk maju ke pembalap berikutnya.
5. Gunakan tombol 2 pada remote untuk mundur ke pembalap sebelumnya.

## Troubleshooting

- Jika LCD tidak menampilkan apa-apa, periksa koneksi I2C dan alamat LCD (0x27).
- Jika remote tidak merespons, pastikan IR Receiver terhubung dengan benar ke pin 2 dan remote kompatibel.
- Periksa Serial Monitor untuk log command yang diterima.

## Simulasi

Proyek ini dapat disimulasikan di Wokwi menggunakan file `wokwi.toml` dan `diagram.json`.