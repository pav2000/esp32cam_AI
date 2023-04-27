Пример использования Edge Impulse (версия января 2023 года).
Была сгенерирована библиотека из среды Edge Impulse и затем доработана для использования в Arduino (см. readme в директории lib).<br>
Некоторые настройки Edge Impulse для нейросети:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic1.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic2.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic3.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic4.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic5.jpg" width="480" /> <br>
<br>
ВНИМАНИЕ! sdk esp32 2.0.5 or 2.0.8!!!!<br>
Тестировался в arduino ide 1.8.9 (1.8.19), sdk esp32 2.0.5. Выбрана плата "ESPЗ2 Dev Module", PSARAM "Enable"<br>
27/04/23 протестировано ide 1.8.9, sdk esp32 2.0.8. Выбрана плата "ESPЗ2 Wrover Module" Flash QIO, 80MHz<br>
<br>
Камера показывает изображение (2-3 кадра в секунду), при посылке любого символа (например Enter) в последовательный порт
происходит фиксация изображения и его классификация через библиотеку Edge Impulse и выдача результатов (на экран и в последовательный порт).
При посылке еще одного символа камера снова показывает текущее изображение (частота около 2 кадров в секунду)<br>
Классификация происходит по двум классам:<br>
- собака <br>
- кошка<br>
Т.к. на макете верх камеры не равен верху дисплея то макет надо тержать разъемом usb вверх для правильной орентации изображения.<br>
Пример распознавания показан ниже.<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic6.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic7.jpg" width="480" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/05_dog_cat/Picture/pic8.jpg" width="480" /> <br>
Распределение памяти:<br>
Memory (bytes) -------- <br>
FreeHeap=281072  MinFreeHeap=271780  HeapSize=343976  MaxAllocHeap=110580 <br>
Нейросеть занимает место около 120 кБ в памяти при точности распознования около 83% <br>
Используется MobileNetV1 96x96 0.25 (no final dense layer, 0.1 dropout).<br>
<br>
<br>
<br>
