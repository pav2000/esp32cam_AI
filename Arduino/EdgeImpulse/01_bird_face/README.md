Пример использования Edge Impulse<br>
Камера показывает изображение (2-3 кадра в секунду), при посылке любого символа (например Enter) в последовательный порт
происходит фиксация изображения и его классификация через библиотеку Edge Impulse и выдача результатов (на экран и в последовательный порт).
При посылке еще одного символа камера снова показывает текущее изображение (частота около 2 кадров в секунду)<br>
Классификация происходит по трем классам:<br>
- птица <br>
- лицо человека<br>
- ланшафт<br>
Т.к. на макете верх камеры не равен верху дисплея то макет надо тержать разъемом usb вверх для правильной орентации изображения.<br>
Примеры классификации приведены ниже:<br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/01_bird_face/Picture/pic1.jpg" width="400" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/01_bird_face/Picture/pic2.jpg" width="400" /> <br>
<img src="https://github.com/pav2000/esp32cam_AI/blob/main/Arduino/EdgeImpulse/01_bird_face/Picture/pic3.jpg" width="400" /> <br>
<br>
В начале при компиляции была ошибка: <br>
…NNSupportFunctions\arm_nn_accumulate_q7_to_q15.c:57:22: error: implicit declaration of function ‘__PKHTB’ [-Werror=implicit-function-declaration]<br>
vo2 = (q31_t)__PKHTB(v1, v2, 16);<br>
^<br>
vo1 = (q31_t)__PKHBT(v2, v1, 16);<br>
^<br>
для исправления в либу bird_classification_3_inferencing.zip в файл arm_nnfunctions.было добавлено в начале <br>
#define __PKHBT(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0x0000FFFF) | \ <br>
                                      (((int32_t)(ARG2) << ARG3) & (int32_t)0xFFFF0000)  ) <br>
  #define __PKHTB(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0xFFFF0000) | \ <br>
                                      (((int32_t)(ARG2) >> ARG3) & (int32_t)0x0000FFFF)  ) <br>

<br>

<br>
