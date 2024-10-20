# AutoGate-Blynk

**Nama Proyek:** AutoGate-Blynk  
**Dibuat oleh:** Kelompok 2 IoT - IF-VA

## Anggota Kelompok:

1. RIFAN WAROSY SIROJUDIN (220660121033)
2. ALIP RIZKY FIRDAUS (220660121078)
3. M ARIF FIRMANSYAH (220660121013)
4. NAUFAL SIDDIQ RAMADHAN (NAUFAL SIDDIQ RAMADHAN)
5. RIVAL FAKHRI AMRULLAH (220660121134)

Proyek ini adalah implementasi pintu otomatis yang menggunakan sensor ultrasonik dan servo, yang terintegrasi dengan **Blynk Cloud** untuk kontrol jarak jauh. Saat objek terdeteksi dalam jarak tertentu, servo akan menggerakkan pintu. Pengguna juga dapat mengontrol pintu melalui aplikasi Blynk.

## Fitur

- **Deteksi Objek:** Menggunakan sensor ultrasonik untuk mendeteksi objek dalam jarak tertentu.
- **Kontrol Servo:** Servo akan membuka atau menutup pintu berdasarkan deteksi objek.
- **Integrasi Blynk:** Kontrol pintu dapat dilakukan secara jarak jauh melalui aplikasi Blynk.

## Komponen yang Dibutuhkan

1. **NodeMCU ESP8266** atau modul Wi-Fi serupa.
2. **Servo Motor**.
3. **Sensor Ultrasonik** (HC-SR04).
4. **Kabel jumper** dan breadboard.
5. **Aplikasi Blynk** (iOS/Android).

## Cara Kerja

- **Sensor Ultrasonik** mendeteksi jarak objek.
- Jika jarak kurang dari 10 cm, **servo** akan bergerak untuk membuka pintu.
- Jika objek tidak terdeteksi dalam waktu 3 detik, servo akan menutup pintu.
- **Aplikasi Blynk** dapat digunakan untuk mengontrol pintu secara manual dari jarak jauh.
