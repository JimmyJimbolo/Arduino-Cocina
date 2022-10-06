void loop() {

  // Comprobacion de Wifi
  if (!WiFi.isConnected()) { Wificonnect(); }

  //OTA
  ArduinoOTA.handle();

  // Comprobacion de MQTT
  if (!MQTTClient.connected()) { MQTTconnect(); }
  MQTTClient.loop();

  // CLIMA
  if (millis() - clima_lectura > (5 * 60000) || enviar == 1) {
    clima_lectura = millis();
    temp = dht.readTemperature();
    // temp=temp-1; // Correcion de lectura con tapa puesta
    hume = dht.readHumidity();
    if (temp != temp_anterior) {
      String S_temp = String(temp, 2);
      MQTTout("arduino/cocina/temperatura", S_temp);
      temp_anterior = temp;
    }
    if (hume != hume_anterior) {
      String S_hume = String(hume, 2);
      MQTTout("arduino/cocina/humedad", S_hume);
      hume_anterior = hume;
    }
  }

  // MQ's
  if (millis() - MQ_tiempo > (5 * 60000) || enviar == 1) {
    MQ_tiempo = millis();

    digitalWrite(pinMPXS1, LOW);
    digitalWrite(pinMPXS2, LOW);
    MQ135 = analogRead(A0);
    if (MQ135 != MQ135_a) {
      S_MQ = String(MQ135, 0);
      MQTTout("arduino/cocina/MQ135", S_MQ);
      MQ135_a=MQ135;
    }

    digitalWrite(pinMPXS1, LOW);
    digitalWrite(pinMPXS2, HIGH);
    MQ2 = analogRead(A0);
    if (MQ2 != MQ2_a) {
      S_MQ = String(MQ2, 0);
      MQTTout("arduino/cocina/MQ2", S_MQ);
      MQ2_a=MQ2;
    }

    digitalWrite(pinMPXS1, HIGH);
    digitalWrite(pinMPXS2, LOW);
    MQ7 = analogRead(A0);
    if (MQ7 != MQ7_a) {
      S_MQ = String(MQ7, 0);
      MQTTout("arduino/cocina/MQ7", S_MQ);
      MQ7_a=MQ7;
    }

    enviar = 0;
  }
}