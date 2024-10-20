#include <Servo.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "-joxYmkPWfqwL45-QYFWIACxi7x6P7_F";  // Ganti dengan Auth Token dari aplikasi Blynk
char ssid[] = "2chan";        // Ganti dengan SSID Wi-Fi kamu
char pass[] = "12345677";     // Ganti dengan password Wi-Fi kamu

#define pinecho1 D1
#define pintriger1 D2
Servo myservo;

bool blynkControl = false;  // Untuk menyimpan status kontrol dari Blynk
bool objectDetected = false;  // Menyimpan status deteksi objek
unsigned long lastDetectionTime = 0;  // Waktu terakhir objek tidak terdeteksi

float read_srf(int pintriger, int pinecho) {
  long durasi;
  digitalWrite(pintriger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintriger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintriger, LOW);
  delayMicroseconds(2);
  durasi = pulseIn(pinecho, HIGH);
  return durasi / 58.2;  // Tidak perlu deklarasi ulang variabel jarak
}

void setup() {
  // Setup Blynk
  Blynk.begin(auth, ssid, pass);

  // Setup sensor ultrasonik dan servo
  Serial.begin(9600);
  pinMode(pintriger1, OUTPUT);
  pinMode(pinecho1, INPUT);

  myservo.attach(D4);
  myservo.write(0);  // Servo awal pada posisi 0 derajat

  Serial.println("Sistem Siap");
}

// Fungsi untuk mengontrol servo dari Blynk
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();  // Nilai dari widget switch Blynk (0-1)
  
  if (pinValue == 1) {
    blynkControl = true;         // Aktifkan kontrol Blynk
    myservo.write(180);          // Servo bergerak 180 derajat
  } else {
    blynkControl = false;        // Matikan kontrol Blynk
    myservo.write(0);            // Servo kembali ke posisi 0 derajat
  }
}

void loop() {
  Blynk.run();  // Jalankan Blynk

  // Jika kontrol Blynk tidak aktif, kontrol dengan sensor ultrasonik
  if (!blynkControl) {
    float jarak = read_srf(pintriger1, pinecho1);

    // Tampilkan jarak pada Serial Monitor
    Serial.print("Jarak: ");
    Serial.println(jarak);

    // Jika jarak kurang dari 10 cm, servo tetap di posisi 180 derajat
    if (jarak < 10) {
      myservo.write(180);        // Servo bergerak 180 derajat
      objectDetected = true;     // Tandai bahwa objek terdeteksi
    } else {
      if (objectDetected) {
        // Jika objek baru saja tidak terdeteksi, mulai hitung mundur 3 detik
        lastDetectionTime = millis();
        objectDetected = false;  // Objek tidak terdeteksi lagi
      }
      
      // Tunggu selama 3 detik setelah objek tidak terdeteksi sebelum servo turun
      if (millis() - lastDetectionTime > 3000) {
        myservo.write(0);  // Servo kembali ke posisi 0 derajat setelah 3 detik
      }
    }
  }

  delay(500);  // Penundaan untuk pembacaan sensor
}