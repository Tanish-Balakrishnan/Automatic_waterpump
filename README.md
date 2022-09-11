# Automatic turn_on_off_waterpump
 
Introduction:
 This code is used to turn on and off the water pump automatically
 using ultrasonic sensor.
 
 Triger pin (2) is used to send the signals to as sound waves. After the
 reflection of the sound wave from water it will be captured in echo pin (3)
 using pulseIn function in the class.
  
 Then distance is calculated using (duration/2)*0.0343
 
 Then if the water level reaches below 80cm water pump will turn on.
 If the water reaches 60 to 79 cm LED will turn into white colour.
 IF the water level is in between 30 to 60 cm LED will turn into blue colour.
 IF the water level is in between 15 to 30 cm LED will turn into green colour.
 IF the water level is in less than 15 cm LED will turn into red colour and 
 water pump will turn off.
 
 
 
 
