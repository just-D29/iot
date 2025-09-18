#include "DHT.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Arduino.h"

#define DHTTYPE DHT11   
#define DHTPIN 27  

TaskHandle_t dhtTaskHandle = NULL;

DHT dht(DHTPIN, DHTTYPE);

void dht_task(void *pvParameters) {
    while(1) {
      float kelembapan = dht.readHumidity();
      float suhu = dht.readTemperature();

        
      Serial.print("Kelembaban: ");
      Serial.print(kelembapan);
      Serial.print(" %  |  Suhu: ");
      Serial.print(suhu);
      Serial.println(" °C");
      

    vTaskDelay(pdMS_TO_TICKS(2000)); 

    }
}


void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Suhu dan Kelembapan");

  

  xTaskCreate(dht_task, "dht_task", 2048, NULL, 1, NULL);
  dht.begin();
}

void loop() {
  vTaskDelay(pdMS_TO_TICKS(1000));
}