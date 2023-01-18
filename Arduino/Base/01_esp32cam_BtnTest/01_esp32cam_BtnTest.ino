// Tест аналоговых кнопок на макете https://github.com/pav2000/esp32cam_AI
#define ADC 0 // Кнопки подключены к IO0 см. схему

void setup() {
 Serial.begin(115200);
 Serial.println("\nАnalog button test");
 Serial.println("Press button");

}

void loop() {
uint16_t val;
val=analogRead(ADC); 
// Serial.println(val);
 
if(val>2000){ // Ни одна кнопка не нажата
	Serial.print("ADC0=");	 	
	Serial.print(val);	 	
	Serial.print(" button pressed: ");	 	
	if (val>3000)  Serial.println("\"-\"");	
	else if(val>2600) Serial.println("\"Ок\"");	
	else if(val>2400) Serial.println("\"+\"");	
	else if(val>2200) Serial.println("\"Esc\"");		  
}
 delay(100);
}
