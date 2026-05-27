#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 4);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int moisturePin = A0;
const int motor = 9;

void setup() {
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW); // ensure motor is off on startup

  Serial.begin(9600);

  lcd.init();        // fixed: use init() not begin()
  lcd.backlight();
  dht.begin();

  // Startup splash screen
  lcd.setCursor(3, 1);
  lcd.print("GREEN HOUSE");
  delay(2000);
  lcd.setCursor(2, 3);   // fixed: was -2
  lcd.print("KANDU_UNI_26");
  delay(2000);
  lcd.clear();
}

void loop() {
  float humidity    = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Guard against failed DHT reads
  if (isnan(humidity) || isnan(temperature)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    Serial.println("ERR|DHT_FAIL");
    delay(2000);
    return;
  }

  // Float math for accurate percentage (replaces map())
  int rawMoisture = analogRead(moisturePin);
  float moisturePercent = (1.0 - rawMoisture / 1023.0) * 100.0;

  lcd.clear();

  // Row 0 - Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print("C");

  // Row 1 - Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  // Row 2 - Moisture
  lcd.setCursor(0, 2);   // fixed: was -4
  lcd.print("Moisture: ");
  lcd.print(moisturePercent, 1);
  lcd.print("%");

  // Row 3 - Status and motor control
  lcd.setCursor(0, 3);   // fixed: was -4
  if (moisturePercent > 60) {
    lcd.print("Status: High ");
    digitalWrite(motor, LOW);   // soil wet, pump off
  } else {
    lcd.print("Status: Low  ");
    digitalWrite(motor, HIGH);  // soil dry, pump on
  }

  // Send data over Bluetooth
  Serial.print(temperature);
  Serial.print("C|");
  Serial.print(humidity);
  Serial.print("%|");
  Serial.print(moisturePercent);
  Serial.println("%");  // newline ends each data frame

  delay(5000);
}