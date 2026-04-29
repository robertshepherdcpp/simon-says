#include "Adafruit_MCP23X17.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Vector.h>
#include <Preferences.h>

// the MCP23017
#define LED1 6
#define LED2 7
#define LED3 21
#define LED4 22
#define LED5 23
#define LED6 24
#define LED7 25
#define LED8 26
#define LED9 27

// esp
#define MCP23017SCK 19
#define MCP23017SDA 20

#define Btn1 11
#define Btn2 10
#define Btn3 9
#define Btn4 0
#define Btn5 1
#define Btn6 2
#define Btn7 21
#define Btn8 22
#define Btn9 23

Adafruit_MCP23X17 mcp;

Preferences pr;

void setup() {
  // leds
  mcp.pinMode(LED1, OUTPUT);
  mcp.pinMode(LED2, OUTPUT);
  mcp.pinMode(LED3, OUTPUT);
  mcp.pinMode(LED4, OUTPUT);

  // buttons
  pinMode(Btn1, INPUT_PULLUP);
  pinMode(Btn2, INPUT_PULLUP);
  pinMode(Btn3, INPUT_PULLUP);
  pinMode(Btn4, INPUT_PULLUP);
  pinMode(Btn5, INPUT_PULLUP);
  pinMode(Btn6, INPUT_PULLUP);
  pinMode(Btn7, INPUT_PULLUP);
  pinMode(Btn8, INPUT_PULLUP);
  pinMode(Btn9, INPUT_PULLUP);
}

// we have a maximum of 128 elements
constexpr size_t ELEMENT_COUNT_MAX = 128;
int storage[ELEMENT_COUNT_MAX];
Vector<int> v(storage);
int current_index = 0; // current index of where the user is at.
int score = 0; // how many successive presses they got right.

auto get_random_number() {
  return random(1, 10);
}

int leds[9] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9};

auto play_sequence() {
  for(int i = 0; i < v.size(); i++) {
    int num = v[i] - 1;
    mcp.digitalWrite(leds[num], HIGH);
    delay(1000);
    mcp.digitalWrite(leds[num], LOW);
  }
}

auto showError() {
  // blink all leds.
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], LOW);
  }
}

auto showWin() {
  // blink 3 times.
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], LOW);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], LOW);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < 9; i++) {
    mcp.digitalWrite(leds[i], LOW);
  }
}

void loop() {
  bool flag = false;
  if(v.size() == 0) {
    v.push_back(get_random_number());
    play_sequence();
  } else {
    // checking which button was pressed
    int btns[9] = {Btn1, Btn2, Btn3, Btn4, Btn5, Btn6, Btn7, Btn8, Btn9};
    for(int i = 0; i < 9; i++) {
      if(digitalRead(btns[i]) == HIGH) {
        if(v[current_index] == i+1) {
          flag = true;
          score += 1;
        } else {
          showError();

          pr.begin("my-app", false);
          int high_score = pr.getInt("highScore", 0);
          if(score > high_score) {
            pr.putInt("highScore", score);
            showWin();
          }
          pr.end();

          score = 0;
          v.clear();
          current_index = 0;
        }
      }
      delay(250); // wait so we dont get duplicate presses counted.
      break;
    }

    if(flag) {
      // then check if we have reached the end of the sequence, if so, we just play the sequence
      if(v.size()-1 == current_index) {
        v.push_back(get_random_number());
        play_sequence();
      }
      else {
        current_index += 1;
      }
    }

    // if(digitalRead(Btn1) == HIGH) {
    //   if(v[current_index] == 1) {
    //     flag = true;
    //     score += 1;
    //   } else {
    //     // the user got it wrong, so we reset
    //     showError(); // should flash all LEDs
    //   }
    // }
  }
}

