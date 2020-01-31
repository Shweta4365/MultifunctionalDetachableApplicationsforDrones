/*
*
* Project Name:   Agricultural Attachment
* Author List:    Siddhant Satam, Sai Rane
* Filename:     Agricultural_Attachment.ino
* Functions:    setup() , loop()
* Global Variables: 3
*
*/

// Initializing the input channel pin
const int CH_1_PIN = 3;

// Initializing the DC water pump control pin
const int pump = 2;

// Initializing the deadzone limit for input PWM value
const int deadzone = 20;

/*
*
* Function Name:   setup()
* Input:    pump , Serial monitor Baud Rate
* Output:   pump is set as output , Serial Monitor Baud rate is set to 9600
* Logic:    pinMode Function is used to define inmput or output
* Example Call:   NA
*
*/

void setup() {
  // Setting the water pump control pin as output
  pinMode(pump, OUTPUT); 

  //Setting the Serial baud rate as 9600
  Serial.begin(9600);
}

/*
*
* Function Name:   loop()
* Input:    CH_1_PIN
* Output:   pwmValue is printed on serial monitor, The pwm value is used for controlling the water pump
* Logic:    pwm signal is read from one channel of the RC receiver and then that pwm value is used to control the Water Pump 
* Example Call:   NA
*
*/
void loop() {

  // Reading the pwmValue of the input signal from the CH-1_PIN
  int pwmValue = pulseIn(CH_1_PIN, HIGH, 25000);

  // Printing the pwm value for our reference on serial monitor
  Serial.println(pwmValue);

  // Using the if and else statements to control the water pump depending on the input PWM value
  if(pwmValue>1600)
  {
   digitalWrite(pump,HIGH); 
  }
  else if(pwmValue<1600)
  {
   digitalWrite(pump,LOW);
  }
}
