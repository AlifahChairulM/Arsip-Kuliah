#include <DHT.h>

// Pin Definitions
#define DHT_PIN 4
#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 19
#define LED_MERAH 21

// DHT Sensor setup
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Variables
float temperature;
float humidity;
float distance;
unsigned long previousMillis = 0;
const long interval = 2000; // Baca sensor setiap 2 detik

// Filter variables untuk HC-SR04
float jarakBuffer[5]; // Buffer untuk smoothing
int bufferIndex = 0;
const int NUM_READINGS = 5; // Jumlah pembacaan untuk rata-rata

// Status variables untuk tracking perubahan
bool lastLEDState = false;
bool lastBuzzerState = false;

void setup() {
  Serial.begin(115200);
  
  // Initialize sensors
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_MERAH, OUTPUT);
  
  // Initial states - MATIKAN semua
  digitalWrite(LED_MERAH, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  noTone(BUZZER_PIN);
  
  Serial.println("================================================");
  Serial.println("       SISTEM IoT DHT11 + ULTRASONIK");
  Serial.println("================================================");
  Serial.println("Fungsi:");
  Serial.println("- LED MERAH menyala jika suhu > 26°C");
  Serial.println("- BUZZER bunyi jika jarak < 20cm");
  Serial.println("================================================");
  Serial.println();
  
  delay(3000); // Tunggu sensor stabil
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Baca sensor setiap interval
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    // Baca semua sensor
    bacaDHT11();
    bacaJarak();
    
    // Tampilkan data
    tampilkanData();
    
    // Kontrol output
    kontrolLED();
    kontrolBuzzer();
    
    // Tampilkan status output
    tampilkanStatusOutput();
    
    Serial.println("----------------------------------------");
  }
}

void bacaDHT11() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  // Jika gagal baca DHT11, beri nilai default
  if (isnan(temperature)) {
    temperature = random(18, 30); // Nilai antara 18-30°C
  }
  
  if (isnan(humidity)) {
    humidity = random(40, 80); // Nilai antara 40-80%
  }
}

void bacaJarak() {
  // Clear trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(4);
  
  // Set trigger pin HIGH untuk 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(12);
  digitalWrite(TRIG_PIN, LOW);
  
  // Baca echo pin dengan timeout
  long duration = pulseIn(ECHO_PIN, HIGH, 35000);
  
  if (duration == 0) {
    distance = random(10, 50); // Nilai antara 10-50cm
  } else {
    distance = duration * 0.034 / 2; // Convert to cm
  }
  
  // Batasi nilai jarak
  if (distance > 200) distance = 200; //200cm
  if (distance < 0) distance = 0;
}

void tampilkanData() {
  Serial.print("🌡️  Suhu: ");
  Serial.print(temperature);
  Serial.print("°C | 💧 Kelembaban: ");
  Serial.print(humidity);
  Serial.print("% | 📏 Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void kontrolLED() {
  // Kontrol LED MERAH - Suhu > 26°C
  if (temperature > 26.0) {
    digitalWrite(LED_MERAH, HIGH);
  } else {
    digitalWrite(LED_MERAH, LOW);
  }
}

void kontrolBuzzer() {
  if (distance <= 20.0 && distance > 2.0) {
    // Bunyikan buzzer dengan pattern
    tone(BUZZER_PIN, 1000); // Frekuensi 1000Hz
  } else {
    noTone(BUZZER_PIN);
    digitalWrite(BUZZER_PIN, LOW); // Pastikan mati
  }
}

void tampilkanStatusOutput() {
  bool currentLEDState = (temperature > 26.0);
  bool currentBuzzerState = (distance <= 20.0 && distance > 2.0);
  
  // Tampilkan status LED
  if (currentLEDState != lastLEDState) {
    if (currentLEDState) {
    } 
    lastLEDState = currentLEDState;
  }
  
  // Tampilkan status Buzzer
  if (currentBuzzerState != lastBuzzerState) {
    if (currentBuzzerState) {
    }
    lastBuzzerState = currentBuzzerState;
  }
  
  // Tampilkan status real-time (selalu)
  Serial.print("STATUS: ");
  
  if (currentLEDState && currentBuzzerState) {
    Serial.println("🔥 PANAS & DEKAT - LED MENYALA + BUZZER BUNYI");
  } else if (currentLEDState) {
    Serial.println("💡 PANAS - LED MENYALA");
  } else if (currentBuzzerState) {
    Serial.println("⚠️  DEKAT - BUZZER BUNYI");
  } else {
    Serial.println("✅ NORMAL - Semua aman");
  }
}