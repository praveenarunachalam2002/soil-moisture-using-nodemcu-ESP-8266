#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int sensor_pin = A0; /* sensor value range 0 to 1024 */
int output_value;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  lcd.clear();
  Serial.println("Soil Moisture Project");
  Serial.println("Reading From the Sensor ...");
  lcd.print(" Soil Moisture ");
  lcd.setCursor(0, 1);
  lcd.print("    Project    ");
  delay(2000);
}
void loop() {
  output_value = analogRead(sensor_pin);
  if (output_value >= 1000)
  {
    Serial.print("Disconnected or Sensor Not in Soil - ");
    Serial.print(output_value);
    Serial.print("\n");
    lcd.clear();
    lcd.print("Sensor Reading");
    lcd.setCursor(0, 1);
    lcd.print("--Disconnected---");
    delay(2000);
  }
  if (output_value < 1000 && output_value >= 750)
  {
    Serial.print("Dry Condition : ");
    Serial.print(output_value);
    Serial.print(" - Time for Watering\n");
    lcd.clear();
    lcd.print("Sensor Reading");
    lcd.setCursor(0, 1);
    lcd.print((int)output_value); lcd.print(" - Dry");
    delay(2000);
  }
  if (output_value < 750 && output_value >= 500)
  {
    Serial.print("Soil Moisture is Perfect - ");
    Serial.print(output_value);
    Serial.print("\n");
    lcd.clear();
    lcd.print("Sensor Reading");
    lcd.setCursor(0, 1);
    lcd.print((int)output_value); lcd.print(" - Perfect");
    delay(2000);
  }
  if (output_value < 500 && output_value >= 300)
  {
    Serial.print("Moderate Moisture - ");
    Serial.print(output_value);
    Serial.print(" - No Need Watering\n");
    lcd.clear();
    lcd.print("Sensor Reading");
    lcd.setCursor(0, 1);
    lcd.print((int)output_value); lcd.print(" - Low Wet");
    delay(2000);
  }
  if (output_value < 300)
  {
    Serial.print("Keep the Sensor in Right Place - ");
    Serial.print(output_value);
    Serial.print("\n");
    lcd.clear();
    lcd.print("Sensor Reading");
    lcd.setCursor(0, 1);
    lcd.print("--System Error--");
    delay(2000);
  }
}
