const int trigPin = 2, echoPin = 3,pump = 4, red = 5, green = 6, blue = 7;
//long duration, distance;

void setup()
{

  //open the serial port at 9600 bps
  Serial.begin(9600);
  // set the digital pin as input 
  pinMode(echoPin, INPUT);
  // set the digital pin as output
  pinMode(trigPin, OUTPUT);  
  //Setting the digital pin for pump
  pinMode(pump, OUTPUT);
  //Setting the digital pin for led colour
  pinMode(red, OUTPUT);  
  pinMode(green, OUTPUT);  
  pinMode(blue, OUTPUT);  
}

void loop()
{
  //setting triger pin as low 
  digitalWrite(trigPin, LOW); 
  delay(2);
  //setting triger pin as high for 10 milliseconds
  digitalWrite(trigPin, HIGH);  
  delay(10);  
  digitalWrite(trigPin, LOW);
  //get input from the echo pinn 
  long  duration = pulseIn(echoPin, HIGH);
  //calculating the distance 
  long  distance = (duration/2)*0.0343;
  //print the distance in serial monitor
  Serial.print("The distance is: ");
  Serial.print(distance);
  Serial.println(" cms");

  //if water level is full then it will turn off water pump and LED turns red
  if(distance<=15)
  {
    digitalWrite(red, HIGH);
    digitalWrite(pump,LOW);
    delay(100);
    digitalWrite(red, LOW);
  }

  // If the water level is between 15 to 30 cms then LED turns green 
  if(distance>15 && distance<=30)
  {
    digitalWrite(green, HIGH);
    delay(100);
    digitalWrite(green, LOW);
  }

  // If the water level is between 30 to 60 cms then LED turns blue 
  if(distance>30 && distance<=60)
  {
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(blue, LOW);
  }
  
  // If the water level is between 60 to 80 cms then LED turns green 
  if(distance>60 && distance<80)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    delay(100);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }

  if(distance >= 80){
    //Turn on pump when water reaches 80
    digitalWrite(pump,HIGH);
  }



  
}