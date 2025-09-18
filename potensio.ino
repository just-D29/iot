// Menentukan pin GPIO yang terhubung ke kaki tengah potensiometer
const int potPin = 34;

// Variabel untuk menyimpan nilai yang dibaca dari potensiometer
int potValue = 0;

void setup() {
  // Memulai komunikasi serial pada baud rate 115200 untuk menampilkan hasil
  Serial.begin(115200);
  
  // Menunggu sejenak agar Serial Monitor siap
  delay(1000); 
}

void loop() {
  // Membaca nilai analog dari pin potensiometer
  potValue = analogRead(potPin);
  
  // Mencetak nilai yang dibaca ke Serial Monitor
  Serial.print("Nilai Potensiometer: ");
  Serial.println(potValue);
  
  // Memberi jeda 500 milidetik sebelum pembacaan berikutnya
  delay(500); 
}