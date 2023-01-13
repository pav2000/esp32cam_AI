Примеры для Arduino IDE <br>
<br>
Base - базовые примеры работы с макетом (без нейросетей). Необходимо начать с них для проверки работоспособности макета.<br>
EdgeImpulse - примеры работы с нейросетями с использованием EdgeImpulse.<br>
<br>
Подготовка среды для программирования esp32 (при выборе версии лучше выбрать 1.0.6, т.к. на ней тесировались примеры если не указано иное)<br>
https://wiki.iarduino.ru/page/esp32-windows/<br>
https://habr.com/ru/post/404685/<br>
https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/<br>
esp32cam<br>
https://portal-pk.ru/news/228-esp32-cam-ov2640-potokovoe-video-v-srede-arduino-ide.html
https://microtechnics.ru/bystryj-start-s-esp32-i-ov2640-modul-esp32-cam/<br>
https://www.youtube.com/watch?v=mUpCZpb30Ds<br>
https://www.youtube.com/watch?v=DqHZ1Fyd10o<br>
<br>
После установки среды при подключении платы через usb к компьютеру, в диспетчере устройств появляется виртуальный последовательный порт, он же появляется
в среде Arduino Инструменты->Порт. Если этого нет то надо смотреть установку драйверов для ft232r на компе (драйвера под этот чип входят в дистрибутив windows начиная с 7).
Без этого дальше двигаться бесполезно - Вы не сможите загрузить код в плату.<br>
В менеджере плат надо выбирать "ESPЗ2 Dev Module". Если прошивка слишком большая и появляется сообщение о не хватке места то
в пункте "Partition Scheme" надо выбрать "Huge APP"
Для программирования платы в среде Arduino необходимо замкнуть перемычку boot и нажать на кнопку reset на плате. Плата перейдет в режим загрузки.
Из среды Arduino (выбрав правильный порт загрузки) надо нажать на кнопку загрузить. Для выполнения кода - убрать перемычку и нажать на кнопку reset.<br>
<br>
<br>
