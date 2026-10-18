# 💧 Smart Water Purification Bottle

A miniature water purification bottle with real-time water quality
monitoring, designed to give underprivileged and slum communities
access to safe drinking water.

> Developed for the **EPD (Engineering Product Design)** module at
> General Sir John Kotelawala Defence University (KDU).

<img width="480" height="657" alt="1758621257213" src="https://github.com/user-attachments/assets/2ca2ec84-1a18-4138-aa90-b0ad4c1cbd97" />


## 🎯 Problem
Many low-income and slum communities lack reliable access to clean
drinking water, which leads to waterborne diseases and poor hygiene.

## 💡 Solution
A compact, affordable bottle that filters water through six layers and
displays the purified water's TDS (Total Dissolved Solids) level so
users can see its quality.

## ⚙️ How It Works
| Section | Function |
|---|---|
| Upper | 300 ml reservoir for raw water |
| Middle | Six-layer filtration unit: [gravel, sand, activated carbon...] |
| Bottom | 300 ml tank for purified water, with TDS sensor |

## 🔧 Hardware
- ESP32-C3 Super Mini
- TDS sensor [model]
- OLED display 
- 2 × 3.7 V Li-Po batteries
- [Charging/protection module, wiring, other components]

## 🔌 Circuit / Wiring
<img width="1023" height="527" alt="1758621257238" src="https://github.com/user-attachments/assets/f303aa44-678d-4f2b-b43b-d293c4b4f858" />


## 💻 Software
- Language: Arduino C++ (Arduino IDE)
- Libraries: [Adafruit_SSD1306, Adafruit_GFX]
- Upload `firmware/water_purifier.ino` to the ESP32-C3 board

## 📊 Results
- [e.g. TDS before filtration: X ppm → after: Y ppm]
- [Test conditions and observations]

## ✅ User Benefits
- Safe, purified drinking water at any time
- Reduced risk of waterborne diseases
- Better hygiene and health
- Affordable for low-income families

## 🚀 Future Improvements
- pH/turbidity sensing, solar charging, filter replacement alerts

## 👥 Team
- [Tharindu Premasundare](https://www.linkedin.com/in/tharindu-premasundare-09a58827a/)
- [Sachila Herath](https://www.linkedin.com/in/sachilaherath/)
- [Naveen Weerakoon](https://www.linkedin.com/in/naveen-weerakoon-bb5443372/)

## 📄 License
MIT License
