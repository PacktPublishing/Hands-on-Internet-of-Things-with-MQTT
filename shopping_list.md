# Shopping List

Below you will find all parts needed to build the projects from the book. For most of the parts there are multiple shops listed. While [Sparkfun](https://www.sparkfun.com/) offers most parts, the shipping costs might be expensive depending on where you are located. If you found another shop with good shipping conditions to your country feel free to add it to the list.

### General Parts

The following parts will be needed for all projects in the book.

**Arduino MKR 1010 Wifi** (1 x)

We are using the same development board for all three projects, which means that you have to remove the Arduino from one prototype to use it for another project. If you want to use all three prototypes side by side you will need three Arduino MKR 1010 Wifis. My recommendation is to get one at first to save money. If you later on want to use all three prototypes in parallel, you can buy two more Arduino MKR 1010 Wifis.

- [Sparkfun](https://www.sparkfun.com/products/15251)
- [Exp-Tech](https://www.exp-tech.de/plattformen/arduino/9177/arduino-mkr-wifi-1010) (DE)

**Breadboard (short)** (1 x)

While some of the prototypes can me built just using jumper wires, you need a breadboard whenever multiple components are involved. You need at least one (short) breadboard, but I would recommend to get 3. It is very convenient when working on multiple prototypes in parallel, or if you don’t want to fully disassemble a prototype.

- [Sparkfun](https://www.sparkfun.com/products/12002)
- [Exp-Tech](https://www.exp-tech.de/zubehoer/breadboards/7142/breadboard-400-300/100) (DE)

**Jumper wires (male-male)** (1 x)

Male-to-male jumper wires are used to connect components to the Arduino MKR 1010 Wifi without soldering. There are different lengths available. 15cm are good for most use-cases.

- [Exp-Tech](https://www.exp-tech.de/zubehoer/kabel/jumper-wires/6025/premium-jumper-wire-50-piece-rainbow-assortment-m-m-15cm) (DE)
- [Sparkfun](https://www.sparkfun.com/products/12795)

**Jumper wires (male-female)** (1 x)

Male-to-female jumper wires are used to connect components to the Arduino MKR 1010 Wifi without soldering. In connection with male-to-male jumper wires they can also be connected in sequence to create longer cables. There are different lengths available. 15cm are good for most use-cases.

- [Exp-Tech](https://www.exp-tech.de/zubehoer/kabel/jumper-wires/6025/premium-jumper-wire-50-piece-rainbow-assortment-m-m-15cm) (DE)
- [Sparkfun](https://www.sparkfun.com/products/12794)

**Jumper wire kit (solid)** (1 x)

Solid jumper wires are a replacement for normal (flexible) jumper wires. Once connected it is less likely that a cable falls off by accident. It is good to start off with flexible jumper wires (most convenient) and (once the prototype is working) replace them with solid jumper wires to make the prototype more sturdy.

- [Sparkfun](https://www.sparkfun.com/products/124)
- [Exp-Tech](https://www.exp-tech.de/zubehoer/kabel/jumper-wires/5030/steckbruecken-set-140-teilig-jumper-wire?c=1179) (DE)

**Micro USB cable** (1 x)

Low quality USB cables (which most of us have lying around at home already) often lead to problems when working with development boards like the Arduino MKR 1010 Wifi. Having a good cable reduces these issues.

- [Sparkfun](https://www.sparkfun.com/products/14742)
- [Exp-Tech](https://www.exp-tech.de/zubehoer/kabel/usb/5296/micro-usb-2.0-kabel-usb-st.-a/usb-micro-st.-b-1-0m) (DE)

**USB power supply** (1 x, optional)

If you want to use one of your prototypes without a computer, you will need an external USB power supply. If you already have a USB power supply at home, chances are good that it will work just fine powering your prototype. The output of most USB power supplies will be 5V (as needed). The Ampere will vary though. If it supplies too little Ampere, your prototype will not work as expected. A power supply with 2A will work for all projects in the book and most other Arduino-based projects. More Ampere is fine.

Depening on the power sockets in your country you have to find the fitting power supply for you. 

You might also want to get a longer USB cable as well if you want to use your prototype permanently.

- [Exp-Tech](https://www.exp-tech.de/zubehoer/netzteile/7906/hnp12-usbl6-5v-2-4a-usb-steckernetzteil-12w) (DE-plug)
- [Amazon](https://www.amazon.com/ICV-USB-Wall-Charger-Lightweight/dp/B0119BUJDQ/) (US-plug)

### Parts for Chapter 5

To build the smart pet-food dispenser you need all the parts listed in *General Parts*, as well as:

**Servo motor**

The servo motor is used to open and close the opening of the dispenser. 
A cheap servo motor is the Tower Pro SG90 Micro Servo. For servo motors, the specified voltage often is 4.8V (instead of 3.3V, as needed to be used with the Arduino MKR WiFi 1010), but chances are that it will work just fine using 3.3V. Please make sure you don't buy a digital servo that is not especially made for 3.3V.
Digital ones made for 4.8V will most likely _not_ work with 3.3V.

- [Sparkfun](https://www.adafruit.com/product/169)

### Parts for Chapter 6

To build the e-ink todo list project, you need all parts listed in *General Parts*, as well as:

**Waveshare 4.2 inch e-ink display module three-colour** (1 x)

A 4.2 inch e-ink display module produced by Waveshare. It can display three colors: black, white and red. In contrast to a regular display it is very energy-efficient. While there are also other e-ink displays (other manufacturers, or different models by the same manufacturer), the instructions in the book are for this specific model.

- [Geekbuying](https://www.geekbuying.com/item/Waveshare-4-2-Inch-E-Ink-Display-Module-400x300-Three-color-388289.html)
- [Exp-Tech](https://www.exp-tech.de/displays/e-paper-e-ink/8703/waveshare-4.2-inch-e-ink-display-module-three-color) (DE)

**Push-Button** (1 x, *optional*)

You can extend the project by adding a push-button to it, which will make it more convenient to clear the contents of the screen. Pick any push-button you like. Some of the buttons require soldering.

- [Sparkfun](https://www.sparkfun.com/products/10791) (Breadboard-friendly Button, no soldering required)
- [All buttons available at Sparkfun](https://www.sparkfun.com/categories/313)
- [All buttons available at Exp-Tech](https://www.exp-tech.de/search?sSearch=schalter) (DE)

### Parts for Chapter 7

To build the smart productivity cube you need the parts listed in *General Parts*, as well as:

**Tilt switches** (4 x)

A tilt switch behaves like a button and can be used to sense basic orientation, so if it is held upside down or not. A small metal ball inside the can makes contact with the two pins and therefore closes the connection in upright position.

- [Sparkfun](https://www.sparkfun.com/products/10289)
- [Adafruit](https://www.adafruit.com/product/173)
- [Exp-Tech](https://www.exp-tech.de/sensoren/sonstige/8555/tilt-sensor-at407) (DE)
