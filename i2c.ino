#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Definisikan pin SDA dan SCL yang akan digunakan
#define SDA_PIN 25
#define SCL_PIN 26

// Atur alamat I2C dan ukuran layar (16x2 atau 20x4)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  // Inisialisasi komunikasi I2C dengan pin yang ditentukan
  Wire.begin(SDA_PIN, SCL_PIN);
  
  // Inisialisasi LCD
  lcd.init();
  
  // Hidupkan lampu latar LCD
  lcd.backlight();
  
  // Cetak teks ke layar
  lcd.setCursor(0, 0); // Kolom 0, Baris 0
  lcd.print("BANGGA POLINES!");
  
  lcd.setCursor(0, 1); // Kolom 0, Baris 1
  lcd.print("TE 3E OKE!");
}

void loop() {
  // Tidak ada yang perlu dilakukan di loop, layar sudah menampilkan teks
  // Jika Anda ingin menampilkan data yang berubah-ubah (misalnya sensor),
  // Anda bisa menempatkan kode di sini.
}