const int lm35Pin = A0;      // LM35 temperature sensor connected to A0
const int relayControlPin = 2;  // Control pin for the relay module

// Set the temperature threshold for turning on the fan
const float temperatureThreshold = 30.0; // Adjust as needed

void setup() {
  pinMode(relayControlPin, OUTPUT);
  digitalWrite(relayControlPin, LOW); // Initially turn off the relay (fan)
  Serial.begin(9600);
}

void loop() {
  // Read temperature from LM35 sensor
  float temperature = analogRead(lm35Pin) * 0.48875; // Convert analog reading to degrees Celsius

  // Print temperature to serial monitor (for debugging)
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check if temperature exceeds the threshold to turn on the fan
  if (temperature >= temperatureThreshold) {
    digitalWrite(relayControlPin, HIGH); // Turn on the relay (fan)
  } else {
    digitalWrite(relayControlPin, LOW); // Turn off the relay (fan)
  }

  delay(1000); // Delay for 1 second (adjust as needed)
}

