# Emergency dan Panic Button Multi Device Menggunakan MQTT

![Nusabot Logo](https://nusabot.id/images/logo/logo-login.svg)

## Deskripsi Proyek

Proyek ini merupakan bagian dari kelas Nusabot yang bertujuan untuk membuat sistem Emergency dan Panic Button yang dapat digunakan oleh banyak perangkat dan di berbagai lokasi yang berbeda menggunakan protokol MQTT. Dengan proyek ini, pengguna dapat membuat sebanyak mungkin tombol darurat (panic button) dan sebanyak mungkin alarm di lokasi yang berbeda, dan semuanya terhubung melalui jaringan menggunakan MQTT.

## Fitur

- Membuat tombol darurat di berbagai lokasi
- Membuat alarm di berbagai lokasi
- Menggunakan protokol MQTT untuk koneksi antar perangkat
- Mendukung koneksi multi-device

## Cara Kerja

1. Setiap tombol darurat akan terhubung ke perangkat mikrokontroler yang memiliki koneksi internet.
2. Mikrokontroler akan mengirimkan pesan melalui protokol MQTT ke server MQTT setiap kali tombol darurat ditekan.
3. Server MQTT akan meneruskan pesan ke semua perangkat yang berlangganan topik yang sesuai.
4. Perangkat yang menerima pesan akan memicu alarm darurat.

## Instalasi dan Penggunaan

1. Clone repositori ini ke perangkat lokal Anda.
2. Konfigurasikan setiap mikrokontroler untuk terhubung ke server MQTT yang sama.
3. Sesuaikan kode di setiap mikrokontroler sesuai dengan spesifikasi dan kebutuhan Anda.
4. Jalankan proyek di setiap perangkat dan pastikan semua perangkat terhubung ke jaringan yang sama.
5. Tekan tombol darurat untuk memicu alarm.

## Kontribusi

Kami mengundang kontribusi dari komunitas. Jika Anda memiliki saran, perbaikan, atau peningkatan, silakan buka *issue* baru atau kirimkan *pull request*.

## Lisensi

Proyek ini dilisensikan di bawah [GPL V3 License](LICENSE).
