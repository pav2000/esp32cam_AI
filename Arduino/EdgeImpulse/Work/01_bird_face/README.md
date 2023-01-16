Пример использования Edge Impulse<br>
Камера показывает изображение, при посылке любого символа (например Enter) в последовательный порт
происходит фиксация изображени и классификация его через библиотеку Edge Impulse и выдача результатов.
При посылке еще одного символа камера снова показывает текущее изображение (частота около 2 кадров в секунду)<br>
Классификация происходит по трем классам:<br>
- птица <br>
- лицо человека<br>
- ланшафт<br>
Т.к. на макете верх камеры не равен верху дисплея то макет надо тержать разъемом usb вверх для правильной орентации изображения.<br>
Примеры классификации приведены ниже:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/Work/01_bird_face/Picture/pic1.jpg" width="400" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/Work/01_bird_face/Picture/pic2.jpg" width="400" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/Work/01_bird_face/Picture/pic3.jpg" width="400" /> <br>
<br>
