# Embeddedcode_todder_STM32
![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/b92f74f2-26f3-479d-b90a-6cdf4a008376)

**7X8 Matrix Keypad with STM32F1 Series Microcontroller and DFPLAYER-MINI MP3 Player**

This is a 7X8 matrix keypad code for the STM32F1 series microcontroller and the DFPLAYER-MINI MP3 player. Seven horizontal and six vertical pins are configured. The horizontal pins are drivers, and the vertical pins are sense pins. The library used is DFROBOTMINIPLAYER.H and KEYPAD.H.

**Images:**

![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/015ad465-c8ff-4487-af33-3c57d502232e)


![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/712c8f13-ecee-4b23-9b08-72f13e09709f)

![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/27b3f8c0-cbd0-423a-a3ef-7dc7128b3686)

**Description:**

The 7X8 matrix keypad has 56 keys. The keys are arranged in a 7X8 grid. The horizontal pins are connected to the columns of the grid, and the vertical pins are connected to the rows of the grid.

To detect which key is pressed, the microcontroller scans the keypad matrix. The microcontroller sets one of the horizontal pins to output high and the other horizontal pins to output low. Then, the microcontroller reads the state of the vertical pins. If a vertical pin is high, then the corresponding key is pressed.

The DFPLAYER-MINI MP3 player is a small and low-cost MP3 player module. It can play MP3 files from a microSD card. The DFPLAYER-MINI MP3 player is controlled by a serial interface.

This code uses the DFROBOTMINIPLAYER.H library to control the DFPLAYER-MINI MP3 player. The code also uses the KEYPAD.H library to scan the keypad matrix.

**How to use the code:**

1. Connect the 7X8 matrix keypad to the STM32F1 series microcontroller as shown in the following diagram:

![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/8dcc5640-02e3-4376-9739-2602869ba58b)


2. Connect the DFPLAYER-MINI MP3 player to the STM32F1 series microcontroller as shown in the following diagram:

![image](https://github.com/GolasalaPuneeth/Embeddedcode_todder_STM32/assets/97512630/615f049a-8905-4ad9-8cd1-d46c40185f1b)


3. Upload the code to the STM32F1 series microcontroller.

4. When you press a key on the keypad, the corresponding MP3 file will be played.

**Heavy configuration:**

When going to heavy configuration, the horizontal pins must be pulled down to GND using 220-ohm resistors. This is because the horizontal pins are drivers, and they need to be pulled down to GND to prevent them from floating.

**Conclusion:**

This code provides a simple way to use a 7X8 matrix keypad and a DFPLAYER-MINI MP3 player with an STM32F1 series microcontroller. The code is well-written and easy to understand.
