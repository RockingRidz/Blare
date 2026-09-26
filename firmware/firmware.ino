#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define TFT_CS    5
#define TFT_DC    16
#define TFT_RST   17

#define BTN_MODE  12
#define BTN_UP    13
#define BTN_DOWN  14
#define BTN_ALARM 27

#define BUZZER    25

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int hours = 7;
int minutes = 30;
int seconds = 0;

int alarmHours = 7;
int alarmMinutes = 31;
bool alarmEnabled = true;
bool alarmActive = false;

int editMode = 0;

unsigned long previousMillis = 0;
const long interval = 1000;

unsigned long lastDebounce = 0;

void setup() {
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_ALARM, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  tft.init(135, 240);
  tft.setRotation(1);
  tft.fillScreen(ST77XX_BLACK);

  drawUI();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) {
          hours = 0;
        }
      }
    }

    if (alarmEnabled && hours == alarmHours && minutes == alarmMinutes && seconds == 0) {
      alarmActive = true;
    }

    drawUI();
  }

  if (alarmActive) {
    if ((millis() / 250) % 2 == 0) {
      digitalWrite(BUZZER, HIGH);
    } else {
      digitalWrite(BUZZER, LOW);
    }
  } else {
    digitalWrite(BUZZER, LOW);
  }

  if (currentMillis - lastDebounce > 200) {
    if (digitalRead(BTN_MODE) == LOW) {
      editMode = (editMode + 1) % 5;
      lastDebounce = currentMillis;
      drawUI();
    }

    if (digitalRead(BTN_ALARM) == LOW) {
      if (alarmActive) {
        alarmActive = false;
      } else {
        alarmEnabled = !alarmEnabled;
      }
      lastDebounce = currentMillis;
      drawUI();
    }

    if (digitalRead(BTN_UP) == LOW) {
      handleIncrement(1);
      lastDebounce = currentMillis;
      drawUI();
    }

    if (digitalRead(BTN_DOWN) == LOW) {
      handleIncrement(-1);
      lastDebounce = currentMillis;
      drawUI();
    }
  }
}

void handleIncrement(int amount) {
  if (editMode == 1) {
    hours = (hours + amount + 24) % 24;
  } else if (editMode == 2) {
    minutes = (minutes + amount + 60) % 60;
  } else if (editMode == 3) {
    alarmHours = (alarmHours + amount + 24) % 24;
  } else if (editMode == 4) {
    alarmMinutes = (alarmMinutes + amount + 60) % 60;
  }
}

void drawUI() {
  tft.fillScreen(ST77XX_BLACK);
  
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.print("BLARE ALARM");

  tft.setTextSize(4);
  tft.setCursor(20, 45);
  if (hours < 10) tft.print("0");
  tft.print(hours);
  tft.print(":");
  if (minutes < 10) tft.print("0");
  tft.print(minutes);

  tft.setTextSize(2);
  tft.setCursor(150, 60);
  if (seconds < 10) tft.print("0");
  tft.print(seconds);

  tft.setTextSize(2);
  tft.setCursor(20, 100);
  tft.print("ALARM: ");
  if (alarmHours < 10) tft.print("0");
  tft.print(alarmHours);
  tft.print(":");
  if (alarmMinutes < 10) tft.print("0");
  tft.print(alarmMinutes);

  tft.setCursor(180, 100);
  if (alarmEnabled) {
    tft.setTextColor(ST77XX_GREEN);
    tft.print("ON");
  } else {
    tft.setTextColor(ST77XX_RED);
    tft.print("OFF");
  }

  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(1);
  tft.setCursor(10, 125);
  if (editMode == 0) tft.print("MODE: NORMAL");
  else if (editMode == 1) tft.print("MODE: SET CLOCK HOUR");
  else if (editMode == 2) tft.print("MODE: SET CLOCK MIN");
  else if (editMode == 3) tft.print("MODE: SET ALARM HOUR");
  else if (editMode == 4) tft.print("MODE: SET ALARM MIN");
}
