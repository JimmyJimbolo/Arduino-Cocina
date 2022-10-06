/* DOMOTICA: HA_Cocina

 SENSORES: Clima, MQ's
 MQTT (arduino/cocina/...)
 OTA

 b1.0 Se parte del codigo de Salita
 b1.1 Modificaciones para cocina
 b1.2 Se crea la funcion leer()
 b1.3 Se activa Wifi, OTA y MQTT
 v2.0 Sensores MQ operativos en HA
 v2.1 Envio de lectura en el arranque
      Suscripcion a canal MQTT "arduino/#" para recibir ordenes
 v2.2 Solo se envia los datos de los MQ si han cambiado
 (C) Jimmy 2022
 -------------------------
*/

#include <ESP8266WiFi.h>
#include <DHT.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
WiFiClient Wclient;
PubSubClient MQTTClient(Wclient);

int enviar = 1;

// MQTT
String ip;

// CLIMA
int pinClima = 13;  // D7 CLIMA
DHT dht(pinClima, DHT11);
float temp;
float temp_anterior = 0;
float hume;
float hume_anterior = 0;
int clima_lectura = 0;

// MQ's
int pinMPXS1 = 5; // D1
int pinMPXS2 = 4; // D2
float MQ2 = 0;
float MQ2_a = 0;
float MQ7 = 0;
float MQ7_a = 0;
float MQ135 = 0;
float MQ135_a = 0;
String S_MQ = "";
int MQ_tiempo = 0;
