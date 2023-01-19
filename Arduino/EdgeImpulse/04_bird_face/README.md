Пример использования Edge Impulse (версия января 2023 года).
Была сгенерирована библиотека из среды Edge Impulse и затем доработана для использования в Arduino (см. readme в директории lib).<br>
Некоторые настройки Edge Impulse для нейросети:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/04_bird_face/Picture/pic1.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/04_bird_face/Picture/pic2.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/04_bird_face/Picture/pic3.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/04_bird_face/Picture/pic4.jpg" width="480" /> <br>
<br>
ВНИМАНИЕ! sdk esp32 2.0.5!!!!<br>
Тестировался в arduino ide 1.8.9 (1.8.19), sdk esp32 2.0.5. Выбрана плата "ESPЗ2 Dev Module", PSARAM "Enable"
Камера показывает изображение (2-3 кадра в секунду), при посылке любого символа (например Enter) в последовательный порт
происходит фиксация изображения и его классификация через библиотеку Edge Impulse и выдача результатов (на экран и в последовательный порт).
При посылке еще одного символа камера снова показывает текущее изображение (частота около 2 кадров в секунду)<br>
Классификация происходит по трем классам:<br>
- птица <br>
- лицо человека<br>
- ланшафт<br>
Т.к. на макете верх камеры не равен верху дисплея то макет надо тержать разъемом usb вверх для правильной орентации изображения.<br>
Пример распознавания показан на картинке ниже.<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/04_bird_face/Picture/pic5.jpg" width="480" /> <br>
Нейросеть меньше чем в 01 примере и распознавание хуже, но сама сеть при работе меньше требует объема свободной RAM.
<br>
<br>
<br>
