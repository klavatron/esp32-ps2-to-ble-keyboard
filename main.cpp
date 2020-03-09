/**
 * This example turns the PS2 keyboard and ESP32 into a Bluetooth LE keyboard 
 */
#include <Arduino.h>
//https://github.com/michalhol/ps2kbdlib
// beginof ps2keyboard
//https://www.arduino.cc/en/Reference/ASCIIchart
//https://ru.wikipedia.org/wiki/%D0%A1%D0%BA%D0%B0%D0%BD-%D0%BA%D0%BE%D0%B4


#include "PS2Kbd.h"
#define KEYBOARD_DATA 32 //G32
#define KEYBOARD_CLK  33 //G33

PS2Kbd keyboard(KEYBOARD_DATA, KEYBOARD_CLK);
// endof ps2keyboard

// beginof ble
//https://github.com/T-vK/ESP32-BLE-Keyboard
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
// endof ble
void setup() {
  Serial.begin(115200);
  Serial.println("Starting PS2");
  keyboard.begin();
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  unsigned char tmp;
  if(bleKeyboard.isConnected()) {
    //Serial.println("BLE connected");
    if (keyboard.available()) {
          //Serial.write(keyboard.read());
         // tmpRaw = keyboard.readRaw();
          tmp = keyboard.read();
          //keyboard.clearBuffers();
         // Serial.print("tRaw = ");Serial.println(tmpRaw);
          Serial.print("TMP= ");Serial.println(tmp);
          if(tmp == 144)
          {
            Serial.println("[PREV Track pressed]");
            bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
            tmp = 0;
          }
          else if(tmp == 145)
          {
            Serial.println("[NEXT Track pressed]");
            bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
            tmp = 0;
          }
          else if(tmp == 146)
          {
            Serial.println("[PLAY/PAUSE]");
            bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
            tmp = 0;
          }
          else if(tmp == 147)
          {
            Serial.println("[STOP]");
            bleKeyboard.write(KEY_MEDIA_STOP);
            tmp = 0;
          }
          else if(tmp == 148)
          {
            Serial.println("[WWW STOP]");
            bleKeyboard.write(KEY_MEDIA_WWW_STOP);
            tmp = 0;
          }
          else if(tmp == 149)
          {
            Serial.println("[REFRESH]");
            //bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
            tmp = 0;
          }
          else if(tmp == 150)
          {
            Serial.println("[BROWSER]");
            bleKeyboard.write(KEY_MEDIA_LOCAL_MACHINE_BROWSER);
            tmp = 0;
          }
          else if(tmp == 151)
          {
            Serial.println("[EMAIL_READER]");
            bleKeyboard.write(KEY_MEDIA_EMAIL_READER);
            tmp = 0;
          }
          else if(tmp == 152)
          {
            Serial.println("[WWW SERACH]");
            bleKeyboard.write(KEY_MEDIA_WWW_SEARCH);
            tmp = 0;
          }

          else if(tmp == 153)
          {
            Serial.println("[WWW bookmarks]");
            bleKeyboard.write(KEY_MEDIA_WWW_BOOKMARKS);
            tmp = 0;
          }

          else if(tmp == 154)
          {
            Serial.println("[CALC]");
            bleKeyboard.write(KEY_MEDIA_CALCULATOR);
            tmp = 0;
          }
          else if(tmp == 241)
          {
            Serial.println("[F1]");
            bleKeyboard.write(KEY_F1);
          }
          else if(tmp == 242)
          {
            Serial.println("[F2]");
            bleKeyboard.write(KEY_F2);
          }
          else if(tmp == 243)
          {
            Serial.println("[F3]");
            bleKeyboard.write(KEY_F3);
          }
          else if(tmp == 244)
          {
            Serial.println("[F41]");
            bleKeyboard.write(KEY_F4);
          }
          else if(tmp == 245)
          {
            Serial.println("[F5]");
            bleKeyboard.write(KEY_F5);
          }
          else if(tmp == 246)
          {
            Serial.println("[F6]");
            bleKeyboard.write(KEY_F6);
          }
          else if(tmp == 247) // 247 = F7hex 124
          {
            Serial.println("[F7]");
            bleKeyboard.write(KEY_F7);
          }
          else if(tmp == 248)
          {
            Serial.println("[F8]");
            bleKeyboard.write(KEY_F8);
          }
          else if(tmp == 249)
          {
            Serial.println("[F9]");
            bleKeyboard.write(KEY_F9);
          }
          else if(tmp == 250)
          {
            Serial.println("[F10]");
            bleKeyboard.write(KEY_F10);
          }
          else if(tmp == 251)
          {
            Serial.println("[F11]");
            bleKeyboard.write(KEY_F11);
          }
          else if(tmp == 252)
          {
            Serial.println("[F12]");
            bleKeyboard.write(KEY_F12);
          }
          
          Serial.print("Have data: ");Serial.print(tmp);Serial.print(" char: ");Serial.println((char)tmp);
          bleKeyboard.print((char)tmp);
    }
  }

}