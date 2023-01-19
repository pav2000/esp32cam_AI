Работающие примеры<br>
Тестировался в arduino ide 1.8.9 (1.8.19), sdk esp32 1.0.6. Выбрана плата "ESPЗ2 Dev Module", PSARAM "Enable"
Пример определения машины, информация выводится через веб сервер.
Веб сервер с выводом картинки с камеры.<br>
Два режима работы (задается #define useAP)<br>
- точка доступа (ssid "ESP32-Access-Point" пароль "12345678")<br>
- цепляется к существующей WiFi сети (в сети должен быть dhcp сервер для раздачи адресов)<br>
При соединении надо зайти на страницу 192.168.4.1 (веб сервер).<br>
В последовательном порте идет лог соединения и определения машины. При обновлении страницы делается новое фото и распознавание.<br>
Проверено, работает.<br>
<br>
<i>Пример лога:</i><br>
Capture image<br>
Converting to RGB888...<br>
Resizing the frame buffer...
Getting signal...<br>
Run classifier...<br>
run_classifier returned: 0<br>
Predictions (DSP: 6 ms., Classification: 561 ms., Anomaly: 0 ms.):<br>
    cars: 	0.671875<br>
    unknown: 	0.328125<br>
Converting resized RGB888 frame to JPG...<br>
Sending back HTTP response...<br>
<br>
<br>