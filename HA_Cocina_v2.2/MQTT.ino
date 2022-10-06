void MQTTconnect() {
  while (!MQTTClient.connected()) {
    if (MQTTClient.connect("", "USER", "PASS")) {  // Usuario y contraseña del broque MQTT
    } else {
      delay(250);
    }
  }
  MQTTClient.setCallback(MQTTin);
  MQTTClient.subscribe("arduino/#");
  MQTTout("arduino/cocina/ip", "0");
  MQTTout("arduino/cocina/ip", ip);
}

void MQTTout(String tema, String dato) {
  char topic[30];
  tema.toCharArray(topic, 30);
  char payload[15];
  dato.toCharArray(payload, 15);
  MQTTClient.publish(topic, payload);
}

void MQTTin(char* topic, byte* message, unsigned int length) {
  String strTopic = String((char*)topic);
  if (strTopic == "arduino/refrescar") {
    MQTTout("arduino/cocina/ip", ip);
    enviar = 1;
  }
}
