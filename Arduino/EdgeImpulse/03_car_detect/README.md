Работающие примеры<br>
Пример определения машины, информация выводится через веб сервер.
Веб сервер с выводом картинки с камеры.<br>
Два режима работы (задается #define useAP)<br>
- точка доступа (ssid "ESP32-Access-Point" пароль "12345678")<br>
- цепляется к существующей WiFi сети (в сети должен быть dhcp сервер для раздачи адресов)<br>
При соединении надо зайти на страницу 192.168.4.1 (веб сервер).<br>
В последовательном порте идет лог соединения и определения машины. При обновлении страницы делается новое фото и распознавание.<br>
Проверено, работает.<br>
<br>
Пример лога:
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