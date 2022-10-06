void setup() {
  Serial.begin(115200);

  // OTA
  InitOTA();

  // MQTT
  MQTTClient.setServer("IP", 1883);  // Direccion IP del broquer MQTT

  // CLIMA
  dht.begin();

  // MPX MQ's
  pinMode(pinMPXS1, OUTPUT);
  pinMode(pinMPXS2, OUTPUT);
}
