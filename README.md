
# Automatic Water Level Indicator Using Ultrasonic Sensor and LCD

This project is a simple and effective system to monitor water levels in tanks using an ultrasonic sensor and display the result on an LCD screen. It's designed to help manage water usage more efficiently and avoid tank overflows or dry runs in pumps.

## 🔧 Components Used

- **PIC16F877A**
- **Ultrasonic Sensor (HC-SR04)**
- **16x2 LCD Display**
- **Buzzer** (for alerts)
- **Connecting wires**
- **Breadboard**
- **Power supply**

## 🧠 Principle

The ultrasonic sensor measures the distance between itself and the surface of the water. The PIC16F877A calculates the percentage of water filled in the tank based on the total depth of the tank and the measured distance. This percentage is then displayed on the LCD, and alerts can be triggered when the water level is too low or too high.


Connections:
- **HC-SR04**
  - VCC 
  - GND 
  - Trig 
  - Echo 
- **16x2 LCD**
  
- **Buzzer**
  - Positive 
  - Negative 


## 📟 Output

- Water level is displayed on the LCD in percentage.
- Buzzer gives alert when water is below or above set threshold.

## ✅ Applications

- Residential water tank monitoring
- Industrial liquid level monitoring
- Agriculture and irrigation systems

## 📈 Advantages

- Non-contact water level measurement
- Cost-effective and reliable
- Easy to install and maintain

## ⚠️ Limitations

- Accuracy depends on ultrasonic sensor alignment
- Affected by environmental noise or foam on the water surface

## 📜 Conclusion

This project is a practical and efficient solution for monitoring water levels using PIC16F877A and ultrasonic sensors. It helps save water and protects equipment like water pumps from damage due to dry runs or overflow.
