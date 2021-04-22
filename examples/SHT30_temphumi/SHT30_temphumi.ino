#include <SHT30.h>
SHT30 sht30(0x45);
void setup(){
	Serial.begin(115200);
	Serial.println();
	sht30.begin();
}

void loop(){
	long interval=sht30.requestMeasurement();
	delay(interval);
	if(sht30.getResult()){
		Serial.printf("Temp C:%lf\n",sht30.getTempInC());
		Serial.printf("Humi:%lf\n",sht30.getHumi());
	}else
		Serial.println("Measurement failed!");
	delay(1000);
}
		