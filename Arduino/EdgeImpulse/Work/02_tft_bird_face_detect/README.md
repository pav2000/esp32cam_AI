Пример классифицирует птицу, человека или сцену на изображении.<br>
<br>
Если компиляция в Arduino IDE, убедитесь, что вы используете версию платы ESP32 1.0.6.Не используйте версию 2.<br>
https://github.com/jonathanrandall/edge_impule_bird_person_scene<br>
<br>
Компилится и работает, надо ставить много библиотек.<br>
<br>
В начале была ошибка: <br>
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