// Definimos los pines a los que están conectados los motores
const int motor1APin = 5;
const int motor1BPin = 6;

const int motor2APin = 9;
const int motor2BPin = 10;

void setup() {
  // Configuramos los pines de los motores como salidas
  pinMode(motor1APin, OUTPUT);
  pinMode(motor1BPin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
  pinMode(motor2BPin, OUTPUT);

  // Establecemos el estado inicial de los pines de salida en LOW
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor1BPin, LOW);
  digitalWrite(motor2APin, LOW);
  digitalWrite(motor2BPin, LOW);
}

void loop() {
  // Movemos hacia adelante ambos motores durante 5 segundos
  digitalWrite(motor1APin, HIGH);
  digitalWrite(motor2APin, HIGH);
  delay(5000); // Movemos los motores durante 5 segundos

  // Detenemos ambos motores
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor2APin, LOW);
  delay(1000); // Esperamos un segundo

  // Giramos a la derecha (activando solo el motor1) durante 2 segundos
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor1BPin, HIGH);
  delay(2000); // Giramos durante 2 segundos

  // Detenemos el motor1
  digitalWrite(motor1BPin, LOW);
  delay(1000); // Esperamos un segundo

  // Movemos hacia adelante ambos motores durante 5 segundos
  digitalWrite(motor1APin, HIGH);
  digitalWrite(motor2APin, HIGH);
  delay(5000); // Movemos los motores durante 5 segundos

  // Detenemos ambos motores
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor2APin, LOW);
  delay(1000); // Esperamos un segundo

  // Giramos a la izquierda (activando solo el motor2) durante 2 segundos
  digitalWrite(motor2APin, LOW);
  digitalWrite(motor2BPin, HIGH);
  delay(2000); // Giramos durante 2 segundos

  // Detenemos el motor2
  digitalWrite(motor2BPin, LOW);
  delay(1000); // Esperamos un segundo
}
