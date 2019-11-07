# ATmega-328P-Based-GPS-Receiver

- This project demonstrates how to get information like location (latitude and longitude), time, date, speed and course-angle using a GPS 
  receiver.
- It uses 8-bit AVR microcontroller (MCU) ATmega328P to get data from GPS (GY-NEO6MV2 GPS Module) and display this data on LCD/OLED 64x128
  (ER_OLED0.96-2 with SSD1306 driver).
- I2C port av microcontoller is used to communicate with LCD/OLED and USART port for communnication with GPS.
- Time, date and latitude, longitude of current location are shown on display.
