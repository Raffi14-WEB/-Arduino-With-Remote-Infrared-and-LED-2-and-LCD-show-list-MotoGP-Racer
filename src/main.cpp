#include <Arduino.h>

#include <Arduino.h>
#include <IRremote.hpp>
#include <LiquidCrystal_I2C.h>

// --- Konfigurasi Pin ---
const int RECV_PIN = 2; 

// --- Nilai command tombol remote (Wokwi Standard) ---
#define CMD_NEXT 0x30     // Tombol "1" untuk Maju
#define CMD_PREVIOUS 0x18 // Tombol "2" untuk Mundur

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- Data Pembalap MotoGP ---
const int jumlahPembalap = 5;
int indexSekarang = -1; // -1 berarti belum ada tombol yang ditekan

String tim[] = {
  "Ducati Lenovo", 
  "Repsol Honda", 
  "Monster Yamaha", 
  "Red Bull KTM", 
  "Aprilia Racing"
};

String pembalap[] = {
  "F. Bagnaia", 
  "Marc Marquez", 
  "F. Quartararo", 
  "Brad Binder", 
  "Aleix Espargaro"
};

void updateDisplay(int idx) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(tim[idx]);
  lcd.setCursor(0, 1);
  lcd.print(pembalap[idx]);
}

void setup() {
  Serial.begin(9600);
  
  // Inisialisasi IR Receiver
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pilih Driver:");
  lcd.setCursor(0, 1);
  lcd.print("1:Next 2:Prev");
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.print("Command diterima: ");
    Serial.println(command, HEX);

    // Logika Tombol 1 (Next)
    if (command == CMD_NEXT) {
      indexSekarang++;
      if (indexSekarang >= jumlahPembalap) {
        indexSekarang = 0; // Kembali ke awal jika sudah di akhir
      }
      updateDisplay(indexSekarang);
    }

    // Logika Tombol 2 (Previous)
    else if (command == CMD_PREVIOUS) {
      indexSekarang--;
      if (indexSekarang < 0) {
        indexSekarang = jumlahPembalap - 1; // Kembali ke akhir jika sudah di awal
      }
      updateDisplay(indexSekarang);
    }

    IrReceiver.resume(); 
  }
}