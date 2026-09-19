#define pinSensor 4
#define pinEmissor 2

bool estadoSensor;
bool estadoSensorAnt = false;

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(pinEmissor, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sketch Inciado!");

  delay(1000);
  digitalWrite(pinEmissor, HIGH);
  Serial.println("Emissor Ativo");
  Serial.println("Sensor Ativo");
}

void loop() {
  bool estadoSensor = digitalRead(pinSensor);

  if (estadoSensor && !estadoSensorAnt) {
    Serial.println("Laser DETECTADO!");
  }

  if (!estadoSensor && estadoSensorAnt){
    Serial.println("Laser não detactado. Sensor Ativo... ");
  }

  estadoSensorAnt = estadoSensor;
}
