# esp32cam_AI
<br>
Development board for testing EDGE IMPULSE AI technology on the esp32 chip.<br>
Edge Impulse (https://www.edgeimpulse.com/) is another solution that aims to simplify
the deployment of machine learning applications on embedded devices based on the
Cortex-M core (also called Embedded ML or TinyML) by collecting real-world sensor
data, train ML models with this data in the cloud and then deploy the model to an embedded device.<br>
<br>
The core is a ready-made esp32cam board (https://iarduino.ru/shop/boards/kontroller-esp32-cam-s-kameroy-ov2640.html)
purchased on ali.<br>
The following elements have been added to extend functionality:<br>
- display st3775 (1.8 inches) with a resolution of 128x160 pixels<br>
- four analog buttons <br>
- UART output on ft232rl for programming and debugging <br>
- one LED <br>
<br>
<br>
Плата разработчика для тестирования технологии ИИ EDGE IMPULSE на чипе esp32.<br>
Edge Impulse (https://www.edgeimpulse.com/) — это еще одно решение, которое призвано упростить развертывание приложений
машинного обучения на встроенных устройствах на основе ядра Cortex-M (также называемых Embedded ML или TinyML)
путем сбора реальных данных датчиков, обучения ML-моделей этим данным в облаке и последующего развертывания
модели на встроенном устройстве.<br>

<br>
В качестве ядра используется готовая плата esp32cam (https://iarduino.ru/shop/boards/kontroller-esp32-cam-s-kameroy-ov2640.html) купленная на ali.
Для расширения функционала добавлены следующие элементы:<br>
- дисплей st3775 (1.8 дюйма) с разрешением 128х160 точек<br>
- четыре аналоговые кнопки <br>
- выход UART на ft232rl для программирования и отладки <br>
- один светодиод <br>
<br>
Внешний вид платы ver 1.0:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Board/view01.png" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Board/view02.png" width="480" /> <br>
Плата в собранном виде:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Board/board01.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Board/board02.jpg" width="480" /> <br>
<br>
Полезные ссылки:<br>
https://www.hackster.io/mjrobot/esp32-cam-tinyml-image-classification-fruits-vs-veggies-4ab970
https://www.survivingwithandroid.com/esp32-anomaly-detection-edge-impulse-machine-learning/<br>
https://www.hackster.io/news/edge-impulse-announces-official-espressif-esp32-support-releases-open-source-esp-eye-firmware-b626af54d66e<br>
https://docs.edgeimpulse.com/docs/deployment/running-your-impulse-locally/running-your-impulse-esp32<br>
https://scrobotics.es/2021/07/08/using-edge-impulse-on-an-esp32/<br>
https://www.theamplituhedron.com/articles/How_to_run_the_Edge_Impulse_ESP_EYE_firmware_on_FireBeetle_ESP32/
https://www.bouvet.no/bouvet-deler/machine-learning-with-esp32
