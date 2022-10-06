void setup() {
  Serial.begin(115200);

  // OTA
  InitOTA();

  // MQTT
  MQTTClient.setServer("192.168.1.200", 1883);

  // CLIMA
  dht.begin();

  // MPX MQ's
  pinMode(pinMPXS1, OUTPUT);
  pinMode(pinMPXS2, OUTPUT);
}
