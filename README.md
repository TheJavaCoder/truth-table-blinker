# 🔌 Pico Logic Gates Demo

A Raspberry Pi Pico project that demonstrates digital logic gates (AND, OR, NAND, NOR, XOR, XNOR) using GPIO pins.  
The program cycles through all input combinations (00, 01, 10, 11) and drives output pins to reflect each gate’s truth table — making Boolean algebra visible with LEDs.  

---

## ✨ Features
- Implements six fundamental logic gates in C  
- Cycles through all input combinations automatically  
- Drives GPIO pins so you can connect LEDs and *see* the truth tables  
- Uses the onboard LED as a heartbeat indicator  

---

## 📚 Truth Tables

| X | Y | AND | OR | NAND | NOR | XOR | XNOR |
|---|---|-----|----|------|-----|-----|------|
| 0 | 0 |  0  |  0 |   1  |  1  |  0  |  1   |
| 0 | 1 |  0  |  1 |   1  |  0  |  1  |  0   |
| 1 | 0 |  0  |  1 |   1  |  0  |  1  |  0   |
| 1 | 1 |  1  |  1 |   0  |  0  |  0  |  1   |

---

## 🛠️ Hardware Setup
- Raspberry Pi Pico (or Pico W)  
- LEDs + resistors connected to GPIO pins:  
  - AND → GP16  
  - OR → GP17  
  - NAND → GP18  
  - NOR → GP19  
  - XOR → GP20  
  - XNOR → GP21  
- Optional: LEDs on GP15 and GP3 to show input values  

---

## 🚀 Getting Started
1. Clone the repo:  
   git clone https://github.com/your-username/pico-logic-gates.git  

2. Build with the Pico SDK:  
   mkdir build && cd build  
   cmake ..  
   make  

3. Flash the `.uf2` file to your Pico.  

---

## 🎯 Demo
Once flashed, the Pico will:  
- Cycle through all input combinations (00, 01, 10, 11)  
- Output the correct gate results on GPIO pins  
- Blink the onboard LED as it steps through each case  

---

## 📸 Inspiration
This project is a hands-on way to visualize Boolean algebra. Instead of just reading truth tables, you can *watch them blink*.  

---

## 🏷️ License
MIT License — feel free to use, modify, and share.  
