#include <Arduino.h>

// Pin Definitions (adjust these based on your actual wiring)
const int BUZZER_PIN = 9;
const int BUTTON_SET_PIN = 2;
const int BUTTON_SNOOZE_PIN = 3;

// Alarm Settings
int alarmHour = 7;
int alarmMinute = 0;
bool alarmEnabled = true;

// State Management
bool isAlarmTriggered = false;

void setup() {
    // Initialize Serial Monitor for debugging
    Serial.begin(115200);

    // Configure Pins
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON_SET_PIN, INPUT_PULLUP);
    pinMode(BUTTON_SNOOZE_PIN, INPUT_PULLUP);

    Serial.println("Blare Alarm Clock Initialized.");
}

void loop() {
    // Read button states
    bool setPressed = (digitalRead(BUTTON_SET_PIN) == LOW);
    bool snoozePressed = (digitalRead(BUTTON_SNOOZE_PIN) == LOW);

    // Handle snooze or stop alarm action
    if (snoozePressed && isAlarmTriggered) {
        stopAlarm();
        delay(500); // Debounce delay
    }

    // Check time conditions (simulated or real-time module integration)
    checkAlarmTrigger();

    // Small delay to prevent CPU thrashing
    delay(100);
}

void checkAlarmTrigger() {
    // Placeholder for Real-Time Clock (RTC) time check logic
    // Example: If current time matches alarmHour and alarmMinute:
    if (alarmEnabled && !isAlarmTriggered) {
        // triggerAlarm();
    }
}

void triggerAlarm() {
    isAlarmTriggered = true;
    Serial.println("Alarm triggered! Wake up!");
    
    // Sound the buzzer pattern
    for (int i = 0; i < 5; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(500);
        digitalWrite(BUZZER_PIN, LOW);
        delay(500);
    }
}

void stopAlarm() {
    isAlarmTriggered = false;
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Alarm snoozed/stopped.");
}
