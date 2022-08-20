#include <DHTesp.h>
DHTesp dht;
// definiendo los pines del led rgb
int Rojo = 5;
int Verde = 4;
int Azul = 0;
float bomba = 2;
float humedad_suelo = 0;
#define SensorPin A0
void setup() {
  //pinMode(SensorPin, INPUT);
  pinMode(Rojo,OUTPUT);
  pinMode(Verde,OUTPUT);
  pinMode(Azul,OUTPUT);
  pinMode(bomba, OUTPUT);
  Serial.begin(9600);
  dht.setup(16,DHTesp::DHT22);
}

void loop() {
  TempAndHumidity valor = dht.getTempAndHumidity();
  humedad_suelo = analogRead(SensorPin);

  ledRGB(valor.temperature);
  
  //Se imprimen las variables
  Serial.println(" Humedad del ambiente: " + String(valor.humidity, 1)+ "%");
  Serial.println(" Temperatura: " + String(valor.temperature, 2)+ "C°\n");
  Serial.println("Humedad del suelo: " + String(humedad_suelo));
  delay(3000);

  digitalWrite(bomba,LOW);
  delay(10000);
  digitalWrite(bomba,HIGH);
  delay(5000);

}

void enciendeBomba(double sensorHumedadSuelo)
{
  digitalWrite(bomba,LOW);
  delay(10000);
  digitalWrite(bomba,HIGH);
}

void ledRGB(double lectura)
{
  if(lectura < 18){
    digitalWrite(Rojo,0);
    digitalWrite(Verde,0);
    digitalWrite(Azul,255);
  }
  if(lectura >=18 || lectura < 25)
  {
    digitalWrite(Rojo,0);
    digitalWrite(Verde,255);
    digitalWrite(Azul,0);
  }
  if(lectura >= 25)
  {
    digitalWrite(Rojo,255);
    digitalWrite(Verde,0);
    digitalWrite(Azul,0);
  }
}
