# Arduino-Cocina
Integracion en Home Assistant (HA) con sensor de temperatura/humedad y sensores MQ de calidad del aire

Este codigo incluye:
- Registro en red WiFi.
- Comprobacion de la conexion WiFi y reconexion en caso de fallo.
- Registro en el broquer MQTT de Home Assistant (Mosquitto) para el envio y recepcion de datos hacia HA.
- Comprobacion del registro MQTT y reconexion en caso de fallo.
- Inicio de servicio OTA para actualizacion del codigo via WiFi.

Caracteristicas
- Envio de datos en el arranque. (Temperatura, humedad, direccion IP y lecturas de sensores)
- Chequeo y envio de datos cada 5 minutos, solo si ha habido cambios desde la lectura anterior.
- Reenvio de datos al recibir un mensaje MQTT desde HA.
